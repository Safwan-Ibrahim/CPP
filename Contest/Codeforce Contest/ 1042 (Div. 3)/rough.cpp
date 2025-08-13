/**
 *    author:  tourist
 *    created: 10.08.2025 07:38:14
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= k;
      a[i] = max(a[i], k - a[i]);
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      b[i] %= k;
      b[i] = max(b[i], k - b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a == b ? "YES" : "NO") << '\n';
  }
  return 0;
}
