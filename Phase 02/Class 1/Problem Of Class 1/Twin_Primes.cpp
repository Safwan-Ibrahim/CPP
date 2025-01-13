// Created on: 2025-01-06 11:46
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e7 + 9;
bool done[N];

vector<int>primes;
vector<pair<int, int>>ans;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!done[i]) {
            primes.push_back(i);
            for (int j = i + i; j < N; j += i) {
                done[j] = true;
            }
        }
    }

    for (int i = 0; i + 1 < primes.size(); i++) {
        if (primes[i] + 2 == primes[i + 1]) {
            ans.push_back({primes[i], primes[i + 1]});
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve();
    int s; 
    while(cin >> s) {
        cout << "(" << ans[s - 1].first << ", " << ans[s - 1].second << ")" << endl;
    }

    return 0;
} 