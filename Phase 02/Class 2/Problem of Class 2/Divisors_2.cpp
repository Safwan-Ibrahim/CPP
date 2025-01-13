// Created on: 2025-01-08 02:55
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 1;
int d[N];
bool no[N];
vector<int>ans;

void count_div() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            d[j]++;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            if (d[j] % d[i] != 0 || d[j] < 4) {
                no[j] = true;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (!no[i]) {
            ans.push_back(i);
        }
    }

}


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    count_div();

    for (int i = 108; i < ans.size(); i += 108) {
        cout << ans[i - 1] << endl;
    }
    return 0;
} 