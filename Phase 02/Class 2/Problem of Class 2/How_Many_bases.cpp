// Created on: 2025-01-12 16:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 100000007;
int n, m, z;

int great_or_equal(vector<int>& sp, int t) {
    int ans = 1;
    for (auto x : sp) {
        ans = 1LL * ans * (x / t + 1) % M;
    }
    return ans;
}

void solve(int t) {
    vector<int>sp;
    for (int i = 2; i * i <= n; i++) {
        int p = 0;
        while(n % i == 0) {
            n /= i;
            p++;
        }
        if (p) {
            sp.push_back(p * m);
        }
    }
    if (n > 1) {
        sp.push_back(m);
    }

    cout << "Case " << t << ": ";
    cout << (great_or_equal(sp, z) - great_or_equal(sp, z + 1) + M) % M << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c = 1;
    while(cin >> n >> m >> z && n + m + z > 0) solve(c++);
    return 0;
} 