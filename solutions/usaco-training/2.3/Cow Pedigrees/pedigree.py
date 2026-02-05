"""
ID: colindi1
LANG: PYTHON3
TASK: nocows
"""


fin = open("nocows.in", "r")
fout = open("nocows.out", "w")

n, k = map(int, fin.readline().split())
fout.write(f"{2**(k-2)}\n")
