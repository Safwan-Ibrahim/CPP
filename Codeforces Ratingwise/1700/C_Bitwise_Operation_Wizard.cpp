// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

char query(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl; 
    char ans; cin >> ans; return ans;
}

void Try() {
    int n; cin >> n;
    
    int x = 0;
    for (int i = 1; i < n; i++) {
        char res = query(x, x, i, i);
        if (res == '<') x = i;
    }
    
    int prev = 0;
    vector<int> V = {0};
    for (int i = 1; i < n; i++) {
        char res = query(x, prev, x, i);
        if (res == '<') {
            prev = i;
            V = {i};
        }
        else if (res == '=') V.push_back(i);
    }
    
    int y = V[0];
    for (int i = 1; i < V.size(); i++) {
        char res = query(y, y, V[i], V[i]);
        if (res == '>') y = V[i];
    }

    cout << "! " << x << " " << y << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 