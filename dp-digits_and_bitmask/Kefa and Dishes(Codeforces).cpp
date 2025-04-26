#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define MOD 1000000007
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
vector<int> levels, vis;
vector<vector<int>> adj;
vector<int> nums;
string s;
const int X = 19, Y = 19;
int n, m, k;
vector<int>val;
int grid[X][Y];
int dp[19][1 << 19];

int rec(int last, int mask) {
    if (__builtin_popcount(mask) >= m) return 0;

    if (~dp[last][mask]) return dp[last][mask];

    int ret = 0;
    for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) == 0) {
            ret = max(ret, rec(j, mask | (1 << j)) + val[j] + grid[last][j]);
        }
    }
    return dp[last][mask] = ret;
}

void solve() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    val.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < k; i++) {
        int x, y, v; cin >> x >> y >> v;
        x--; y--;
        grid[x][y] = v;
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, rec(i, (1 << i)) + val[i]);
    }

    cout << mx << endl;
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
