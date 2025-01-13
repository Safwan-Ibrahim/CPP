// Created on: 2024-10-03 20:30
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int op = 0;
    while(n > 0) {
        if (n > 2) {
            n -= 3;
        }
        else {
            n -= 2;
        }
        op++;
    }
    
    cout << op << endl;
    return 0;
} 