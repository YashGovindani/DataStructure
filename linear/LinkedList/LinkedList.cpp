#include<iostream>

using namespace std;

class LinkedList
{
    public:
    class LinkedListNode
    {
        public:
        int data;
        LinkedListNode *next;
        LinkedListNode(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
    LinkedListNode *start;
    int size;
    LinkedList()
    {
        this->start = NULL;
        this->size = 0;
    }
    void insert(int data, int index)
    {
        if(index < 0 || index > this->size) return;
        LinkedListNode *newNode = new LinkedListNode(data);
        if(this->start == NULL) this->start = newNode;
        else if(index == 0)
        {
            newNode->next = this->start;
            this->start = newNode;
        }
        else
        {
            LinkedListNode *t = this->start;
            index--;
            while(index > 0)
            {
                index--;
                t = t->next;
            }
            newNode->next = t->next;
            t->next = newNode;
        }
        this->size++;
    }
    void pushFront(int data)
    {
        insert(data, 0);
    }
    void pushBack(int data)
    {
        insert(data, this->size);
    }
    void push(int data)
    {
        pushFront(data);
    }
    int at(int index)
    {
        if(index<0 || index >= this->size) return 0;
        LinkedListNode *t = this->start;
        while(index > 0)
        {
            t = t->next;
            index--;
        }
        return t->data;
    }
};

int main()
{
    LinkedList lst;
    for(int i = 0; i < 15; i++) lst.pushBack(i*10);
    lst.insert(225, 4);
    lst.pushFront(124);
    for(int i = 0; i < lst.size; i++) cout<<lst.at(i)<<endl;
    return 0;
}