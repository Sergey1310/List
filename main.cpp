#include <iostream>

class List
{
public:
    List();
    ~List();

    void PushBack(int data);
    void PushFront(int data);
    void Insert (int data, int index);

    void Clear();
    void PopBack();
    void PopFront();
    void Remove (int index);

    int GetSize();
    void Print();
    int Sum();
    void Revers();
    int& operator[] (const int index);

    void PrintSize(){
        std::cout << "Size = " << size << std::endl;
    }

private:
    struct Node
    {
        int data;
        Node *pNext;
        Node *pPrev;

        Node(int data = 0, Node *pNext = nullptr, Node *pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }

    };



    int size;
    Node *head;
    Node *tail;

    friend std::ostream &operator<<(std::ostream &os, List a);


};

std::ostream &operator<<(std::ostream &os, List a) {
    int count = 0;
    List::Node *current = a.head;
    while (current)
    {
        ++count;
        std::cout << count << "\t Data = " << current->data << "\t Current address = " << current;
        std::cout << "\t Previous address = " << current->pPrev << "\t Next address = " << current->pNext << std::endl;
        current = current->pNext;
    }
};

List::List():head(nullptr), tail(nullptr), size(0) {}

void List::PushBack(int data)
{
    if (!head)
        head = tail = new Node (data);
    else
    {
        Node *temp = new Node (data, nullptr, tail);
        tail->pNext = temp;
        tail = temp;
    }
    ++size;

}
void List::PushFront(int data)
{
    if (!head)
        head = tail = new Node (data);
    else
    {
        Node *temp = new Node(data,head);
        head->pPrev = temp;
        head = temp;
    }
    ++size;
}
void List::Insert(int data, int index) {
    if (!head)
        PushBack(data);
    else if (index == 1)
        PushFront(data);
    else if (index == size)
        PushBack(data);
    else
    {
        Node *PREV;
        Node *NEXT;
        Node *temp;
        if ((size - index) >= (size/2))
        {
            PREV = NEXT = head;
            for (int i = 1; i < index; ++i) {
                PREV = PREV->pNext;
                NEXT = NEXT->pNext;
            }
            PREV = PREV->pPrev;
            temp = new Node(data,NEXT,PREV);
            PREV->pNext = temp;
            NEXT->pPrev = temp;
            ++size;
        }
        else
        {
            PREV = NEXT = tail;
            int i = size - index;
            for (int j = 0; j < i; ++j)
            {
                PREV = PREV->pPrev;
                NEXT = NEXT->pPrev;
            }
            PREV = PREV->pPrev;
            temp = new Node(data,NEXT,PREV);
            PREV->pNext = temp;
            NEXT->pPrev = temp;
            ++size;
        }
    }

}

List::~List() {}

void List::Clear()
{
    while (head!=tail)
    {
        PopFront();
    }
    delete head;
    head = tail =nullptr;
    --size;
}

void List::PopBack()
{
    Node *temp;
    tail = tail->pPrev;
    temp = tail->pNext;
    tail->pNext = nullptr;
    delete temp;
    --size;
}

void List::PopFront()
{
    Node *temp = head;
    head = head->pNext;
    head->pPrev= nullptr;
    delete temp;
    --size;
}


int main()
{
    List lst;
    lst.PushBack(1);
    lst.PushBack(2);
    lst.PushBack(3);
    lst.PushBack(4);
    lst.PushBack(5);
    lst.PushFront(0);
    std::cout << lst;
    lst.PrintSize();
    lst.Insert(777, 6);
    std::cout << lst;
    lst.PrintSize();

    lst.PopBack();
    std::cout << lst;
    lst.PrintSize();

    lst.PopFront();
    std::cout << lst;
    lst.PrintSize();

    lst.Clear();
    std::cout << lst;
    lst.PrintSize();

    return 0;
}