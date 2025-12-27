#include <bits/stdc++.h>

using namespace std;
#define bool int

int main() {
    int n;
    cin >> n;

    // Sum of elements <= N implies that every element is <= N
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        freq[x]++;
    }

    vector<pair<int, int>> compressed;
    for (int i = 1; i <= n; i++) {
        if (freq[i] > 0) compressed.emplace_back(i, freq[i]);
    }

    vector<bool> dp(n + 1, 0);
    dp[0] = 1;

    for (const auto &[w, k] : compressed) {
        vector<bool> ndp = dp;

        for (int p = 0; p < w; p++) {
            int sum = 0;

            for (int multiple = p, count = 0; multiple <= n; multiple += w, count++) {
                if (count > k) {
                    sum -= dp[multiple - w * count];
                    count--;
                }
                
                if (sum > 0) ndp[multiple] = 1;
                sum += dp[multiple];
            }
        }

        swap(dp, ndp);
    }

    cout << "Possible subset sums are:\n";
    for (int i = 0; i <= n; i++) {
        if (dp[i] > 0) cout << i << " ";
    }
}