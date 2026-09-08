class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next)
            return;

        vector<ListNode*> arr;

        ListNode* temp = head;

        while (temp) {
            arr.push_back(temp);
            temp = temp->next;
        }

        int l = 0;
        int r = arr.size() - 1;

        while (l < r) {

            ListNode* leftNode = arr[l];

            ListNode* rightNode = arr[r];

            ListNode* nextLeft = arr[l + 1];

            leftNode->next = rightNode;

            rightNode->next = nextLeft;

            l++;
            r--;

        }

        arr[l]->next = nullptr;
    }
};