// Created on: 2025-05-13 16:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, k; char S[nn];

int need(char c, int id) {
    int ans = 0;
    for (int i = id; i <= n; i += k) {
        ans += c != S[i];
    }
    return ans;
}

map<char, int>Mp;
void cal(int id) {
    for (int i = id; i <= n; i += k) {
        Mp[S[i]]++;
    }
}

char get_char() {
    int mx = 0; char c;
    for (auto [x, y] : Mp) {
        if (y >= mx) {
            mx = y;
            c = x;
        }
    } 
    return c;
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    
    int ans = 0;
    for (int i = 1, j = k; i <= j; i++, j--) {
        Mp.clear();
        cal(i); char a = get_char();
        if (i == j) {
            ans += need(a, i); continue;
        }
        cal(j); char b = get_char();
        Mp.clear();
        cal(j); char c = get_char();
        int mn = 1e9;
        mn = need(a, i) + need(a, j);
        mn = min(mn, need(b, j) + need(b, i));
        mn = min(mn, need(c, i) + need(c, j));
        ans += mn;
    }


    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 