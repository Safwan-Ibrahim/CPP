// Created on: 2025-03-20 18:52
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8, M = 1e9 + 7;
int a, b, Ans[N];

int count(int x) {
    if (x == 1 || x == 2) {
        return 1;
    }
    if (x == 3) {
        return 2;
    }
    if (Ans[x] != -1) {
        return Ans[x];
    }
    return Ans[x] = (count(x - 1) + count(x - 3)) % M;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        Ans[i] = -1;
    }
    cout << count(n) << endl;
    
    
    return 0;
} 