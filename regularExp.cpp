#include <iostream>
using namespace std;

bool match(char* str, char* pattern)
{
     
        if(*pattern=='\0') return *str=='\0';
        if(  *(pattern+1)=='*'  )
        {
            if(( *pattern=='.'&&(* str!='\0') ) || *pattern==*str)
               return match(str,pattern+2)|| match(str+1,pattern+2) || match(str+1,pattern);
            else 
              return match(str,pattern+2);
        }
       
        else
            return  (  *str==*pattern||  ( *pattern=='.'&&(* str!='\0') ) ) && match (str+1,pattern+1);
        return false;
}

int main(int argc,char **argv)
{
if(argc==3)
{
   cout<<"argv[0] : "<< argv[0]<<endl;
   cout<<"argv[1] : "<< argv[1]<<endl;
   cout<<"argv[3] : "<< argv[2]<<endl;

if(match(argv[1],argv[2]) )  cout<<"match"<<endl;

}
return 0;
}
