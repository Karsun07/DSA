class Solution {
public:
    int maximum69Number (int num) {
        vector<int>ans(5,0);
        int divide=10000;
        for(int i=0;i<5;i++){
            ans[i]=num/divide;
            num=num%divide;
            divide=divide/10;
        }
        for(int i=0;i<5;i++){
            if(ans[i]==6){
                ans[i]=9;
                break;
            }
        }
        int sum=0;
        divide=10000;
        for(int i=0;i<5;i++){
            sum+=ans[i]*divide;
            divide/=10;

        }
        return sum;

    }
};