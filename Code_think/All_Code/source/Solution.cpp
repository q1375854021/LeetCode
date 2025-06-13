#include <Solution.h>
#include <algorithm>
#include <cstddef>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <unordered_set>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::accumulate;
using std::unordered_set;
using std::unordered_map;

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
// 如果有num，这返回num最右侧的坐标，如果没有num，返回第一个大于num的值的坐标
int Solution::binary_search_zone(vector<int> &nums, int num){
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
    return left;
}
// 测试
void Solution::test_binary_search_1_2_zone(){
    vector<int> nums{-1,0,2,2,2,5,9,12};
    int index = 0;
    index = binary_search1(nums,9);
    cout << "index = " << index << endl;
    index = binary_search2(nums,9);
    cout << "index = " << index << endl;
    index = binary_search1(nums,8);
    cout << "index = " << index << endl;
    index = binary_search2(nums,8);
    cout << "index = " << index << endl;
    index = binary_search_zone(nums,3);
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

// P977 sortedSquares  有序数组的平方   一遍过， 使用二分查找找到最接近零的数值，然后双指针依次向两边遍历，然后遍历最终剩余的数据就可以了。
vector<int> Solution::sortedSquares(vector<int>& nums) {
    vector<int> result;
    int right = binary_search_zone(nums, 0);
    int left = right-1;
    for( ; right<=nums.size()-1 && left >=0; ){
        if(abs(nums[right]) >= abs(nums[left])){
            result.emplace_back(nums[left] * nums[left]);
            left--;
        }else{
            result.emplace_back(nums[right] * nums[right]);
            right++;
        }
    }
    while(left >= 0){
        result.emplace_back(nums[left] * nums[left]);
        --left;
    }
    while(right <= nums.size()-1){
        result.emplace_back(nums[right] * nums[right]);
        ++right;
    }
    return result;
}

// 移动窗，之前用了while实现，但是while要同时协调两个东西，边界条件很难确定。不如就用for循环确定一个，另一个借机处理
int Solution::minSubArrayLen(int target, vector<int>& nums) {
    if(accumulate(nums.begin(), nums.end(), 0) < target){
        return 0;
    }
    int start = 0;
    int end = 0;
    int sum = 0;
    int minlength = nums.size()+1;
    for(end=0; end <= nums.size()-1; end++){
        if(sum < target){
            sum += nums[end];
        }
        while(sum >= target){
            minlength = min(minlength, end - start + 1);
            sum -= nums[start];
            ++start;
        }
    }
    return minlength;
}

void Solution::minSubArrayLen_test(){
    vector<int> nums{2,3,1,2,4,3};
    int target = 7;
    cout << minSubArrayLen(target, nums) << endl;
}

// 产生n维的螺旋矩阵
vector<vector<int>> Solution::generateMatrix(int n) {
    vector<vector<int>> result(n,vector<int>(n));       // 这个很妙
    if(n==0){
        return result;
    }
    result.resize(n);
    int right_bound = n-1;
    int left_bound = 0;
    int low_bound = n-1;
    int up_bound = 0;
    int direction = 0;      // 0右  1下  2左  3上
    int x=0,y=0;        // 当前坐标(x,y)
    
    for(int i=1; i<=n*n; i++){
        result[y][x]=i;
        if(direction==0){
            if(x<=right_bound-1){
                x++;
            }
            else{   // x == right_bound
                up_bound = y+1;
                direction = 1;
                y++;
            }
        }
        else if(direction==1){
            if(y<=low_bound-1){
                y++;
            }
            else{   // y==low_bound
                right_bound = x-1;
                direction = 2;
                x--;
            }
        }
        else if(direction==2){  
            if(x>=left_bound+1){
                x--;
            }
            else{  // x == left_bound
                low_bound = y-1;
                direction = 3;
                y--;
            }
        }
        else{
            if(y>=up_bound+1){
                y--;
            }
            else{  // y==up_bound
                left_bound = x+1;
                direction = 0;
                x++;
            }
        }
    }
    return result;
}
void Solution::generateMatrix_test(int n){
    vector<vector<int>> result = generateMatrix(n);
    for(auto y: result){
        for(auto x: y){
            cout << x << " ";
        }
        cout << endl;
    }
}


void Solution::zone_sum(void){
    int length;
    cin >> length;
    vector<int> prefix_num;

    int sum = 0;
    int num = 0;
    prefix_num.push_back(0);
    for(int i=0 ;i<= length-1; ++i){
        cin >> num;
        sum += num;
        prefix_num.push_back(sum);
    }

    int left, right;
    while(cin >> left >> right){
        cout << prefix_num[right+1] - prefix_num[left] << endl;
    }
}
void Solution::zone_sum_test(void){
    // 测试文件为zone_sum_test.txt
    // 测试的时候就  ./bin/main.exe < ./Test_source/zone_sum_test.txt 
    zone_sum();
}


// 使用二维前缀和，就非常简单。
int Solution::minimum_diff(void){
    int m, n;
    cin >> m >> n;      //n代表x轴方向，  m代表y轴方向   n行m列
    int total = m*n;
    vector<int> nums(total,0);   // 一维数组使用索引替代二维数组(x,y) = y*m+n;
    for(int i=0; i<total; ++i){
        cin >> nums[i];
    }
    vector<int> prefix_num_x;   // x方向的前缀和
    vector<int> prefix_num_y;   // y方向的前缀和
    int A_value=0, B_value=0;

    // 开始计算x方向的前缀和
    int sum = 0;
    for(int x=0; x<n; ++x){
        for(int y=0; y<m; ++y){
            sum += nums[y*n+x];
        }
        prefix_num_x.push_back(sum);
    }
    int total_value = prefix_num_x[n-1];

    // 查看x方向前缀的最小值，如果是0的话直接返回
    int min_value = total_value;
    for(int x=0; x<n; ++x){
        if(total_value - prefix_num_x[x] == prefix_num_x[x]){
            cout << 0;
            return 0;
        }
        A_value = prefix_num_x[x];
        B_value = total_value-prefix_num_x[x];
        min_value = min(min_value, abs(A_value-B_value));
    }

    // 计算y方向前缀和
    sum = 0;
    for(int y=0; y<m; ++y){
        for(int x=0; x<n; ++x){
            sum += nums[y*n+x];
        }
        prefix_num_y.push_back(sum);
    }

    // 查看y方向前缀的最小值，如果是0的话直接返回
    for(int y=0; y<m; ++y){
        if(total_value - prefix_num_y[y] == prefix_num_y[y]){
            cout << 0;
            return 0;
        }
        A_value = prefix_num_y[y];
        B_value = total_value-prefix_num_y[y];
        min_value = min(min_value, abs(A_value-B_value));
    }
    cout  << min_value;
    return min_value;
}
void Solution::minimum_diff_test(void){
    // 测试文件为minimum_diff_test.txt
    // 测试的时候就  ./bin/main.exe < ./Test_source/minimum_diff_test.txt 
    freopen("./Test_source/minimum_diff_test.txt", "r", stdin);
    minimum_diff();
}

bool Solution::isAnagram(string s, string t) {
    if(s.size()==0){
        return false;
    }       
    if(t.size()==0){
        return true;
    }
    // 把s的全部字母都放进哈希表， 记录每个字母出现的次数
    std::unordered_map<char , int> count_map;
    for(auto &m: s){
        count_map[m]++;
    }
    // 开始遍历t，并更新哈希表
    for(auto &s:t){
        count_map[s]--;
    }
    // 检查哈希表
    for(auto m:count_map){
        if(m.second != 0){
            return false;
        }
    }
    return true;
}

bool Solution::isAnagram2(string s, string t) {
    if(s.size()==0){
        return false;
    }       
    if(t.size()==0){
        return true;
    }
    // 把s的全部字母都放进哈希表， 记录每个字母出现的次数
    std::vector<int> count_map(26,0);
    for(auto &m: s){
        count_map[m-'a']++;
    }
    // 开始遍历t，并更新哈希表
    for(auto &s:t){
        count_map[s-'a']--;
    }
    // 检查个数
    for(auto m:count_map){
        if(m!=0){
            return false;
        }
    }
    return true;
}

bool Solution::isAnagram3(string s, string t) {
    if(s.size()!=t.size()){
        return false;
    }       
    if(t.size()==0){
        return true;
    }
    // 把全部字母都放进数组， 记录每个字母出现的次数
    std::vector<int> count_map(26,0);
    for(int i=0; i<=s.size()-1; ++i){
        count_map[s[i]-'a']++;
        count_map[t[i]-'a']--;
    }
    // 检查个数
    for(auto m:count_map){
        if(m!=0){
            return false;
        }
    }
    return true;
}


vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> num_common;
    if(nums1.size()==0 || nums2.size()==0){
        return num_common;
    }
    unordered_set<int> nums_set;
    unordered_set<int> nums_set_result;
    for(auto &m: nums1){
        nums_set.insert(m);
    }
    for(auto &m: nums2){
        if(nums_set.find(m) != nums_set.end()){
            nums_set_result.insert(m);
        }
    }
    num_common = vector<int>(nums_set_result.begin(), nums_set_result.end());
    return num_common;
}

