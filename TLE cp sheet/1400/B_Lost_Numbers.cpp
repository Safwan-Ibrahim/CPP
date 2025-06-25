// Created on: 2025-05-25 16:02
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int ans; cin >> ans;
    return ans;
}

int32_t main() {
    vector<int>V = {4, 8, 15, 16, 23, 42};
    map<int, pair<int, int>>Mp;
    for (int i = 0; i < V.size(); i++) {
        for (int j = i + 1; j < V.size(); j++) {
            Mp[V[i] * V[j]] = {V[i], V[j]};
        }
    }

    vector<int>Ans;
    int v1 = query(1, 2), v2 = query(2, 3);
    Ans.push_back(Mp[v1].first);
    Ans.push_back(Mp[v1].second);
    if (Ans[0] == Mp[v2].first || Ans[0] == Mp[v2].second) {
        swap(Ans[0], Ans[1]);
    }
    if (Mp[v2].second == Ans[0] || Mp[v2].second == Ans[1]) {
        Ans.push_back(Mp[v2].first);
    }
    else {
        Ans.push_back(Mp[v2].second);
    }
    

    v1 = query(4, 5), v2 = query(5, 6);
    Ans.push_back(Mp[v1].first);
    Ans.push_back(Mp[v1].second);
    if (Ans[3] == Mp[v2].first || Ans[3] == Mp[v2].second) {
        swap(Ans[3], Ans[4]);
    }
    if (Mp[v2].second == Ans[3] || Mp[v2].second == Ans[4]) {
        Ans.push_back(Mp[v2].first);
    }
    else {
        Ans.push_back(Mp[v2].second);
    }

    cout << "! ";
    for (auto x : Ans) {
        cout << x << " ";
    } 
    cout << endl;

    return 0;
} 