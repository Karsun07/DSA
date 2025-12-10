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
    int getDecimalValue(ListNode* head) {
        string num="";
        while(head){
            num+=to_string(head->val);
            head=head->next;
        }
        int n=num.size();
        reverse(num.begin(),num.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(num[i]-'0')*pow(2,i);
        }
        return ans;
    }
};