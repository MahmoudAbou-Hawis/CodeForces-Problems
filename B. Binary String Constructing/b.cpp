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
     
int main(){
    Created By Tourists
    int a,b,c;
    cin>>a>>b>>c;
    string st = "";
    for(int i = 0 ; i < c ;i++)
    {
       st += (i&1)?'0':'1';
       if(i&1)a--;
       else b--;
    } 
    if(b==0)reverse(all(st));
    if(c&1)
    {
        for(int i = 0 ; i < b ;i++)st+='1';
        for(int i = 0 ; i < a ;i++)st+='0';
    }
    else
    {
         for(int i = 0 ; i < a ;i++)st+='0';
         for(int i = 0 ; i < b ;i++)st+='1';
    }
    cout<<st;
    return 0;
}


