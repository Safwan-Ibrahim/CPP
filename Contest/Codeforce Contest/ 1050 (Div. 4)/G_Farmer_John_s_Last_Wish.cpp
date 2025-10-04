// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];
vector<int> Div[nn];
vector<int> Cnt(nn);

void prec() {
    for (int i = 1; i < nn; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                Div[i].push_back(j);
                if (i / j != j) Div[i].push_back(i / j);
            }
        } 
    }
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int gcd_ = A[1], mx = 0;
    for (int i = 1; i <= n; i++) {
        int prev_gcd = gcd_;
        gcd_ = gcd(gcd_, A[i]);
        for (auto x : Div[A[i]]) {
            Cnt[x]++;   
            if (Cnt[x] > mx && x > gcd_) mx = Cnt[x];
        }
        for (int x = gcd_ + 1; x <= prev_gcd; x++) {
            if (Cnt[x] > mx) mx = Cnt[x];
        }
        cout << mx << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        for (auto x : Div[A[i]]) {
            Cnt[x]--;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec();
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 