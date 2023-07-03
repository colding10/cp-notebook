from sys import stdin, stdout


t = int(stdin.readline())
for _ in range(t):
    stdin.readline()

    inputs = []
    outputs = []

    n, m = map(int, stdin.readline().rstrip().split())

    for l in range(m):
        i, o = stdin.readline().rstrip().split()
        o = int(o)

        inputs.append(i)
        outputs.append(o)

    stdout.write(f"{solve(inputs, outputs)}\n")
