#include "help.h"

int find(vector<int> &arr1, int s1,int e1,vector<int> &arr2,int s2,int e2,int index)
{
   if(s1>e1) return arr2[s2+index];
   if(s2>e2) return arr1[s1+index];
   int m1=0,m2=0;
   if(e1-s1>e2-s2)
   {
      m2=min(index>>1,e2-s2+1);
      m1=index-m2;
   }
   else
   {
      m1=min(index>>1,e1-s1+1);
      m2=index-m1;
   }
   if(index==1) return min(arr1[s1],arr2[s2]);
   //int m=minindex>>1;
   //int m2=(s2+e2)>>1;
   if(arr1[s1+m1-1]>arr2[s2+m2-1])
   {
       return find(arr1,s1,e1,arr2,s2+m2,e2,index-m2);
   }
   else if(arr1[s1+m1-1]<arr2[s2+m2-1])
   {
      return find(arr1,s1+m1,e1,arr2,s2,e2,index-m1);
   }
   else 
      return arr1[s1+m1-1];
}

int getUpMedian(vector<int> arr1, vector<int> arr2) {
int n=arr1.size();
return find(arr1,0,n-1,arr2,0,n-1,n);
}

int main()
{
  int a1[]={1,2,3,4};
  int a2[]={4,5,7,8};
  vector <int> i1(a1,a1+4);
  vector <int> i2(a2,a2+4);
  cout<<getUpMedian(i1, i2) ;
  return 0;
}
