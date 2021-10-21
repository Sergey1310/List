#include <iostream>
#include <functional>
#include "List.h"

void TestCommon(const std::string& testName, std::function<bool ()> testFunc) {
    try {
        if (testFunc()) {
            std::cout << "\033[32m" << testName << " OK" << "\033[39m" << std::endl;
        } else {
            std::cout << "\033[31m" << testName << " FAILED" << "\033[39m" << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cout << "\033[31m" << testName << " ERROR " << "\033[39m" << ex.what() << std::endl;
    }
}
//
const int SIZE = 10;

bool TestSizeNewEmptyList() {
    List list;
    return list.GetSize() == 0;
}

bool TestAddOneToEmptyList() {
    List list;
    list.PushFront(1);
    if (list.GetSize() != 1) return false;

    List list2;
    list2.PushBack(1);
    if (list2.GetSize() != 1) return false;

    List list3;
    list3.Insert(1, 1);
    if (list3.GetSize() != 1) return false;
    return true;
}

bool TestPopFromEmptyList() {
    List list;
    list.PopBack();
    if (list.GetSize() != 0) return false;

    List list2;
    list2.PopFront();
    if (list2.GetSize() != 0) return false;
    return true;
}

bool TestPopOneFormList() {
    List list;
    list.PushFront(1);
    list.PopFront();
    if (list.GetSize() != 0) return false;

    List list2;
    list2.PushFront(1);
    list.PopBack();
    if (list2.GetSize() != 0) return false;

    List list3;
    list3.PushFront(1);
    list3.Remove(1);
    if (list3.GetSize() != 0) return false;
    return true;
}

bool TestManyPush() {
    List list;
    for (int i = 0; i < SIZE; ++i) {
        list.PushFront(i);
    }
    if (list.GetSize() != SIZE) return false;

    List list2;
    for (int i = 0; i < SIZE; ++i) {
        list2.PushBack(i);
    }
    if (list2.GetSize() != SIZE) return false;
    return true;
}

bool TestClear() {
    List list;
    for (int i = 0; i < SIZE; ++i) {
        list.PushFront(i);
    }
    list.Clear();
    return list.GetSize() == 0;
}

bool TestManyPop() {
    List list;
    for (int i = 0; i < SIZE; ++i) {
        list.PushFront(i);
    }

    for (int i = 0; i < SIZE / 2; ++i) {
        list.PopFront();
    }
    if (list.GetSize() != SIZE - SIZE / 2) return false;

    for (int i = 0; i < SIZE - SIZE / 2; ++i) {
        list.PopBack();
    }
    if (list.GetSize() != 0) return false;
    return true;
}

bool TestSum() {
    int sum = 0;
    List list;
    for (int i = 0; i < SIZE; i += 2) {
        sum += i;
        list.PushFront(i);
    }
    return list.Sum() == sum;
}

bool TestReverse() {
    List list;
    for (int i = 0; i < SIZE; ++i) {
        list.PushBack(i);
    }
    list.Revers();
    for (int i = 0; i < SIZE; ++i) {
        if (list.Back() != i) return false;
        list.PopBack();
    }


    list.Clear();
    for (int i = 0; i < SIZE + 1; ++i) {
        list.PushBack(i);
    }
    list.Revers();
    for (int i = 0; i < SIZE + 1; ++i) {
        if (list.Back() != i) return false;
        list.PopBack();
    }

    return true;
}

bool TestManyInsert() {
    List list;
    for (int i = 0; i < SIZE; ++i) {
        list.PushBack(i);
    }
    const int VALUE = 100;

    list.Insert(VALUE, 1);
    if (list.Front() != VALUE) return false;

    list.Insert(VALUE, list.GetSize());
    if (list.Back() != VALUE) return false;

    list.Insert(VALUE, SIZE);
    for (int i = 0; i < SIZE - 1; ++i) {
        list.PopFront();
    }
    if (list.Front() != VALUE) return false;

    return true;
}

int main() {
    TestCommon("Test size of new empty list", TestSizeNewEmptyList);
    TestCommon("Test add one to empty list", TestAddOneToEmptyList);
    TestCommon("Test pop from empty list", TestPopFromEmptyList);
    TestCommon("Test pop one from list", TestPopOneFormList);
    TestCommon("Test many push", TestManyPush);
    TestCommon("Test clear", TestClear);
    TestCommon("Test many pop", TestManyPop);
    TestCommon("Test sum", TestSum);
    TestCommon("Test reverse", TestReverse);
    TestCommon("Test many insert", TestManyInsert);
    return 0;
}