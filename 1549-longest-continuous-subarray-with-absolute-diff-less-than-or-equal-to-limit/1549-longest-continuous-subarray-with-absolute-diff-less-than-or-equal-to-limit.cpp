class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>decq;
        deque<int>incq;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){

            while(!decq.empty() && nums[right]>decq.back()){
                decq.pop_back();
            }
            decq.push_back(nums[right]);
            while(!incq.empty() && nums[right]<incq.back()){
                incq.pop_back();
            }
            incq.push_back(nums[right]);
            if(decq.front() - incq.front()>limit){
                if(nums[left]==decq.front()) decq.pop_front();
                if(nums[left]==incq.front())  incq.pop_front();
                left++;
            }
            ans=max(ans,right-left+1);
            
        }
        return ans;

        
    }
};