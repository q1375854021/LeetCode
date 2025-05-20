#include <Solution.h>

using std::cout;
using std::cin;
using std::endl;

// 二分查找, 在nums中查找num，然后返回它的下标， [left, right]版本, 默认nums升序排列
int Solution::binary_search1(vector<int> &nums, int num){
    if(nums.size()<=0){
        return -1;
    }
    int left = 0;
    int right = nums.size()-1;
    int middle = 0;

    while(left <= right){
        middle = (left+right)/2;
        if(nums[middle] < num){
            left = middle+1;
        }
        else if(nums[middle] > num){
            right = middle-1;
        }
        else{
            return middle;
        }
    }
    // 没有找到目标值
    return -1;
}
// 二分查找, 在nums中查找num，然后返回它的下标， [left, right)版本, 默认nums升序排列
int Solution::binary_search2(vector<int> &nums, int num){
    if(nums.size()<=0){
        return -1;
    }
    int left = 0;
    int right = nums.size();
    int middle = 0;

    while(left < right){
        middle = (left+right)/2;
        if(nums[middle] < num){
            left = middle+1;
        }
        else if(nums[middle] > num){
            right = middle;
        }
        else{
            return middle;
        }
    }
    // 没有找到目标值
    return -1;
}
// 测试
void Solution::test_binary_search_1_2(){
    vector<int> nums{-1,0,3,5,9,12};
    int index = 0;
    index = binary_search1(nums,9);
    cout << "index = " << index << endl;
    index = binary_search2(nums,9);
    cout << "index = " << index << endl;
    index = binary_search1(nums,8);
    cout << "index = " << index << endl;
    index = binary_search2(nums,8);
    cout << "index = " << index << endl;
}



// 移除元素  一看就是左右指针指针， 右指针始终指向尾部，  左指针递进   思想对了就一定能编出来，老是报错肯定是边界条件没考虑好。
int Solution::removeElement1(vector<int>& nums, int val){
    if(nums.size()==0){
        return 0;
    }
    int left = 0;
    int right = nums.size();
    while(left < right){
        if(nums[left] == val){
            nums[left] = nums[right-1];
            right--;
        }
        else{
            left++;
        }
    }
    return left;
}
// 快慢指针实现，这个可以保证原本的顺序  fast正常遍历，slow看情况遍历
int Solution::removeElement2(vector<int>& nums, int val){
    if(nums.size()==0){
        return 0;
    }
    int slow = 0;
    for(int fast=0; fast<nums.size();++fast){
        if(nums[fast]!=val){
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}
void Solution::removeElement_test(){
    vector<int> nums{0,1,2,2,3,0,4,2};
    int length = removeElement2(nums, 2);
    std::cout << "Length = " << length << endl;
    for(auto m:nums){
        std::cout << m << " ";
    }
}