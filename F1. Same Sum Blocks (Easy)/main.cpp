#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Sofar cout.tie(0);
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
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
int main()
{
    Created By Sofar
    int n;
    cin>>n;
    vi v(n);
    for(auto &i :v)cin>>i;
    map<int,vector<pair<ll,ll>>>ans;
    for(int i = 0 ; i < n ; i++)
    {
        int sum = 0;
        for(int e = i ; e < n ;e++)
        {
            sum+=v[e];
            ans[sum].pb({i, e});

        }
    }
    vector<pair<ll,ll>>pairs;
    for(auto &sum : ans)
    {
        int sz = sum.s.size();
        vector<pair<ll,ll>>best;
        best.push_back(sum.second[0]);
        int currentIdx = 0;
        for (int i = 1; i < sz; i++)
        {
            if(sum.second[i].f > best[currentIdx].s)
            {
                best.pb(sum.s[i]);
                currentIdx++;
            }
            else
            {
                if(sum.second[i].s <= best[currentIdx].s)
                {
                    best.pop_back();
                    best.pb(sum.s[i]);
                }
            }
        }
        if(sz(best) > sz(pairs))pairs = best;
    }
    cout<<pairs.size()<<'\n';
    for(auto &i : pairs)
    {
        cout<<i.f+1<<" "<<i.s+1<<"\n";
    }

    return 0;
}