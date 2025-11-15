/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;   // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> p;

        
        for (auto node : lists) {
            if (node) p.push(node);
        }

        if (p.empty()) return nullptr;

       
        ListNode* head = p.top();
        p.pop();

        ListNode* temp = head;
        if (temp->next) p.push(temp->next);

      
        while (!p.empty()) {
            ListNode* x = p.top();
            p.pop();

            temp->next = x;
            temp = temp->next;

            if (x->next) p.push(x->next);
        }

        return head;
    }
};
