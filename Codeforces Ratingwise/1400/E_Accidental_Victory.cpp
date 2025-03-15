// Created on: 2025-02-26 18:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
pair<int, int> A[N];
ll Ps[N]; // rem to clear

void Try() {
    int n; cin >> n; // rem n == 1
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A + 1, A + n + 1);

    A[n + 1].first = 0;
    for (int i = 1; i <= n; i++) {
        Ps[i] = A[i].first + Ps[i - 1];
    }   

    vector<bool>Ans(n + 1, false);
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (Ps[i] >= A[i + 1].first) {
            Ans[A[i].second] = true;
            cnt++;
        }
        else {
            break;
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (Ans[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    memset(Ps, 0, (n + 2) * 4);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 