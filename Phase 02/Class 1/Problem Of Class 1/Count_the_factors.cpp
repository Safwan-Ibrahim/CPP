// Created on: 2024-12-31 20:55
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9;
int dp[N], spf[N];

void all_primes(int x) {
    int n = x;
    set<int>st;
    while(x > 1) {
        st.insert(spf[x]);
        x /= spf[x];
    }
    dp[n] = st.size();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            spf[j] = min(spf[j], i);
        }
    }

    for (int i = 2; i < N; i++) {
        all_primes(i);
    }

    int x; 
    while(cin >> x && x != 0) {
        cout << x << " : " << dp[x] << endl;
    }

    return 0;
} 