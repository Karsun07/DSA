import heapq

class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:

        adj = [[] for _ in range(n + 1)]

        for u, v, w in times:
            adj[u].append((v, w))

        dist = [float('inf')] * (n + 1)
        dist[k] = 0

        pq = [(0, k)]

        while pq:

            curr_dist, node = heapq.heappop(pq)

            if curr_dist > dist[node]:
                continue

            for neighbour, weight in adj[node]:

                if curr_dist + weight < dist[neighbour]:

                    dist[neighbour] = curr_dist + weight

                    heapq.heappush(
                        pq,
                        (dist[neighbour], neighbour)
                    )

        ans = 0

        for i in range(1, n + 1):

            if dist[i] == float('inf'):
                return -1

            ans = max(ans, dist[i])

        return ans