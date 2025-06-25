// Created on: 2025-06-04 10:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    int last = -1;
    for (int i = 1; i <= n; i++) {
        int start = i;
        while(i <= n && A[i] == A[start]) i++;
        if (i - start >= 4) {
            cout << "Yes\n"; return;
        } 
        if (last != -1 && i - start >= 2) {
            int need = A[start] - A[last] - 1;
            if (lower_bound(A + 1, A + n + 1, A[start]) - lower_bound(A + 1, A + n + 1, A[last + 1]) >= need) {
                cout << "Yes\n"; return;
            }
        }
        if (i - start >= 2) last = --i;
        else i--;
    }

    cout << "No\n"; return;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 