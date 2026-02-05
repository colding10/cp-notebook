'''
ID: colindi1
LANG: PYTHON3
TASK: pprime
'''

# simple logic, not much algorithms
# generate the palindromes with the lengths incrementing
# check if it is prime
# much faster than looping through primes or by checking odd numbers
# there are way less palindromes

with open('pprime.in', 'r') as file:
    A, B = map(int, file.readline().strip().split())

def isPrime(n):
    """Returns True if n is prime."""
    if n == 2:
        return True
    if n == 3:
        return True
    if n % 2 == 0:
        return False
    if n % 3 == 0:
        return False

    i = 5
    w = 2

    while i * i <= n:
        if n % i == 0:
            return False

        i += w
        w = 6 - w

    return True

def generatePalindromesWithLength(length):
    palindromes = []

    if length == 1:
        return [i for i in range(10)]
    if length % 2 == 0:
        half_length = int(length / 2)
        for x in range(10 ** (half_length - 1), 10 ** half_length):
            palindromes.append(int(str(x) + str(x)[::-1]))
    else:
        half_length = int((length - 1) / 2)
        for x in range(0, 10):
            for y in range(10 ** (half_length - 1), 10 ** half_length):
                palindromes.append(int(str(y) + str(x) + str(y)[::-1]))
    
    palindromes.sort()
    return palindromes

def generatePalindromes(minimum_number, maximum_number):
    starting_length = len(str(minimum_number))
    ending_length = len(str(maximum_number))

    for length in range(starting_length, ending_length + 1):
        palindromes = generatePalindromesWithLength(length)

        for palindrome in palindromes:
            if minimum_number <= palindrome <= maximum_number:
                yield palindrome

out_list = []

palindrome_generator = generatePalindromes(A, B)

for palindrome in palindrome_generator:
    if isPrime(palindrome):
        out_list.append(str(palindrome))

out = '\n'.join(out_list)

with open('pprime.out', 'w') as file:
    file.write(out)
    file.write('\n')