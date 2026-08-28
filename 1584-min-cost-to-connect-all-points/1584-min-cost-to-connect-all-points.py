class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:

        n=len(points)
        visited=[0]*n
        pq=[(0,0)]
        # cost,node
        total=0
        while pq:
            cost,node=heapq.heappop(pq)

            if visited[node]:
                continue

            visited[node]=1
            total+=cost 

            for i in range(n):
                if not visited[i]:
                    dist=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1])

                    heapq.heappush(pq,(dist,i))


        return total            





        
        