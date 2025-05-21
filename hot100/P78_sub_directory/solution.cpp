#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::string;


class Solution {
public:
    vector<string> keys{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
    vector<string> letterCombinations(string digits) {
        vector<string> result;                                         // 记录结果
        if(digits == ""){
            return result;
        }
        vector<char> vec(digits.begin(), digits.end());                 // 拆分成vector<char>
        vector<int> number;                                             // 转换成实际的key的index
        vector<char> path;                                              // 记录路径
        
        for(int i=0; i<=vec.size()-1; ++i){
            number.emplace_back(vec[i]-'2');                          // 转换成数字
        }
        int length = vec.size();                                        // 总共输入了这么多数字
        process(&result, number, 0, path);
        return result;
    }
    void process(vector<string> *result, vector<int> number, int index, vector<char> &path){
        if(index >= number.size()){
            string str(path.begin(), path.end());
            result->push_back(str);
            return ;
        }
        for(int i=0; i<=keys[number[index]].length()-1; ++i){
            path.emplace_back(keys[number[index]].at(i));
            process(result, number, index+1, path);
            path.pop_back();
        }
    }
};


int main(int argc, char **argv)
{
    Solution solution;
    string input = "7";
    vector<string> result = solution.letterCombinations(input);
    for(auto m:result){
        std::cout << m << " \n";
    }
    return 0;
}

