from collections import deque


class Solution:

    def fun(self, heights, type):

        r = len(heights)
        c = len(heights[0])

        q = deque()

        visited = [[False for _ in range(c)] for _ in range(r)]

        row = [-1, 1, 0, 0]
        col = [0, 0, -1, 1]


        # Pacific Ocean
        if type == 0:

            for i in range(r):
                for j in range(c):

                    if i == 0 or j == 0:
                        q.append((i,j))
                        visited[i][j] = True


        # Atlantic Ocean
        else:

            for i in range(r):
                for j in range(c):

                    if i == r-1 or j == c-1:
                        q.append((i,j))
                        visited[i][j] = True



        while q:

            i,j = q.popleft()

            for k in range(4):

                i1 = i + row[k]
                j1 = j + col[k]


                if (0 <= i1 < r and 
                    0 <= j1 < c and 
                    not visited[i1][j1] and 
                    heights[i1][j1] >= heights[i][j]):

                    visited[i1][j1] = True
                    q.append((i1,j1))


        return visited



    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:

        r = len(heights)
        c = len(heights[0])


        pacific = self.fun(heights, 0)

        atlantic = self.fun(heights, 1)


        ans = []

        for i in range(r):
            for j in range(c):

                if pacific[i][j] and atlantic[i][j]:
                    ans.append([i,j])


        return ans