#include <iostream>
#include <vector>


using namespace std;

int find(vector <int >& pre_status,int row,int col,vector <vector <int >> &input)  // pre_status :store hignest scores in pre col
	                                                                               // the function return the hignest score in(i,j)
{
	if(input[row][col]<0) return -1;  // blocked
	int n=input.size();  // n is the number of rows of input
	int ret=-1;                     // return value

	/********Upward search*******/
	int sumthiscol=0;        //the sum values in this col    
	int i=row;               //search start point 
	for(;i>=0;i--)
	{
		if(input[i][col]>=0)  // the cell is not blocked 
		{
			sumthiscol+=input[i][col];
			if(pre_status[i]>=0)  
				ret=max(pre_status[i]+sumthiscol,ret);  //the left col maybe turn right in (i,col)
		}
		else
			break;
	}
	if(i==-1&&input[n-1][col]>=0&&pre_status[n-1]>=0)  ret=max(input[0][col],ret); // at the bottom and go down int pre col 

	/********Downward search*******/
	sumthiscol=0;   //just like upward search
	i=row;
	for(;i<n;i++)
	{
		if(input[i][col]>=0)
		{
			sumthiscol+=input[i][col];
			if(pre_status[i]>=0)  
				ret=max(pre_status[i]+sumthiscol,ret);
		}
		else
			break;
	}
	if(i==n&&input[0][col]>=0&&pre_status[0]>=0)  ret=max(input[n-1][col],ret);


	return ret;
}
int main()
{
	int n,m;
	cin>>n>>m;
	if(n<1||m<1) 
	{
		cout<<"m should be in the range of [1,100000] and n [2,100000]"<<endl;
		return 0;
	}
	vector <vector <int >> input(n,vector<int>(m,0)) ; // input array
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>input[i][j];
		}
	}
	// calculate the highest score if we can reach (i,j)
	// I will calculate that col by col and sovle the problem in O(n*n*m) time
	// the highest score in (i,j)  only depends on the highest score in the (j-1)th col and the values of cells in (j)th col 
	vector <int > pre_status(n,0); //highest scores int pre col 
	for(int j=0;j<m;j++)  // col by col
	{
		vector <int > this_status; // store the highest scores  in  (j)th col
		for(int i=0;i<n;i++)
		{
			this_status.push_back( find( pre_status,i,j,input) ); //find the highest scores in (j)th col
		}
		swap(pre_status,this_status);  // swap the result to do the next iteration
	}
	 //print the answer 
	int highestscore=-1;
	for(int i=0;i<n;i++)
	{
		if(pre_status[i]>highestscore)
			highestscore=pre_status[i];
	}
        cout<<highestscore<<endl;
	return 0;

}
