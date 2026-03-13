/*
 * api-ms-win-core-synch-l1-2-0.dll stub for Windows 7
 * Based on https://github.com/petrkr/api-ms-win-core-synch-Win7
 *
 * Implements WaitOnAddress/WakeByAddress* using CONDITION_VARIABLE
 * (available since Vista/Win7). All other synch functions are forwarded
 * to kernel32.dll via the DEF file.
 */
#include <windows.h>
#include <string.h>

typedef struct _ADDR_CVAR_ASSOC {
	volatile VOID *Address;
	CONDITION_VARIABLE CVar;
	UINT NumberOfWaiters;
} ADDR_CVAR_ASSOC, *PADDR_CVAR_ASSOC;

#define AddrCVarAssocTblSize ((SIZE_T)256)
CRITICAL_SECTION AddrCVarAssocTblLock;
PADDR_CVAR_ASSOC AddrCVarAssocTbl[AddrCVarAssocTblSize];

BOOL WINAPI DllMain(
	HINSTANCE hInstDLL,
	DWORD fdwReason,
	LPVOID lpReserved)
{
	(void)hInstDLL;
	(void)lpReserved;

	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		memset(AddrCVarAssocTbl, 0, sizeof(AddrCVarAssocTbl));
		InitializeCriticalSection(&AddrCVarAssocTblLock);
		break;
	case DLL_PROCESS_DETACH:
		DeleteCriticalSection(&AddrCVarAssocTblLock);
		break;
	}

	return TRUE;
}

static BOOL CompareVolatileMemory(const volatile void *A1, const void *A2, size_t size)
{
	switch (size) {
	case 1:		return (*(const UINT8*)A1 == *(const UINT8*)A2);
	case 2:		return (*(const UINT16*)A1 == *(const UINT16*)A2);
	case 4:		return (*(const UINT32*)A1 == *(const UINT32*)A2);
	case 8:		return (*(const UINT64*)A1 == *(const UINT64*)A2);
	default:	return FALSE;
	}
}

BOOL WINAPI WaitOnAddress(
	volatile VOID *Address,
	PVOID CompareAddress,
	SIZE_T AddressSize,
	DWORD dwMilliseconds)
{
	SIZE_T idxAddrCVarAssoc;
	SIZE_T availableNullSlot = 0;
	BOOL ReturnValue;
	DWORD SleepConditionVariableCSError;

	if (!Address || !CompareAddress) {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (!(AddressSize == 1 || AddressSize == 2 || AddressSize == 4 || AddressSize == 8)) {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	EnterCriticalSection(&AddrCVarAssocTblLock);
	if (!CompareVolatileMemory(Address, CompareAddress, AddressSize)) {
		LeaveCriticalSection(&AddrCVarAssocTblLock);
		SetLastError(ERROR_SUCCESS);
		return TRUE;
	}

	for (idxAddrCVarAssoc = 0; idxAddrCVarAssoc < AddrCVarAssocTblSize; ++idxAddrCVarAssoc) {
		if (AddrCVarAssocTbl[idxAddrCVarAssoc] && AddrCVarAssocTbl[idxAddrCVarAssoc]->Address == Address) {
			break;
		} else if (AddrCVarAssocTbl[idxAddrCVarAssoc] == NULL) {
			availableNullSlot = idxAddrCVarAssoc;
		}
	}

	if (!(AddrCVarAssocTbl[idxAddrCVarAssoc] && AddrCVarAssocTbl[idxAddrCVarAssoc]->Address == Address)) {
		idxAddrCVarAssoc = availableNullSlot;
		AddrCVarAssocTbl[idxAddrCVarAssoc] = (PADDR_CVAR_ASSOC) malloc(sizeof(ADDR_CVAR_ASSOC));
		InitializeConditionVariable(&AddrCVarAssocTbl[idxAddrCVarAssoc]->CVar);
		AddrCVarAssocTbl[idxAddrCVarAssoc]->Address = Address;
		AddrCVarAssocTbl[idxAddrCVarAssoc]->NumberOfWaiters = 1;
	} else {
		++AddrCVarAssocTbl[idxAddrCVarAssoc]->NumberOfWaiters;
	}

	ReturnValue = SleepConditionVariableCS(&AddrCVarAssocTbl[idxAddrCVarAssoc]->CVar, &AddrCVarAssocTblLock, dwMilliseconds);
	SleepConditionVariableCSError = GetLastError();

	if (--AddrCVarAssocTbl[idxAddrCVarAssoc]->NumberOfWaiters == 0) {
		free(AddrCVarAssocTbl[idxAddrCVarAssoc]);
		AddrCVarAssocTbl[idxAddrCVarAssoc] = NULL;
	}
	LeaveCriticalSection(&AddrCVarAssocTblLock);

	SetLastError(SleepConditionVariableCSError);
	return ReturnValue;
}

void WINAPI WakeByAddressAll(PVOID Address)
{
	SIZE_T idxAddrCVarAssoc;
	EnterCriticalSection(&AddrCVarAssocTblLock);
	for (idxAddrCVarAssoc = 0; idxAddrCVarAssoc < AddrCVarAssocTblSize; ++idxAddrCVarAssoc) {
		if (AddrCVarAssocTbl[idxAddrCVarAssoc] && AddrCVarAssocTbl[idxAddrCVarAssoc]->Address == Address) {
			WakeAllConditionVariable(&AddrCVarAssocTbl[idxAddrCVarAssoc]->CVar);
			break;
		}
	}
	LeaveCriticalSection(&AddrCVarAssocTblLock);
}

void WINAPI WakeByAddressSingle(PVOID Address)
{
	SIZE_T idxAddrCVarAssoc;
	EnterCriticalSection(&AddrCVarAssocTblLock);
	for (idxAddrCVarAssoc = 0; idxAddrCVarAssoc < AddrCVarAssocTblSize; ++idxAddrCVarAssoc) {
		if (AddrCVarAssocTbl[idxAddrCVarAssoc] && AddrCVarAssocTbl[idxAddrCVarAssoc]->Address == Address) {
			WakeConditionVariable(&AddrCVarAssocTbl[idxAddrCVarAssoc]->CVar);
			break;
		}
	}
	LeaveCriticalSection(&AddrCVarAssocTblLock);
}
