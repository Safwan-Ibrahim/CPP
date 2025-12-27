// Created on: 2025-05-30 04:02
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int>A(n + 3, 0);
    set<int>St, Got;
    for (int i = 3; i <= n; i++) {
        St.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        Got.insert(i);
    }
    St.insert(1e9); St.insert(1e9 + 8);
    int cnt = 0;
    int l = 1, r = 2;
    while(cnt + 1 < n) {
        cout << "? " << l << " " << r << endl;
        int x; cin >> x;
        cout << "? " << r << " " << l << endl; 
        int y; cin >> y;
        if (y > x) {
            A[r] = y; r = *St.begin(); 
            Got.erase(y);
            St.erase(St.begin());
        }
        else {
            A[l] = x; l = *St.begin();
            Got.erase(x);
            St.erase(St.begin());
        }
        cnt++;
    }

    cout << "! " << endl;
    for (int i = 1; i <= n; i++) {
        cout << (A[i] ? A[i] : *Got.begin()) << " ";
    }
    cout << endl;
    
    return 0;
} 