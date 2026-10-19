class Solution {
public:
    typedef long long ll;

    ll MOD = 1e9 + 7;
    vector<vector<ll>> PT;

    ll fun(vector<int>& nums) {
        if(nums.size() < 3)
            return 1;

        vector<int> leftarr, rightarr;

        int root = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < root)
                leftarr.push_back(nums[i]);
            else
                rightarr.push_back(nums[i]);
        }

        ll x = fun(leftarr) % MOD;
        ll y = fun(rightarr) % MOD;

        ll z = PT[nums.size() - 1][leftarr.size()];

        return (((x * y) % MOD) * z) % MOD;
    }

    int numOfWays(vector<int>& nums) {

        int n = nums.size();

 
        PT.resize(n + 1);

        for(int i = 0; i <= n; i++) {

            PT[i] = vector<ll>(i + 1, 1);

            for(int j = 1; j < i; j++) {
                PT[i][j] =
                    (PT[i - 1][j - 1] + PT[i - 1][j]) % MOD;
            }
        }

        return (fun(nums) - 1) % MOD;
    }
};