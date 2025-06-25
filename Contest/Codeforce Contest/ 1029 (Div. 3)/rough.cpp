// code check 
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define PI acos(-1.0)
#define pb push_back
#define mp make_pair
#define vi vector<ll>
#define maxn 500005
#define mod 1000000007
#define inf 1000000007
#define pii pair<ll,ll>
#define vii vector<pii>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lcm(a,b) ((a*b)/__gcd(a,b));
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define setbits(x) __builtin_popcountll(x)
#define cnt_zero(x) __builtin_clzll(x)
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define rev_str(str) reverse(str.begin(),str.end());
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define printp(v) for(auto e:v) cout<<e.first<<" "<<e.second<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
bool sortByValue(const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}
const int N = 1e5+7;
const ll M =998244353;
bool cmp(const pair<ll,ll>& a,const pair<ll,ll>&b){
    if(a.first != b.first) return a.first< b.first;
    return a.second<b.second;
}
bool is_Prime(ll n) {
    if (n < 2) return false; 
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false; 
    }
    return true; 
}
long long Pow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans*=a;
        b>>=1;
        a*=a;
    }
    return ans;
}
long long modPow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
// lies between divisor of a and b == GCD
// prime factorization while the taking the maximum power == LCM...
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
 
ll Lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
void solve() {
    ll n;cin>>n;
    vi p(n);
    map<ll,ll>mpp;
    rep(i,0,n){
        cin>>p[i];
    }
    //print(p);
    ll ans = 1;
    rep(i,0,n){
        mpp[p[i]]++;
        map<ll,ll>mpp1;
        ll j = i+1;
        ll cnt = sz(mpp);
        while (j<n && cnt>0)
        {
            if(mpp[p[j]]>0){
                mpp1[p[j]]++;
                cnt--;
                mpp.erase(p[j]);
                if(cnt==0) break;
            }
            else{
                mpp1[p[j]]++;
            }
            j++;
        }
        mpp.clear();
        mpp = mpp1;
        if(cnt==0){
            ans++;
        }
        i = j-1;
    }
    cout<<ans<<endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
