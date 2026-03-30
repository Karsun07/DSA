class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i = n1-1; i >= 0; i--) {
        for(int j = n2-1; j >= 0; j--) {
            if(str1[i] == str2[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    int i = 0, j = 0;
    string ans = "";
    while(i < n1 && j < n2) {
        if(str1[i] == str2[j]) {
            ans += str1[i];
            i++;
            j++;
        }
        else if(dp[i+1][j] > dp[i][j+1]) {
            ans += str1[i];
            i++;
        }
        else {
            ans += str2[j];
            j++;
        }
    }
    while(i < n1) ans += str1[i++];
    while(j < n2) ans += str2[j++];
    return ans;
}
};