#include <string>
#include <iostream>

using namespace std;

void reverse(string &s,int p,int q)
{
 while(p<q)
 {
  swap(s[p],s[q]);
  p++;
  q--;
 }
}
string reverseSentence(string &s)
{
 string ret;
 int n=s.size();
 int start=0;
 while(start<n&&s[start]==' ')
  start++;
 int end=n-1;
 while(end>=0&&s[end]==' ')
   end--;
 if(start>end) return ret;
  
 reverse(s,start,end);
 int p=start,q=p+1;
 while(q<=end)
 {
   if(s[q]!=' ') q++;
   else if(s[q-1]!=' ') 
   {
     reverse(s,p,q-1);
     ret+=s.substr(p,q-p);
     ret+=' ';
     p=q+1;
     while(p<=end&&s[p]==' ')
            p++;
     q=p+1;
   }
   else { }
 }

 reverse(s,p,q-1);
 ret+=s.substr(p,q-p);

 return ret;
}

int main(int argc,char ** argv)
{
 string input(argv[1]);
 cout<<reverseSentence(input);
}
