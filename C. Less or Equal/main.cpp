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
    int n ,k;
    cin>>n>>k;
    vi v;
    int number;
    for(int i = 0 ; i < n ; i++ )
    {
        cin>>number;
        v.pb(number);
    }
    sort(v.begin(),v.end());
    v.pb(-1);
    if(k == 0)
    {
        if(v[0] == 1)cout<<-1;
        else cout<<v[0]-1;
        return 0;
    }
    cout<<((v[k-1] != v[k])?v[k-1]:-1);
    return 0;
}


