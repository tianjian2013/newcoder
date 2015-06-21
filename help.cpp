#include "help.h"
void showvector(vector<int>&  input)
{
	for(size_t i=0;i<input.size();i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;
}

void showTreeNode(TreeNode * p)
{
  if(p==NULL) return ;
  cout<<" p->val : " << p->val<<endl;
  if(p->pa) 
   cout<<" p->pa : " << p->pa->val<<endl;
  if(p->left) 
   cout<<" p->left : " << p->left->val<<endl;
  if(p->right) 
   cout<<" p->right : " << p->right->val<<endl;
}
/*
void showmap( map<int ,int > &m)
{
 vector <int,int>::iterator it=m.begin();
 while(it!=m.end()){
  cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
  it++;
 }
}*/
