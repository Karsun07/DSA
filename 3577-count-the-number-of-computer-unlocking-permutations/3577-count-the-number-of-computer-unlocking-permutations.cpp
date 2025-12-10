class Solution {
public:
    static const long long mod = 1000000007LL;

    long long fact(int n) {
        long long res = 1;
        for (int i = 1; i <= n; i++)
            res = (res * i) % mod;
        return res;
    }

    int countPermutations(vector<int>& comp) {
        int n = comp.size();

       int x=comp[0];
        for (int i = 1; i < n; i++)
            if (comp[i] <= x) return 0;

        long long f = fact(n - 1);   // n! / n = (n-1)!
        return (int)f;
    }
};
