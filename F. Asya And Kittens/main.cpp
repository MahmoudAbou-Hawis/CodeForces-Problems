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
   Node * par  = this; 
   Node * End  = this;
   Node * next = NULL;
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
        First->End->next = Second;
        First->End  = Second->End;
    }
}



int main()
{
    Code By Abou_Hawis
    int n , x,y;
    cin >> n;
    vector<Node*>Nodes(n);
    for(int i = 0 ; i < n ;i++)
    {
        Nodes[i] = new Node(i+1);
    }
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x >> y;
        join(Nodes[x-1],Nodes[y-1]);
    }
    Node * st = getParent(Nodes[0]);
    while(st != NULL)
    {
        cout << st->id << ' ';
        st = st->next;
    }

    return 0;
}