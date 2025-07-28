// Created on: 2025-07-27 20:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

bool good(vector<int>V) {
    for (int i = 0; i + 4 < V.size(); i++) {
        if (V[i] < V[i + 1] && V[i + 1] < V[i + 2] && V[i + 2] < V[i + 3] && V[i + 3] < V[i + 4]) return false;
        if (V[i] > V[i + 1] && V[i + 1] > V[i + 2] && V[i + 2] > V[i + 3] && V[i + 3] > V[i + 4]) return false;
    }
    return true;
}

vector<int>B;

string Ans(int st) {
    B.clear();
    string S;
    for (int i = 1, j = n; i <= j;) {
        if (st % 2) {
            if (A[i] < A[j]) {
                B.push_back(A[i]);
                S.push_back('L'); i++;
            }
            else {
                B.push_back(A[j]);
                S.push_back('R'); j--;
            }
        }
        else {
            if (A[i] < A[j]) {
                B.push_back(A[j]);
                S.push_back('R'); j--;
            }
            else {
                B.push_back(A[i]);
                S.push_back('L'); i++;
            }
        }
        st++;
    }
    return S;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    string S = Ans(1);
    cout << S << endl;
    assert(good(B));
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 