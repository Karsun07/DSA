class Solution {
public:
    int fun(string &s,int i){
        if(i==s.size()){
            return stoi(s);
        }
        if(s[i]=='6'){
            s[i]='9';
            return stoi(s);
        }
         return fun(s,i+1);
    }
    int maximum69Number (int num) {
      string s=to_string(num);
      return fun(s,0);
      

    }
};