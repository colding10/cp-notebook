def bit_difference(a, b):
    x = a^b
    return bin(x).count('1')

def read_cow(s):
    return eval('0b' + s.replace("G", "1").replace("H", "0"))

def solve(i, cows):
    cow = cows[i]
    maximum = -1
    for j in range(len(cows)):
        if j == i:
            continue
        maximum = max(maximum, bit_difference(cow, cows[j]))
    
    return maximum

def main():
    length, n = map(int, input().split())
    cows = [read_cow(input()) for _ in range(n)]
    
    for i in range(n):
        print(solve(i, cows))

main()