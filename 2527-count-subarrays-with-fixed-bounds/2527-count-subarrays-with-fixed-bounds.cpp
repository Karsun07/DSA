class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long count = 0, left = 0;
            deque<int> incq,decq;
           
    
            for (int  right= 0; right < nums.size(); right++) {
                if (nums[right] < minK || nums[right] > maxK) {
                    incq.clear();
                    decq.clear();
                    left = right + 1;
                    continue;
                }
    
                while (!incq.empty() && nums[incq.back()] >= nums[right]) incq.pop_back();
                incq.push_back(right);
    
                while (!decq.empty() && nums[decq.back()] <= nums[right]) decq.pop_back();
                decq.push_back(right);
    
                if (nums[incq.front()] == minK && nums[decq.front()] == maxK) {
                    int start = min(incq.front(), decq.front());
                    // left se aage minK aur max k ke bich ki values hai
                // start wo point hai jaha pe hame dono mink aur maxk ek subarray me mil gaye as minimum and maximum respectively
                    count += (start - left + 1);
                }
            }
            return count;
        }
    };
     