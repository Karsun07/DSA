class Solution {
public:
    int winner(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int m = winner(n - 1, k);
        return (m + k) % n;
    }

    int findTheWinner(int n, int k) {
        return winner(n, k) + 1;  
    }
};
