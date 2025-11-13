class Solution {
public:
    int minOperations(vector<int>& nums) {
        int arr[100002] = {0};
        int ans = 0, t = 1;
        for(int i = 0; i < nums.size(); i++){
            while(t > 0 && arr[t-1] > nums[i]) t--;
            if( arr[t-1] < nums[i]){
                arr[t] = nums[i];
                t++;
                ans++;
            }
        }
        return ans;
    }
};