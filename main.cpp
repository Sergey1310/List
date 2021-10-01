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
    int Sum();
    void Revers();
    int& operator[] (const int index);



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

    Node* Serch (Node *PREV, int &index);
    friend std::ostream &operator<<(std::ostream &os, List const &a);
};

std::ostream &operator<<(std::ostream &os, List const &a) {
    int count = 0;
    List::Node *current = a.head;
    std::cout << "\n";
    while (current)
    {
        ++count;
        std::cout << count << "\t Data = " << current->data << "\t Current address = " << current;
        std::cout << "\t Previous address = " << current->pPrev;
        if (count == 1)
            std::cout << "\t\t Next address = " << current->pNext << std::endl;
        else
            std::cout << "\t Next address = " << current->pNext << std::endl;
        current = current->pNext;
    }
    if (a.size == 0)
        std::cout << "\nList is empty!" << std::endl;
    std::cout << "Size = " << a.size << std::endl;
};

List::List():head(nullptr), tail(nullptr), size(0) {}
List::~List() {Clear(); std::cout << "Destructor was run!" << std::endl;}

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
    else if (index == size+1)
        PushBack(data);
    else
    {
        Node *PREV = nullptr;
        Node *NEXT = nullptr;
        Node *temp = nullptr;
        PREV = NEXT = Serch(PREV,index);
        PREV = PREV->pPrev;
        temp = new Node(data,NEXT,PREV);
        PREV->pNext = temp;
        NEXT->pPrev = temp;
        ++size;
    }

}

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
void List::Remove(int index)
{
    if (index == 1)
        PopFront();
    else if (index == size)
        PopBack();
    else
    {
        Node *PREV = nullptr;
        Node *NEXT;
        Node *temp;
        PREV = NEXT = Serch(PREV,index);
        temp = PREV;
        PREV = PREV->pPrev;
        NEXT = NEXT->pNext;
        PREV->pNext = NEXT;
        NEXT->pPrev = PREV;
        delete temp;
        --size;
    }
}

int List::GetSize() {
    return size;
}
int List::Sum() {
    int SUM = 0;
    Node *temp = head;
    while (temp)
    {
        SUM += temp->data;
        temp = temp->pNext;
    }
    return SUM;
}
void List::Revers() {
    Node *first = head;
    Node *lust = tail;
    Node *temp = new Node;
    for (int i = 0; i < (size/2); ++i) {
        temp->data = first->data;
        first->data = lust->data;
        lust->data = temp->data;
        first = first->pNext;
        lust = lust->pPrev;
    }
    delete temp;

}
int &List::operator[](const int index) {
    Node *temp = nullptr;
    int i = index;
    temp = Serch(temp, i);
    return temp->data;
}

List::Node *List::Serch(List::Node *PREV, int &index)
{
    if ((size - index) >= (size / 2)) {
        PREV = head;
        for (int i = 1; i < index; ++i)
        {
            PREV = PREV->pNext;
        }
        return PREV;
    } else {
        PREV = tail;
        int i = size - index;
        for (int j = 0; j < i; ++j)
        {
            PREV = PREV->pPrev;
        }
        return PREV;
    }
}


int main()
{
    List lst;
    for (int i = 1; i < 6; ++i)
    {
        lst.PushBack(i);
    }
    lst.PushFront(0);
    std::cout << lst;


    std::cout << lst.Sum() << std::endl;
    std::cout << lst[6] << std::endl;

    lst.Revers();
    std::cout << lst;

    lst.Insert(777, 7);
    std::cout << lst;

    lst.PopBack();
    std::cout << lst;

    lst.PopFront();
    std::cout << lst;

    lst.Remove(2);
    std::cout << lst;

    lst.Clear();
    std::cout << lst;

    lst.PushBack(777);
    std::cout << lst;

    return 0;
}