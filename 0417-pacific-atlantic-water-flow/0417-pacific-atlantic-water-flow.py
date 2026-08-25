from typing import List

class Solution:

    def dfs(self, i, j, heights, visited):

        visited[i][j] = True

        r = len(heights)
        c = len(heights[0])

        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        for dx, dy in directions:

            x = i + dx
            y = j + dy

            if x < 0 or x >= r or y < 0 or y >= c:
                continue

            if visited[x][y]:
                continue

            # reverse flow condition
            if heights[x][y] < heights[i][j]:
                continue

            self.dfs(x, y, heights, visited)



    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:

        r = len(heights)
        c = len(heights[0])


        pacific = [[False] * c for _ in range(r)]
        atlantic = [[False] * c for _ in range(r)]


        # Pacific ocean (top row + left column)

        for j in range(c):
            self.dfs(0, j, heights, pacific)

        for i in range(r):
            self.dfs(i, 0, heights, pacific)



        # Atlantic ocean (bottom row + right column)

        for j in range(c):
            self.dfs(r-1, j, heights, atlantic)

        for i in range(r):
            self.dfs(i, c-1, heights, atlantic)



        ans = []

        for i in range(r):
            for j in range(c):

                if pacific[i][j] and atlantic[i][j]:
                    ans.append([i, j])


        return ans