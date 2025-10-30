// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;

    set<int> St;
    vector<int> A(n);

    for (int i = 1; i <= n; i++) {
        St.insert(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    for (auto x : A) {
        if (St.find(x) != St.end()) {
            St.erase(x);
        }
    }

    int done = 0;
    for (auto x : St) {
        if (done == k) break;
        A.push_back(x);
        done++;
    }

    vector<int> need;
    set<int> Have;

    for (int i = A.size() - 1; i >= 0; i--) {
        if (Have.find(A[i]) == Have.end()) {
            need.push_back(A[i]);
            Have.insert(A[i]);
        }
    }

    int i = 2;
    swap(need[0], need[1]);
    while (done < k) {
        done++;
        A.push_back(need[i++]);
        i %= need.size();
    }

    for (int i = n; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 