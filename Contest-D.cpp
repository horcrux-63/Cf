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

// check for a bipartite graph (odd len cycle or even len cycle) using dfs
//if the graph is bipartite thn it has even len cycle else it has odd len cycle

// int col[1000005]; //make sure to make it -1 at every index

// bool checkbipartite(int node, int color, vector<vector<int>>&adj)
// {
//     col[node] = color;
//     cout << node << " " << color << nline;
//     for (auto& it : adj[node]) {
//         if (col[it] == -1) {
//             if (checkbipartite(it, !color, adj))
//                 return true;
//         }
//         else if (col[it] == color) {
//             return true;
//         }
//     }
//     return false;
// }
// // if false the graph is bipartite
// //usingBFS

// bool checkBipartite(int node, int color, vector<vector<int>>&adj)
// {
//     col[node] = color;
//     queue<pair<int, int>>q;
//     q.push({node, color});

//     while (!q.empty()) {
//         int node = q.front().first;
//         int color = q.front().second;
//         q.pop();

//         for (auto& it : adj[node]) {
//             if (col[node] == -1) {
//                 q.push({node, !color});
//                 col[it] = color;
//             }
//             else if (col[it] == color) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// //topological uisng dfs
// void topoSortHelper(int node, stack<int>&st)
// {
//     vis[node] = 1;

//     for (auto& it : node) {
//         if (!vis[it]) {
//             topoSortHelper(it, st);
//         }
//     }
//     st.push(node);
// }

// void topoSort() {
//     stack<int>st;
//     for (int i = 0; i < n; ++i) {
//         if (!vis[i]) {
//             topoSortHelper(i, st);
//         }
//     }

//     while (!st.empty()) {
//         cout << st.top() << " ";
//         st.pop();
//     }
// }

// //toposort using kahn's algorihtm(BFS)

// void topoSort()
// {
//     vector<int>inDegree(n, 0);
//     for (int i = 0; i < n; ++i) {
//         for (auto& it : adj[i]) {
//             inDegree[it]++;
//         }
//     }
//     queue<int>q;
//     for (int i = 0; i < n; ++i) {
//         if (inDegree[i] == 0) {
//             q.push(i);
//         }
//     }
//     while (!q.empty()) {
//         cout << q.front() << " ";
//         int node = q.front();
//         q.pop();

//         for (auto& it : adj[node]) {
//             inDegree[it]--;
//             if (inDegree[it] == 0) {
//                 q.push(it);
//             }
//         }
//     }
// }

// struct Node {
//     int u, v, w;
//     Node(int _u, int _v, int _w) {
//         u = _u;
//         v = _v;
//         w = _w;
//     }

// };

void pathprint(int n, vector<int>& par) {
    if (par[n] == -1) return;
    pathprint(par[n], par);
    cout << n << " ";
}

void djikstra(int src, int n, vector < vector<pair<int, int>>>& adj)
{
    vector<int>dist(n + 1, INT_MAX);
    vector<int>par(n + 1, -1);
    par[1] = 0;
    dist[src] = 0;
    priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto& it : adj[node]) {
            int adjNode  = it.first;
            int wt = it.second;

            if (w + wt < dist[adjNode]) {
                par[adjNode] = node;
                dist[adjNode] = w + wt;
                pq.push({w + wt, adjNode});
            }

        }
    }
    if (par[n] == -1) {
        cout << par[n] << nline;
        return;
    }
    // vector<int>ans;
    // ans.push_back(n);
    // while (par[n] != 0) {
    //     ans.push_back(par[n]);
    //     n = par[n];
    // }
    // reverse(ans.begin(), ans.end());
    // for (auto& it : ans) {
    //     cout << it << " ";
    // }
    pathprint(n, par);

}

void run_test_case() {
    ll n, m; cin >> n >> m;
    vector < vector<pair<int, int>>>adj(n + 1);
    for (int i = 0; i < n; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    djikstra(1, n, adj);

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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