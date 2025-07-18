// Created on: 2025-06-15 20:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int pn, A[nn];

void Try() {
    cin >> pn;
    for (int i = 1; i <= pn; i++) {
        cin >> A[i];
    }
    vector<bool>Done(pn + 1, false);
    multiset<int>Ms;
    for (int i = 1; i <= pn; i++) {
        Ms.insert(A[i]);
    }
    
    Ms.insert(2e9);
    for (int i = 1; i <= pn; i++) {
        Ms.erase(Ms.find(A[i]));
        if (*Ms.begin() < A[i]) {
            Done[i] = true;
            A[i]++;
        }
    }
    
    int min_left = 2e9;
    for (int i = 1; i <= pn; i++) {
        if (!Done[i] && min_left < A[i] - 1) {
            A[i]++;
        }
        else if (Done[i]) {
            min_left = min(min_left, A[i] - 1);
        }
    }
    
    sort(A + 1, A + pn + 1);
    for (int i = 1; i <= pn; i++) {
        cout << A[i] << " ";
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