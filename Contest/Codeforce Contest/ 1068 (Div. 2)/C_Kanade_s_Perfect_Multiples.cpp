// Created on: 2025-12-05 21:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

template<typename T>
void debug(const string &nm, T &&v, int f = -1) {
    if (f == -1) cerr << nm << " = " << v << "\n";
    else {
        string vn = nm.substr(0, nm.size() - 3);
        cerr << vn << "[" << f << "] = " << v << "\n";
    }
}

#define db(x) debug(#x, x)
#define ds(x, i) debug(#x, x, i)

void Try() {
    int n, k; cin >> n >> k;

    set<int> Done, Ans, St;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        St.insert(x);
    }
    
    vector<int> A = {St.begin(), St.end()};
    int ans = 0;

    for (int i = 0; i < A.size(); i++) {

        ds(A[i], i);
        int cnt = 0;
        for (int j = A[i]; j <= k; j += A[i]) {
            if (!St.count(j)) {
                cout << -1 << endl; return;
            }
            if (!Done.count(j)) {
                cnt = 1;
                Done.insert(j);
            }
        }

        db(cnt);
        if (cnt) {
            ans++;
            Ans.insert(A[i]);
        }
    }
    
    cout << ans << endl;
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;

    cerr << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 