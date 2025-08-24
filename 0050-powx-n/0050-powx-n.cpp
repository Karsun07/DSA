class Solution {
public:
    double pow(double x, long long n) {
        if(n==0){
            return 1;
        }
        if (n % 2 == 0) {
            double root = pow(x, n / 2);
            return root * root;
        }
        return x * pow(x, n - 1);
    }
    
    double myPow(double x, long long n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            x = 1/x;
            n = -n;
        }
        return pow(x, n);
    }
};