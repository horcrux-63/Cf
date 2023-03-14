//Glorify the name of your lord
#include<bits/stdc++.h>
using namespace std;
#define      PI                    2*acos(0)
#define      ll                    long long
#define      pii                   pair<ll,ll>
#define      nline                 "\n"
#define      Min_Heap              priority_queue<ll, vector<ll>, greater<ll>>
#define      forr(arr)             for (auto &x : (arr))
#define      all(x)                (x).begin(), (x).end()
#define      rall(x)               (x).rbegin(), (x).rend()
#define      gcd(x, y)             __gcd(x, y)
#define      lcm(x, y)             x *(y / gcd(x, y))
#define      MAX                   2000010
#define      MOD                   1000000007
#define      RunFast               ios::sync_with_stdio (0); cin.tie(0);

/*.......................................................................................................................*/
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*.......................................................................................................................*/

void run_test_case() {
    ll n, m; cin >> n >> m;
    vector < pair<ll, pair<ll, ll>>>adj;
    vector<ll>ans;
    vector<bool>vis(10000005, false);
    for (int i = 0; i < n; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        adj.push_back({w, {u, v}});
    }
    sort(adj.begin(), adj.end());
    set<int>mm;
    mm.insert(m);
    ans.push_back(m);
    vis[m] = 1;
    for (int i = 0; i < n; ++i) {
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        if (mm.count(u) > 0 || mm.count(v) > 0) {
            if (!vis[u]) ans.push_back(u);
            else if (!vis[v]) ans.push_back(v);
            vis[u] = 1;
            vis[v] = 1;
            mm.insert(u);
            mm.insert(v);
        }
    }
    cout << ans.size() << nline;
    int i = 0;
    for (auto& it :  ans) {
        if (i > 0) cout << ' ';
        cout << it;
        ++i;
    }
    cout << nline;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    RunFast

    ll tc = 1, cs = 1;
    cin >> tc;
    while (tc--)
    {
        cout << "Case " << cs++ << ":" << nline;
        run_test_case();
        //return 0 ;

    }


}