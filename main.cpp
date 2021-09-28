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

private:
    class Node
    {
    public:
        Node *pNext;
        Node *pLast;
        int data;

        Node(int data = 0, Node *pNext = nullptr, Node *pLast = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pLast = pLast;
        }
    };

    int size;
    Node *head;
};



List::List() {
    size = 0;
    head = nullptr;
}
List::~List() {
    Clear();
}

void List::PushBack(int data) {
    if (head == nullptr)
    {
        head = new Node (data);
    }
    else
    {
        Node *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
        Node *last = current;
        current = current->pNext;
        current->pLast = last;
    }
    size++;
}
void List::PushFront(int data) {
    head = new Node(data, head);
    Node *temp = head->pNext;
    temp->pLast = head;
    ++size;
}
void List::Insert(int data, int index) {

    if (!index)
    {
        PushFront(data);
    }else if (index==size-1)
    {
        PushBack(data);
    } else
    {
        Node *prev = this->head;
        for (int i = 0; i < index-1; ++i) {
            prev = prev->pNext;
        }
        Node *newNode = new Node(data,prev->pNext,prev);
        Node *temp = newNode;
        prev->pNext = newNode;
        for (int i = 0; i < 2; ++i) {
            prev = prev->pNext;
        }
        prev->pLast=temp;
        ++size;
    }

}

void List::Clear() {
    while (size-1)
    {
        PopFront();
    }
}
void List::PopBack() {
    Node *temp = head;
    Node *toDel;
    while (temp->pNext != nullptr)
    {
        temp = temp->pNext;
    }
    temp = temp->pLast;
    toDel = temp->pNext;
    delete toDel;
    temp->pNext = nullptr;
    --size;
}
void List::PopFront() {
    Node *temp = head;
    head = head->pNext;
    head->pLast= nullptr;
    delete temp;
    --size;
}
void List::Remove(int index) {
    if (!index){PopFront();}
    else if (index==size-1){PopBack();}
    else
    {
        Node *post = this->head;
        Node *prev = this->head;
        for (int i = 0; i < index-1; ++i) {
            prev = prev->pNext;
        }
        for (int i = 0; i < index+1; ++i) {
            post = post->pNext;
        }
        Node *toDel = prev->pNext;
        delete toDel;
        prev->pNext = post;
        post->pLast = prev;
        --size;

    }
}

int List::GetSize()
{
    return size;
}
void List::Print() {
    Node *current = this->head;
    while (current->pNext != nullptr)
    {
        std::cout << "Data = " << current->data <<"\t This Link = " << current <<"\t Last link = " << current->pLast << "\t Next link = " << current->pNext << std::endl;
        current = current->pNext;
        if (current->pNext == nullptr) std::cout << "Data = " << current->data <<"\t This Link = " << current <<"\t Last link = " << current->pLast << "\t Next link = " << current->pNext << std::endl;

    }
}
int &List::operator[](const int index) {
    int counter = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        ++counter;
    }
}
int List::Sum() {
    int sum = 0;
    Node *temp = head;
    for (int i = 0; i < size; ++i)
    {
        sum += temp->data;
        temp = temp->pNext;
    }
    return sum;
}

void List::Revers() {
    Node *first = head;
    Node *last = head;
    while (last->pNext != nullptr)
    {
        last = last->pNext;
    }
    int temp;
    for (int i = 0; i < (size/2); ++i) {
        temp = first->data;
        first->data = last->data;
        last->data = temp;
        first = first->pNext;
        last = last->pLast;
    }
}


void Show( List& lst )
{
    lst.Print();
    std::cout << "Objects in list : " <<lst.GetSize() << std::endl << std::endl;
}

int main()
{
    List lst;
    lst.PushBack(15);
    lst.PushBack(10);
    lst.PushBack(5);
    lst.PushBack(100);

    std::cout << "\n Sum = " << lst.Sum() << std::endl;

    std::cout << "The second element of list = " << lst[1] << std::endl;
    Show(lst);

    lst.PopFront();
    Show(lst);

    lst.PushFront(99);
    Show(lst);

    lst.Insert(777,2);
    Show(lst);

    lst.Remove(2);
    Show(lst);

    lst.PushBack(666);
    Show(lst);

    lst.PopBack();
    Show(lst);

    lst.Revers();
    Show(lst);

    lst.Clear();
    Show(lst);

    return 0;
}