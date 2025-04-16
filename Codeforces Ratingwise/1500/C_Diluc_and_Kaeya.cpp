// Created on: 2025-04-13 21:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

pair<int, int>get_ratio(int a, int b) {
    int g = gcd(a, b);
    a /= g, b /= g;
    return {a, b};
}

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    map<pair<int, int>, int>Mp;

    int d = 0, k = 0;
    for (int i = 0; i < n; i++) {
        d += S[i] == 'D';
        k += S[i] == 'K';
        auto r = get_ratio(d, k);
        cout << ++Mp[r] << " ";
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