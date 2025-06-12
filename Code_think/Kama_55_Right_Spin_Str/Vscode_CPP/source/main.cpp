#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>


using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::string;
using std::endl;
using std::cin;

class Solution {
public:
    string replace_number(string &s){
        string new_s;
        for(int i=0; i<=s.size()-1; ++i){
            if(s[i]<='9'&&s[i]>='0'){
                new_s.push_back('n');
                new_s.push_back('u');
                new_s.push_back('m');
                new_s.push_back('b');
                new_s.push_back('e');
                new_s.push_back('r');
            }
            else{
                new_s.push_back(s[i]);
            }
        }
        return new_s;
    }
};

int main()
{   
    string s;
    Solution solution;
    cin >> s;
    s = solution.replace_number(s);
    cout << s;
}
