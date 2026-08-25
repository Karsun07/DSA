from collections import deque
from typing import List

class Solution:

    def bfs(self, i, j, mat):

        q = deque()

        q.append((i,j))
        mat[i][j] = "T"

        r = len(mat)
        c = len(mat[0])

        row = [-1,1,0,0]
        col = [0,0,-1,1]

        while q:

            x,y = q.popleft()

            for k in range(4):

                nx = x + row[k]
                ny = y + col[k]

                if (0 <= nx < r and 
                    0 <= ny < c and 
                    mat[nx][ny] == "O"):

                    mat[nx][ny] = "T"
                    q.append((nx,ny))


    def solve(self, mat: List[List[str]]) -> None:

        if not mat:
            return

        r = len(mat)
        c = len(mat[0])


        # first row
        for j in range(c):
            if mat[0][j] == "O":
                self.bfs(0,j,mat)


        # last row
        for j in range(c):
            if mat[r-1][j] == "O":
                self.bfs(r-1,j,mat)


        # left column
        for i in range(r):
            if mat[i][0] == "O":
                self.bfs(i,0,mat)


        # right column
        for i in range(r):
            if mat[i][c-1] == "O":
                self.bfs(i,c-1,mat)


        # convert
        for i in range(r):
            for j in range(c):

                if mat[i][j] == "T":
                    mat[i][j] = "O"

                elif mat[i][j] == "O":
                    mat[i][j] = "X"