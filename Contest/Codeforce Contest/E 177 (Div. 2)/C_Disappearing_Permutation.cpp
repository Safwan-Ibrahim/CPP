// Created on: 2025-04-17 21:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, A[nn], Id[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Id[A[i]] = i;
    }
    
    int ans = 0;
    vector<bool>Done(n + 2, false);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int store = A[x];   
        while(true) {
            if (Done[store]) {
                break;
            }
            if (!Done[x]) {
                Done[x] = true;
                ans++;
                x = Id[x];
            }
            else {
                break;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 