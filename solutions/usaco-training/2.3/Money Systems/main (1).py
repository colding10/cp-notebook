'''
ID: colindi1
LANG: PYTHON3
TASK: money
'''

from math import factorial

stdin = open('money.in', 'r')
stdout = open('money.out', 'w')

V, N = map(int, stdin.readline().split())
coins = sorted(list(map(int, stdin.readline().split())))

def count(coins, n, sum):
 
    # table[i] will be storing the number of solutions for
    # value i. We need sum+1 rows as the table is constructed
    # in bottom up manner using the base case (sum = 0)
    # Initialize all table values as 0
    table = [0 for _ in range(sum+1)]

    # Base case (If given value is 0)
    table[0] = 1

    # Pick all coins one by one and update the table[] values
    # after the index greater than or equal to the value of the
    # picked coin
    for i in range(n):
        for j in range(coins[i], sum+1):
            table[j] += table[j - coins[i]]

    return table[sum]
            
res = count(coins, len(coins), N)

stdout.write(f'{res}\n')