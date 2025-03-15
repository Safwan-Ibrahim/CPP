// Created on: 2025-03-10 19:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 3e3 + 8;
int A[N];

void Try() {
    int n; cin >> n;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }
    
    int lo = A[1];
    int k = 2;
    while(1) {
        int sum = 0;
        bool pos = true;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            sum += A[i];
            if (sum == lo) {
                sum = 0;
                cnt++;
            }
            else if (sum > lo || i == n) {
                pos = false;
                break;
            }
        }
        if (pos) {
            cout << n - cnt << endl; return;
        }
        lo += A[k++];
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