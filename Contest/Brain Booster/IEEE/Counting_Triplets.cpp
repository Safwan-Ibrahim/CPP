// Created on: 2025-02-26 13:12
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005;
bool done[N];
vector<int>P;

void seive(int n) {
    for (int i = 2; i <= n; i++) {
        if (!done[i]) {
            P.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                done[j] = true;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    seive(n);
    
    ll ans = 0;
    for (auto x : P) {
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= x; j++) {
                if (i + j >= x) {
                    break;
                }
                int need = x - (i + j);
                if (need <= x && need >= 1) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
} 