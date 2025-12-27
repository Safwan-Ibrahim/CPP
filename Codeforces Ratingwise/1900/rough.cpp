#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 5;
vector<int> ad[mxN];
int a[mxN], b[mxN];
long long dp[mxN][2], sz[mxN], ans[mxN];
void add(int u, int v) {
  sz[u] += sz[v];
  dp[u][b[u] ^ 1] += sz[v];
  for (int i : {0, 1}) {
    if (b[u] == i) dp[u][i] += dp[v][i];
    else dp[u][i] += dp[v][i ^ 1];
  }
}
void del(int u, int v) {
  sz[u] -= sz[v];
  dp[u][b[u] ^ 1] -= sz[v];
  for (int i : {0, 1}) {
    if (b[u] == i) dp[u][i] -= dp[v][i];
    else dp[u][i] -= dp[v][i ^ 1];
  }
}
void dfs(int u, int p) {
  dp[u][0] = dp[u][1] = 0;
  sz[u] = 1;
  dp[u][b[u] ^ 1]++;
  for (int v : ad[u]) {
    if (v == p) continue;
    dfs(v, u);
    add(u, v);
  }
}
void dfs1(int u, int p) {
  ans[u] = min(dp[u][0], dp[u][1]);
  for (int v : ad[u]) {
    if (v == p) continue;
    del(u, v);
    add(v, u);
    dfs1(v, u);
    del(v, u);
    add(u, v);
  }
}
void testCase() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  vector<long long> out(n + 1);
  for (int bit = 0; bit <= 20; bit++) {
    for (int i = 1; i <= n; i++) b[i] = a[i] >> bit & 1;
    dfs(1, -1);
    dfs1(1, -1);
    for (int i = 1; i <= n; i++) {
      out[i] += (1LL << bit) * ans[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << out[i] << " ";
    ad[i].clear();
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
  return 0;
}