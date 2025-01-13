// Created on: 2025-01-06 22:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<string>callender{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int interval(int l, int r, int n) {
    return r / n - (l - 1) / n;
}

void solve(int t) {
    string l_m; int l_d, l_y; cin >> l_m >> l_d; cin.ignore(); cin >> l_y;
    string r_m; int r_d, r_y; cin >> r_m >> r_d; cin.ignore(); cin >> r_y;
    
    int l_m7 = find(callender.begin(), callender.end(), l_m) - callender.begin();
    if (l_m7 > 1) {
        l_y++;
    }
    int r_m7 = find(callender.begin(), callender.end(), r_m) - callender.begin();
    if (r_m7 == 1 && r_d < 29) {
        r_y--;
    } 
    else if (r_m7 == 0) {
        r_y--;
    } 

    int ans = interval(l_y, r_y, 4) - interval(l_y, r_y, 100) + interval(l_y, r_y, 400);
    cout << "Case " << t << ": " << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c = 1;
    int t = 1; cin >> t;
    while(t--) solve(c++);
    return 0;
} 