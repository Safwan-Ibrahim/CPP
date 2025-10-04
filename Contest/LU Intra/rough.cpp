#include <bits/stdc++.h>
using namespace std;
int main() {
    string X, Y;
    // prottek pair input nibo
    while (cin >> X >> Y)
    {
        int m = X.size(), n = Y.size();
        // dp[i][j] = length of LCS of first i char of X and first j char of Y
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1; // char same, add 1
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // na hole max of previous
            }
        }
        cout << dp[m][n] << "\n"; // LCS length
    }
}
