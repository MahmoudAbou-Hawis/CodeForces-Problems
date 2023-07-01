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
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<vector<ll>>PrefixSum(1010,vector<ll>(1010,0));
        for(int i = 0 ; i < n ; i++)
        {
            int x,y;
            cin>>x>>y;
            PrefixSum[x][y] += x*y; 
        }
        for(int i = 1 ; i < 1010 ; i++)
        {
            for(int e = 1 ; e < 1010 ;e++)
            {
                PrefixSum[i][e] = PrefixSum[i][e] + PrefixSum[i-1][e]
                                 +PrefixSum[i][e-1] - PrefixSum[i-1][e-1];
            }
        }
        while(q--)
        {
           int hs,ws,hb,wb;
           cin>>hs>>ws>>hb>>wb;
           cout<<PrefixSum[hs][ws]

				- PrefixSum[hb-1][ws]

				- PrefixSum[hs][ wb- 1]

				+ PrefixSum[hb - 1][wb - 1] << '\n';

        }

    }

    return 0;
}
