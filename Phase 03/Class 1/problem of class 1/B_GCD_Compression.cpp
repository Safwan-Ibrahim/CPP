// Created on: 2025-07-09 19:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    stack<int>Even, Odd;
    int A[2 * n + 1];
    for (int i = 1; i <= 2 * n; i++) {
        int x; cin >> x;
        if (x % 2) Odd.push(i);
        else Even.push(i);
        A[i] = x;
    }
    
    int g = 0;
    for (int i = 1; i < n; i++) {
        int sum = 0;
        if (Even.size() > 1) {
            cout << Even.top() << " ";
            sum += A[Even.top()];
            Even.pop();
            cout << Even.top() << endl;
            sum += A[Even.top()];
            Even.pop();
        }
        else if (Odd.size() > 1) {
            cout << Odd.top() << " ";
            sum += A[Odd.top()];
            Odd.pop();
            cout << Odd.top() << endl;
            sum += A[Odd.top()];
            Odd.pop();
        }
        g = gcd(g, sum);
    }

    assert(g > 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 