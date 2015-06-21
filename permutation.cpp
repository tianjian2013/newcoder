#include "help.h"
void reverse(string &s,int p,int q)
{
   while(p<q)
   {
     swap(s[p],s[q]);
     p++;
     q--;
   }
}
vector<string> Permutation(string str) {
   sort(str.begin(),str.end());
   int n=str.size();
   vector <string > ret;
   ret.push_back(str);
   if(n<2) return ret;

   string p=str;
   while(1)
   {
    int i=n-2,j=n-1;
    while(i>=0)
    { 
      if(p[i]<p[j]) break;
      i--;
      j--;
    }
    if(i<0) break;
    int k=n-1;
    while(k>=0&&p[k]<=p[i]) k--;
    if(k<0) break;
    swap(p[i],p[k]);
    reverse(p,j,n-1);
    ret.push_back(p);
   }
    // }while(p.compare(str)!=0);
   return ret;
}

int main()
{
   string s("bacd");
   vector <string > ret=Permutation(s);
   for(int i=0;i<ret.size();i++){
   cout<<ret[i]<<endl;
   }
}
