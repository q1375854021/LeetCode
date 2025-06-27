#ifndef __SOLUTION_H
#define __SOLUTION_H

#include <vector>
#include <iostream>

using std::vector;


class Solution{
public: 
    // 二分查找   只要把区间掌握好了就非常OK  P704
    int binary_search1(vector<int> &nums, int num);      // 二分查找, 在nums中查找num，然后返回它的下标， [left, right]版本
    int binary_search2(vector<int> &nums, int num);      // 二分查找, 在nums中查找num，然后返回它的下标， [left, right)版本
    void test_binary_search_1_2();       

    // P27 removeElement  这个题目一看就是快慢指针
    int removeElement1(vector<int>& nums, int val);     // 左右指针实现， 比较快，但是处理后的顺序无序。 如果要保持有序的话，应该也行，但是需要很大程度的修改
    int removeElement2(vector<int>& nums, int val);     // 快慢指针实现，这个可以保证原本的顺序
    void removeElement_test();                         // 测试

};

#endif