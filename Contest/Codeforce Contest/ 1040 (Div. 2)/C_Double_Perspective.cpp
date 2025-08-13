// Created on: 2025-07-31 21:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    array<int, 3> A[n + 1];
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        A[i] = {a, b, i};
    }
    
    sort(A + 1, A + n + 1);
    set<int>St;
    vector<int>Ans;
    for (int i = 1; i <= n; i++) {
        if (St.count(A[i][1])) {
            continue;
        }
        else {
            St.insert(A[i][1]);
            Ans.push_back(A[i][2]);
        }
    }

    cout << Ans.size() << endl;
    for (auto x : Ans) {
        cout << x << " ";
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