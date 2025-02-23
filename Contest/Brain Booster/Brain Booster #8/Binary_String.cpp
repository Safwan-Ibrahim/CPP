// Created on: 2025-02-17 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;
    string S; cin >> S;
    vector<int>A;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char x = S[i];
        if (x == '1') {
            cnt++;
        }
        else {
            if (cnt) {
                A.push_back(cnt);
            }
            cnt = 0;
        }
        if (i == n - 1 && cnt) {
            A.push_back(cnt);
        }
    }

    sort(A.rbegin(), A.rend());

    ll sum = 0;
    if (A.size() > 0) {
        sum += A[0];
    } 
    for (int i = 1; i < (int)A.size(); i++) {
        if (k <= 0) {
            break;
        }
        sum += A[i];
        k--;
    }

    cout << sum << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 