// Created on: 2024-10-01 01:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+9;
ll d[N];
int a[N],l[N],r[N];

bool cmp(pair<int,int>a, pair<int,int>b) {
    return a.first > b.first;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q; cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1,a+n+1,greater<int>());

    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        d[l[i]]++;
        d[r[i]+1]--;
    }    

    pair<int,int> mp[n+5];
    for (int i = 1; i <= n; i++) {
        d[i] += d[i-1];
        mp[i].first = d[i];
        mp[i].second = i;
    }

    sort(mp+1,mp+n+1,cmp);

    for (int i = 1; i <= n; i++) {
        d[mp[i].second] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        d[i]+= d[i-1];
    }

    ll sum = 0;
    for (int i = 1; i <= q; i++) {
        sum += d[r[i]] - d[l[i]-1];
    }

    cout << sum << endl;

    return 0;
} 