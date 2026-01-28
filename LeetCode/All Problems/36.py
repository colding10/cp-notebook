"""
36. Valid Sudoku
MEDIUM
"""

class Solution:
    def isValidList(self, list: List[str]) -> bool:
        for c in "123456789":
            if list.count(c) > 1:
                return False
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            if not self.isValidList(board[i]):
                return False
            if not self.isValidList([l[i] for l in board]):
                return False
        
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                rows = board[i:i+3]
                square = [row[j:j+3] for row in rows]
                if not self.isValidList(sum(square, [])):
                    return False
        
        return True