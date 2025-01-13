#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

double look(double x) {
    return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
} 

void solve()
{
    double y; cin >> y;
    double lo = 0, hi = 100, ans = -1;
    int it = 60;
    while(it--) {
        double mid = (hi+lo)/2;
        int check = look(mid);
        if (check >= y ){
            ans = mid;
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    if (ans == -1) {
        cout << "No solution!\n";
    }
    else {
        cout << fixed << setprecision(4) << ans << endl;
    }
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 