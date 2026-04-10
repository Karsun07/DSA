class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0,pro=0;
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,prices[i+1]);
            pro=max(pro,maxi-prices[i]);
        }
        return pro;
    }
};