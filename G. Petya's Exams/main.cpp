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
    int n,m;
    cin>>n>>m;
    vector<pair<pi,pi>>v;
    vector<int>result(n+1,0);
    for(int i = 0 ; i  < m ; i++)
    {
        int si,di,ci;
        cin>>si>>di>>ci;
        result[di] = m+1;
        v.pb({{di,si},{ci,i+1}});
    }
    sort(v.begin(),v.end());
    bool flag =true;
    for(auto &i : v)
    {
        for(int e = i.f.s ; e < i.f.f && i.s.f; e++)
        {
            if(result[e]==0)
            {
                result[e] = i.s.s;
                i.s.f--;
            }

        }
        if(i.s.f !=0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        for(int i = 1 ; i  <= n ; i++)cout<<result[i]<<' ';
    }
    else
    {
        cout<<-1;
    }
    return 0;
}


