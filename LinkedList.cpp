//
//  lecture09_Node_LL.cpp Copy Constructor
//

#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode();
    ListNode(int iData);
    ListNode(int iData, ListNode* iNext);
    //mutators
    void setData(int);
    void setNext(ListNode*);

    //accessors
    int getData(void) const;
    ListNode* getNext(void) const;
private:
    int data;
    ListNode* next;
};


class LinkedList {
public:
    LinkedList();
    LinkedList(ListNode* iHead);
    //initialize the list with an int array
    LinkedList(const int* arr, int arrSize);
    //initialize the list with an exising list
    LinkedList(const LinkedList &l);
    ~LinkedList();

    //pre-append
    void preAppend(int nv);
    ListNode* getHead(void) const;
    void display(void) const;

private:
    ListNode* head;
};

int main(int argc, char* argv[]) {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    LinkedList arrList(arr, 10);
    arrList.display();

    LinkedList copyList(arrList);
    ListNode* node2 = copyList.getHead();
    node2->setData(-1);

    copyList.display();
    arrList.display();

    return 0;
}

ListNode::ListNode() {
    data = 0;
    next = nullptr;
}
ListNode::ListNode(int iData) {
    data = iData;
    next = nullptr;
}

ListNode::ListNode(int iData, ListNode* iNext) {
    data = iData;
    next = iNext;
}

int ListNode::getData(void) const {
    return data;
}

ListNode* ListNode::getNext(void) const {
    return next;
}

void ListNode::setData(int newData) {
    data = newData;
}

void ListNode::setNext(ListNode* newNext) {
    next = newNext;
}

////////// Linked List //////////
LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(ListNode* iHead) {
    head = iHead;
}

LinkedList::LinkedList(const LinkedList& l) {
    ListNode* head = l.head;
    ListNode* currentNode = head;
    while (currentNode != nullptr) {
        currentNode->getData() = l.head->getData();
        currentNode->getNext() = l.head->getNext();
    }
    currentNode->getNext() = nullptr;
}
LinkedList::~LinkedList() {
    ListNode* currentNode = head;
    ListNode* next;
    while (head != NULL) {
        next = head->getNext();
        delete head;
        head = next;
    }
}

//initialize the list with an int array
LinkedList::LinkedList(const int* arr, int arrSize) {
    head = nullptr;

    for (int i = arrSize - 1; i >= 0; i--) {
        preAppend(arr[i]);
    }
}

ListNode* LinkedList::getHead(void) const {
    return head;
}

void LinkedList::display(void) const {
    ListNode* cursor = head;
    while (cursor != nullptr) {
        cout << cursor->getData() << " ";
        cursor = cursor->getNext();
    }
    cout << endl;
}

void LinkedList::preAppend(int nv) {
    ListNode* node = new ListNode(nv, head);
    head = node;
}