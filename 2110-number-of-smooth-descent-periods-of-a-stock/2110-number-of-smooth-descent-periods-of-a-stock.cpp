class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size() ;
        long long ans = 0 ;
        int i=0 ;
        int j=0 ;
        while(j<n){
                if(j!=0 && prices[j] + 1 != prices[j-1]) i=j ;
                ans += j-i+1 ;
                j++ ;
        }
        return ans ;
    }
};