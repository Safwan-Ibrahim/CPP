// Created on: 2025-08-01 14:13
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {

    
    ll n;cin>>n;
    ll l = 0;
    ll r = n-1;
    ll mn = 1e18;
    map<ll,ll>mpp;
    vector<ll>p(n);
    for(int i =0;i<n;i++){
        cin>>p[i];
        mn = min(p[i],mn);
        mpp[p[i]]++;
    }
    ll ki = n -mpp[mn];
    ll sum = mn*n;
    sum+=ki;
    cout<<sum<<endl;
    // if(mpp.size()==1){
    //     cout<<sum<<endl;return;
    // }
    // for(int i =0;i<n;i++){
    //     if(mn != p[i]){
    //         break;
    //     }
    // }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 