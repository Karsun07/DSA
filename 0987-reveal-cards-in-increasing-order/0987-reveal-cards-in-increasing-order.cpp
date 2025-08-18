class Solution {
public:
    void fun(vector<int>deck,int i,queue<int>&q,vector<int>&ans){
        if(q.empty()|| i==deck.size()) return;
        ans[q.front()]=deck[i];
        q.pop();
        q.push(q.front());
        q.pop();
        fun(deck,i+1,q,ans);

    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            q.push(i);
        }
        fun(deck,0,q,ans);
        return ans;
    }
};