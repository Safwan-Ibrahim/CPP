// Created on: 2025-07-27 20:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool yes(vector<int>V) {
    for (int i = 2; i < V.size(); i++) {
        if (V[i] > max(V[i - 1], V[i - 2])) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8};
    do {
        if (yes(V)) {
            for (auto x : V) {
                cout << x << " ";
            }
            cout << endl;
        }
    } while(next_permutation(V.begin(), V.end()));
    return 0;
} 