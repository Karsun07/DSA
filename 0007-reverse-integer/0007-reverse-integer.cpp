class Solution {
public:
    int reverse(int x) {
        long long z = llabs((long long)x);  
        string y = to_string(z);
        std::reverse(y.begin(), y.end());

        int n = y.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = y[i] - '0';
        }

        long long ans = 0;                
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = ans + arr[i] * (long long)pow(10, j);
            j++;
        }

        if (x < 0) ans = -ans;

        if (ans > INT_MAX || ans < INT_MIN) return 0;  // FIX 3
        return (int)ans;
    }
};
