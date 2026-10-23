class Solution {
public:
    static bool cmp(int &a,int &b){       
        long long s1=0,s2=0;
        int x=a,y=b;
        while(x){
            s1+=x%10;
            x=x/10;
        }
        while(y){
            s2+=y%10;
            y=y/10;
        }
        if(s1==s2) return a<b;
        return s1<s2;
    }
    int minSwaps(vector<int>& nums) {
        auto temp=nums;
        sort(temp.begin(),temp.end(),cmp);
        if(temp==nums) return 0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=temp[i]){
                int pos=mp[temp[i]];
                mp[nums[i]]=pos;
                ans++;
                swap(nums[i],nums[pos]);
            }
        }
        return ans;

    }
};