class Solution {
public:
    ListNode* fun(ListNode* list1, ListNode* list2, ListNode* head){
        if(!list1){
            head->next = list2;
            return head;
        }
        if(!list2){
            head->next = list1;
            return head;
        }

        if(list1->val < list2->val){
            head->next = list1;
            fun(list1->next, list2, list1);
        } else {
            head->next = list2;
            fun(list1, list2->next, list2);
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        fun(list1, list2, dummy);
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
