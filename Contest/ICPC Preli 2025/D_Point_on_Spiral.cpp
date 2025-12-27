// Created on: 2025-11-30 10:37
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int a, b;

bool found(int x, int y, int nx, int ny) {
    if (x != nx) {
        if (nx > x) {
            for (int i = x; i <= nx; i++) {
                if (i == a && y == b) {
                    return 1;
                }
            }
        }
        else {
            for (int i = x; i >= nx; i--) {
                if (i == a && y == b) {
                    return 1;
                }
            }
            
        }
    }
    else if (y != ny) {
        if (ny > y) {
            for (int i = y; i <= ny; i++) {
                if (i == b && x == a) {
                    return 1;
                }
            }
        }
        else {
            for (int i = y; i >= ny; i--) {
                if (i == b && x == a) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> a >> b;

    int add = 1;
    int round = 0;
    int ans = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= 1000; i++) {
        int nx, ny;
        if (round == 0) {
            nx = x + add;
            ny = y;
        }
        if (round == 1) {
            nx = x;
            ny = y + add;
        }
        if (round == 2) {
            nx = x - add;
            ny = y;
        }
        if (round == 3) {
            nx = x;
            ny = y - add;
        }
        if (found(x, y, nx, ny)) break;

        ans++;
        
        if (i % 2 == 0) add++;
        round++;
        round %= 4;
        x = nx, y = ny;
    }

    cout << ans << endl;
    
    return 0;
} 