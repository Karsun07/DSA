class Solution {
public:
    int countTriples(int n) {
       int count=0;
       for(int i=1;i<=n-2;i++){
        int a=i*i;
        for(int j=i+1;j<=n-1;j++){
            int b=j*j;
            double c = sqrt(a + b);
            if(c <= n && c == (int)c) count += 2;

        }
       }
       return count;



    }
};