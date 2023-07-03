import sys, os
from io import IOBase, BytesIO

BUFFSIZE = 8192

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

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

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
        

def generateDigitPos():
    digits = 1
    digit_pos = 9
    starting_ending = (1, 9)
    
    yield (digit_pos, digits, starting_ending)
    
    while True:
        digits += 1
        starting_ending = starting_ending[0] * 10, (starting_ending[1]) * 10 + 9
        digit_pos += (abs(starting_ending[0] - starting_ending[1]) + 1) * digits
        
        yield (digit_pos, digits, starting_ending)

def findDigitAtPos(p):
    for digit_pos, digits, starting_ending in generateDigitPos():
        if p <= digit_pos:
            break
        
    starting, ending = starting_ending
    numbers, remainder = divmod(digit_pos - p, digits)
    
    return str(ending - numbers)[(remainder + 1) * -1]

def solve(n):
    global x, a
    
    if a == -1:
        a = [1]
    if x == -1:
        x = 1
        
    while len(a) <= n:
        a[-1:-1] = list(map(int, str(x)))
        x += 1
        print('adding num')
        
    return a[n - 1]

a = -1
x = -1

N = int(input())

for _ in range(N):
    print(findDigitAtPos(int(input())))