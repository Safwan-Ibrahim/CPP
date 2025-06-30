#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;
int a[N];
int F(int n) { // 1 + 2 + ... + n
    return (1LL * n * (n + 1) / 2) % mod;
}
int S(int l, int r) { // l + (l + 1) + ... + r
    return (F(r) - F(l - 1) + mod) % mod;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += a[j];
            ans += sum * (j - i + 1);
        }
    }
    cout << ans << endl;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        int contrib = (1LL * S(i, n) * i % mod - 1LL * (n - i + 1) * S(1, i) % mod + mod) % mod;
        contrib = (contrib + 1LL * (n - i + 1) * i % mod) % mod;
        ans += 1LL * a[i] * contrib % mod;
        ans %= mod;
    }
    cout << ans << '\n';
    ans = 0;
    for (int i = 1; i <= n; i++) {
        int con = S(i, n) * i - S(0, i - 1) * (n - i + 1);
        ans += con * a[i];
    }
    cout << ans << endl;

    return 0;
}