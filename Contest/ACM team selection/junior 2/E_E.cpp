// Created on: 2025-08-01 14:05
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int w,a,b,c,d;cin>>w>>a>>b>>c;
    ll sum = a+b+c;
    if(sum<=w){
        cout<<"S"<<endl;
    }
    else{
        cout<<'N'<<endl;
    }
    
    return 0;
} 