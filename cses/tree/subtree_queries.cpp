#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>

#define ll long long
#define eps 1e-8
#define MOD 1000000007

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

// change if necessary
#define MAXN 1000000

using namespace std;

int n, q;
int vals[MAXN];
vector<int> adj[MAXN];
ll bit[MAXN];
int in[MAXN];
int out[MAXN];
int t = 1;

void upd(int x, int v) {
    while (x < MAXN) {
        bit[x] += v;
        x += x & -x;
    }
}

ll qry(int x) {
    ll res = 0;
    while (x) {
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

void dfs(int v, int p) {
    in[v] = t++;
    upd(in[v], vals[v]);
    for (int e : adj[v]) {
        if (e != p) {
            dfs(e, v);
        }
    }
    out[v] = t++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            upd(in[s], -vals[s]);
            vals[s] = x;
            upd(in[s], vals[s]);
        } else {
            int s; cin >> s;
            cout << qry(out[s]) - qry(in[s] - 1) << '\n';
        }
    }

    return 0;
}
