class Solution {
public:

    int solve(int i, int sum,
              vector<int>& primes,
              vector<vector<int>>& dp) {

        if (sum == 0) return 0;

        if (i == primes.size() || sum < 0)
            return 1e9;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        // Don't take
        int notTake = solve(i + 1, sum, primes, dp);

        // Take
        int take = 1 + solve(i + 1, sum - primes[i], primes, dp);

        return dp[i][sum] = min(take, notTake);
    }

    vector<int> maxPrimeSubset(int n, int s) {

        if (s == 1) return {};

        // Sieve
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }

        int m = primes.size();

        vector<vector<int>> dp(
            m + 1,
            vector<int>(s + 1, -1)
        );

        int maxiSum = s;

        while (maxiSum >= 2 &&
               solve(0, maxiSum, primes, dp) == 1e9) {
            maxiSum--;
        }

        vector<int> ans;
        int sum = maxiSum;

        // Reconstruction
        for (int i = 0; i < m && sum > 0; i++) {

            int take = 1 + solve(i + 1,
                                 sum - primes[i],
                                 primes,
                                 dp);

            int notTake = solve(i + 1,
                                sum,
                                primes,
                                dp);

            if (take <= notTake) {
                ans.push_back(primes[i]);
                sum -= primes[i];
            }
        }

        return ans;
    }
};