#ifndef __SOLUTION_H
#define __SOLUTION_H

#include <vector>
#include <iostream>

using std::vector;
using std::string;

class Solution{
public: 
    // 二分查找   只要把区间掌握好了就非常OK  P704
    int binary_search1(vector<int> &nums, int num);      // 二分查找, 在nums中查找num，然后返回它的下标， [left, right]版本
    int binary_search2(vector<int> &nums, int num);      // 二分查找, 在nums中查找num，然后返回它的下标， [left, right)版本
    int binary_search_zone(vector<int> &nums, int num);  // 查找最接近且小于等于num的坐标
    void test_binary_search_1_2_zone();       

    // P27 removeElement  这个题目一看就是快慢指针
    int removeElement1(vector<int>& nums, int val);     // 左右指针实现， 比较快，但是处理后的顺序无序。 如果要保持有序的话，应该也行，但是需要很大程度的修改
    int removeElement2(vector<int>& nums, int val);     // 快慢指针实现，这个可以保证原本的顺序
    void removeElement_test();                         // 测试

    // P977 sortedSquares  有序数组的平方
    vector<int> sortedSquares(vector<int>& nums);

    // P209  长度最小的子数组
    int minSubArrayLen(int target, vector<int>& nums);
    void minSubArrayLen_test();

    // P59 螺旋矩阵
    vector<vector<int>> generateMatrix(int n);
    void generateMatrix_test(int n);

    // Kama P58 区间和
    void zone_sum(void);
    void zone_sum_test(void);

    // kama P44  开发商购买土地
    int minimum_diff(void);
    void minimum_diff_test(void);

    // P242. 有效的字母异位词
    bool isAnagram(string s, string t);         // codethink用的哈希表，但实际完全没必要
    bool isAnagram2(string s, string t);        // 不用哈希表，预分配数组
    bool isAnagram3(string s, string t);        // 不用哈希表，用数组，但是逻辑上更快

    // P349  返回两个数组的交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);   

    //P202 快乐数
    bool isHappy(int n);
    void isHappy_test(int n);

    // P1  两数之和
    vector<int> twoSum(vector<int>& nums, int target);
    void twosum_test();



private:
    int is_happy_calculate_sum(vector<int> &result, int n);

};

#endif