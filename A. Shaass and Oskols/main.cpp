#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

 
int main()
{
    setIO("");
    int n;
    cin >> n;
    vector<int> birds(n);

    for(auto &z : birds)
    {
        cin >> z;
    }

    int m;
    cin >> m;
    int a,b;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        int left  = b -1;
        int right = abs(birds[a - 1] - b);
        birds[ a - 1 ] = 0;
        if(a - 2 >=0)
        {
            birds[a - 2] += left;
        }
        if(a < n)
        {
            birds[a] += right;
        }

    }

    for(auto z : birds)
    {
        cout << z << '\n';
    }
    return 0;
}