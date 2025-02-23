// Created on: 2025-02-18 14:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int A[N], H[N];

void Try() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }
    
    vector<vector<int>>B;
    vector<int>T{A[1]};

    for (int i = 1; i + 1 <= n; i++) {
        if (H[i] % H[i + 1] != 0) {
            B.push_back(T);
            T.clear();
        }
        T.push_back(A[i + 1]);
    }
    B.push_back(T);

    int mx = 0;
    for (auto x : B) {
        int ans = 0, r = 0, sum = 0;
        for (int l = 0; l < x.size(); l++) {
            while(r < x.size() && sum + x[r] <= k) {
                sum += x[r];
                r++;
            }
            ans = max(ans, r - l);
            sum -= x[l];
        }
        mx = max(ans, mx);
    }

    cout << mx << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 