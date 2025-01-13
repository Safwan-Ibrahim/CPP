// Created on: 2024-10-06 14:03
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    priority_queue <int, vector<int>, greater<int>> pq;

    for (int i= 1; i <= n; i++) {
        int a; cin >> a;
        pq.push(a);
    }

    while(pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push((a+b)/2);
    }
    cout << pq.top() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 