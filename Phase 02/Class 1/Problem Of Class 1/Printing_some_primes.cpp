// Created on: 2024-12-31 19:11
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e8 + 9;
vector<bool>done(N, false);
vector<int>primes;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; 1LL * i * i < N; i++) {
        if (!done[i]) {
            for (int j = i * i; j < N; j += i) {
                done[j] = true; 
            }
        }
    }

    for (int i = 2; i < N; i++) {
        if (!done[i]) {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < primes.size(); i += 100) {
        cout << primes[i] << endl;
    }
    
    
    return 0;
} 