// Created on: 2025-06-13 22:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1007;
int pn, Final[nn], Position[nn], Index_of_pos[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> pn;
    for (int i = 1; i <= pn; i++) {
        cin >> Final[i];
        Position[i] = i;
        Index_of_pos[Position[i]] = i;
    }

    vector<int>Ans;
    for (int last = pn; last >= 1; last--) {
        int id_of_last = Index_of_pos[Final[last]];
        for (int i = id_of_last - 1; i >= 1; i--) {
            Ans.push_back(Final[last]);
            Ans.push_back(Position[i]);
        }
        for (int i = 1; i <= id_of_last - 1; i++) {
            Ans.push_back(Position[i]);
            Ans.push_back(Final[last]);
        }
        for (int i = id_of_last + 1; i <= last; i++) {
            Ans.push_back(Position[i]);
            Ans.push_back(Final[last]);
            swap(Position[i - 1], Position[i]);
            swap(Index_of_pos[Position[i]], Index_of_pos[Position[i - 1]]);
        }
    }

    cout << Ans.size() / 2 << endl;
    for (int i = 0; i < Ans.size(); i += 2) {
        cout << Ans[i] << " " << Ans[i + 1] << endl;
    }

    return 0;
} 