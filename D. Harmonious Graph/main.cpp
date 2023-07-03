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


pair<int,int> point = {0,0};

bool inter(int x , int y){
 
    if(x<=point.second && y> point.second){
        point.first = point.second;
        point.second = y;
        return 1;
    }
    if(x>=point.second){
        point.first = x;
        point.second = y;
        return  1;
    }
    return 0;
}

int main()
{
    Code By Abou_Hawis
    int n, m, from, to;
    cin >> n >> m;
    vector<Node*>nodes(n);
    vector<pair<int,int>>Edges;
    int counter = 1;
    for(auto &i : nodes)
    {
        i = new Node(counter++);
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin >> from >>to;
        Edges.pb({min(from,to), max(from,to)});
        join(nodes[min(from,to)-1],nodes[max(from,to)-1]);
    }
    sort(all(Edges));
    ll result = 0LL ;
    for(int i = 0 ; i < m ;i++)
    {
        if(inter(Edges[i].first , Edges[i].second))
        {
            for(int e = point.first +1 ; e < point.second ; e++)
            {
                if(getParent(nodes[point.first-1]) != getParent(nodes[e-1]))
                {
                    join(nodes[point.first-1],nodes[e-1]);
                    result++;
                }
            }
        }
    }
    cout << result << '\n';
    return 0;
}