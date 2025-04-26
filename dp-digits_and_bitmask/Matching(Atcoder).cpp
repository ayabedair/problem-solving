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
vector<int> levels, vis;
vector<vector<int>> grid;
vector<int> nums;
int n;
int dp[22][1 << 21];
int rec(int j, int mask) {
    if (__builtin_popcount(mask) == n && j == n) {
        return 1;
    }
    if (~dp[j][mask]) return dp[j][mask];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)) && grid[j][i])
            ans = add(ans, rec(j + 1, mask | (1 << i)), mod);
    }
    return dp[j][mask] = ans;
}


void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    grid.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << rec(0, 0);
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
