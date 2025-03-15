// Created on: 2025-02-26 12:16
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
int A[N];

int J[N], Last[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = n; i >= 1; i--) {
        if (i + A[i] <= n) {
            J[i] = J[i + A[i]] + 1;
            Last[i] = Last[i + A[i]]; 
        }
        else {
            J[i] = 1;
            Last[i] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Last[i] << " " << J[i] << endl;
    }
    
    return 0;
} 