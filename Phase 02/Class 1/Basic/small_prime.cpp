#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 9;

int Sp[nn];
vector<int>Prime;
vector<bool>Gone(nn, false);
vector<int> Pf[nn];

void prec() {
    for (int i = 2; i * i < nn - 2; i++) {
        if (!Gone[i]) {
            for (int j = i * i; j < nn - 2; j += i) {
                Gone[j] = true;
            }
        }
    }

    for (int i = 2; i < nn - 2; i++) {
        if (!Gone[i]) {
            Prime.push_back(i);
        }
    }

    for (int i = 1; i < nn - 2; i++) {
        Sp[i] = i;
    }
    for (int i = 2; i * i < nn - 2; i++) {
        if (Sp[i] == i) {
            for (int j = i * i; j < nn - 2; j += i) {
                Sp[j] = min(Sp[j], i);
            }
        }
    }

    for (int i = 2; i < nn - 2; i++) {
        int n = i;
        while(n > 1) {
            Pf[i].push_back(Sp[n]);
            n /= Sp[n];
        }
    }
}

int32_t main() {   
    ios_base::sync_with_stdio(0);
    prec();

    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        for (auto x : Pf[n]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
} 