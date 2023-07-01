#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
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
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int main()
 {
    setIO();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>Even;
        vector<int>Odd;
        int num;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>num;
            if(num&1)Odd.push_back(num);
            else Even.push_back(num);
        }
        if(Even.size() < Odd.size())
        {
            int diff = Odd.size()-Even.size() ;
            for(int i = 0 ; i < diff; i++)
                Even.push_back(0);
        }
        else
        {
             int diff = Even.size()-Odd.size() ;
           for(int i = 0 ;i <  diff ; i++)
                Odd.push_back(0); 
        }
    
        sort(all(Odd));
        sort(all(Even),greater<int>());
        long Mihai  = 0;
        long Bianca = 0;
        bool flag = true;
        for(int i = 0 ; i < Even.size() ; i++)
        {
            Mihai += Even[i];
            if(Mihai <= Bianca)
            {
                flag = false;
                break;
            }
            Bianca+=Odd[i];
        }
        if(Bianca >= Mihai ) flag = false;
        cout<<((flag)?"YES\n":"NO\n");
 
    }

    return 0;
}