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
ll total_sum(ll x)
{
    return (x*(x+1))/2;
}
vector<int>perumation;
int main()
{
    Created By Sofar
    int n;
    cin>>n;
    vector<ll>v(n-1) ;
    ll last = 0 ;
    ll total = 0;
    perumation.pb(0);
    for(auto &i :v )
    {
        cin>>i;
        perumation.pb(last + i);
        total+=last + i;
        last = last + i;
    }
    total*=-1;
    ll _totalSum = total_sum(n);
    if((_totalSum + total )%n != 0 )
    {
        cout<<-1;
        return 0;
    }
    ll a = (_totalSum + total)/n;
    ll sz = perumation.size();
    vector<bool>freq(2*1e5+20 , 0);
    bool ans = true;
    for(int i = 0 ; i < sz ;i++)
    {
        perumation[i]=perumation[i]+a;
        if(perumation[i]<0 || perumation[i] >n || freq[perumation[i]])
        {
            ans = false;
            break;
        }
        freq[perumation[i]] =true;
    }
    if(ans)
    {
        for(auto &i :perumation)
        {
            cout<<i<<" ";
        }
    }
    else
    {
        cout<<-1;
    }
    return 0;
}


