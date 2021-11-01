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
};