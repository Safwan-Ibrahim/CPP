#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int nn = 2e5 + 17;
int n, k, A[nn], Suffix_mx_index[nn];
ll Kth_sum[nn];

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        if (i >= k) {
            if (i > k) sum -= A[i - k];
            Kth_sum[i - k + 1] = sum;
        }
    }

    ll mx = -1, id = -1;
    for (int i = n - k + 1; i >= 1; i--) {
        if (Kth_sum[i] >= mx) {
            mx = Kth_sum[i];
            id = i;
        }
        Suffix_mx_index[i] = id;
    }

    mx = -1;
    for (int i = 1; i <= n - 2 * k + 1; i++) {
        mx = max(mx, Kth_sum[i] + Kth_sum[Suffix_mx_index[i + k]]);
    }

    for (int i = 1; i <= n - 2 * k + 1; i++) {
        if (mx == Kth_sum[i] + Kth_sum[Suffix_mx_index[i + k]]) {
            cout << i << " " << Suffix_mx_index[i + k] << endl; break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
}