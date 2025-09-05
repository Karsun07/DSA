class Solution {
public:
    void Heapify(vector<int>&nums,int i,int n){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[left]>nums[largest]) largest=left;
        if(right<n && nums[right]>nums[largest]) largest=right;
        if(largest!=i){
            swap(nums[largest],nums[i]);
            Heapify(nums,largest,n);
        }
    }
    void maxheap(vector<int>&nums,int n){
        for(int  i=n/2-1;i>=0;i--){
            Heapify(nums,i,n);
        }
    }
    void sortheap(vector<int>&nums,int i,int n,int k){
        maxheap(nums,n);
        
        while(k--){
            swap(nums[0],nums[n-1]);
            n--;
            Heapify(nums,0, n);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        sortheap(nums,0,n,k);
        return nums[n-k];
    }
};
