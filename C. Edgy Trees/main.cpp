#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
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
const int N = 1e5 + 9 ;

#define  Parent        int
#define  NodesNumber   int
struct Node
{
   int id = 0;
   Node * par = this; 
   Node(int _id) : id(_id){};
};


Node * getParent(Node* _Node)
{
    if(_Node == _Node->par)
    {
        return _Node;
    }
    return _Node->par = getParent(_Node->par);
}

void join(Node * First, Node * Second)
{
    First  = getParent(First);
    Second = getParent(Second);
    if(First != Second)
    {
        Second->par = First;
    }
}

ll Power(int base , int pwr)
{
    ll result = 1;
    for(int i = 0 ; i < pwr ; i++)
    {
        result *= base;
        result %= MOD;
    }
    return result;
}

int main()
{
    Code By Abou_Hawis
    int n, k ;
    cin >> n >> k;
    ll ans = Power(n,k) - n;
    map<Parent,NodesNumber>freq;
    vector<Node *>nodes(n);
    int u, v, x;
    int counter = 1;
    for(auto &i : nodes)
    {
        i = new Node(counter++);
    }
    for(int i = 0 ; i <  n-1 ; i ++)
    {
        cin >> u >> v >> x;
        if(x == 0)
        {
            join(nodes[u-1],nodes[v-1]);
        }

    }
    for(int i = 0 ; i < n ; i++)
    {
        freq[getParent(nodes[i])->id]++;
    }
    ll NodeNumber = 0;
    for(auto &i : freq)
    {
        ans -= Power(i.second,k);
        ans += MOD;
        ans %= MOD;
        NodeNumber += i.s;
    }
    ans += NodeNumber;
    ans += MOD;
    ans %= MOD;
    cout << ans << '\n';

    return 0;
}