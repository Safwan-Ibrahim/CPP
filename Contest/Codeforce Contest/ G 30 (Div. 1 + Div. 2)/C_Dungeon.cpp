// Created on: 2025-11-06 21:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
pair<int, int> B[nn];
int n, m, A[nn];

void Try() {
    cin >> n >> m;

    multiset<int> Ms;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Ms.insert(A[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> B[i].first;
    }

    for (int i = 1; i <= m; i++) {
        cin >> B[i].second;
    }

    sort(A + 1, A + n + 1);
    sort(B + 1, B + m + 1);
    int mx = A[n];

    int ans = 0;
    vector<int> M;
    for (int i = 1; i <= m; i++) {       
        bool need = true;
        if (B[i].second) {
            auto it = Ms.lower_bound(B[i].first);
            if (it != Ms.end()) {
                ans++;
                Ms.insert(max(B[i].second, *it));
                Ms.erase(it);
                need = false;
            }
        }
        if (need) M.push_back(B[i].first);
    }    

    A[n] = mx;

    int i = n;
    for (auto x : Ms) {
        A[i] = x;
        i--;
    }
    sort(M.rbegin(), M.rend());

    int p = 0; m = M.size();
    for (int i = 1; i <= n; i++) {
        while (p < m && M[p] > A[i]) {
            p++;
        }
        if (p < m) {
            p++; ans++;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 