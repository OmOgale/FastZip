f = open("output.bin", "r")
output = open("compressed.bin", "bw")
for x in f:
    if x != "" and x != '\n':
        temp = int(x)
        output.write(temp.to_bytes(15, 'big'))
