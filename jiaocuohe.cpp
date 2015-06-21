#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned long long ll;

ll x=1000000007;

int str2int(string &str)
{
   int n=str.size();
   int ret=0;
   for(int i=0;i<n;i++)
   {
     ret+=  ( 1-2*(i%2) ) *  (int) (str[i]-'0');
   }
   return ret;
}

string ll2str(ll num)
{
  stringstream ss;
  ss<<num;
  string str;
  ss>>str;
  return str;
}

ll str2ll(string &str)
{
  stringstream ss;
  ss<<str;
  ll num;
  ss>>num;
  return num;
}

bool addone(string &str,int & inc)
{
   int n=str.size()-1;
   bool jinwei=false;
   inc=0;
   do
   {
      if(str[n]=='9')
      {
         jinwei=true; 
         str[n]='0';
         inc+=( 2*(n%2)-1 )*9;
      }
      else
      {
         jinwei=false;
         str[n]=str[n]+1;
         inc+= ( 1-2*(n%2) ); 
      }
      n--;
   }
   while(n>=0&&jinwei);
   return jinwei;
}

int main()
{
   
   ll l,r;
   int k;
   cin>>l>>r;
   cin>>k;
   ll ret=0;
  
   string strl=ll2str(l);
   //string strr=ll2str(r);

   int tmpsum=str2int(strl) ;
   if(tmpsum==k)
   {
       ret+= str2ll(strl);
       ret%=(x);
   }
   
   for( ll i=0;i<r-l;i++)
   {
       int inc=0;
       if(addone(strl,inc) )
       {
         strl.insert(0,1,'1');
         //tmpsum=tmpsum+1-inc;
         tmpsum=str2int(strl) ;
       }
       else 
       {
         tmpsum+=inc;
       }
       //cout<<strl<<endl;
       if(tmpsum==k)
       {
          ret+=str2ll(strl);
          ret%=(x);
       }
   }
   cout<<ret<<endl;
   return 0;
   
   
   
}
