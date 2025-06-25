// Created on: 2025-04-16 18:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int A[nn], B[nn], Pref[nn];

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        B[i] = A[i] % n;
    }
    
    vector<int>Ans;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += B[i];
        sum %= n;
        Pref[i] = sum;
    }

    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        if (Pref[i] == 0) {
            for (int j = 1; j <= i; j++) {
                Ans.push_back(j);
            }
            break;
        }
        if (Mp[Pref[i]] != 0) {
            for (int j = Mp[Pref[i]] + 1; j <= i; j++) {
                Ans.push_back(j);
            }
            break;
        }
        Mp[Pref[i]] = i;
    }

    cout << Ans.size() << endl;
    for (auto x : Ans) {
        cout << x << " ";
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