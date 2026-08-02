class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long>pref(n,0);
        for(auto &it:boosts){
            int i=it[0],j=it[1],b=it[2];
            pref[i]+=b;
            if(j+1<n) pref[j+1]-=b;
        }
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        long long prevEnergy=0,ans=0;
        for(int i=0;i<n;i++){
            if(pref[i]<monsters[i]){
                ans=max(ans,monsters[i]-pref[i]+prevEnergy);
            }
            prevEnergy+=monsters[i];
        }
        return ans;

    }
};