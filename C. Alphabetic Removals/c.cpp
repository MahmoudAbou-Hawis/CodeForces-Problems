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
const int N=1e6;
queue<int>v[30];
bool freq[N];
int main(){
    Created By Tourists
    int n,k;
    cin>>n>>k;
    string a= "";
    char ch;
    for(int i =  0; i < n ;i++)
    {
        cin>>ch;
        a+=ch;
        v[ch-'a'].push(i);
    }
    int i = 0;
    while(k)
    {
        if(!v[i].empty())
        {
            freq[v[i].front()] = 1;
            v[i].pop();
            k--;
        }
        else
        {
            i++;
        }

    }
    for(int i = 0; i < n ;i++)
    {
        if(!freq[i])
        {
            cout<<a[i];
        }
    }

    return 0;
}


