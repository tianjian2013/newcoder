#include "help.h"

 void cvt(TreeNode* root,TreeNode** last)
    {
         if(root==NULL )  return ;
         TreeNode* ts=root;
         if(ts->left){
             cvt(ts->left,last);
         }
         ts->left=*last;
         if(*last) (*last)->right=ts;
         *last=ts;
         if(ts->right)
         {
             cvt(ts->right,last);
         }
    }
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* last=NULL;
        cvt(pRootOfTree,&last);
        
        while (last->left)
             last=last->left;
        return last;
        
	}

int main()
{
 TreeNode n0(1);
 TreeNode n1(0);
 TreeNode n2(2);
 n0.left=&n1;
 n0.right=&n2;
 TreeNode * ret=Convert(&n0);
 return 0;
}
