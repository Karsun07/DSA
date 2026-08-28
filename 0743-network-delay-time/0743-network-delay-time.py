class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:

        # distance array
        dist = [float('inf')] * (n + 1)

        # source node
        dist[k] = 0

        # relax all edges n-1 times
        for _ in range(n - 1):

            change = False

            for u, v, t in times:

                if dist[u] != float('inf') and dist[u] + t < dist[v]:
                    dist[v] = dist[u] + t
                    change = True

            # optimization: if no update, stop early
            if not change:
                break

        # find maximum distance
        ans = 0

        for i in range(1, n + 1):

            # unreachable node
            if dist[i] == float('inf'):
                return -1

            ans = max(ans, dist[i])

        return ans