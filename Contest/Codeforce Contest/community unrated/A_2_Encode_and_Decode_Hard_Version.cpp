// Created on: 2025-11-09 20:47
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void encode() {
    int n; cin >> n;
    vector<string> A(n, string(10, 'z'));

    string Ans = "";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        string Tmp = to_string(x);
        for (int j = 0; j < Tmp.size(); j++) {
            A[i][j] =  Tmp[j] - '0' + 'a';
        }

        Ans += A[i];
    }

    cout << Ans << endl;
}

void decode() {
    string S; cin >> S;
    int n = S.size();

    cout << n / 10 << endl;

    for (int i = 0; i < n; i += 10) {
        for (int j = i; j < i + 10 && S[j] != 'z'; j++) {
            cout << S[j] - 'a';
        }
        cout << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    string T; cin >> T;
    if (T[0] == 'f') encode();
    else decode();
    
    return 0;
} 