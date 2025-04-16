// Created on: 2025-04-11 17:12
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    string S;
    getline(cin, S);
    stringstream ssin(S);
    char a, b; 
    ssin >> a >> b;
    string c = string() + a + b;
    if (c == "ti") {
        for (int j = 1; j <= 5; j++) {
            char dum; ssin >> dum;
        }
        string Tmp; 
        ssin >> Tmp;
        Tmp.pop_back(); Tmp.pop_back();
        cout << Tmp << endl;
    }
    
    return 0;
} 