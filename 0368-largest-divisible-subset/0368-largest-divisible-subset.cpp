class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        vector<int> arr(n, 1);     
        vector<int> hash(n, -1); 
        int idx = 0;
        int maxilen = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && arr[j] + 1 > arr[i]){   
                        arr[i] = arr[j] + 1;
                        hash[i] = j;
                }
            }
            if(arr[i] > maxilen){  
                maxilen = arr[i];
                idx = i;
            }
        }
        vector<int> ans;
        int i = idx;
        while(i != -1){
            ans.push_back(nums[i]);
            i = hash[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;



        
    }
};