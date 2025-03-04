#TLE

from itertools import compress
from math import prod

def getNumberOfFactors(n: int):
    factorization = getPrimeFactorization(n)

    return prod([i[1] + 1 for i in factorization])

def getPrimeFactorization(n: int):
    """ Returns a list of the prime factorization of n, in tuples containing base and exponent."""
    primes_list = getPrimes(int(n ** 0.5) + 1)
    pf = []
    for p in primes_list:
        if p * p > n: break
        count = 0
        while not n % p:
            n //= p
            count += 1
        if count > 0: pf.append((p, count))
    if n > 1: pf.append((n, 1))
    return pf

def getPrimes(n: int):
    """ Returns a list of primes < n for n > 2 """
    sieve = bytearray([True]) * (n // 2)
    for i in range(3, int(n ** 0.5) + 1, 2):
        if sieve[i // 2]:
            sieve[i * i // 2::i] = bytearray((n - i * i - 1) // (2 * i) + 1)

    return [2, *compress(range(3, n, 2), sieve[1:])]

N = int(input())

queries = [int(input()) for _ in range(N)]

for query in queries:
    print(getNumberOfFactors(query))