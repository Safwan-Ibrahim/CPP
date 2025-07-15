// Created on: 2025-07-12 02:05
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k, m; cin >> n >> k >> m;
    vector<int>Cost(n);
    vector<string>A(n);
    for (auto &x : A) {
        cin >> x;
    }
    for (auto &x : Cost) {
        cin >> x;
    }

    map<string, int>Id;
    for (int i = 0; i < n; i++) {
        Id[A[i]] = i;
    }
    
    vector<int>Group(n);
    vector<int>V(k, 1e9);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        while(x--) {
            int id; cin >> id; id--;
            Group[id] = i;
            V[i] = min(V[i], Cost[id]);
        }
    }
    
    ll sum = 0;
    for (int i = 1; i <= m; i++) {
        string S; cin >> S;
        int id = Id[S];
        int group = Group[id];
        sum += V[group];
    }
    cout << sum << endl;
    
    return 0;
} 