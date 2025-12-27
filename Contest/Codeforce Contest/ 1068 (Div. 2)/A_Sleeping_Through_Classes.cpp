// Created on: 2025-12-05 20:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

template<typename T>
void debug(const string &nm, T &&v, int f = -1) {
    if (f == -1) cerr << nm << " = " << v << "\n";
    else {
        int id = 0;
        while (id < nm.size() && nm[id] != '[') cerr << nm[id++];
        cerr << "[" << f << "] = " << v << "\n";
    }
}

#define db(x) debug(#x, x)
#define ds(x, i) debug(#x, x, i)

void Try() {
    int n, k; cin >> n >> k;

    string S; cin >> S;
    int ans = 0;
    int cant = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == '1') {
            cant = k;
        }
        else {
            if (cant) cant--;
            else ans++;
        }
        db(cant);
        ds(S[i], i);
    }
    
    cerr << endl;
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