// Created on: 2025-07-08 13:57
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int inf = 1e8;

vector<int> get_digit(int x) {
    vector<int>Ans;
    while(x > 0) {
        if (x % 10 != 0) Ans.push_back(x % 10);
        x /= 10;
    }
    sort(Ans.begin(), Ans.end());
    Ans.erase(unique(Ans.begin(), Ans.end()), Ans.end());
    return Ans;
}

int dp(int n) {
    // min step to get x from 0 is Min[x];
    vector<int>Min(n + 1, inf);
    Min[0] = 0; 
    for (int i = 1; i <= n; i++) {
        vector<int>V = get_digit(i);
        for (auto x : V) {
            Min[i] = min(Min[i], 1 + Min[i - x]);
        }
    }
    return Min[n];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    cout << dp(n) << endl;
    
    
    return 0;
} 