class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string,int> mp;
        int n=s.size();
        for (string & word : words) mp[word]++;
        
        
        int win=words[0].size();
        
        vector<int>ans;
        

        for(int start=0;start<win;start++){

            int l=start,r=start;
            int count=0;
            unordered_map<string,int>mp1;

            while(r<=n-win){
                string x=s.substr(r,win);
                r+=win;

                if(mp.find(x)==mp.end()){
                    count=0;
                    l=r;
                    mp1.clear();
                }
                else{
                    mp1[x]++;
                    count++;
                    
                    while(mp1[x]>mp[x]){
                        mp1[s.substr(l,win)]--;
                        
                        l+=win;

                        count--;
                    }
                    if(count==words.size()){
                       
                        ans.push_back(l);
                        mp1[s.substr(l,win)]--;
                        if(mp1[s.substr(l,win)]==0) mp1.erase(s.substr(l,win));
                        l+=win;
                        count--;
                    }
                    
                }
        }

        }
        return ans;

        

   
    }
};