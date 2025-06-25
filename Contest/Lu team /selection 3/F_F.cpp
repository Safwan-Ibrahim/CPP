// Created on: 2025-04-24 10:21
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll money, plastic, glass, ret; cin >> money >> plastic >> glass >> ret;
    ll ans = 0;

    if (money < glass && money < plastic) {
        cout << 0 << endl; return 0;
    }

    if (glass - ret >= plastic) {
        cout << money / plastic << endl; return 0;
    }

    if (plastic >= glass) {
        if (money < glass) {
            cout << 0 << endl; return 0;
        }
        money -= glass;
        ans += money / (glass - ret);
        money = money % (glass - ret);
        money += glass;
        if (money >= glass) {
            ans+= (money/glass);
        }
        cout << ans << endl;
        return 0;
    }   
    
    
    
    if (money < glass) {
        cout << money / plastic << endl; return 0;
    }
    money -= glass;
    ans += money / (glass - ret);
    money = money % (glass - ret);
    money += glass;
    ll op1 = money / plastic;
    ll op2 = (money / glass);
    money += -glass + ret;
    op2 += money / plastic;
    ans += max(op1, op2);

    cout << ans << endl;
    
    return 0;
} 