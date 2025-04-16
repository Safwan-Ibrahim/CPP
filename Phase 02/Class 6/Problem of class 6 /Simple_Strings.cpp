// Created on: 2025-04-13 15:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string S; cin >> S;

    // for (int i = 0; i < S.size(); i++) {
    //     char l = '.', r = '.';
    //     if (i != 0) {
    //         l = S[i - 1];
    //     }
    //     if (i != S.size() - 1) {
    //         r = S[i + 1];
    //     }
    //     if (l == S[i] && r == S[i]) {
    //         if (l != 'a') {
    //             S[i] = 'a';
    //         }
    //         else {
    //             S[i] = 'b';
    //         }
    //     }
    // }

    // for (int i = 0; i < S.size(); i++) {
    //     char l = '.', r = '.';
    //     if (i != 0) {
    //         l = S[i - 1];
    //     }
    //     if (i != S.size() - 1) {
    //         r = S[i + 1];
    //     }
    //     if (l == S[i] || r == S[i]) {
    //         if ('a' != l && 'a' != r) {
    //             S[i] = 'a';
    //         } 
    //         else if ('b' != l && 'b' != r) {
    //             S[i] = 'b';
    //         } 
    //         else {
    //             S[i] = 'c';
    //         } 
    //     }
    // }

    int n = S.size();
    for (int i = 1; i < n; i++) {
        if (S[i] == S[i - 1]) {
            char c = 'a';
            while(c == S[i - 1] || (i < n - 1 && S[i + 1] == c)) {
                c++;
            }
            S[i] = c;
        }
    }
    cout << S << endl;
    
    return 0;
} 