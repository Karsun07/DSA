# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        if not head or not head.next:
            return

        arr = []

        temp = head

        while temp:
            arr.append(temp)
            temp = temp.next

        l = 0
        r = len(arr) - 1

        while l < r:

            leftNode = arr[l]

            rightNode = arr[r]

            nextLeft = arr[l + 1]

            leftNode.next = rightNode

            rightNode.next = nextLeft

            l += 1
            r -= 1

        arr[l].next = None