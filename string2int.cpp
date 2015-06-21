#include <iostream>
#include <string>

using namespace std;

int StrToInt(string str) {
  string s=str;
  int n=s.size();
  int start=0;
  while(start<n&&s[start]==' ')
            start++;
  s=s.substr(start);
  n=s.size();
  int end=n-1;
  while(n>=0&&s[end]==' ')
            end--;
  s=s.substr(0,end+1);
  n=s.size();
  if(n==0) return 0;
  int i=0;
  bool pos=true;
  bool zpos=true;
  bool dian=false;
  bool zhishu=false;
  string  zhenshu;
  string xiaoshu;
  int   szhishu=0;
  
  while(i<n)
  {
     if(s[i]=='+' || s[i]=='-' )
     {
       if(i==0) pos=( s[i]=='+' );
       else if(s[i-1]=='E'||s[i-1]=='e' ) 
           zpos=(s[i]=='+');
       else return 0;
     }
     else if(s[i]=='.')
     {
        if(dian||zhishu) return 0;
        dian=true;
     }
     else if(s[i]=='E'||s[i]=='e' )
     {
       if(zhishu) return 0;
       zhishu=true;
     }
     else if(s[i]>='0'&&s[i]<='9') 
     {
        if(zhishu) szhishu=szhishu*10+(s[i]-'0');
        else if(dian) xiaoshu.push_back(s[i]);
        else zhenshu.push_back(s[i]);
     } 
     else
           return 0; 
    
     i++;
  }   

  if(zpos==false)
  {
    int n=zhenshu.size();
    if(n<=zhishu) return 0;
   else zhenshu=zhenshu.substr(0,n-szhishu);
  }
 if(zpos)
 {
  int n=zhenshu.size();
 for(int i=0;i<szhishu;i++)
  zhenshu.push_back('0');
 for(int i=0;i<min(szhishu,(int)xiaoshu.size() );i++)
   zhenshu[n++]=xiaoshu[i];


 }
long long  ret=0;
for(int i=0;i<zhenshu.size();i++)
 ret=ret*10+zhenshu[i]-'0';
 if(ret<=INT_MAX) 
     return pos ?ret:-ret;	
 else if(ret==INT_MAX+1&& !pos) return INT_MIN;
     else
     return 0;	
}

int main(int argc,char **argv)
{
  string x(argv[1]);
  cout<<StrToInt(x);
}
