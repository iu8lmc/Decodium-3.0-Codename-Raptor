"""
Patch GetSystemTimePreciseAsFileTime -> GetSystemTimeAsFileTime in PE import table.
Only patches the import hint/name entry (identified by 2-byte hint prefix < 0x1000).
"""
import sys

target = sys.argv[1]

with open(target, "rb") as f:
    data = bytearray(f.read())

old_name = b"GetSystemTimePreciseAsFileTime"
new_name = b"GetSystemTimeAsFileTime"
replacement = new_name + b'\x00' * (len(old_name) - len(new_name))

pos = 0
patched = 0
while True:
    pos = data.find(old_name, pos)
    if pos < 0:
        break
    # Import hint/name entries have a 2-byte hint before the name
    # and are followed by a null terminator
    hint = int.from_bytes(data[pos-2:pos], 'little')
    followed_by_null = (data[pos + len(old_name)] == 0)
    if hint < 0x2000 and followed_by_null:
        data[pos:pos+len(old_name)] = replacement
        patched += 1
        print(f"Patched import entry at 0x{pos:x} (hint={hint})")
    else:
        print(f"Skipped symbol at 0x{pos:x} (hint={hint}, null={followed_by_null})")
    pos += len(old_name)

if patched:
    with open(target, "wb") as f:
        f.write(data)
    print(f"Done: {patched} import(s) patched")
else:
    print("No import entries found to patch")
