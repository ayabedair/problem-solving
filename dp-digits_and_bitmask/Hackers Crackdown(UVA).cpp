#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define mod 1000000007
#define int long long

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int sub(int a, int b, int m) {
    return ((a % m) - (b % m) + m) % m;
}

int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
// int n, k, mx = LONG_MAX;
// vector<int> levels, vis;
vector<vector<int>> adj;
vector<int>vis;
int n, m, sz;
int dp[1 << 17], node_and_neighbors[17], final[1 << 17];

int rec(int mask) {
    if (mask == 0) return 0;

    if (~dp[mask]) return dp[mask];

    int ans = 0;
    for (int submask = mask; submask; submask = (submask-1) & mask) {
            ans = max(ans, rec(mask ^ submask) + (final[submask] == (1 << n) - 1));
    }


    return dp[mask] = ans;
}



void solve() {
    int tc = 1;
    while (cin >> n && n != 0) {
        memset(dp, -1, sizeof(dp));
        memset(node_and_neighbors, 0, sizeof(node_and_neighbors));
        for (int i = 0; i < n; i++) {
            cin >> m;
            int u;
            node_and_neighbors[i] |= (1 << i); // node
            for (int j = 0; j < m; j++) {
                cin >> u;
                node_and_neighbors[i] |= (1 << u); // neighbours
            }
        }

        for (int msk = 0; msk < (1 << n); msk++) {
            final[msk] = 0;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & msk) {
                    final[msk] |= node_and_neighbors[i];
                }
            }
        }
        cout << "Case " << tc++ << ": " << rec((1 << n) - 1) << endl;
    }


}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
