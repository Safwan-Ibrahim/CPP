// Created on: 2025-11-23 14:34
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void push(vector<int> &B, int x, int n) {
    for (int i = 1; i <= n; i++) {
        if (x == 1) {
            if (i % 2 == 1 && i % 3 != 0) B.push_back(i);
        }
        else if (x == 2) {
            if (i % 2 == 0 && i % 3 != 0) B.push_back(i);
        }
        else if (x == 3) {
            if (i % 3 == 0 && i % 2 == 1) B.push_back(i);
        }
        else if (i % 3 == 0 && i % 2 == 0) B.push_back(i);
    }
}

void Try() {
    int n; cin >> n;
    
    vector<int> A(n + 1, -1), B;
    
    push(B, 1, n), push(B, 3, n), push(B, 6, n), push(B, 2, n);
    assert(B.size() == n);

    for (int i = 1; i <= n; i += 3) {
        A[i] = B.back();
        B.pop_back();
        if (i + 1 <= n) {
            A[i + 1] = B.back();
            B.pop_back();
        }
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] == -1) {
            A[i] = B.back();
            B.pop_back();
        }
    }

    int cnt = 0;
    for (int i = 1; i + 2 <= n; i++) {
        int a = A[i], b = A[i + 1], c = A[i + 2];
        if (__gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) == 1) {
            cnt++;
        }
    }

    assert(cnt <= 6);

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