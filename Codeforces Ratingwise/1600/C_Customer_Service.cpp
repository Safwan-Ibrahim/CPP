// Created on: 2025-06-12 18:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 307;
int pn, A[nn][nn];

void Try() {
    cin >> pn; 
    multiset<int>Ms;
    for (int i = 1; i <= pn; i++) {
        for (int j = 1; j <= pn; j++) {
            cin >> A[i][j];
        }
        int cnt = 0;
        for (int j = pn; j >= 1; j--) {
            if (A[i][j] != 1) break;
            cnt++;
        } 
        Ms.insert(cnt);
    } 
    
    int ans = 1;
    for (int i = 1; i <= pn - 1; i++) {
        while(Ms.size() && *Ms.begin() < i) Ms.erase(Ms.begin());
        if (Ms.empty()) break;
        Ms.erase(Ms.begin());
        ans++;
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 