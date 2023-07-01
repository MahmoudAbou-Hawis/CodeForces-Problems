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
void solve(vector<int>&v)
{
   ll start = 1 , end = v.size()-2 ,mid ,ans =0;
    while(start <= end)
    {
        mid = (start +end )/2;
        cout<< "? "<<(mid - start +1)<< ' ' ;
        for(ll i = start ; i<= mid ; i++)
        {
            cout<< i << ' ';
        }
        cout<<endl;
        ll input; 
        cin>>input;
        if(input == v[mid] - v[start-1])
        {
            start = mid+1;
        }
        else 
        {
            end = mid-1;
            ans = mid;
        }
    }
    cout << "! " << ans <<endl ;
}
int main()
{
    Created By Sofar
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n+2 ,0);
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>v[i];
            v[i]+=v[i-1];
        }
        solve(v);
    }
    return 0;
} 