// Created on: 2025-07-19 21:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n; pair<int, int> A[nn];

bool cmp(pair<int, int>a, pair<int, int>b) {
    return a.first + a.second < b.first + b.second;
}

void Try() {
    cin >> n;
    map<pair<int, int>, vector<int>>Mp;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
        Mp[{A[i]}].push_back(i);
    }   
    
    sort(A + 1, A + n + 1, cmp);
    n /= 2;
    for (int i = 1; i <= n; i++) {
        cout << Mp[{A[i]}].back() << " " << Mp[{A[i + n]}].back() << endl;
        Mp[{A[i]}].pop_back(), Mp[{A[i + n]}].pop_back();
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 