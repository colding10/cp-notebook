# ==============================              CONFIG                ==============================
NEEDED_LIBRARIES = \
    [
        'itertools'
    ]

BUFFSIZE = 8192
MOD_NUMBER = 1000000007 #10 ^ 9 + 7

STDIN_FILE = None
STDOUT_FILE = None

# ==============================              IMPORTS                ==============================
# DEFAULTS
import os, sys, math
from io import BytesIO, IOBase


# CUSTOMS
for library_name in NEEDED_LIBRARIES:
    library_name = __import__(library_name)

# ==============================              FAST I/O                ==============================
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
  
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")

sys.stdin, sys.stdout = IOWrapper(STDIN_FILE or sys.stdin), IOWrapper(STDOUT_FILE or sys.stdout)

def input():
    return sys.stdin.readline().rstrip("\r\n")
def print(*args, **kwargs):  
    """Prints the values to a stream, or to sys.stdout by default."""
    
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
            
        file.write(str(x))
        at_start = False
        
    file.write(kwargs.pop("end", "\n"))
    
    if kwargs.pop("flush", False):
        file.flush()
        

# ==============================              CUSTOM INPUT FUNCTIONS                ==============================
def map_integers_input(seperator = ' '): return map(int, input().strip().split(seperator))
def map_floats_input(seperator = ' '): return map(float, input().strip().split(seperator))
def map_booleans_input(seperator = ' '): return map(bool, input().strip().split(seperator))

def list_integers_input(seperator = ' '): return list(map_integers_input(seperator = seperator))
def list_floats_input(seperator = ' '): return list(map_floats_input(seperator = seperator))
def list_booleans_input(seperator = ' '): return list(map_booleans_input(seperator = seperator))


# ==============================              CONSTANTS                ==============================
alphabet_lowercase = 'abcdefghijklmnopqrstuvwxyz'
alphabet_uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
alphabet_both = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'

vowels_lowercase = ['a', 'e', 'i', 'o', 'u']
vowels_uppercase = ['A', 'E', 'I', 'O', 'U']

infinity = float('inf')

# ==============================              CUSTOM MATH FUNCTIONS                ==============================
def isPowerOfTwo(n): return (n and (not(n & (n - 1)))) 
def decimalToBinary(n): return bin(n).replace("0b", "")
def LCMofArray(array): return math.lcm(*array)
def makePairs(array): return [[array[i], array[i + 1]] for i in range(len(array) - 1)]

# ==============================              MAIN CODE                ==============================
def main():
    N, T = map_integers_input()
    speeds = list_integers_input()
    
    total_prods_per_sec = sum((1 / s for s in speeds))
    minimum_time = math.floor(total_prods_per_sec)
    
    for time in range(minimum_time, minimum_time * 100):
        prods_made = sum((divmod(time, speeds[i])[0] for i in range(N)))
        
        if prods_made >= T:
            print(time)
            return
    
    print(time)

if __name__ == '__main__':
    main()