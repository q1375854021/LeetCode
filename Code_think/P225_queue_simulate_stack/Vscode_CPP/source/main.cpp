#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <string>
#include <stack>
#include <queue>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::string;
using std::endl;
using std::stack;
using std::queue;

class MyStack {
public:
    queue<int> inqueue;
    queue<int> backup_queue;
    MyStack() {
        
    }
    
    void push(int x) {
        inqueue.push(x);
    }
    
    int pop() {
         // inqueue拷贝数据到backup_queue
        while(inqueue.size()>=2){
            backup_queue.push(inqueue.front());
            inqueue.pop();
        }
        // 然后得到最后面的值
        int value = inqueue.front();
        inqueue.pop();
        // 然后把backup_queue备份一下
        inqueue = backup_queue;
        backup_queue = {};      // 清空backup_queue
        return value;
    }
    
    int top() {
         // inqueue拷贝数据到backup_queue
        while(inqueue.size()>=2){
            backup_queue.push(inqueue.front());
            inqueue.pop();
        }
        // 然后得到最后面的值
        int value = inqueue.front();
        inqueue.pop();
        backup_queue.push(value);
        // 然后把backup_queue备份一下
        inqueue = backup_queue;
        backup_queue = {};      // 清空backup_queue
        return value;
    }
    
    bool empty() {
        return (inqueue.empty()&&backup_queue.empty());
    }
};


int main()
{   
    string s("abcdefg");
    Solution solution;
    s = solution.reverseStr(s, 2);
    cout << s << endl;
    return 0;
}
