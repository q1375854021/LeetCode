#ifndef __MY_SORT_H
#define __MY_SORT_H

#include <vector>

class ListNode{
    public:
        int val;                                                // 存储的元素
        ListNode *next;                                         // 下一个节点的指针

        // 构造函数
        ListNode(): val(0), next(nullptr){};                        // 初始化一个空的head
        ListNode(int x): val(x), next(nullptr){};                   // 只初始化value

        int Insert_tail(int value);                                // 尾插  在current_list的末尾插上value
        int Show_All(void);                                         // 遍历输出所有的元素
};

class Solution{
    public:
        ListNode *reverseList(ListNode *head);

};

#endif