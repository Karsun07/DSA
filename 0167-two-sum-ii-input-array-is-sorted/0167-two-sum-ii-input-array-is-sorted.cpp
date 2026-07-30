class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
       for(int i=0;i<n-1;i++){
            int t=target-numbers[i];
            int start=i+1;
            int end=n-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(numbers[mid]==t) return {i+1,mid+1};
                if(numbers[mid]>t){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
       }
       return {};

    }
};