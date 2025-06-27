#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
    int Item_Num, Bag_V;        // 物品种类，背包容量
    cin >> Item_Num >> Bag_V;
    // printf("Item_Num = %d,  Bag_V = %d \n", Item_Num, Bag_V);

    vector<int> Item_Size(Item_Num);      // 物品的体积
    vector<int> Item_Value(Item_Num);     // 物品的价值

    // initalize item 
    for(auto &m : Item_Size){
        cin >> m;
    }
    for(auto &m : Item_Value){
        cin >> m;
    }

    // printf("\nItem_Size = \n");
    // for(auto m : Item_Size){
    //     cout << m << " " ;
    // }
    // printf("\nItem_Value = \n");
    // for(auto m : Item_Value){
    //     cout << m << " ";
    // }
    

    // alloc memory
    vector<vector<int>> dp(Item_Num, vector<int>(Bag_V+1));
    // x-v 物品的种类    y-> 剩余的背包空间


    // initalize
    for(int i=0; i<Bag_V+1; ++i){
        if(i>=Item_Size[0]){
            dp[0][i] = Item_Value[0];
        }
    }

    // begin dp process
    for(int i=1; i<Item_Num; ++i){
        for(int j=0; j<Bag_V+1; ++j){
            if(j >= Item_Size[i]){               // 当前背包容量可以放得下当前物品
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-Item_Size[i]]+Item_Value[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            // printf("dp[%d][%d] = %d \n", i, j, dp[i][j]);
        }
    }
    cout << dp[Item_Num-1][Bag_V] << endl;
}