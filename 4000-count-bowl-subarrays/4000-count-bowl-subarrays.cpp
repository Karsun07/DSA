class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngr(n, -1), pgr(n, -1);
        vector<int> st(n);
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[i] > nums[st.back()]) {
                ngr[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] > nums[st.back()]) {
                pgr[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            if (ngr[i]!= -1 && ngr[i]- i >= 2){
                ans++;
            }
            if (pgr[i] != -1 && i- pgr[i] >= 2) {
                ans++;
            }
        }
        return ans;
    }
};