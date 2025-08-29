#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> tick(n);
    vector<ll> maxp(m);
    multiset<ll> ms;

    for (auto &it : tick)
    {
        cin >> it;
        ms.insert(it);
    }
    for (auto &it : maxp)
    {
        cin >> it;
    }

    for (int i = 0; i < m; i++)
    {
        auto it = ms.lower_bound(maxp[i]);
        if (*it == maxp[i])
        {
            cout << *it << endl;
            ms.erase(it);
        }
        else if (it != ms.begin())
        {
            --it;
            if (*it < maxp[i])
            {
                cout << *it << endl;
                ms.erase(it);
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}