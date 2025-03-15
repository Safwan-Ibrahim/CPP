// Created on: 2025-02-26 12:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

map<char, int>Need;

void prec() {
    string T = "IEEELUSBCHAPTER";
    for (auto x : T) {
        Need[x]++;
    }
}
bool check(map<char, int>&Mp) {
    for (auto [x, y] : Need) {
        if (Mp[x] < y) {
            return false;
        }
    }
    return true;
}

void Try() {
    string S; cin >> S;
    map<char, int> Ps[S.size() + 4];
    int mn = 1e9;
    
    int l = -1;
    map<char, int>Mp2;
    for (int r = 0; r < S.size(); r++) {
        Mp2[S[r]]++;
        while(l < r) {
            map<char, int>Tmp;
            for (auto [x, y] : Mp2) {
                if (l != -1) {
                    Tmp[x] = Mp2[x] - Ps[l][x];
                }
                else {
                    Tmp[x] = Mp2[x];
                }
            }
            if (check(Tmp)) {
                mn = min(mn, (r + 1) - (l + 1));
                l++;
            }
            else {
                break;
            }
        }
    }

    if (mn == 1e9) {
        cout << -1 << endl;
    }
    else {
        cout << mn << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 