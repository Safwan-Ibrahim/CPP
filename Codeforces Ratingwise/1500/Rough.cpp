// Created on: 2025-04-13 13:15
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<vector<int>>Vector_of_all_subset;
    Vector_of_all_subset.push_back({});


    for (int i = 1; i <= n; i++) {
        int sz = Vector_of_all_subset.size(); 
        for (int j = 0; j < sz; j++) {
            vector<int>New_subset;
            for (auto x : Vector_of_all_subset[j]) {
                New_subset.push_back(x);
            }
            New_subset.push_back(A[i]);
            Vector_of_all_subset.push_back(New_subset);
        }
    }

    int ans = 0;
    for (auto Only_one_subset : Vector_of_all_subset) {
        ll sum = 0;
        for (auto x : Only_one_subset) {
            sum += x;
        }
        if (sum == 4) {
            ans++;
        }
    }















    // vector<vector<int>>V;
    // V.push_back({});
    // for (int i = 1; i <= n; i++) {
    //     int sz = V.size();
    //     for (int j = 0; j < sz; j++) {
    //         vector<int>T;
    //         for (auto y : V[j]) {
    //             T.push_back(y);
    //         }
    //         T.push_back(A[i]);
    //         V.push_back(T);
    //     }
    // }
    
    // for (auto x : V) {
    //     for (auto a : x) {
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }


    
    return 0;
} 