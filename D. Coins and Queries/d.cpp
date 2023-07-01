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
unsigned countBits(unsigned int number)
{    
    return (int)log2(number)+1;
}
int main(){
    Created By Tourists
    vector<ll>freq(35,0);
    int n,q;
    cin>>n>>q;
    ll number; 
    for(int i =0 ; i <n ;++i)
    {
        cin>>number;
        freq[countBits(number)]++;
    }
    while(q--)
    {
        ll temp;
        cin>>temp;
        int counter = 0;
        for(ll i = 31 ; i>=0 && temp > 0;i--)
        {
            if((1<<i) <= temp && freq[i+1]>0)
            {
                ll reminder = temp%(1<<i);
                ll looping = (temp-reminder)/(1<<i);
                temp-=min(looping,freq[i+1]) * (1<<i);
                counter+=min(looping,freq[i+1]);
            }
        }
        if(temp!=0)cout<<-1<<'\n';
        else cout<<counter<<'\n';

    }
    return 0;
}



