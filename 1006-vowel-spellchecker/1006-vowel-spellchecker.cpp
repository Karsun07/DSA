class Solution {
public:
    string to_lower(string s){
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
        }
        return s;
    }
    string devowel(string s){
    for(int i=0;i<s.size();i++){
        s[i] = tolower(s[i]); 
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            s[i]='*';
        }
    }
    return s;
}

    vector<string> spellchecker(vector<string>& word, vector<string>& que) {
        int n=word.size();
        int m=que.size();
        unordered_set<string>se;
        unordered_map<string,string>m1,m2;

        for(int i=0;i<n;i++){
            se.insert(word[i]);

            string low=to_lower(word[i]);
            string vowstar=devowel(word[i]);

            if(!m1.count(low)) m1[low]=word[i];
            if(!m2.count(vowstar)) m2[vowstar]=word[i];
        }
        vector<string>ans;
        for(int i=0;i<m;i++){
            string x=que[i];
            //exact found
            if(se.count(x)) ans.push_back(x);
            else{
                string low=to_lower(x);
                string vowstar=devowel(x);
                if(m1.count(low)) ans.push_back(m1[low]);
                else if(m2.count(vowstar)) ans.push_back(m2[vowstar]);
                else{
                    ans.push_back("");
                }
            }
        }
        return ans;
        
       
    }
};
