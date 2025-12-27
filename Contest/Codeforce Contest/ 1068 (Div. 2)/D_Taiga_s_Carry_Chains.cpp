// Created on: 2025-12-06 20:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 33;
int Ans[20][nn][2], sz;
vector<pair<int, int>> A;

int get_max(int i, int k, bool last) {
    if (i >= sz) return 0;
    if (k == 0) return 0;

    if (Ans[i][k][last] != -1) return Ans[i][k][last];

    int ans = A[i].first - 1 + get_max(i + 1, k - 1, 0) + last;
    if (k >= 1 + (A[i].second - 1)) {
        ans = max(ans, last + A[i].first - 1 + get_max(i + 1, k - (1 + A[i].second - 1), 1));
    }
    ans = max(ans, get_max(i + 1, k, 0));

    return Ans[i][k][last] = ans;
}

void Try() {
    int n, k; cin >> n >> k;
    
    if (k >= 32) {
        cout << __builtin_popcount(n) + k - 1 << endl; return;
    }

    while (n % 2 == 0) n >>= 1; 
    
    vector<int> Tmp; int s = 0, us = 0;
    for (int i = 0; i < 31; i++) {
        if ((n >> i) & 1) {
            if (us) Tmp.push_back(us);
            us = 0;
            s++;
        }
        else {
            if (s) Tmp.push_back(s);
            s = 0;
            us++;
        }
    }

    Tmp.push_back(us);
    A.clear();
    for (int i = 0; i + 1 < Tmp.size(); i += 2) {
        A.push_back({Tmp[i], Tmp[i + 1]});
    }

    sz = A.size();
    memset(Ans, -1, sizeof Ans);
    cout << k + get_max(0, k, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 