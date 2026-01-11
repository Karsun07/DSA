class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
     int ans=0;
     int n=nums.size();
     for(int i=0;i<n;i++){
         int sum=0;
         unordered_set<int>s;
         for(int j=i;j<n;j++){
            sum+=nums[j];
            s.insert(nums[j]);
            if(s.count(sum)) ans++;
         }
         }
     
      return ans;
}

};