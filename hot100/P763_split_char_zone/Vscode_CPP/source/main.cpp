#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int begin_index = 0;
        int last_index = s.length()-1;
        char begin_char = 0;
        int index = begin_index;

        while(begin_index <= s.length()-1){
            begin_char = s[begin_index];
            last_index = get_last_char(s,begin_char);
            index = begin_index;
            while(index != last_index){
                begin_char = s[index];
                last_index = std::max(last_index, get_last_char(s, begin_char));
                index++;
            }
            result.emplace_back(last_index-begin_index+1);
            begin_index = last_index+1;
        }
        return result;
    }

    int get_last_char(string s, char a){
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==a){
                return i;
            }
        }
        return -1;
    }
};

int main()
{   
    
    Solution solution;
    string s = "ababcbacadefegdehijhklij";
    vector m = solution.partitionLabels(s);
    for(auto num : m){
        std::cout << num << std::endl;
    }
    return 0;
}
