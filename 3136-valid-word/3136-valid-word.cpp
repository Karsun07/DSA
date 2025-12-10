class Solution {
public:
    bool isvow(char c){
        char x=tolower(c);
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return 1;
        return 0;
    }
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return 0;
        bool vow=0,cons=0;
        for(int i=0;i<n;i++){
            if(!isalpha(word[i]) && !isdigit(word[i])) return 0;
            if(isalpha(word[i])){
                if(isvow(word[i])) vow=1;
                else cons=1;
            }
           
        }
        if(vow && cons) return 1;
        return 0;
        
    }
};