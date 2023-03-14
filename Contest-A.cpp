//Glorify the name of your lord
#include<bits/stdc++.h>
using namespace std;
#define      PI                    2*acos(0)
#define      ll                    long long
#define      pii                   pair<int,int>
#define      nline                 "\n"
#define      Min_Heap              priority_queue<int, vector<int>, greater<int>>
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
    ll n, x; cin >> n >> x;
    vector<int>a(n + 2);
    a[0] = 0, a[n + 1] = x;
    //for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int mx = -1e9;
    for (int i = 1; i <= n + 1; i++) {
        mx = max(a[i] - a[i - 1], mx);
    }
    //cout << (double)mx / 2 << nline;
    cout << n + x;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    RunFast

    ll tc = 1;
    //cin >> tc;
    while (tc--)
    {
        run_test_case();
        //return 0 ;

    }


}