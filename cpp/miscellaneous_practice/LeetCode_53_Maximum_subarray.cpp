
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem statement
//  we have to find the subarray wiith the maximum sum
//  sub array= array inside the array
//  [-2,1,-3,4,-1,2,1,-5,4]
//  [-2,1,-3] or [-5,4] or the array itself can be called as an subarray
// the sum should be talen in a continuos manner

// lets try an brute force approach using two loops
//  using max function to store the largest sum
//  we only have to return the largest subarray sum and not that subarray
// T.C -> O(n^2)
// S.C -> O(1)
int brute_force(vector<int> &nums)
{
    int len = nums.size();
    int maximum_sum = nums[0];

    for (int i = 0; i < len; i++)
    {
        int sum =0;
        for (int j = i; j < len; j++)
        {
            sum = sum + nums[j];
            maximum_sum = max(sum, maximum_sum);
        }
    }
    return maximum_sum;
}
 

// kadanes algo
// the algo is simple it simply runs in one loop and has a variable called current sum 
// the sum is set to zero whenever the its lower than zero

int better_approch(vector <int>& nums){
    int len=nums.size();
    int current_sum=nums[0];
    int sum=0;
    for(int i=0;i<len;i++){
        sum=sum+nums[i];
        current_sum=max(sum,current_sum);
        if(sum<0){
            sum=0;
        }
    }
    
    return current_sum;
}


int main()
{   vector <int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<brute_force(nums)<<endl;
    cout<<better_approch(nums)<<endl;
    return 0;
}