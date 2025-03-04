from sys import stdin, stdout
from itertools import chain

correct = [list(stdin.readline().strip()) for _ in range(3)]
guess = [list(stdin.readline().strip()) for _ in range(3)]

correct = list(chain.from_iterable(correct))
guess = list(chain.from_iterable(guess))

green = 0
yellow = 0

pool = {}
for g, s in zip(guess, correct):
    if g == s:
        continue
    if s in pool:
        pool[s] += 1
    else:
        pool[s] = 1
        
for guess_letter, solution_letter in zip(guess, correct):
    if guess_letter == solution_letter:
        green += 1
    elif guess_letter in correct and guess_letter in pool and pool[guess_letter] > 0:
        yellow += 1
        pool[guess_letter] -= 1


stdout.write(f"{green}\n{yellow}\n")
