// Created on: 2025-12-05 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn], B[nn];

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
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    ll kmn = min(0 - A[1], B[1] - 0); 
    ll kmx = max(0 - A[1], B[1] - 0); 

    db(kmn); db(kmx);
    for (int i = 2; i <= n; i++) {
        ll tkmx = kmx, tkmn = kmn;
        tkmn = min({kmn - A[i], B[i] - kmn, kmx - A[i], B[i] - kmx});
        tkmx = max({kmn - A[i], B[i] - kmn, kmx - A[i], B[i] - kmx});
        kmx = tkmx, kmn = tkmn;
        db(kmx);db(kmn);ds(A[i], i);ds(B[i], i);
        cerr << endl;
    }
    
    cout << kmx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; 
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 