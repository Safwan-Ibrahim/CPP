// Created on: 2025-05-18 15:44
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<vector<int>>V;
vector<bool>Taken(5, false);
int n;



void rec(vector<int>A) {
    if (A.size() == n) {
        V.push_back(A);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (Taken[i]) continue;
        A.push_back(i);
        Taken[i] = true;
        rec(A);
        Taken[i] = false;
        A.pop_back();
    }
    return;
} 

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    rec({});
    for (auto v : V) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}