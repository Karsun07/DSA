# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        ptr=head
        temp=head
        i=1
        while(i<=n):
            ptr=ptr.next
            i=i+1
        
        if not ptr:
            return head.next
        
        while ptr.next:
            ptr=ptr.next
            temp=temp.next
        
        temp.next=temp.next.next

        return head

        