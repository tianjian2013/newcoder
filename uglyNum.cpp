#include "help.h"

int GetUglyNumber_Solution(int index) {
     if(index=0) return 0;
	 vector <int > ref(index,1);
        int c2=0,c3=0,c5=0;
     for(int i=1;i<index;i++){
         ref[i]=min(ref[c2]*2,min(ref[c3]*3,ref[c5]*5));
         if(ref[i]==ref[c2]*2) c2++;
         if(ref[i]==ref[c3]*3) c3++;
         if(ref[i]==ref[c5]*5) c5++;
         
     }
     showvector(ref);
     return ref[index-1];
}
int main()
{
  int ret=GetUglyNumber_Solution(15) ;
}
