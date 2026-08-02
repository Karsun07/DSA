class Solution {
public:
    int maximumWidth(vector<int>& v) {
        map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]++;
        }
        vector<pair<int,int>>arr(mp.begin(),mp.end());
        for(int i=0;i<arr.size()-1;i++){
            auto [e1,f1]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                auto [e2,f2]=arr[j];
                mp[e1+e2]+=min(f1,f2);
            }
        mp[e1*2]+=f1/2;
        }
        int ans=1;
        for(auto &it:mp){
            ans=max(ans,it.second);
        }
        return ans;


    }
};