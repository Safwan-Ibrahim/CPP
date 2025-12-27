// Created on: 2025-12-16 06:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    vector<int> A(n + 1, 0), V(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        V[A[i]] = i;
    }

    set<int> Mx;
    for (int i = 1; i <= n; i++) {
        if (V[i]) Mx.insert(V[i]);
    }
    
    int s = Mx.size();
    vector<bool> Done(n + 1, 0);
    map<int, deque<int>> C;
    vector<int> Ans;

    for (int _ = 1, r = 1, l = 1; _ <= s; _++) {

        while (r <= n && r <= *Mx.begin()) {
            if (!Done[A[r]]) {
                C[A[r]].push_back(r);
            }
            r++;
        }

        if (_ & 1) {
            auto p = *C.rbegin();
            Ans.push_back(p.first);
            int id =  p.second.front();

            C.erase(p.first);
            while (l <= id) {
                if (C.find(A[l]) != C.end()) {
                    C[A[l]].pop_front();
                    if (C[A[l]].empty()) C.erase(A[l]);
                }
                l++;
            }
        }
        else {
            auto p = *C.begin();
            Ans.push_back(p.first);
            int id =  p.second.front();

            C.erase(p.first);
            while (l <= id) {
                if (C.find(A[l]) != C.end()) {
                    C[A[l]].pop_front();
                    if (C[A[l]].empty()) C.erase(A[l]);
                }
                l++;
            }
        }

        Done[Ans.back()] = 1;
        Mx.erase(V[Ans.back()]);
    }

    cout << Ans.size() << "\n";
    for (auto x : Ans) {
        cout << x << " ";
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