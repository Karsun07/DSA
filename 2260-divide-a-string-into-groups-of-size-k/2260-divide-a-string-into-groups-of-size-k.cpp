class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;i+=k){
            string part=s.substr(i,k);
            while(part.size()<k){
                part.push_back(fill);
            }
            ans.push_back(part);
        }
        return ans;

    }
};