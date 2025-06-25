// Created on: 2025-04-21 17:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;

int n;
int a[nn], b[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    // We want a[i] == b[n - i + 1]
    int samePos = 0;
    vector<pair<int, int>> mismatches;

    for (int i = 1, j = n; i <= j; i++, j--) {
        if (a[i] == b[j]) continue;
        mismatches.push_back({i, j});
    }

    if (mismatches.size() % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> ans;

    // Fix mismatches greedily
    for (int i = 0; i < mismatches.size(); i += 2) {
        int x1 = mismatches[i].f, y1 = mismatches[i].s;
        int x2 = mismatches[i + 1].f, y2 = mismatches[i + 1].s;

        // Make sure a[x1] == b[y1] by swapping a[x1] with a[y2]
        swap(a[x1], a[x2]);
        ans.emplace_back(x1, x2);
    }

    // Validate result
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[n - i + 1]) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (auto &[x, y] : ans) cout << x << " " << y << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1; cin >> t;
    while (t--) Try();
    return 0;
}
