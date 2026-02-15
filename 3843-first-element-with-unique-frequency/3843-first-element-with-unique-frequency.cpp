class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        unordered_map<int,int> freq;
        unordered_map<int,int> freqCount;
        for(int x : nums){
            freq[x]++;
        } 
        for(auto &it : freq){
            freqCount[it.second]++;
        }
        for(int x : nums){
            if(freqCount[freq[x]] == 1){
                return x;
            }
        }

        return -1;
    }
};
