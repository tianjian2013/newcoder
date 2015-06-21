#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size)
  {
        int n=num.size();
        vector<int > ret;
        if(n==0||size<1||size>n) return ret;
        deque<int> ref;
      for(int i=0;i<size;i++){
            while( !ref.empty() && num[i]>num[ref.back()])
                ref.pop_back();
            ref.push_back(i);
        }
        ret.push_back(num[ref.front()]);
        for(int i=size;i<n;i++){
             while( !ref.empty() && num[i]>num[ref.back()])
                ref.pop_back();
             while( !ref.empty() && i-ref.front()+1>size)
                 ref.pop_front();
             ref.push_back(i);
             ret.push_back(num[ref.front()]);
        }
        return ret;
  }
};

int main()
{
Solution sl;
int a[]={2,3,4,2,6,2,5,1};
vector <int> input(a,a+8);
vector <int> ret=sl.maxInWindows(input,3);
return 0;
}
