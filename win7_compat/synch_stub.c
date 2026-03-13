/*
 * api-ms-win-core-synch-l1-2-0.dll stub for Windows 7
 *
 * Implements WaitOnAddress / WakeByAddressSingle / WakeByAddressAll
 * using Win7-compatible APIs (polling + Sleep).
 *
 * On Win8+ these are native KERNEL32 exports; on Win7 they don't exist,
 * so this DLL provides them.
 */

#include <windows.h>

/* ---------- WaitOnAddress ----------
 * Blocks until the value at Address differs from CompareAddress,
 * or until dwMilliseconds elapses.
 */
BOOL WINAPI WaitOnAddress(
    volatile VOID *Address,
    PVOID CompareAddress,
    SIZE_T AddressSize,
    DWORD dwMilliseconds)
{
    DWORD start = GetTickCount();

    for (;;) {
        BOOL changed = FALSE;

        switch (AddressSize) {
        case 1:
            changed = (*(volatile BYTE *)Address != *(BYTE *)CompareAddress);
            break;
        case 2:
            changed = (*(volatile SHORT *)Address != *(SHORT *)CompareAddress);
            break;
        case 4:
            changed = (*(volatile LONG *)Address != *(LONG *)CompareAddress);
            break;
        case 8:
            changed = (*(volatile LONGLONG *)Address != *(LONGLONG *)CompareAddress);
            break;
        default:
            changed = (memcmp((const void *)Address, CompareAddress, AddressSize) != 0);
            break;
        }

        if (changed)
            return TRUE;

        if (dwMilliseconds == 0) {
            SetLastError(ERROR_TIMEOUT);
            return FALSE;
        }

        if (dwMilliseconds != INFINITE) {
            DWORD elapsed = GetTickCount() - start;
            if (elapsed >= dwMilliseconds) {
                SetLastError(ERROR_TIMEOUT);
                return FALSE;
            }
        }

        Sleep(1);  /* 1 ms polling — low CPU, adequate latency for Qt/Boost usage */
    }
}

/* ---------- WakeByAddressSingle / WakeByAddressAll ----------
 * In a polling implementation these are no-ops: the waiter
 * re-checks the value every 1 ms anyway.
 */
void WINAPI WakeByAddressSingle(PVOID Address)
{
    (void)Address;
}

void WINAPI WakeByAddressAll(PVOID Address)
{
    (void)Address;
}
