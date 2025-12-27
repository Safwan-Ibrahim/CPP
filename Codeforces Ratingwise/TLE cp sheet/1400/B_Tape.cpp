// Created on: 2025-05-06 05:37
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int A[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }    

    int ans = n;
    vector<int>V;
    for (int i = 1; i + 1 <= n; i++) {
        V.push_back(A[i + 1] - A[i] - 1);
    }

    sort(V.begin(), V.end());
    ans += accumulate(V.begin(), V.begin() + n - k, 0);
    cout << ans << endl;

    return 0;
} 