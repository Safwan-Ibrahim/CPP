#include<bits/stdc++.h>
using namespace std;

const int N = 305, mod = 1e9 + 7;
using ll = long long;

int n, dp[N][N][N], a[N];
int yo(int i, int mx, int mx2) {
  if (i == n + 1) return 1;
  int &ret = dp[i][mx][mx2];
  if (ret != -1) return ret;
  ret = yo(i + 1, mx, mx2);
  if (mx2 <= a[i]) {
    int nxt_mx = max(mx, a[i]);
    int nxt_mx2 = mx2;
    if (mx > a[i]) nxt_mx2 = max(nxt_mx2, a[i]);
    ret += yo(i + 1, nxt_mx, nxt_mx2);
    if (ret >= mod) ret -= mod;
  }
  return ret;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << yo(1, 0, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}