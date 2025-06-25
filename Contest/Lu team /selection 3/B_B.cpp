// Created on: 2025-04-24 09:13
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int A[n + 5];
    set<int>St;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        St.insert(A[i]);
    }

    set<int>Need;
    for (int i = 1; i <= n; i++) {
        if (St.find(i) == St.end()) {
            Need.insert(i);
        }
    }

    vector<bool>Done(n + 5, false);
    for (int i = 1; i <= n; i++) {
        if (A[i] > n) {
            A[i] = *Need.begin();
            Need.erase(Need.begin());
            Done[A[i]] = true;
        }
        else if (Done[A[i]]) {
            A[i] = *Need.begin();
            Done[A[i]] = true;
            Need.erase(Need.begin());
        }
        else {
            Done[A[i]] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
} 