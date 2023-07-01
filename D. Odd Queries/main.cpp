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
    int t,n,q,l,r,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        vector<int>arr(n);
        for(int i = 0 ; i < n ;i++)
        {
            cin>>arr[i];
            if(i!=0)
            {
                arr[i] += arr[i-1];
            }
        }
        for(int w = 0 ;w < q ;w++)
        {
            cin>>l>>r>>k;
            int diff = arr[r-1] - ((l-1)?arr[l-2]:0);
            int remainArr = arr[n-1] - diff;
            int Total = remainArr + (k*(r-l+1));
            cout << ((Total&1)?"YES\n":"NO\n");
        }
    }
    return 0;
}