class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1) return stones[0];

        priority_queue<int>p;
        for(int i=0;i<n;i++) p.push(stones[i]);

        while(p.size()>1){
            int first = p.top(); p.pop();
            int second = p.top(); p.pop();
            if (first != second) {
                p.push(first - second);
            }
        }
        return p.empty()?0:p.top();

    }
};