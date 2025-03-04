import sys

sys.stdin = open('censor.in')
sys.stdout = open('censor.out', 'w')

s = input().rstrip()
t = input().rstrip()

n = len(t)

censored = ''

for c in s:
    censored += c
    if censored[-n:] == t:
        censored = censored[:-n]

print(censored)
