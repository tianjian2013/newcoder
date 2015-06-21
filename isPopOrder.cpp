#include "help.h"

 bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.empty()) return true;
        if(pushV.size()!=popV.size() ) return false;
	 map <int ,int > ref;
        for(int i=0;i<pushV.size();i++)
            {
            ref[pushV[i]]=i;
        }
        int j=0;
        stack<int > sk;
        if(ref.count(popV[0])==0 ) return false;
        for(;j<ref[popV[0]];j++)
            sk.push(pushV[j]);
             j++;
        for(int i=1;i<popV.size();i++)
            {
            if(ref.count(popV[i])==0 ) return false;
            if(ref[popV[i]]>ref[popV[i-1]])
                {
                 
                 for(;j<ref[popV[i]];j++)
                  sk.push(pushV[j]);
                j++;
            }
            else
                {
                if(sk.size()==0) return false;
                int k=sk.top();
                if(k!=popV[i]) return false;
        sk.pop();
            }
        }
        return true;
  }

int main()
{
  int a[]={1,2,3,4,5};;
  vector <int > aa(a,a+5);
 int b[]={4,3,5,1,2};
 vector <int > bb(b,b+5);
 if(IsPopOrder(aa,bb )) 
cout<<"ok"<<endl;
}
