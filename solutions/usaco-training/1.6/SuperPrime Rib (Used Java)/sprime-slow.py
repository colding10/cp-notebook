'''
ID: colindi1
LANG: PYTHON3
TASK: sprime
'''

# too slow, used Java instead

with open('sprime.in', 'r') as file:
    rib_length = int(file.readline())

def isPrime(n):
    """Returns True if n is prime."""
    if n == 1:
        return False
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

def isSuperPrime(n):
    n = str(n)
    for slice_amount in range(len(n)):
        if slice_amount == 0:
            test_num = n
        else:
            test_num = n[:-slice_amount]
        
        if not isPrime(int(test_num)):
            return False
    
    return True

def sum_digits(n):
   r = 0
   while n:
       r, n = r + n % 10, n // 10
   return r

out_list = []

for odd_number in range((10 ** (rib_length - 1)) + 1, (10 ** (rib_length)), 2):
    if sum_digits(odd_number) % 3 == 0:
        continue
    if odd_number % 10 == 5:
        continue
    
    if isSuperPrime(odd_number):
        out_list.append(str(odd_number))

out = '\n'.join(out_list)

with open('sprime.out', 'w') as file:
    file.write(out)
    file.write('\n')