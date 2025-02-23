// Created on: 2024-11-25 01:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int power(int x, int n, int m) {
    int ans = 1; 
    while(n) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        x = 1LL * x * x % m;
        n >>= 1;
    }
    return ans;
}

string form(int x) {
    string s = to_string(x);
    while(s.size() < 3) {
        s = "0" + s;
    } 
    return s;
}

void solve()
{
    int n, k; cin >> n >> k;
    double num = k * log10(n);
    double x = num - (int) num;
    cout << (int)(pow(10, x) * 100) << "..." << form(power(n, k, 1000)) << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 