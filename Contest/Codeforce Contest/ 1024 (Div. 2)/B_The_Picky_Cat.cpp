// Created on: 2025-05-11 21:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] = abs(A[i]);
    }
    
    int want = A[1];
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) {
        if (want == 0 && A[i] == want) {
            int rest = n - i;
            if (rest >= n / 2) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
            return;
        }
        if (want != 0 && A[i] == want) {
            int rest = n - i;
            if (n % 2 == 0) {
                if (rest + 1 >= n / 2) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
            else {
                if (rest >= n / 2) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n"; 
                }
            }
            return;
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