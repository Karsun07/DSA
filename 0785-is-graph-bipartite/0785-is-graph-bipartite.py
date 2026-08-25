from collections import deque
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:

        n=len(graph)
        color=[-1]*n

        for i in range(n):

            if color[i]==-1:
                q=deque()
                q.append(i)
                color[i]=0

                while q :
                    node =q[0]
                    q.popleft()
                    for nb in graph[node]:

                        if color[nb] == -1:
                            color[nb] = (color[node] + 1) % 2
                            q.append(nb)

                        elif color[nb] == color[node]:
                            return False
        
        return True


        
        