class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        for(int i=0;i<fl.size();i++){
            if(fl[i]==0){
                bool leftempty= (i==0||fl[i-1]==0);
                bool rightempty=(i==fl.size()-1||fl[i+1]==0); 
                if(leftempty&&rightempty){
                fl[i]=1;
                n--;
                if(n==0) return true;
            }
            }      
        }
       return n <= 0;
    }
};