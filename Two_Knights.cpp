#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll k)
{
    ll n = k * k;
    ll nC2 = n * (n - 1) / 2;
    ll knightCantBePlaced = 2 * 2 * (k - 1) * (k - 2);
    ll ans = nC2 - knightCantBePlaced;
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << solve(i) << endl;
    }
    return 0;
}
