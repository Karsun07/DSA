class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();   
        int l=0,r=n-1,leftmax=0,rightmax=0;
        int ans=0;
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(leftmax>arr[l]){
                    ans+=leftmax-arr[l];
                }
                else leftmax=arr[l];
                l++;
            }
            else{
                if(rightmax>arr[r]){
                    ans+=rightmax-arr[r];
                }
                else rightmax=arr[r];
                r--;
            }
        }
        return ans;
    }
};