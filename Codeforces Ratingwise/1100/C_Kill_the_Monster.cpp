// Created on: 2025-01-28 20:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll cl(ll a, ll b) {
    return (a + b - 1) / b;
} 

void solve() {
    ll heath_hero, damage_hero, health_villian, damage_villian; 
    cin >> heath_hero >> damage_hero >> health_villian >> damage_villian;
    int k, extra_damage, extra_health; cin >> k >> extra_damage >> extra_health;

    for (int i = 0; i <= k; i++) {
        ll new_health_hero = heath_hero + i * extra_health;
        ll new_damage_hero = damage_hero + (k - i) * extra_damage;
        if (cl(new_health_hero, damage_villian) >= cl(health_villian, new_damage_hero)) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 