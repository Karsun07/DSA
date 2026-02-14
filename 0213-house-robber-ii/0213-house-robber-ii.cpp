class Solution {
public:
    int houserob(vector<int>& arr){
        int prev = arr[0];
        int prev2 = 0;

        for(int i = 1; i < arr.size(); i++){
            int take = arr[i];
            if(i > 1) take += prev2;

            int nottake = prev;
            int curr = max(nottake, take);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0]; 

        vector<int> robfirst(n-1);
        vector<int> roblast(n-1);

        for(int i = 0; i < n-1; i++){
            robfirst[i] = nums[i];
            roblast[i] = nums[i+1];
        }

        int rob1 = houserob(robfirst);
        int rob2 = houserob(roblast);

        return max(rob1, rob2);
    }
};
