// n * m overall complexity 
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
const int N = 3005;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

string a, b;
ll dp[N][N];

ll lcs(ll i, ll j)
{
    if(i == (ll)a.size() || j == (ll) b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll score = 0;
    if(a[i] == b[j])
    {
        score = lcs(i+1, j+1) + 1;
    }
    score = max(score, lcs(i+1, j));
    score = max(score, lcs(i, j+1));
    return dp[i][j] = score;
}

void prr(ll i, ll j)
{
    if(i == (ll)a.size() || j == (ll) b.size()) return;
    if(a[i] == b[j])
    {
        cout << a[i];
        prr(i+1, j+1);
        return;
    }
    ll score = lcs(i+1, j);
    ll score_2 = lcs(i, j+1);

    if(score > score_2) prr(i+1, j);
    else prr(i, j+1);
}

void solve()
{
    mem(dp, -1);
    cin >> a >> b;
    // cout << lcs(0, 0) << endl;
    prr(0, 0);
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
