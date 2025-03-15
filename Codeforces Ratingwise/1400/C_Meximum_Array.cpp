// Created on: 2025-02-27 02:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int n, A[N];
int Mp[N]; // rem to clear
vector<int>Ans; // rem to clear

void solve(int i) {
    if (i > n) {
        return;
    }
    map<int, int>Store;
    int x = 0;
    if (Mp[0] == 0) {
        for (int x = i; x <= n; x++) {
            Ans.push_back(0);
        }
        return;
    }
    for (int x = 0; x < N; x++) {
        if (Mp[x] > 0) {
            while(Store[x] == 0) {
                Store[A[i]]++;
                i++;
            }
        }
        else {
            Ans.push_back(x);
            for (auto [x, y] : Store) {
                Mp[x] -= y;
            }
            solve(i);
            return;
        }
    }
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Mp[A[i]]++;
    }
    
    solve(1);
    cout << Ans.size() << endl;
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    Ans.clear();

    for (int i = 1; i <= n; i++) {
        Mp[A[i]] = 0;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 