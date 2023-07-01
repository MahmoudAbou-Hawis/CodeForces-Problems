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
int n;
vector<ll>v ;
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;   
int dx[] = {0,1,0,1,-1,0,-1,-1,1};
int dy[] = {0,1,1,0,0,-1,-1,1,-1};
void input()
{
    cin>>n;
    v = vector<ll>(n);
    for(auto &i : v)
    {
        cin>>i;
    }
}
void solve()
{
    ll result = INT64_MAX;
    for(int i = 0 ; i < 9 ; ++i)
    {
        ll diff = (v[1]+dx[i] ) - (v[0] + dy[i]);
        ll counter = abs(dx[i]) + abs(dy[i]);
        ll last = v[1]+dx[i];
        for(int e = 2 ; e < n ; e++)
        {
            ll NewNumber = last + diff;
            if(abs(NewNumber - v[e])>1)
            {
                counter = INT64_MAX;
                break;
            }
            counter+=abs(NewNumber - v[e]);
            last = NewNumber;
        }
        result = min(result,counter);
    }
    cout<<((result == INT64_MAX)?-1:result);

}
int main()
{
    Created By Sofar
    input();
    solve();

    return 0;
}


