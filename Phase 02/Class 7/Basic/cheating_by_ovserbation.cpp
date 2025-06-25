#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = max(ans, __gcd(i, j));
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int n = 1; n <= 20; n++) {
        cout << n << ": " << solve(n) << '\n';
    }
    // that means ans is n / 2

    return 0;
}