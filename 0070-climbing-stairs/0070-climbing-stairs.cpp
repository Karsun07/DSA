class Solution {
public:
    int climbStairs(int n) {
       if(n<=3) return n;

       int a=2, b=3;
       int next;
       for(int i=3;i<n;i++){
          next=a+b;
          a=b;
          b=next;
       }
       return next;


    }
};