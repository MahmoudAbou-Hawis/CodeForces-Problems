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

double getDist(pair<int,int>x,pair<int,int>y)
{
    int a = x.first - y.first;
    ll b = a*a;
    int c = x.second - y.second;
    ll d = c*c;
    return sqrt(b+d); 
} 

int main()
 {
    setIO();
    int n,m;
    double x;
    cin >> n >> m >>x;
    vector<vector<pair<int,int>>>v(30);
    vector<int>chrs(30,-1);
    char c;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ;j++)
        {
            cin >> c;
            if(c == 'S')
            {
                v[29].push_back({i,j});
            }
            else
            {
                v[c-'a'].push_back({i,j});
            }
        }
    }
    
    int l;
    cin >>l;
    string str;
    cin >> str; 
    int cnt = 0;
    for(int i = 0 ; i < l; i++)
    {
        if(str[i] < 'a')
        {
            if(v[str[i]-'A'].size() == 0 || v[29].size() ==0)
            {
                cout << -1;
                return 0;
            }
            if(chrs[str[i]-'A'] == -1)
            {
                unsigned int mn = -1;
                
                for(int ie = 0 ; ie < v[str[i] -'A'].size() ; ie++)
                {
                    for(int j = 0 ;j < v[29].size() ; j++)
                    {
                       double result = getDist(v[str[i]-'A'][ie],v[29][j]); 
                        if(result > x)
                        {
                            mn = min(mn,1U);
                        }
                        else
                        {
                            mn = 0;
                        }
                    }
                    
                } 
                chrs[str[i]-'A'] = mn;
                
            }
            cnt += chrs[str[i]-'A'];
        }
        else
        {
            if(v[str[i]-'a'].size() == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << cnt;

    return 0;
}