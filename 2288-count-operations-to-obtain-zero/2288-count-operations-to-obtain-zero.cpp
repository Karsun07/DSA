class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1==0 || num2==0) return 0;
        int ans=1;
        while(num1!=num2){
            if(num1>num2) num1=num1-num2;
            else if(num1<num2) num2=num2-num1;
            ans++;
        }
        return ans;
    }
};