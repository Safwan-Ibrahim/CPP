// Created on: 2024-10-11 15:55
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n,a[16];

bool rec(int pos = 0, int i = 1) {
    if (i > n) {
        return pos % 360 == 0;
    }
    return rec(pos+a[i],i+1) || rec(pos-a[i],i+1);
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << (rec() ? "YES" : "NO") << endl;    
    return 0;
} 