// Created on: 2024-11-04 15:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool ok(set<int>&v, int x) {
    auto it = v.upper_bound(x);
    if(it != v.begin()) {
        it--;
        v.erase(it);
        return true;
    }
    return false;
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int one = 0;
    set<int>zero;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one++;
        }
        else {
            zero.insert(i + 1);
        }
    }
    ll mnus = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (!one) {
            break;
        }
        if (s[i] == '1') {
            if (ok(zero,i + 1)) {
                mnus += i + 1;
            }
            else if (one > 1) {
                one--;
                mnus += i + 1;
            }
            one--;
        }
    }
    cout << 1LL * n * (n + 1) / 2 - mnus << endl;   
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 