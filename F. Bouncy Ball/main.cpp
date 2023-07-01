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
int  n,m,i,j,i2,j2;
string str;
int solve()
{
    bool found = false;
     int numberOfBounce = 0;
     int vis[n+150][m+150] = {0};
     bool reflect; 
    pi p((str[0]=='D')?1:-1,(str[1]=='R')?1:-1);
    while(vis[i][j] < 4)
    {
         vis[i][j]++;
        reflect = false;

        if((i == n && p.first > 0)|| (i == 1 && p.first < 0) )
        {
            p.first *=-1; 
            reflect =true;
        }
        if((j == 1 && p.second <0 ) ||(j==m && p.second > 0 ))
        {
            p.second *= -1;
            reflect   = true;
        }
        if(i == i2 && j == j2)
        {
            found = true;
            break;
        }
        i+=p.first;
        j+=p.second;
        if(reflect)numberOfBounce++;
     }
     return ((found)?numberOfBounce:-1);
}
int main()
{
    Created By Sofar
    int t;
    cin>>t;
    while(t--)
    {

        cin>>n>>m>>i>>j>>i2>>j2>>str;
        cout<<solve()<<'\n';
    }
    return 0;
}
