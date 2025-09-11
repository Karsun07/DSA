class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(k>n) return -1;
        priority_queue<int>p;
        for(int i=0;i<n;i++){
            p.push(nums[i]);
        }
        k--;
        while(k--){
            p.pop();
        }
        return p.top();

    }
};
