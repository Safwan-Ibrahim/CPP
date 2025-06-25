// Created on: 2025-05-13 04:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 8;
int n, k; char S[nn];

void make_it() {
    vector<bool>Done(n + 3, false);
    for (int i = 1; i <= n; i++) {
        if (S[i] != '?' && !Done[i]) {
            for (int j = i + k; j <= n; j += k) {
                Done[j] = true;
                if (S[j] == '?') {
                    S[j] = S[i];
                }
            }
        }
    }
}

bool check() {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        cnt0 += S[i] == '0';
        cnt1 += S[i] == '1';
        if (i >= k) {
            if (i > k) {
                if (S[i - k] == '0') cnt0--;
                else cnt1--;
            }
            if (cnt0 != cnt1) return false;
        }
    }
    return true;
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    
    make_it();
    reverse(S + 1, S + n + 1);
    make_it();

    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= k; i++) {
        cnt1 += S[i] == '1';
        cnt0 += S[i] == '0';
    }

    for (int i = 1; i <= k; i++) {
        if (S[i] == '?') {
            if (cnt0 > cnt1) {
                cnt1++;
                S[i] = '1';
            }
            else {
                cnt0++;
                S[i] = '0';
            }
        }
    }

    make_it();
    cout << (check() ? "YES\n" : "NO\n");

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 