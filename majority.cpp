#include "help.h"

int MoreThanHalfNum_Solution(vector<int> numbers) {
vector<int> &nums=numbers;
	 int n=nums.size();
     if(n==0) return 0;
     int id=0;
     int times=0;
     for(int i=0;i<n;i++)
     {
         if(times==0)
         {
             id=i;
             times=1;
         }
         else
         {
             if(nums[i]==nums[id]) times++;
             else 
                times--;
         }
     }
     //return nums[id];
     times=0;
     int val=nums[id];
     for(int i=0;i<n;i++){
         if(nums[i]==val) times++;
     }
     return times>n/2?val:0;
}
