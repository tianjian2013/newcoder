#include <iostream>
#include <vector>

using namespace std;

int GetNumberOfK(vector<int> data ,int k) {
int p=0,q=data.size()-1;
int n=data.size();
int start=p,end=q;


while(p<=q)
{
  int mid =(p+q)>>1;
  if(data[mid]<k) p=mid+1;
  else if(data[mid]>k) q=mid-1;
  else 
  {
     if( mid+1==n ||data[mid+1]>k)
     {
        end=mid;
        break;
     }
    else 
      p=mid+1;
  }
}	
if(p>q) return 0;
p=0,q=data.size()-1;
while(p<=q)
{
  int mid =(p+q)>>1;
  if(data[mid]<k) p=mid+1;
  else if(data[mid]>k) q=mid-1;
  else
  {
     if( mid==0 ||data[mid-1]<k)
     {
        start=mid;
        break;
     }
    else
      q=mid-1;
  }
}

if(p>q) return 0;
return end-start+1;
	
}
int main ()
{
  int a[]={4,4,4,4,4,4,4,4};
  vector <int > input(a,a+8);
  cout<<GetNumberOfK(input ,4);
}
