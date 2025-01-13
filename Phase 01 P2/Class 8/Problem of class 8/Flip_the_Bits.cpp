// Created on: 2024-11-01 00:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    char a[n + 5],b[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    set<int>seg;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '1') {
            cnt1++;
        }
        else {
            cnt0++;
        }
        if(cnt1 == cnt0) {
            seg.insert(i);
        }
    }

    bool rev = false;
    for (int i = n; i >= 1; i--) {
        if(a[i] != b[i] && !rev) {
            if(seg.find(i) != seg.end()) {
                rev ^= 1;
            } 
            else {
                cout << "NO\n";
                return;
            }
        }
        else if (a[i] == b[i] && rev) {
            if(seg.find(i) != seg.end()) {
                rev ^= 1;
            } 
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 