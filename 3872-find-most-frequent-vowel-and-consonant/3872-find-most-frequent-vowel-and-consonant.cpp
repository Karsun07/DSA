class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>vow(26,0);
        vector<int>cons(26,0);
        int max1=0,max2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vow[s[i]-'a']++;
                max1=max(max1,vow[s[i]-'a']);
            }
            else{
                cons[s[i]-'a']++;
                max2=max(max2,cons[s[i]-'a']);
            }
        }
        return max1+max2;
    }
};