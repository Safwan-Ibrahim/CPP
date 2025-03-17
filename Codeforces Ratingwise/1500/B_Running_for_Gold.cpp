// Created on: 2025-03-17 03:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 5e4 + 8;
int A[6][N];

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> A[j][i];
        }
    }
    
    int a = 1, b = 2; 
    int nxt = 2;  
    for (int i = 1; i <= n - 1; i++) {
        int cnt_a = 0, cnt_b = 0;
        for (int j = 1; j <= 5; j++) {
            if (A[j][a] < A[j][b]) {
                cnt_a++;
            }
            else {
                cnt_b++;
            }
        }
        if (cnt_a > cnt_b) {
            b = ++nxt;
        }
        else {
            a = ++nxt;
        }
    }
    
    if (a == nxt) {
        swap(a, b);
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= 5; j++) {
            if (A[j][a] <= A[j][i]) {
                cnt++;
            }
        }
        if (cnt < 3) {
            cout << -1 << endl; return;
        }
    }
    cout << a << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 