// Created on: 2025-06-08 20:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int cnt = 1;
    set<int>St, Tmp, Sec;
    St.insert(A[1]);
    for (int i = 2; i <= n; i++) {
        Tmp.insert(A[i]);
        if (St.find(A[i]) != St.end()) {
            Sec.insert(A[i]);
        }
        if (St.size() == Sec.size()) {
            cnt++;
            St = Tmp;
            Tmp.clear();
            Sec.clear();
        }
    }

    cout << cnt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 