# should just be a mathematical forumla


def calculate(y, x):
    larger_number = max(x, y)
    L_number = ((larger_number - 1) ** 2) + 1 if larger_number % 2 else larger_number**2

    other_number = x if larger_number == y else y

    print(L_number - ((other_number - 1)))

def cal(x, y):
    z = max(y, x)
    
    mult = 1
    if z == y:
        l = ((z - 1) ** 2) + 1 if not z % 2 else z ** 2
        n = x
        if y % 2 == 0:
            mult = -1
    elif z == x:
        l = ((z - 1) ** 2) + 1 if z % 2 else z ** 2
        n = y
        if x % 2 == 1:
            mult = -1
    
    return l - ((n - 1) * mult)

N = int(input())

for _ in range(N):
    y, x = map(int, input().split())
    print(cal(y, x))
