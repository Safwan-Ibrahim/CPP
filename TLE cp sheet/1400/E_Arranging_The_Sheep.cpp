// Created on: 2025-02-23 05:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9;
char A[N];
int n;

ll calculate(int id) {
    ll ans = 0;
    for (int i = id + 1, gap = 1; i <= n; i++) {
        if (A[i] == '*') {
            ans += i - (gap + id);
            gap++;
        }
    }
    for (int i = id - 1, gap = 1; i >= 1; i--) {
        if (A[i] == '*') {
            ans += id - gap - i;
            gap++;
        }
    }
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int med = 0;
    for (int i = 1; i <= n; i++) {
        med += A[i] == '*';
    }
    
    med = (med + 1) / 2; 
    int cnt = 0;
    int id = 0;
    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        cnt += A[i] == '*';
        if (cnt == med) {
            ans = calculate(i);
            break;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 