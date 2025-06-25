// Created on: 2025-05-19 00:33
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool cmp(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    pair<int, int> A[n + 3], St[n + 3];
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
        St[i] = A[i];
    }

    sort(A + 1, A + n + 1, cmp);
    pair<int, int> a = {-1, -1}, b = {-1, -1};
    multiset<pair<int, int>>S;
    for (int i = 1; i <= n; i++) {
        auto it = S.lower_bound({A[i].first, -1});
        if (it != S.end()) {
            a = *it;
            b = A[i]; 
            break;
        }
        S.insert(A[i]);
    }

    if (a.first == a.second && a.first == -1) {
        cout << -1 << " " << -1 << endl; return 0;
    }

    int ans1 = -1, ans2 = -1;
    for (int i = 1; i <= n; i++) {
        if (ans1 == -1 && St[i] == a) {
            ans1 = i;
        }
        else if (ans2 == -1 && St[i] == b) {
            ans2 = i;
        }
    }

    cout << ans1 << " " << ans2 << endl;
    
    return 0;
} 