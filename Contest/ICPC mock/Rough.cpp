/*
 *Copyhi (c) Swadheen Islam Robi (SIR01)
 *Created on Fri Nov 08 2024 6:00:43 PM
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pie 2*(acos(0.0))
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pb push_back
#define endl "\n"
#define lcm(a,b) (a*b)/(__gcd<ll>(a,b))
#define mod 1000000007
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define ALLAHU_AKBAR ios::sync_with_stdio(false); cin.tie(nullptr);

#define db double

db rt(db a) {
    db l = 0, r = a;
    int it = 60;
    db ans = 0;
    while(it--) {
        db m = (l + r) / 2;
        if (m * m <= a) {
            r = m;
            ans = m;
        }
        else {
            l = m;
        }
    }
    return ans;
}
db solve(db sa) {
    db lo = 0.0, hi = 1e9;
    db mv = 0.0;


    int it = 100;    
    while (it--) {
        db a = (lo + hi)/2;
        db s = (sa - a * a)/(2*a);
        
        if (s <= 0) {
            hi = a;
            continue;
        }
        db h = rt(s * s - (a / 2) * (a / 2));
        
        db vol = (1.0 / 3.0) * a * a * h;
        mv = max(mv, vol);
        
        if (vol < mv) {
            hi = a;
        } else {
            lo = a;
        }
    }
    return mv;
}

int main() {
    double sa;
    while (cin >> sa && sa >= 0) {
        db vol = solve(sa);
        cout << fixed << setprecision(4)<< vol << "\n";
    }
    return 0;
}