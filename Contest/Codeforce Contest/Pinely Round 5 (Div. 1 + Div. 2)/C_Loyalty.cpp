// Created on: 2025-10-30 23:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, x, A[nn];

void Try() {
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1);

    vector<int> Ans;
    ll ans = 0, cur = 0;
    for (int i = 1, j = n; i <= j;) {
        if (A[j] + cur >= x) {
            ans += A[j];
            Ans.push_back(A[j]);
            cur = (cur + A[j]) % x;
            j--;
        }
        else {
            Ans.push_back(A[i]);
            cur += A[i];
            i++;
        }
    }

    cout << ans << endl;
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