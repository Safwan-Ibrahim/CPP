// Created on: 2025-11-07 09:17
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> p(20);
    p[0] = 1;
    //cout<<p[0]<< ' ';
    for(int i=1; i<20; i++) {
        p[i] = 2 * p[i - 1];
        //cout << p[i] << ' ';
    }
    //cout<<endl;
    for(int i=1; i<20; i++) {
        p[i] = p[i] + p[i - 1];
        //cout << p[i] << ' ';
    }
    
    //cout<<endl;



    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++) {
        int n;
        cin>>n;
        int ans = 1;
        for(int i=0; i<20; i++) {
            if(p[i] >= n) {
                break;
            }
            ans++;
        }
        cout << "Case " << t << ": " << ans << endl;
    }
    
    
    return 0;
} 