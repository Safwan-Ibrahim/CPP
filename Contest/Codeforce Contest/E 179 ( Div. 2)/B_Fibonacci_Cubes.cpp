// Created on: 2025-06-03 21:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mm = 2e5 + 17, nn = 15;
int n, m, Fibo[nn];

void prec() {
    Fibo[1] = 1, Fibo[2] = 2;
    for (int i = 3; i <= 12; i++) {
        Fibo[i] = Fibo[i - 2] + Fibo[i - 1];
    }
}


void Try() {
    cin >> n >> m;
    vector<int>V(3, 0);
    for (int i = 1; i <= m; i++) {
        cin >> V[0] >> V[1] >> V[2];
        sort(V.begin(), V.end());
        if (Fibo[n] <= V.front() && Fibo[n + 1] <= V.back()) cout << '1';
        else cout << '0';
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 