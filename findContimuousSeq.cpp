#include <vector>
#include <iostream>
using namespace std;


vector<vector<int> > FindContinuousSequence(int sum) {
vector<vector<int> > ret;
        if(sum<=0 ) return ret;
        int p=1,q=1,sumtmp=1;
       
        while(q<=sum){
            if(sum==sumtmp)
            {
               vector <int > tmp;
                for(int i=p;i<=q;i++){
                    tmp.push_back(i);
                    ret.push_back(tmp);
                    cout<<i;
                }
                cout<<endl;
                sumtmp=sumtmp-p+q+1;
                p++;
                q++;
            }
            else if(sum>sumtmp)
            {
                sumtmp=sumtmp+q+1;
                q++;
            }
            else 
            {
                 sumtmp=sumtmp-p;
                 p++;
            }
        }
        return ret;
	}
	}

int main()
{
  vector<vector<int> > ret=FindContinuousSequence(3);
  cout<<ret.size();
}
