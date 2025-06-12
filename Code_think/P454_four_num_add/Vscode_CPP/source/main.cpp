#include <iostream>
#include <vector>
#include <numeric>
#include <list>

using std::list;
using std::accumulate;
using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;

class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode():val(0), next(nullptr){}
        ListNode(int val):val(val), next(nullptr){}
        ListNode(int val, ListNode *next): val(val), next(next){}
};

class MyLinkedList {
private:
    ListNode *dummy_head;
    int size = 0;
    ListNode *cur_node;

public:
    MyLinkedList() {
        dummy_head = new ListNode(0,nullptr);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        cur_node = dummy_head;
        int i = 0;
        while(cur_node->next != nullptr){
            if(i == index){
                return cur_node->next->val;
            }
            else{
                cur_node = cur_node->next;
                ++i;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        cur_node = dummy_head;
        int i = 0;
        while(cur_node != nullptr){
            if(i==index){
                cur_node->next = new ListNode(val, cur_node->next);
                size++;
                return ;
            }
            else{
                cur_node = cur_node->next;
                ++i;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        cur_node = dummy_head;
        ListNode *todelete = nullptr;

        int i = 0;
        while(cur_node->next != nullptr){
            if(i==index){
                todelete = cur_node->next;
                cur_node->next = cur_node->next->next;
                delete(todelete);
                --size;
                return;
            }
            else{
                cur_node = cur_node->next;
                ++i;
            }
        }
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{   
    std::vector<int> num{1,5,2};
    MyLinkedList list;
    list.addAtTail(1);
    cout << list.get(0) << endl;
    return 0;
}
