// Created on: 2024-10-28 20:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool ok(int x,const string& s,int one) {
    int zero = s.size() - one;
    for (int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '1') {

        }
    }
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int one = 0;
    for (auto x : s) {
        if (x == '1') {
            one++;
        }
    }
    int l = 0, r = n / 2, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(ok(mid,s,one)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 