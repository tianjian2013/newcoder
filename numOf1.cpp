#include "help.h"

int NumberOf1Between1AndN_Solution(int n)
	{
        int ret=0;
        int base=1;
        int pre=0;
        while(n){
            int k=n%10;
            if(k==0){
                ret+=n/10*base;
            }
            else if(k==1){
                ret+=n/10*base;
                ret+= (pre+1); 
            }
            else 
                ret+=(n/10+1)*base;
            pre+=base*k;
            base*=10;
            n/=10;
           
        }
        return ret;
	}


int main()
{
cout<<NumberOf1Between1AndN_Solution(21345);
}
