# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq=[]
        count=0

        for list in lists:
            if list:
                heapq.heappush(pq,(list.val,count,list))
                count+=1
        
        if not pq:
            return None

        dummy=ListNode(0)
        tail=dummy

        while pq:
            _,_,node=heapq.heappop(pq)

            tail.next=node
            tail=tail.next

            if node.next:
                heapq.heappush(pq,(node.next.val,count,node.next))
                count+=1

        return dummy.next


        

        