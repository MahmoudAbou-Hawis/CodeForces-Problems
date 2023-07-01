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
    ll x,y;
    cin>>x>>y;
    if(y%x != 0)
    {
        cout<<-1 ;
        return 0;
    }
    y/=x;
    ll counter = 0;
    while(y %2 == 0 || y %3 ==0)
    {
        if(y%2 == 0 && ++counter)y/=2;
        if(y%3 == 0 && ++counter) y/=3;
    }
    cout<<((y==1)?counter:-1);
    return 0;
}


