// Created on: 2024-11-08 15:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void i() {
    cout << "perfectus\n";
}
void j() {
    cout << "invalidum\n";
}

void solve(int x)
{   
    cout << "Case " << x << ": ";
    int a,b,c; cin >> a >> b >> c;
    vector<int>v{a,b,c};
    sort(v.begin(),v.end());
    if (v[2] == 6 ) {
        if(v[1] == 1 && v[0] == 1 || v[1] == 3 && v[0] == 0) {
            i();
        }
        else {
            j();
        }
    } 
    else if (v[2] == 4) {
        if(v[1] == 4 && v[0] == 0 || v[1] == 3 && v[0] == 1 || v[1] == 2 && v[0] == 1 ) {
            i();
        }
        else{
            j();
        }
    }
    else if (v[2] == 3) {
        if (v[1] == 3 && v[0] == 3 || v[1] == 3 && v[0] == 0) {
            i();
        }
        else {
            j();
        }
    }
    else if (v[2] == 2 && v[1] == 2 && v[0] == 2) {
        i();
    }
    else {
        j();
    }
     
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    for (int i= 1; i <= t; i++) {
        solve(i);
    }
    return 0;
} 