def check(a, b):
    if max((a, b)) / 2 > min(a, b):
        return False
    if ((a + b) % 3) == 0:
        return True

    return False

def main():
    N = int(input())

    for _ in range(N):
        if check(*map(int, input().split())):
            print('YES')
        else:
            print('NO')

main()