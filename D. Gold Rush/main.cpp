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
bool bfs(int start ,int tar)
{
    if(tar > start)return false;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        if(temp == tar)
        {
            return true;
        }
        if(temp%3 == 0)
        {
            int x = temp/3;
            if(x >= tar)
            q.push(x);
            if(2*x >= tar)
            q.push(2*x);
        }
    }
    return false;
}
int main()
{
    Created By Sofar
    int t; 
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<(bfs(n,m)?"YES\n":"NO\n");
    }
    return 0;
}