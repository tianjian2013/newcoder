//#include <algorithm>
#include <queue>
#include <vector> 
#include <iostream>
using namespace std;
class Solution{
priority_queue < int ,vector <int> ,greater<int> >  minstk;
priority_queue < int ,vector <int> >  maxstk;
public :
void Insert(int num)
{
  if(maxstk.size()==0) maxstk.push(num);
  else if(minstk.size()==0) minstk.push(num);
  else
  {
    int m=maxstk.top();
    // int n=minstk.top();
    if(m>num) maxstk.push(num);
    else  minstk.push(num);  
  }
  if((int)(maxstk.size()-minstk.size()) >1 )
  {
    int m=maxstk.top();
    maxstk.pop();
    minstk.push(m);
  }TreeNode* pRoot
   if((int) (minstk.size()-maxstk.size()) >1 )
  {
    int m=minstk.top();
    minstk.pop();
    maxstk.push(m);
  }


}

double GetMedian()
{
   if(maxstk.size()>minstk.size()  )
  {
     return maxstk.top();
  }
  else  if(minstk.size()>maxstk.size()  )
  {
    return minstk.top();
  } 
  else 
  {
    if ( maxstk.size()==0) return 0;
    else 
         return  (double)( maxstk.top()+minstk.top()) /2;
  }
  

}

};
int main()
{
  Solution sl;

  
   sl.Insert(5);
cout<<sl.GetMedian()<<endl;
 sl.Insert(2);
cout<<sl.GetMedian()<<endl;
 sl.Insert(3);
cout<<sl.GetMedian()<<endl;
 sl.Insert(4);
cout<<sl.GetMedian()<<endl;
 sl.Insert(1);
cout<<sl.GetMedian()<<endl;
 sl.Insert(6);
cout<<sl.GetMedian()<<endl;
 sl.Insert(7);
cout<<sl.GetMedian()<<endl;
 sl.Insert(0);
cout<<sl.GetMedian()<<endl;
 sl.Insert(8);
cout<<sl.GetMedian()<<endl;
}
