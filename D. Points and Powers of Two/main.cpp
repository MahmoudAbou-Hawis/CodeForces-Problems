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
unsigned countBits(unsigned int number)
{    
    return (int)log2(number)+1;
}
int main()
{
    Created By Sofar
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0; i < n ; i++)
    {
        cin>>v[i];
    }
    sort(all(v));
    for(int i = 0 ; i < n ; i++)
    {
        for(int e =  0; e<31 ; e++)
        {
            if(binary_search(all(v),v[i]+(1LL<<e)) && binary_search(all(v),v[i]+2*(1LL<<e)))
            {
                cout<<3<<'\n';
                cout<<v[i] << " "<<v[i]+(1LL<<e) << " "<<v[i]+2*(1LL<<e);
                return 0 ;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int e =  0; e<31 ; e++)
        {
            if(binary_search(all(v),v[i]+(1LL<<e)))
            {
                cout<<2<<'\n';
                cout<<v[i] << " "<<v[i]+(1LL<<e);
                return 0 ;
            }
        }
    }
    cout<<1<<'\n'<<v[0];

    return 0;
}
