// Created on: 2025-06-12 22:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

#define dbg(x) cerr << #x << " " << x << endl;

void Try() {
    int n, k; cin >> n >> k;
    int A[n], B[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    
    int q; cin >> q;
    q = 0;
    cout << "YES\n";
    while(q--) { 
        int x; cin >> x;
        map<int, int>L, R; bool right = true; int time = 0;
        auto it = lower_bound(A, A + n, x);
        if (it == A + n) {
            cout << "YES\n"; continue;
        }
        int id = it - A;
        id--;
        int go = 100000;
        for (int i = 1; i <= 100000; i++) {
            if (right) {
                id++;
                if (id >= n || id <= -1) {
                    cout << "YES\n"; break;
                }
                time += abs(x - A[id]);
                time %= k;
                if (time == B[id]) {
                    right ^= 1; 
                    R[id]++;
                    if (R[id] > 2) {
                        cout << "NO\n"; break;
                    }
                }
                x = A[id];
            }
            else {
                id--;
                if (id <= -1 || id >= n) {
                    cout << "YES\n"; break;
                }
                time += abs(x - A[id]); 
                time %= k;
                if (time == B[id]) {
                    right ^= 1; 
                    L[id]++;
                    if (L[id] > 2) {
                        cout << "NO\n"; break;
                    }
                }
                x = A[id];
            }
        }

    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 