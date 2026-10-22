class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool fun(int i, int open, string& s) {

        // Too many ')' encountered
        if (open < 0)
            return false;

        // End of string
        if (i == n)
            return open == 0;

        // Already calculated
        if (dp[i][open] != -1)
            return dp[i][open];

        bool ans = false;

        if (s[i] == '(') {

            // '(' increases unmatched opening brackets
            ans = fun(i + 1, open + 1, s);

        }
        else if (s[i] == ')') {

            // ')' needs an unmatched '('
            if (open > 0)
                ans = fun(i + 1, open - 1, s);

        }
        else { // '*'

            // '*' -> '('
            if (fun(i + 1, open + 1, s))
                ans = true;

            // '*' -> ')'
            else if (open > 0 && fun(i + 1, open - 1, s))
                ans = true;

            // '*' -> empty
            else if (fun(i + 1, open, s))
                ans = true;
        }

        return dp[i][open] = ans;
    }

    bool checkValidString(string s) {
        n = s.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return fun(0, 0, s);
    }
};