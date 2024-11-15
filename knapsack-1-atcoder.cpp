#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define MOD 1000000007
#define vll vector<ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define mem(a,b) memset(a, b, sizeof(a))
#define co(n) cout << n << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fr(x, n) for (int i = x; i < n; ++i)
#define fraction(x) cout << fixed << setprecision(x)
#define Baba_Yaga ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
const double eps = 1e-9;
const int N = 105;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

ll n, max_w;
ll w[N], v[N];
ll dp[N][100005];

ll knap(ll i, ll now_weight)
{
    if(i == n+1) return 0;
    if(dp[i][now_weight] != -1) return dp[i][now_weight];
    ll ans = knap(i+1, now_weight);
    if(now_weight + w[i] <= max_w) ans = max(ans, knap(i+1, now_weight+w[i]) + v[i]);
    return dp[i][now_weight] = ans;
}

void solve()
{
    mem(dp, -1);
    cin >> n >> max_w;
    for(int i=1; i<=n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << knap(1, 0) << endl;
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
