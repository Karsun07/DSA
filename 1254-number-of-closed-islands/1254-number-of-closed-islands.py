class Solution:
    def bfs(self, i, j, grid):
        n = len(grid)
        m = len(grid[0])

        grid[i][j] = 1
        q = deque()
        q.append((i, j))

        directions = [(0,1), (0,-1), (1,0), (-1,0)]

        while q:
            r, c = q.popleft()

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == 0:
                    grid[nr][nc] = 1
                    q.append((nr, nc))

    def closedIsland(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])


        for i in range(n):
            if grid[i][0] == 0:
                self.bfs(i, 0, grid)

            if grid[i][m-1] == 0:
                self.bfs(i, m-1, grid)

        for j in range(m):
            if grid[0][j] == 0:
                self.bfs(0, j, grid)

            if grid[n-1][j] == 0:
                self.bfs(n-1, j, grid)


        count = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    count += 1
                    self.bfs(i, j, grid)

        return count