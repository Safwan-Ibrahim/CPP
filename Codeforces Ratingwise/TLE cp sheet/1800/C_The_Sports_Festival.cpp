// Created on: 2025-11-16 13:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2000 + 17;
int n, A[nn]; 
ll Ans[nn][nn];

ll min_cost(int i, int l, int r) {
    if (!i) return i;

    ll &ans = Ans[i][l];
    if (ans != -1) return ans;

    ans = A[r] - A[l] + min_cost(i - 1, l + 1, r);
    ans = min(ans, A[r] - A[l] + min_cost(i - 1, l, r - 1));

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1);
    memset(Ans, -1, sizeof Ans);

    cout << min_cost(n, 1, n) << endl;
    return 0;
} 
