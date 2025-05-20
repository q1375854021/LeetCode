#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(auto it = nums1.end()-1; it != nums1.begin()-1; --it){
            if(m==0)    //  nums1被取空了
            {
                *it = nums2.at(--n);
            }
            else if(n==0)
            {
               *it = nums1.at(--m);
            }
            else if(nums1.at(m-1) >= nums2.at(n-1) ) {
                *it = nums1.at(m-1);
                --m;
            }
            else if(nums1.at(m-1) < nums2.at(n-1)){
                *it = nums2.at(n-1);
                --n;
            }
        }
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    int m=3, n=3;

    solution.merge(nums1,m,nums2,n);
    
    for(auto &m:nums1)
        std::cout << m <<" ";
    return 0;
}