// Created on: 2025-04-11 15:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ld double
#define endl '\n'
const ld pi = 3.1415926;
const ld rt2 = 1.41421356;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        ld a, b, d;

        cin >> a >> b >> d;
    
        ld l = d / rt2;
    
        ld carea = pi * (d/2.0) * (d/2.0);
    
        ld sqarea = l * l;
    
        ld xtra = carea - sqarea;
    
        ld cl = l/2.0;
    
        ld narea = pi * cl * cl;
        narea/=2.0;
    
        narea *= 4.0;
    
        ld ans = narea - xtra;
    
        cout << fixed << setprecision(7) << ans << endl;
    }
    return 0;
} 