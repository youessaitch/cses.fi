#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;
// bottom up approach (iterative) as top bottom giving tle bcuz of the deep recursion tree

// TOP BOTTOM:

bool check(int i, int j, int n)
{
    if (i >= 0 && j >= 0 && i < n && j < n)
        return 1;
    else
        return 0;
}

ll solve(int i, int j, int n, vector<vector<char>> &v, vector<vector<int>> &dp)
{
    if (!check(i, j, n) || v[i][j] == '*')
        return 0;

    if ((i == n - 1) && (j == n - 1))
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];
    int right = solve(i, j + 1, n, v, dp);
    int down = solve(i + 1, j, n, v, dp);

    return dp[i][j] = (right + down) % mod;
}

int main()
{
    ll n;
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solve(0, 0, n, v, dp);
    cout << ans % mod << endl;
    return 0;
}

//----------------------------------------------------------------------------------

// BOTTOM UP:
bool check(int i, int j, int n)
{
    if (i >= 0 && j >= 0 && i < n && j < n)
        return 1;
    else
        return 0;
}

int main()
{
    ll n;
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = (v[0][0] == '.') ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int right = 0, down = 0;
            if (i == 0 && j == 0)
                continue;
            if (v[i][j] != '*')
            {
                if (check(i - 1, j, n))
                    right = dp[i - 1][j];
                if (check(i, j - 1, n))
                    down = dp[i][j - 1];
                dp[i][j] = (right + down) % mod;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n - 1][n - 1] % mod << endl;
    return 0;
}
