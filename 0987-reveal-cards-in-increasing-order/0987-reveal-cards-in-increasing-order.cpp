class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> ans(n, 0);
        for(int i = 0 ; i < n; i++){
            q.push(i);
        }
        for(int c : deck){
            ans[q.front()] = c;
            q.pop();
            if(q.empty()){
                return ans;
            }
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};