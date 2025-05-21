#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>

using std::vector;
using std::string;
using std::queue;
using std::unordered_set;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        unordered_set<int> walked;
        int board_dim_x = board[0].size();
        int board_dim_y = board.size();
        unordered_set<char> hash_list;
        for(int x=0; x<board_dim_x; ++x){
            for(int y=0; y<board_dim_y;++y){
                hash_list.insert(board[y][x]);
            }
        }
        for(int i=0; i<word.size(); ++i){
            if(hash_list.find(word[i]) == hash_list.end()){
                return false;
            }
        }
        for(int x=0; x<board_dim_x; ++x){
            for(int y=0; y<board_dim_y;++y){
                if(board[y][x] == word[0]){
                    process(result, x,y,board,board_dim_x, board_dim_y, word, 0, walked);
                    if(result == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    // result用于存放最终的结果，  x表示当前的横坐标   y表示当前的纵坐标，  board代表棋盘，  board_dim_x表示棋盘的横长度   board_dim_y表示棋盘的纵长度   input表示从什么方向进来的,'a'表示坐标进来的， 'd'表示右边， 'w'表示上边; 's'表示下边  
    // std::
    void process(bool &result, int x, int y, vector<vector<char>>& board, int board_dim_x, int board_dim_y, string &word, int index, unordered_set<int> &walked){
        if(index == word.size()){
            result = true;
        }
        if(walked.find(y*board_dim_x+x)!=walked.end() ||  x<0 || x > board_dim_x-1 || y<0 || y>board_dim_y-1 || board[y][x] != word[index]){
            return ;
        }
        walked.insert(y*board_dim_x+x);
        process(result, x+1, y, board, board[0].size(), board.size(), word, index+1, walked);
        process(result, x, y+1, board, board[0].size(), board.size(), word, index+1, walked);
        process(result, x-1, y, board, board[0].size(), board.size(), word, index+1, walked);
        process(result, x, y-1, board, board[0].size(), board.size(), word, index+1, walked);
        walked.erase(y*board_dim_x+x);
    }
};



int main(int argc, char **argv)
{
    Solution solution;
    vector<vector<char>> board;
    board.resize(3);
    vector<char> temp;
    temp.resize(3);
    temp[0] = 'C'; temp[1] = 'A'; temp[2]='A';
    board[0] = temp;
    temp[0] = 'A'; temp[1] = 'A'; temp[2]='A';
    board[1] = temp;
    temp[0] = 'B'; temp[1] = 'C'; temp[2]='D';
    board[2] = temp;
    bool result = solution.exist(board,"AAB");
    std::cout << result;
    return 0;
}

