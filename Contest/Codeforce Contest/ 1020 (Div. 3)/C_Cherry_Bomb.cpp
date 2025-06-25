// Created on: 2025-04-24 20:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, k;
pair<int, int> A[nn];

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i].first = x;
    }
    
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i].second = x;
    }

    int sum = -1;
    for (int i = 1; i <= n; i++) {
        if (A[i].second != -1) {
            if (sum == -1) {
                sum = A[i].first + A[i].second;
            }
            else {
                if (sum != A[i].first + A[i].second) {
                    cout << 0 << endl; return;
                }
            }
        }
    }
    sort(A + 1, A + n + 1);
    if (sum == -1) {
        int lo = A[n].first - A[1].first;
        cout << max(0, k - lo + 1) << endl; return;
    }

    int mn = A[1].first, mx = A[n].first;
    if (sum - mn >= 0 && sum - mn <= k && sum - mx >= 0 && sum - mx <= k) {
        cout << 1 << endl; 
    }
    else {
        cout << 0 << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 