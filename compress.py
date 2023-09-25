f = open("output.bin", "r")
output = open("compressed.bin", "bw")
byte_array = bytearray()
for x in f:
    if x == "":
        continue
    for i in range(0, len(x) - 1, 8):
        temp = x[i:i + 8]
        byte_array.append(int(temp, 2))
output.write(bytes(byte_array))
