class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return 0;
        bool vow=0,cons=0;
        for(int i=0;i<n;i++){
            if(word[i]=='@'||word[i]=='#'||word[i]=='$') return 0;
            else if(word[i]=='1'||word[i]=='2'||word[i]=='3'||word[i]=='4'||word[i]=='5'||word[i]=='6'||word[i]=='7'||word[i]=='8'||word[i]=='9') continue;
           else if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U') vow=1;
           else cons=1;
            

        }
        if(vow&&cons) return 1;
        return 0;
    }
};