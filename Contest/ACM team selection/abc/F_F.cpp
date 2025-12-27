// Created on: 2025-11-07 10:28
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
using ld=long double;
#define endl '\n'

void Try() {
    
    ld r,abc; cin >> r >> abc;
    ld R = r*2.0L;
    ld abn = abc/2.0L;
    ld bn = R * cosl(abn);
    ld bo = r * cosl(abn);
    ld on = bn-bo;
    ld oh = sinl(abn)*bo;
    ld bc = R * cosl(abc);
    ld bd = bc/2.0L;
    ld cbn = abn;
    ld noi = 90.0L - abn;
    ld nd = sqrtl(bn*bn + bd*bd - 2.0L * bn * bd * cosl(cbn));
    ld ino = acos((bn*bn + nd*nd - bd*bd) / 2.0L * bn * nd);
    ld nio = 180.0L - (ino+noi);
    ld io = (sinl(ino) * on) / sinl(nio);

    ld hi = oh + io;
    cout<<fixed<<setprecision(8)<<hi<<'\n';
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 