bool Solution::isHappy(int n){
        vector<int> result;
        int sum = n;
        unordered_set<int> sums_set;

        while(sums_set.find(sum) == sums_set.end()){
            sums_set.insert(sum);
            sum = is_happy_calculate_sum(result, sum);
            if(sum == 1){
                return true;
            }
        }
        return false;
}

int Solution::is_happy_calculate_sum(vector<int> &result, int n){
    int index_num = 0;
    result = {};

    int sum = 0;
    int pow = 10;
    while(n!=0){
        index_num=n%pow;
        n = n-index_num;
        index_num = index_num/(pow/10);
        pow*=10;
        result.emplace_back(index_num);
    }
    for(auto m:result){
        sum += m*m;
    }
    return sum;
}

void Solution::isHappy_test(int n){
    std::cout << isHappy(n) << std::endl;
}

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    // 把所有的值和index都放置在map里面
    for(int i=0; i<=nums.size()-1; ++i){
        map[nums[i]]=i;
    }
    for(int i=0; i<=nums.size()-1; ++i){
        auto iter = map.find(target-nums[i]);
        if(iter != map.end()){
            return {i, iter->second};
        }
    }
    return {0,0};
}

void Solution::twosum_test(){
    vector<int> array{3,2,4};
    vector<int> result = twoSum(array, 6);
    for(auto m:result){
        cout << m << " ";
    }
    cout << endl;
}