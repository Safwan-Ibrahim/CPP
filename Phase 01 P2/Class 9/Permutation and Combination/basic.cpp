// Created on: 2025-02-20 02:16
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 8, M = 1e9 + 7;
int Fact[N], IFact[N];

int power(int x, int n) {
    int ans = 1 % M;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % M;
        }
        n >>= 1;
        x = 1LL * x * x % M;
    }  
    return ans; 
}

void prec() {
    Fact[0] = 1 % M;
    for (int i = 1; i < N - 2; i++) {
        Fact[i] = 1LL * Fact[i - 1] * i % M;
    }

    IFact[N - 1] = power(Fact[N - 1], M - 2);
    for (int i = N - 2; i >= 1; i--) { // check video
        IFact[i] = 1LL * IFact[i + 1] * (i + 1) % M;
    }
}

int nCr(int n, int r) {
    return 1LL * Fact[n] * IFact[r] % M * IFact[n - r] % M;
}

int nPr(int n, int r) {
    return 1LL * Fact[n] * IFact[n - r] % M;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    
    
    return 0;
} 