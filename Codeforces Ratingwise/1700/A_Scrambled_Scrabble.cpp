// Created on: 2025-07-29 01:54
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    map<char, int>Mp;
    string S; cin >> S;
    int n = 0, g = 0, c = 0, v = 0, y = 0;  
    for (auto x : S) {
        if (x == 'G') {
            g++;
        }
        else if (x == 'N') {
            n++;
        }
        else if (x == 'Y') {
            y++;
        }
        else if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') v++;
        else c++;
    }
    
    
    if (n < g) swap(n, g);
    c += n + g;
    int ans = 0;
    int take;
    take = min(c / 2, v);
    ans += take * 3;
    c -= take * 2;
    v -= take;
    int uc = take * 2;

    take = min(c / 2, y);
    ans += take * 3;
    c -= take * 2;
    y -= take;
    uc += take * 2;

    take = min(y / 2, c);
    c -= take;
    y -= take * 2;
    ans += take * 3;
    uc += take;

    int lft = min(g, c);
    int ug = g - lft;
    ans += min(uc, lft);
    ug += min(uc, lft);
    take = min(y / 2, v);
    ans += take * 3;
    y -= take * 2;
    v -= take; 
    ans += y - y % 3;

    while(y % 3) {
        if (v == 1 && c == 1) ans++, y--;
        else if (ug > 1) {
            ans += y % 3;
            ug -= y % 3;
            y -= y % 3;
        }
        else if (ug > 0 && y > 1) {
            ug--;
            y--;
            ans++;
        }
        else break;
    }

    cout << ans << endl;
    return 0;
} 