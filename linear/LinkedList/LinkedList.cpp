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
};