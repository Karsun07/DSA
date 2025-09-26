class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        freq[0]++; // if k=2,aur hame agar 2 mil gaya iska matlab wo index 0 se shuru hua ,find(sum-k) to 0 milega kyuki ye hame pehle nahi mila ,lekin isko lena chahiye kyuki ye sum req hai isliye ye edge case hai 
        int count = 0, sum = 0;
        
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
            if (freq.find(sum - k) != freq.end()) {
                count += freq[sum - k];
            }
            freq[sum]++;
        }

        return count;
    }
};