// Created on: 2025-11-06 22:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17, inf = 1e6 + 1;
vector<int> L[30], A, B;
char S[nn], T[nn];
int n, k;

int min_op(int i, int mn) {
    if (i == 1) return 0;

    int ans = inf;
    int need = T[i] - 'a';
    int s = L[need].size();

    int lo = 0, hi = s - 1, p = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (L[need][mid] <= mn) {
            p = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    if (p != -1 && p < s && i - L[need][p] <= k) {
        A.push_back(i);
        B.push_back(L[need][p]);
        ans = max(i - L[need][p], min_op(i - 1, min(i - 1, L[need][p])));
    }

    return ans;
}

void res() {
    for (int i = 0; i <= 27; i++) {
        L[i].clear();
    }
    A.clear(); B.clear();
}

void Try() {
    res();

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }

    for (int i = n; i >= 1; i--) {
        L[S[i] - 'a'].push_back(i);
    }

    if (S[1] != T[1]) {
        cout << -1 << endl; return;
    }

    int mn = min_op(n, n);
    if (mn > k) {
        cout << -1 << endl; return;
    }

    cout << mn << endl;
    for (int i = 1; i <= mn; i++) {
        for (int j = 0; j < A.size(); j++) {
            if (B[j] < A[j]) {
                S[B[j] + 1] = S[B[j]];
                B[j]++;
            }
        }
        for (int j = 1; j <= n; j++) {
            cout << S[j];
        }
        cout << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 