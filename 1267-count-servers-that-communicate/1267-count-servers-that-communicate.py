class Solution:
    def countServers(self, grid: list[list[int]]) -> int:

        n = len(grid)
        m = len(grid[0])

        col = [0] * m
        row = [0] * n
        total = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    total += 1
                    col[j] += 1
                    row[i] += 1

        for i in range(n):
            if row[i]==1:
                for j in range(m):
                    if grid[i][j]==1 and col[j]==1:
                        total-=1
        
        return total