#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 998244353;

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    cout << (n % M + M ) % M; 
} 