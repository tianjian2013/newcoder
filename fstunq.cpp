
#include <set>
#include <iostream>
using namespace std;
class listnode{
    public:
    char val;
    listnode(char k):val(k) { next=NULL;}
    listnode* next;
};

class Solution
{
    listnode* pre;
    set<int > delch;
public:
    Solution()
    {
        pre= new listnode('#');
    }
  //Insert one char from stringstream
	void Insert(char ch)
	{
          if(delch.count(ch) ) return ;
          listnode* p=pre;
          bool del=false;
	  while(p->next){
            if(p->next->val==ch) 
            {
                listnode* tmp=p->next;
                p->next=p->next->next;
                delete tmp;
                del=true;
                delch.insert(ch);
                break;
            }
            p=p->next;
         }
        if(!del)
            p->next= new listnode(ch);
	
        }
  //return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
	     if(pre->next)
              return pre->next->val;
         else 
              return '#';
	}

};

int main()
{
Solution sl;
sl.Insert('g');
sl.Insert('o');
cout<<sl.FirstAppearingOnce()<<endl;
sl.Insert('o');
sl.Insert('g');
sl.Insert('l');
sl.Insert('g');
sl.Insert('e');
cout<<sl.FirstAppearingOnce()<<endl;
return 0;
}
