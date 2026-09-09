# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        mp={}

        temp=head
        while(temp):
            if temp in mp:
                return True
            mp[temp]=mp.get(temp,0)+1
            temp=temp.next
        
        return False
        