search_str = ""
make_str = ""
n = len(make)
for a in range(n):
    search_str += make[a]
    if search_str in map:
        make_str += map[search_str]
        search_str = ""

with open("output.txt", "w") as fh:
    fh.write(make_str)

