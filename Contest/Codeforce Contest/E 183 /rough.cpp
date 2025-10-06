// Created on: 2025-10-06 20:24
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int sc(const vector<int>& V) {
    int n = (int)V.size();
    int total = n * (n + 1) / 2;
    int nondec = 0;         
    int run_len = 1;        

    for (int i = 1; i < n; ++i) {
        if (V[i-1] <= V[i]) {
            ++run_len;
        } else {
            nondec += run_len * (run_len + 1) / 2;
            run_len = 1;
        } 
    }
    nondec += run_len * (run_len + 1) / 2;

    return total - nondec;
}

void print(vector<int> &V) {
    for (auto x : V) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t; cin >> t;

    int lm = 2e8 / (30 * t);
    random_device rd;
    mt19937 g(rd()); 
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == 1) {
            cout << 0 << endl; continue;
        }
        vector<int> V(n);
        iota(V.begin(), V.end(), 1);
        if (sc(V) == k) {
            print(V); continue;
        }
        reverse(V.begin(), V.end());
        if (sc(V) == k) {
            print(V); continue;
        }
        reverse(V.begin(), V.end());
        
        for (int i = 1; i <= lm; i++) {
            if (i == lm) {
                cout << 0 << endl; break;
            }
            shuffle(V.begin(), V.end(), g);
            if (sc(V) == k) {
                print(V); break;
            }
            reverse(V.begin(), V.end());
            if (sc(V) == k) {
                print(V); break;
            }
        }
    }

    
    return 0;
} 