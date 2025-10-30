// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, Ans[nn]; 
ll A[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    Ans[1] = 1; int cnt = 2;
    for (int i = 2; i <= n; i++) {
        ll inc = A[i] - A[i - 1];
        assert(0 < inc && inc <= i);
        if (inc == i) {
            Ans[i] = cnt++;
        }
        else Ans[i] = Ans[i - inc];
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