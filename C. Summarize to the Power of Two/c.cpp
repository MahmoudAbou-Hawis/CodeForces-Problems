#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Tourists cout.tie(0);
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
unsigned int getBits(unsigned int number)
{
    return (int)log2(number)+1;
}
int main(){
    Created By Tourists
    int n;
    cin>>n;
    vector<ll>v(n);
    map<int,vi>m;
    int result = 0;
    int number = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>number;
        m[number].pb(i);
        v[i]=number;
    }
    for(int i = 0 ; i < n ; i++)
    {
        bool flag =false;
        for(int e = 31 ; e >= 0 ;e--)
        {
            if((1<<e) - v[i] >=0 && sz(m[(1<<e) - v[i]])>=1)
            {
               if((1<<e) - v[i] == v[i] && sz(m[v[i]])==1)
               {
                 continue;
               }
               flag = true ;
               break;
            }

        }
        if(!flag)result++;
    }
    cout<<result;
    return 0;
}


