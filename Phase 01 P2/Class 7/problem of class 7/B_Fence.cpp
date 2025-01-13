// Created on: 2024-10-06 01:52
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k; cin >> n >> k;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   

    int l = 0; ll sum = 0, ans = 1e18;

    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (i >= k) {
            if (sum < ans) {
                ans = sum;
                l = i-k+1;
            }
            sum -= a[i-k+1];
        }
    }

    cout << l << endl;
    
    return 0;
} 