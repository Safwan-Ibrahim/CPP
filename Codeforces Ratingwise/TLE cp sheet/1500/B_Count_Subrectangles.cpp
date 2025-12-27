// Created on: 2025-05-14 05:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int nn = 4e4 + 8;
int n, m, k; 

vector<int> get_v(vector<int> &A, int n) {
    vector<int>Ans(n + 1, 0);
    for (auto x : A) {
        for (int i = 1; i <= x; i++) {
            Ans[i] += x - i + 1;
        }
    }

    return Ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    vector<int>A, B; int cnt = 0;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '1') cnt++;
        if (c == '0' || i == n) {
            if (cnt) A.push_back(cnt);
            cnt = 0;
        }
    }
    
    cnt = 0;
    for (int i = 1; i <= m; i++) {
        char c; cin >> c;
        if (c == '1') cnt++;
        if (c == '0' || i == m) {
            if (cnt) B.push_back(cnt);
            cnt = 0;
        }
    }

    A = get_v(A, n); 
    B = get_v(B, m);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (k % i == 0 && k / i <= m) {
            ans += A[i] * B[k / i];
        }
    }

    cout << ans << endl;

    return 0;
} 