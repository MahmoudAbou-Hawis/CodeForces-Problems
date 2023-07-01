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
string substring(string &str,int firstIdx , int secondIdx)
{
    string result = "";
    for(int i = firstIdx ; i < secondIdx ;i++)
    {
        result+=str[i];
    }
    return result;
}
int main()
{
    Created By Sofar
    string str ;
    cin>>str;
    int len = str.size();
    int m;
    cin>>m;
    while (m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        k %= (r-l+1);
        l--;
        r--;
        str = substring(str,0,l)+ substring(str,(r+1-k),r+1)+ substring(str,(l),l+(r-l+1 -k))+ substring(str,r+1,len);
    }
    cout<<str<<'\n';
    return 0;
}


