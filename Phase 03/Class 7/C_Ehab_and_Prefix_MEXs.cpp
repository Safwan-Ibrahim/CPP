// Created on: 2025-09-23 21:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn], Cnt[nn], Cnt2[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Cnt[A[i]]++;
    }

    int mex = 0;
    vector<int> B(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (A[i - 1] != A[i]) {
            B[i] = A[i - 1];
            mex = max(mex, A[i]);
        }
        else {
            while (Cnt[mex]) {
                mex++;
            }
            B[i] = mex++;
        }
    }

    mex = 0;
    for (int i = 1; i <= n; i++) {
        Cnt2[B[i]]++;
        while (Cnt2[mex]) mex++;
        if (mex != A[i]) {
            cerr << -1 << endl; return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    
    return 0;
} 