// Created on: 2025-02-23 19:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int A[N];

void Try() {
    int n, k; cin >> n >> k;

    map<int, stack<int>>Mp;
    vector<int>B;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (Mp[A[i]].size() < k) {
            Mp[A[i]].push(i);
            B.push_back(A[i]);
        }
    }
    
    vector<int>Ans(n + 1, 0);
    int color = 0;
    sort(B.begin(), B.end());
    for (int i = 0; i < B.size(); i++) {
        if (i + k - 1 >= B.size() && color == 0) {
            break;
        }
        int id = Mp[B[i]].top();
        Mp[B[i]].pop();
        Ans[id] = ++color;
        if (color == k) {
            color = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
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