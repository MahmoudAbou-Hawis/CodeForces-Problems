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
    int n,k;
    cin>>n>>k;
    int target = n/k;
    vector<int>v(n);
    map<int , vector<int>>m;
    map<int,queue<int>>reminders;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>v[i];
        if(sz(m[v[i]%k]) < target)
        {
            m[v[i]%k].pb(i);
        }
        else
        {
            reminders[v[i]%k].push(i);
        }
    }

    ll result = 0;
    int l = 0;
    for(auto &[reminder,array] : reminders)
    {
       while(l < k &&l<reminder)l++;
       while(!array.empty())
        {
            while(m[l%k].size() == target)l++;
            int idx = array.front();
            array.pop();
            long diff = l%k - reminder;
            int New = (diff > 0)?diff:diff+k;
            v[idx]+=New;
            result+=New;
            m[l%k].pb(idx);
        }
    }
    cout<<result<<'\n';
    for(int i = 0 ; i < n ;i++)cout<<v[i]<< " ";
    return 0;
}