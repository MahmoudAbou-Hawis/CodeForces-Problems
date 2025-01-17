#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i, s, e) for (int i = s; i < e; i++)
#define fd(i, e, s) for (int i = e; i >= s; i--)
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "")
{
    Code By So_Far if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("");
    int n, b, d;
    cin >> n >> b >> d;
    int cnt = 0;
    int orange = 0;
    int wasted = 0;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> orange;
        if(orange > b)
        {
            continue;
        }
        if(wasted + orange > d)
        {
            cnt++;
            wasted = 0;
        }
        else
        {
            wasted += orange;
        }
    }
    cout << cnt;
    return 0;
}