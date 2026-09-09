# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = []
        count = 0

        # Put first node of every list into heap
        for node in lists:
            if node:
                heapq.heappush(pq, (node.val, count, node))
                count += 1

        # No nodes
        if not pq:
            return None

        # Dummy node
        dummy = ListNode(0)
        tail = dummy

        while pq:

            # Get smallest node
            _, _, node = heapq.heappop(pq)

            # Attach it to answer
            tail.next = node
            tail = tail.next

            # Put next node of same list into heap
            if node.next:
                heapq.heappush(pq, (node.next.val, count, node.next))
                count += 1

        return dummy.next


        

        