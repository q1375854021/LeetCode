#include <iostream>
#include <ListNode.h>
#include <common.h>
#include <random>
#include <algorithm>

int main()
{   
    ListNode *head = new ListNode(0);          // 头节点必须初始化
    Solution my_solution;

    // 开始初始化链表
    head->Insert_tail(1);      // 插入链表
    head->Insert_tail(2);      // 插入链表
    head->Insert_tail(3);      // 插入链表
    head->Insert_tail(4);      // 插入链表
    head->Insert_tail(5);      // 插入链表
    head->Show_All();            // 遍历输出
    std::cout << std::endl;

    
    // 反转单链表
    head = my_solution.reverseList(head);
    head->Show_All();            // 遍历输出
    
    return 0;
}
