def proc(orig):
    out = []
    integers = []
    in_integer = False
    curr_int = ""
    for c in orig:
        if c.isupper():
            out.append(c)
            if curr_int:
                # print(curr_int)
                integers.append(int(curr_int))
                curr_int = ""
        elif c == '-':
            if curr_int:
                integers.append(int(curr_int))
                curr_int = c
            else:
                curr_int += c
        elif c.isdigit():
            curr_int += c
        else:
            if curr_int:
                # print(curr_int)
                integers.append(int(curr_int))
                curr_int = ""
    if curr_int:
        integers.append(int(curr_int))
    # print(integers)
    out.append(str(sum(integers)))
    return "".join(out)

n = int(input())
for _ in range(n):
    orig = input().strip()
    print(proc(orig))
