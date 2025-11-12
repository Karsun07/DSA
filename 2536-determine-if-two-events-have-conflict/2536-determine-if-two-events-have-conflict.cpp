class Solution {
public:
    int fun(string s){
        string x="";
        for(int i=0;i<5;i++){
            if(s[i]==':'){
                continue;
            }
            x+=s[i];
         }
         return stoi(x);
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
         string s1=event1[0],e1=event1[1];
         string s2=event2[0],e2=event2[1];
         int x1=fun(s1);
         int x2=fun(e1);
         int x3=fun(s2);
         int x4=fun(e2);
         vector<vector<int>>arr;
         arr.push_back({x1,x2});

         arr.push_back({x3,x4});
         sort(arr.begin(),arr.end());
         if(arr[0][1]>=arr[1][0]){
            return true;
         }
         return false;
         
         

         




    }
};