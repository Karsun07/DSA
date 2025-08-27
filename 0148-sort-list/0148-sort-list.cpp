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
    ListNode* sortList(ListNode* head) {
        ListNode* curr=head;
        vector<int>arr;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        head=NULL;
        curr=NULL;
        for(int i=0;i<n;i++){
            if(!head){
                head=new ListNode(arr[i]);
                curr=head;
            }
            else{
                ListNode* temp=new ListNode(arr[i]);
                curr->next=temp;
                curr=curr->next;


            }
        }
        return head;
    }
};