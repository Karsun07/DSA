class Solution {
public:
    static bool cmp(const pair<string, string>& a,
                const pair<string, string>& b) {
    unordered_map<string, int> mp;
    mp["electronics"] = 1;
    mp["grocery"] = 2;
    mp["pharmacy"] = 3;
    mp["restaurant"] = 4;

    
    if (mp[a.second] != mp[b.second]) {
        return mp[a.second] < mp[b.second];
    }

  
    return a.first < b.first;
}

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>temp;
        vector<string>ans;
        unordered_map<string,int>mp;
        mp["electronics"]=1;
        mp["grocery"]=2;
        mp["pharmacy"]=3;
        mp["restaurant"]=4;
        for(int i=0;i<isActive.size();i++){
            if(isActive[i]){
                string s=code[i];
                int size=s.size();
                if(size==0) continue;
                bool flag=1;
                for(int j=0;j<size;j++){
                    if(!isalnum(s[j]) && s[j]!='_'){
                        flag=0;
                        break;
                    }
                }
                if(flag && businessLine[i]!="invalid"){
                    temp.push_back({s,businessLine[i]});
                }
            }
        }
        sort(temp.begin(),temp.end(),cmp);
        for(auto &it:temp){
            ans.push_back(it.first);
        }
        return ans;
    }
};