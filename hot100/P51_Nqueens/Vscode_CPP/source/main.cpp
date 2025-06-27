#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    static int times;
    int Nqueens_number(int n){
        if(n<1){
            return 0;
        }
        int *record = new int[n];
        return process1(0, record, n);
    }

    // i表示第i行  总共有n-1行
    int process1(int i, int *record, int n){
        if(i == n){         // 能到这一行，说明找到了一个解法
            return 1;
        }
        int res = 0;        // 解法
        for(int j=0; j<=n-1; j++){      // 对每一列进行遍历，
            if(isValid(record, i, j)){  // 如果有效
                record[i] = j;
                res+= process1(i+1, record, n);
            }
        }
        return res;
    }

    // (k, record[k])       (i,j)
    bool isValid(int *record, int i, int j){
        for(int k=0; k<=i-1; k++){
            if(j==record[k] || std::abs(k-i)==std::abs(j-record[k])){
                return false;
            }
        }
        return true;
    }


};
int main()
{
}
