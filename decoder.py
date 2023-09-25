with open("compressed.bin", "rb") as fh:
    bin_map_data = fh.readline()
    bin_data = fh.read()

map_str = bin_map_data.decode("utf-8")
sym_lst = map_str.split(";")
sym_map = {}

for a in sym_lst:
    if a[2::] in sym_map:
        continue
    sym_map[a[2::]] = a[0]

bin_str = bin_data.decode("utf-8")
search_str = ""
make_str = ""
n = len(bin_str)

for m in range(n):
    search_str += bin_str[m]
    if search_str in sym_map:
        make_str += sym_map[search_str]
        search_str = ""

with open("uncompressed.txt", "w+") as fw:
    fw.write(make_str)


