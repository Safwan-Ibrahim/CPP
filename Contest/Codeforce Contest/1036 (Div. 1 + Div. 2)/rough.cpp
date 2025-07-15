// Created on: 2025-07-06 20:16
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> V(n);
        for (int i = 0; i < n; i++) {
            cin >> V[i];
        }
        vector<int>N;
        for (int i = V.size() - 1; i - 1 >= 0; i--) {
            if (V[i] % V[i - 1] != 0) {
                int cut = V[i - 1] / gcd(V[i], V[i - 1]);
                N.push_back(cut);
                V[i - 1] /= cut;
            }
        }
        int l = 1;
        for (auto x : N) {
            l = lcm(x, l);
        }
        cout << l << endl;
    }
    
    return 0;
} 