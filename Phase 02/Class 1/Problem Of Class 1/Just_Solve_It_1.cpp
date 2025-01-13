// Created on: 2024-12-31 14:07
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9;
int lpf[N], sum[N], gpf[N], dv[N], tp[N], dpf[N];

void total_primes_and_lpf_gpf(int x) {
    int n = x;
    multiset<int>ms;
    while(x > 1) {
        ms.insert(lpf[x]);
        x /= lpf[x]; 
    }
    set<int>st(ms.begin(), ms.end());
    gpf[n] = *ms.rbegin();
    tp[n] = ms.size();
    dpf[n] = st.size();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            dv[j]++;
        }
    }

    for (int i = 2; i < N; i++) {
        lpf[i] = i;
    }

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            lpf[j] = min(i, lpf[j]);
        }
    }

    for (int i = 2; i < N; i++) {
        total_primes_and_lpf_gpf(i);
    }

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            sum[j] += i;
        }
    }

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cout << lpf[x] << " " << gpf[x] << " " << dpf[x] << " " << tp[x] << " " << dv[x] << " " << sum[x] << endl;
    }

    return 0;
} 