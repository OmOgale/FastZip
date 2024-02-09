import os
import sys

if len(sys.argv) < 2:
    sys.exit(1)

encoding_length_val = int(sys.argv[1])
f = open("intermediate.txt", "r")
output = open("compressed.bin", "bw")

byte_array = bytearray()
byte_array.extend((encoding_length_val).to_bytes(3, 'big'))
for x in f:
    if x == "":
        continue
    for i in range(0, len(x) - 1, 8):
        temp = x[i:i + 8]
        byte_array.append(int(temp, 2))
output.write(bytes(byte_array))
os.remove("intermediate.txt")
