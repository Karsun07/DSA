class Solution {
public:
    int n;
    bool isPalindrome(int start,int end,string &s){
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void fun(int start,vector<string>&temp,vector<vector<string>>&ans,string &s){
        if(start>=n){
            ans.push_back(temp);
        }
        for(int end=start;end<n;end++){
            if(isPalindrome(start,end,s)){
                temp.push_back(s.substr(start,end-start+1));
                fun(end+1,temp,ans,s);
                temp.pop_back();
            }
        }

        

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        n=s.size();
        fun(0,temp,ans,s); 
        return ans;
        
    }
};