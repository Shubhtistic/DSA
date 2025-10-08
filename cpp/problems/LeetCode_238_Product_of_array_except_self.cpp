#include <vector>
#include <iostream>
using namespace std;

// first lets try brte force method
// in this we make an copy vector to store the products as the original gets modified after every iteration so it will cause multiplication with modified variables
// simple use to loop to store the product in the copy vector
// use if(i==j) condn to avoid self multiplication
// it may also fail when the elements are very big powers of 10
// we have to handle this test case 
// T.C -> O(n^2)
// S.C -> O(n)

vector<int> brute_force(vector<int> &nums)
{
    auto len = nums.size();
    vector<int> nums2(nums.size());
    // vector<int> nums2 = nums; un neccesary copy
    for (int i = 0; i < len; ++i)
    {
        int product = 1;
        for (int j = 0; j < len; ++j)
        {
            if (j == i)
            {
                continue;
            }
            else
            {
                product = product * nums[j];
            }
        }
        nums2[i] = product;
    }
    return nums2;
}


// how about we try to just takke an product at once and then multiply by individual elements
// this also fails when the vector contains zero and also has overflow issues


//optimal approach
// simply we can do when we reach an element all elements on its right and on the left as well
// result[i]=left side * right side

vector<int> better_method(vector<int> nums)
{
}

int main()
{

    return 0;
}