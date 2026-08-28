class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:

        adj=[[] for _ in range(n)]

        for u,v,t in flights:
            adj[u].append((v,t))
        
        dist = [[float('inf')] * (k + 2) for _ in range(n)]

        pq=[]
        dist[src][0]=0
        heapq.heappush(pq, (0, src, 0))
        # dist,node,stops

        while pq:
            cost,node,stops=heapq.heappop(pq)

            if dist[node][stops]<cost :
                continue
            
            if node==dst :
                return cost
            if stops==k+1 :
                continue

            for v,t in adj[node]:
                if(dist[v][stops+1]>dist[node][stops]+t):
                    dist[v][stops+1]=dist[node][stops]+t
                    heapq.heappush(pq,(dist[v][stops+1],v,stops+1))
            
        return -1
            

