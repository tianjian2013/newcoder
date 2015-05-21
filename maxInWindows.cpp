#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
  deque<int> Q;  
  int n=num.size();
  vector<int> ret(n-size+1,0);
  for (int i = 0; i < size; i++) {  
    while (!Q.empty() && num[i] >= num[Q.back()])  
      Q.pop_back();  
    Q.push_back(i);  
  }  
  for (int i = size; i < n; i++) {  
    ret[i-size] = num[Q.front()];  
    while (!Q.empty() && num[i] >= num[Q.back()])  
      Q.pop_back();  
    while (!Q.empty() && Q.front() <= i-size)  
      Q.pop_front();  
    Q.push_back(i);  
  }  
  ret[n-size] = num[Q.front()];  
  return ret;	
}
int main()
{
  int a[]={2,3,4,2,6,2,5,1};
  vector<int> input(a,a+8);
  vector <int > ret=maxInWindows(input, 3);
  cout<<ret.size()<<endl;
}
