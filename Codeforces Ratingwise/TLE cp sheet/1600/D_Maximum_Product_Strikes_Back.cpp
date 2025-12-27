// Created on: 2025-05-26 03:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n, A[nn], LP[nn], LN[nn], CT[nn], CN[nn]; 

void Try() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int cn = 0, ct = 0;
    for (int i = 1; i <= n; i++) {
        ct += abs(A[i]) == 2;
        cn += A[i] < 0;
        CT[i] = ct, CN[i] = cn;
    }

    int lp = 0, ln = 0;
    for (int i = n; i >= 1; i--) {
        if (A[i] != 0) {
            LP[i] = lp, LN[i] = ln;
            if (A[i] < 0) {
                if (!ln) ln = i;
            }
            else {
                if (!lp) lp = i;
            }
        }
        else {
            lp = ln = 0;
        }
    }

    int mx = 0; pair<int, int>Ans = {n, 0};
    for (int i = 1; i <= n; i++) {
        if (!A[i]) continue;
        if (!LP[i] || !LN[i]) {
            if (A[i] == 2 && 1 > mx) {
                mx = 1; Ans = {i - 1, n - i};
            }
        }
        if (LP[i]) {
            int ct = CT[LP[i]] - CT[i - 1];
            bool pos = (CN[LP[i]] - CN[i - 1]) % 2 == 0;
            if (pos && ct > mx) {
                mx = ct; Ans = {i - 1, n - LP[i]};
            } 
        }
        if (LN[i]) {
            int ct = CT[LN[i]] - CT[i - 1];
            bool pos = (CN[LN[i]] - CN[i - 1]) % 2 == 0;
            if (pos && ct > mx) {
                mx = ct; Ans = {i - 1, n - LN[i]};
            } 
            LN[i]--;
            ct = CT[LN[i]] - CT[i - 1];
            pos = (CN[LN[i]] - CN[i - 1]) % 2 == 0;
            if (pos && ct > mx) {
                mx = ct; Ans = {i - 1, n - LN[i]};
            } 
        }
    }
    
    cout << Ans.first << " " << Ans.second << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 