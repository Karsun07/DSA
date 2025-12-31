class Solution {
public:
    int bestClosingTime(string customers) {
        int ycount=0;
        int ncount=0;
        int n=customers.size();
        vector<int>penalty(n,0);
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                ycount++;
            }
            else if(customers[i]=='N'){
                penalty[i]+=ycount;
            }
        }
        if(ycount==n) return n;
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                penalty[i]+=ncount;
                ncount++;
            }
        }
        if(ncount==n) return 0;
        int ans=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                if(mini>penalty[i]){
                    mini=penalty[i];
                    ans=i;
                }
            }
        }
        
        if(mini==ncount){
            return ans;
        }
        else if(min(mini,ncount)==ncount) return n;
        return ans;
    }
};