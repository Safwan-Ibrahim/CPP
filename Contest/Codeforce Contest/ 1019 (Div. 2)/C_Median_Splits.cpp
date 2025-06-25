// Created on: 2025-04-21 21:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, k, A[nn];

bool ok(vector<bool> &P, vector<bool> &S) {
    int id = -1;
    for (int i = 1; i <= n - 2; i++) {
        if (P[i]) {
            while(i + 1 <= n - 2 && P[i + 1] && A[i + 1] > k) {
                i++;
            }
            id = i;
            break;
        }
    }
    if (id == -1) {
        return false;
    }

    int b = 0, s = 0;
    for (int i = id + 1; i <= n; i++) {
        if (A[i] <= k) {
            s++;
        }
        else {
            b++;
        }
        if (i != n && s >= (s + b + 1) / 2) {
            return true;
        }
        if (i != id + 1 && S[i]) {
            return true;
        } 
    }
    return false;
} 

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<bool>P(n + 5, false), S(n + 5, false);
    int s = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] <= k) {
            s++;
        }
        else {
            b++;
        }
        P[i] = s >= ((b + s + 1) / 2);
    }
    
    s = 0, b = 0;
    for (int i = n; i >= 1; i--) {
        if (A[i] <= k) {
            s++;
        }
        else {
            b++;
        }
        S[i] = s >= ((b + s + 1) / 2);
    }
    
    bool yes = ok(P, S);
    reverse(A + 1, A + n + 1);
    reverse(P.begin() + 1, P.begin() + n + 1);
    reverse(S.begin() + 1, S.begin() + n + 1);
    yes |= ok(S, P);
    cout << (yes ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 


// for (int i = 1; i <= n; i++) {
//     if (A[i] <= k) {
//         s++;
//     }
//     else {
//         b++;
//     }
//     P[i] = s >= ((b + s + 1) / 2);
// }

// s = 0, b = 0;
// for (int i = n; i >= 1; i--) {
//     if (A[i] <= k) {
//         s++;
//     }
//     else {
//         b++;
//     }
//     S[i] = s >= ((b + s + 1) / 2);
// }