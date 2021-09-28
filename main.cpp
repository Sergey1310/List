#include <iostream>

class List
{
public:
    List();
    ~List();

    void PushBack(int data);
    void PopFront();
    int GetSize(){return size;}
    void Print(){
        Node *current = this->head;
        while (current->pNext != nullptr)
        {
            std::cout << "Data = " << current->data <<"\t This Link = " << current <<"\t Last link = " << current->pLast << "\t Next link = " << current->pNext << std::endl;
            current = current->pNext;
            if (current->pNext == nullptr) std::cout << "Data = " << current->data <<"\t This Link = " << current <<"\t Last link = " << current->pLast << "\t Next link = " << current->pNext << std::endl;

        }
    }

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
        size++;
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

void List::PopFront() {
    Node *temp = head;
    head = head->pNext;
    head->pLast= nullptr;
    delete temp;
    --size;
}


int main()
{
    List lst;
    lst.PushBack(15);
    lst.PushBack(10);
    lst.PushBack(5);
    lst.PushBack(100);
    lst.Print();
    std::cout << lst.GetSize() << std::endl;
    std::cout << lst[1] << std::endl;
    lst.PopFront();
    lst.Print();
    std::cout << lst.GetSize() << std::endl;
    std::cout << lst[1] << std::endl;
    return 0;
}