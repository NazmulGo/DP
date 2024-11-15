// reach 1,1 to n, m on a matix in min_cost
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
ll inf = 1e10;
const double eps = 1e-9;
const int N = 100;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

ll n, m; 
ll cost[N][N], dp[N][N];

ll min_cost(ll i, ll j)
{
    if(dp[i][j] != -1) return dp[i][j];
    if(i == n and j == m) return cost[i][j];
    if(i == n+1 or j == m+1) return inf;
    ll ans = min_cost(i,j+1) + cost[i][j];
    ans = min(ans, min_cost(i+1, j) + cost[i][j]);
    return dp[i][j] = ans;
}

void solve()
{
    mem(dp, -1);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << min_cost(1,1) << endl;
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
