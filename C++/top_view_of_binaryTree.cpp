#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    if(root==NULL)
    return;
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node*,int>p=q.front();
        int val=p.second;
        Node* t=p.first;
        if(mp.find(val)==mp.end())
        {
            mp[val]=t->data;
        }
        if(t->left)
        {
            q.push(make_pair(t->left,val-1));
        }
         if(t->right)
        {
            q.push(make_pair(t->right,val+1));
        }
        q.pop();
    }
    map<int,int>::iterator itr;
    for(itr=mp.begin();itr!=mp.end();++itr)
    {
        cout<<itr->second<<" ";
    }
    
}



