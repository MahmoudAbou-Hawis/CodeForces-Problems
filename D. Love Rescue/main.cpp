#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

struct Node
{
   Node * par = this; 
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

int main()
{
    Code By Abou_Hawis
   vector<Node*>_Nodes(26);
   vector<pair<char,char>>v;
   for(int i = 0 ; i < 26  ; i++ )
   {
    _Nodes[i] = new Node;
   }
   int n;
   cin >> n ;
   string first,second;
   cin >> first >> second;
   for(int i = 0 ; i < n ;i++)
   {
        if(getParent(_Nodes[(first[i]-'a')]) != getParent(_Nodes[(second[i]-'a')]))
        {
            v.push_back({first[i],second[i]});
            join(getParent(_Nodes[(first[i]-'a')]) , getParent(_Nodes[(second[i]-'a')]));
        }
   }
   cout << v.size() << '\n';
   for(auto &i : v)
   {
    cout << i .first << " " << i.second << '\n';
   }

    return 0;
}