#
# @lc app=leetcode id=412 lang=python3
#
# [412] Fizz Buzz
#

# @lc code=start
class Solution:
    def calculate(self, n: int) -> str:
        if n % 3 == 0 and n % 5 == 0:
            return "FizzBuzz"
        if n % 3 == 0:
            return "Fizz"
        if n % 5 == 0:
            return "Buzz"
        
        return str(n)
    
    def fizzBuzz(self, n: int) -> List[str]:
        return [self.calculate(n) for n in range(1, n+1)]
# @lc code=end

