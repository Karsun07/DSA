class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();

        long long sum = 0;   
        long long temp = LLONG_MIN;

        while (r < n) {
            sum += nums[r];     
            r++;

            if (r - l == k) {   
                temp = max(temp, sum);  
                sum -= nums[l];        
                l++;
            }
        }

        return (double)temp / k;
    }
};
