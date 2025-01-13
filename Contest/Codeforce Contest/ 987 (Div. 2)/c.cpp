// Created on: 2024-11-15 18:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6;

void solve2(int n) {
    map<int,int>mp;
    mp[1] = N, mp[10] = N, mp[26] = N;
    mp[23] = N - 1, mp[27] = N - 1;
    int number = 1;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (mp.find(i) != mp.end()) {
            cout << mp[i] << " ";
        }
        else {
            cout << number << " ";
            c++; 
            if (c == 2) {
                c = 0;
                number++;
            }
        }
    }
    cout << endl;
}

void solve()
{
    int n; cin >> n;

    if (n & 1) {
        if (n < 26) {
            cout << - 1 << endl;
        }
        else {
            solve2(n);
        }
    }
    else {
        for (int i = 1; i <= n / 2; i++) {
            cout << i << " " << i << " ";
        }
        cout << endl;
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