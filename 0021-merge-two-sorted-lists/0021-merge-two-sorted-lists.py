class Solution:
    def mergeTwoLists(self, list1, list2):

        if list1 == None:
            return list2
        if list2 == None:
            return list1

        if list1.val <= list2.val:
            head = list1
            list1 = list1.next
        else:
            head = list2
            list2 = list2.next

        tail = head

        while list1 and list2:

            if list1.val <= list2.val:
                tail.next = list1      
                list1 = list1.next      
            else:
                tail.next = list2      
                list2 = list2.next      
                
            tail = tail.next

        if list1:
            tail.next = list1
        else:
            tail.next = list2

        return head