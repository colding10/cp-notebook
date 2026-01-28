#
# @lc app=leetcode id=733 lang=python3
#
# [733] Flood Fill
#

# @lc code=start
class Solution:
    def floodFill(
        self, image: List[List[int]], sr: int, sc: int, color: int
    ) -> List[List[int]]:
        visited = [[False for _ in range(len(image[0]))] for _ in range(len(image))]

        self.original = image[sr][sc]
        
        self.dfs(image, visited, sr, sc, color)
        
        return image

    def dfs(
        self,
        image: List[List[int]],
        visited: List[List[bool]],
        i: int,
        j: int,
        color: int):
        if i < 0 or i >= len(image) or j < 0 or j >= len(image):
            return
        if image[i][j] == self.original and not visited[i][j]:
            visited[i][j] = True
            image[i][j] = color
            self.dfs(image, visited, i - 1, j, color)
            self.dfs(image, visited, i + 1, j, color)
            self.dfs(image, visited, i, j - 1, color)
            self.dfs(image, visited, i, j + 1, color)
# @lc code=end
