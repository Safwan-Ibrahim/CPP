// Created on: 2025-05-01 05:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool pos(string &S) {
    int cnt = 0;
    for (auto x : S) {
        if (x == '(') {
            cnt++;
        }
        else {
            if (cnt == 0) {
                return false;
            }
            cnt--;
        }
    }
    return cnt == 0;
}

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    int l = 0, r = 0;
    for (auto x : S) {
        if (x == ')') {
            r++;
        }
        else {
            l++;
        }
    }

    if (l != r) {
        cout << -1 << endl; return;
    }


    bool one = pos(S);
    for (int i = 0; i < n; i++) {
        if (S[i] == ')') {
            S[i] = '(';
        }
        else {
            S[i] = ')';
        }
    }
    one |= pos(S);
    
    if (one) {
        cout << 1 << endl;
        for (int i = 1; i <= n; i++) {
            cout << 1 << " ";
        }
        cout << endl; return;
    }
    
    vector<int>A(n + 5, 1);
    stack<int>St;
    for (int i = 0; i < n; i++) {
        if (S[i] == '(') {
            St.push(i + 1);
        }
        else {
            if (St.size()) {
                A[St.top()] = 2;
                St.pop();
                A[i + 1] = 2;
            }
        }
    }
    cout << 2 << endl;
    for (int i = 1; i <= n; i++) {
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