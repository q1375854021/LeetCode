#include "ListNode.h"
#include "common.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>      // 产生随机数用于测试
#include <iterator>
#include <queue>        // 调用priority_queue


// 对链表进行尾插
int ListNode::Insert_tail(int value){
    ListNode *new_node = new ListNode(value);           // 新插入的节点
    ListNode *tail = this;                                      // 遍历寻找尾部的node
    // 本身存在一个链表
    while(tail->next != nullptr){     // 还不是最后一个尾节点
        tail = tail->next;   // 向下移动一个节点
    }
    // 移动完之后，肯定就已经到了最后一个节点，然后插入
    tail->next = new_node;
    new_node->next = nullptr;

    // 然后free掉
    // delete(tail);                       // tail已经是有效节点了，不能删除掉
    return 0;
}

int ListNode::Show_All(){
    ListNode *tail = new ListNode;                                      // 遍历寻找尾部的node
    tail = this;
    // 本身存在一个链表
    while(tail->next != nullptr){     // 还不是最后一个尾节点
        std::cout << tail->val << " ";
        tail = tail->next;   // 向下移动一个节点
    }
    std::cout << tail->val << std::endl;
    return 0;
}


ListNode *Solution::reverseList(ListNode *head){
    // 检测直接返回的情况
    if(head==nullptr) return nullptr;

    // 初始化变量
    ListNode *Head = head;
    ListNode *beg = head;
    ListNode *end = head->next;
    
    // 检测不需要反转的情况
    if(end == nullptr) return head;

    // 开始进行遍历      // 设置边界条件
    while(end != nullptr){
        beg->next = end->next;
        end->next = head;
        head = end;
        end = beg->next;
    } 
    return head;
}