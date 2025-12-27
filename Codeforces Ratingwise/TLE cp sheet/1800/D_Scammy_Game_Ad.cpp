// Created on: 2025-11-28 17:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 33;
int n;
int Ans[nn];
pair<int, int> A[3][nn];
ll S[2][nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 2; k++) {
            char c; cin >> c; int x; cin >> x;
            if (c == '+') {
                A[k][i] = {1, x};
            }
            else {
                A[k][i] = {2, x};
            }
        }
    }
    
    for (int k = 1; k <= 2; k++) {
        ll ans = 1;
        for (int i = n; i >= 1; i--) {
            S[k][i] = ans += (A[k][i].first == 1 ? 1 : A[k][i].second);
        }
    }
    
    for (int i = 2; i <= n; i++) {
        int cv2 = (A[2][i].first == 1 ? 1 : A[2][i].second);
        int cv1 = (A[1][i].first == 1 ? 1 : A[1][i].second);
        if (S[2][i] >= S[1][i]) {
            if (cv1 > cv2 && cv1 - cv2 > S[2][i] - S[1][i]) Ans[i - 1] = 1;
            else Ans[i - 1] = 2;
        } 
        else {
            if (cv2 > cv1 && cv2 - cv1 > S[1][i] - S[2][i]) Ans[i - 1] = 2;
            else Ans[i - 1] = 1;
        }
    }

    ll x = 1, y = 1;
    for (int i = 1; i <= n; i++) {
        ll nx = x;
        if (A[1][i].first == 1) {
            nx += A[1][i].second;
        }
        else nx *= A[1][i].second;
        
        ll ny = y;
        if (A[2][i].first == 1) {
            ny += A[2][i].second;
        }
        else ny *= A[2][i].second;

        ll nw = ny + nx - x - y;
        if (Ans[i] == 1) x += nw;
        else y += nw;
    }

    cout << x + y << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 