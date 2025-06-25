// Created on: 2025-05-10 16:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 8;
int n, A[nn];

void Try() {
    cin >> n;
    vector<int> A[n + 3];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[x].push_back(i);
    }

    vector<int>Ans(n + 3, -1);
    int pt = n;
    for (int i = 1; i <= n; i++) {
        int mx = -1;
        int sz = A[i].size();
        for (int j = 0; j < sz; j++) {
            if (j == 0) {
                mx = max(mx, A[i][j]);
            }
            else {
                mx = max(mx, A[i][j] - A[i][j - 1]);
            }
            if (j == sz - 1) {
                mx = max(mx, n - A[i][j] + 1);
            }
        }
        if (mx != -1 && mx <= pt && pt > 0) {
            do {
                Ans[pt] = i;
                pt--;
            }
            while(pt >= mx);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 