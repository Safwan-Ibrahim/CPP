// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, x, y, A[nn];

void Try() {
    cin >> n >> x >> y;
    
    for (int i = 1; i <= x; i++) {
        cin >> A[i];
        A[i] %= n;
    }
    
    int ans = x + y - 2;
    sort(A + 1, A + x + 1); 
    
    priority_queue<int, vector<int>, greater<int>> Pq1, Pq2;
    
    int d = (A[1] - A[x] + n) % n;
    if (d % 2 == 0) Pq1.push(d);
    else Pq2.push(d);

    for (int i = 2; i <= x; i++) {
        if ((A[i] - A[i - 1]) % 2 == 0) {
            Pq1.push(A[i] - A[i - 1]);
        }
        else Pq2.push(A[i] - A[i - 1]);
    }

    while(Pq1.size()) {
        auto d = Pq1.top();
        Pq1.pop();

        int full = d / 2 - 1;
        if (y >= full) {
            ans += full + 1;
            y -= full;
        }
        else {
            ans += y;
            y = 0;
        }
    }
    
    while(Pq2.size()) {
        auto d = Pq2.top();
        Pq2.pop();

        int full = d / 2;
        if (y >= full) {
            ans += full;
            y -= full;
        }
        else {
            ans += y;
            y = 0;
        }
    }

    cout << min(n - 2, ans) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 