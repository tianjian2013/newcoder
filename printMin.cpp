#include "help.h"

bool cmp(const int &n1,const int &n2)
    {
        string s1,s2;
        stringstream ss1;
        ss1<<n1;
        ss1>>s1;
        stringstream ss2;
        ss2<<n2;
        ss2>>s2;
        
        string p1=s1+s2;
        string p2=s2+s1;
        
        for(int i=0;i<p1.size();i++){
            if(p1[i]==p2[i] )  continue;
            else return (p1[i]>p2[i] ) ;
        }
        return false;
    }

class Solution {
public:

	string PrintMinNumber(vector<int> numbers) {
	sort(numbers.begin(),numbers.end(),cmp);
        if(numbers.empty()||numbers[numbers.size()-1]==0) return "0";
        string ret;
        
        for(int i=0;i<numbers.size();i++){
            string str;
            stringstream ss;
            ss<<numbers[i];
            ss>>str;
            ret+=str;
        }
        int k=0;
        while(k<ret.size() && ret[k]=='0') k++;
        ret=ret.substr(k);
        return ret;
	}
};

int main()
{
  vector <int > input;
  for(int i=1;i<=5;i++) input.push_back(i);
  Solution sl;
  cout<<sl.PrintMinNumber(input);
}
