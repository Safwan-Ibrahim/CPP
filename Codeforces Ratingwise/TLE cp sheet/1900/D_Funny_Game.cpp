// Created on: 2025-12-17 14:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2000 + 17;
int n, A[nn];

#define db(x, ...) _db(x, #x, ##__VA_ARGS__)

template<typename T>
void _db(T val, const char* name) {
    cerr.write(name, strcspn(name,"[")) << " = " << val << endl;
}

template<typename T, typename... Args>
void _db(T val, const char* name, Args... args) {
    cerr.write(name, strcspn(name,"[")); 
    ((cerr << "[" << args << "]"), ...);
    cerr << " = " << val << endl;
}

struct DSU {
    vector<int> Par, Size;
    int c;

    DSU(int n) : Par(n + 1), Size(n + 1, 1), c(n) {
        for (int i = 1; i <= n; i++) Par[i] = i;;
    }

    int find(int v) {
        if (Par[v] == v) return v;
        else return Par[v] = find(Par[v]);
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int get_size(int v) {
        return Size[find(v)];
    }

    int count() {
        return c;
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        c--; 
        if (Size[a] > Size[b]) swap(a, b); 
        Par[a] = b;
        Size[b] += Size[a];
    }
};

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    DSU D(n);
    vector<int> Ans;

    int m = n - 1;
    vector<vector<int>> Mc(m); // modulo class
    for (int i = m; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            Mc[A[j] % i].push_back(j);
        }

        for (int j = 0; j < i; j++) {

            int lp = 0;
            for (int k = 0; k < Mc[j].size(); k++) {
                if (D.find(Mc[j][k]) == Mc[j][k]) {
                    if (!lp) {
                        lp = Mc[j][k];
                    }
                    else {
                        D.merge(Mc[j][k], lp);
                        db(lp);
                        db(Mc[j][k], j, k);
                        Ans.push_back(Mc[j][k]);
                        Ans.push_back(lp);
                        goto here;
                    }
                }
            }

        }

        here:
        for (int j = 0; j < i; j++) {
            Mc[j].clear();
        }
    }


    cout << "YES\n";
    reverse(Ans.begin(), Ans.end());
    for (int i = 0; i + 1 < Ans.size(); i += 2) {
        cout << Ans[i] << " " << Ans[i + 1] << endl;
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