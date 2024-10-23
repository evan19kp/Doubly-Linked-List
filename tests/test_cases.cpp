#include <iostream>
#include "DLL.hpp"

int main() {
    DoublyLinkedList<int> list;

    // Test 1: Empty list size
    std::cout << "Test 1: " << (list.size() == 0 ? "Passed" : "Failed") << std::endl;

    // Test 2: Push front
    list.push_front(10);
    std::cout << "Test 2: " << (list.front() == 10 && list.size() == 1 ? "Passed" : "Failed") << std::endl;

    // Test 3: Push back
    list.push_back(20);
    std::cout << "Test 3: " << (list.back() == 20 && list.size() == 2 ? "Passed" : "Failed") << std::endl;

    // Test 4: Push front again
    list.push_front(5);
    std::cout << "Test 4: " << (list.front() == 5 && list.size() == 3 ? "Passed" : "Failed") << std::endl;

    // Test 5: Element at index
    std::cout << "Test 5: " << (list.at(0) == 5 && list.at(1) == 10 && list.at(2) == 20 ? "Passed" : "Failed") << std::endl;

    // Test 6: Pop front
    list.pop_front();
    std::cout << "Test 6: " << (list.front() == 10 && list.size() == 2 ? "Passed" : "Failed") << std::endl;

    // Test 7: Pop back
    list.pop_back();
    std::cout << "Test 7: " << (list.back() == 10 && list.size() == 1 ? "Passed" : "Failed") << std::endl;

    // Test 8: Insert at specific position
    list.insert_after(0, 30);
    std::cout << "Test 8: " << (list.back() == 30 && list.size() == 2 ? "Passed" : "Failed") << std::endl;

    // Test 9: Erase an element
    list.erase(list.begin());
    std::cout << "Test 9: " << (list.front() == 30 && list.size() == 1 ? "Passed" : "Failed") << std::endl;

    // Test 10: Clear the list
    list.clear();
    std::cout << "Test 10: " << (list.size() == 0 && list.empty() ? "Passed" : "Failed") << std::endl;

    // Test 11: Reverse an empty list
    list.reverse();
    std::cout << "Test 11: " << (list.size() == 0 ? "Passed" : "Failed") << std::endl;

    // Test 12: Reverse a single element list
    list.push_back(100);
    list.reverse();
    std::cout << "Test 12: " << (list.front() == 100 && list.size() == 1 ? "Passed" : "Failed") << std::endl;

    // Test 13: Reverse a two-element list
    list.push_back(200);
    list.reverse();
    std::cout << "Test 13: " << (list.front() == 200 && list.back() == 100 ? "Passed" : "Failed") << std::endl;

    // Test 14: Copy constructor
    DoublyLinkedList<int> list2(list);
    std::cout << "Test 14: " << (list2.size() == 2 && list2.front() == 200 && list2.back() == 100 ? "Passed" : "Failed") << std::endl;

    // Test 15: Assignment operator
    DoublyLinkedList<int> list3;
    list3 = list;
    std::cout << "Test 15: " << (list3.size() == 2 && list3.front() == 200 && list3.back() == 100 ? "Passed" : "Failed") << std::endl;

    // Test 16: Insert into an empty list
    list.clear();
    list.push_back(500);
    std::cout << "Test 16: " << (list.front() == 500 && list.size() == 1 ? "Passed" : "Failed") << std::endl;

    // Test 17: Iterator ++ operator
    list.push_back(600);
    auto it = list.begin();
    ++it;
    std::cout << "Test 17: " << (*it == 600 ? "Passed" : "Failed") << std::endl;

    // Test 18: Iterator -- operator
    --it;
    std::cout << "Test 18: " << (*it == 500 ? "Passed" : "Failed") << std::endl;

    // Test 19: Equality operator for lists
    list2.clear();
    list2.push_back(500);
    list2.push_back(600);
    std::cout << "Test 19: " << (list == list2 ? "Passed" : "Failed") << std::endl;

    // Test 20: Inequality operator for lists
    list2.push_back(700);
    std::cout << "Test 20: " << (list != list2 ? "Passed" : "Failed") << std::endl;

    // Test 21: Erase from the middle
    list2.erase(list2.begin() + 1);  // Erase second element
    std::cout << "Test 21: " << (list2.size() == 2 && list2.back() == 700 ? "Passed" : "Failed") << std::endl;

    // Test 22: Iterator += operator
    it = list2.begin();
    it += 1;
    std::cout << "Test 22: " << (*it == 700 ? "Passed" : "Failed") << std::endl;

    // Test 23: Insert after iterator
    list2.insert_after(list2.begin(), 650);
    std::cout << "Test 23: " << (list2.at(1) == 650 ? "Passed" : "Failed") << std::endl;

    // Test 24: Multiple inserts and access
    list2.push_back(800);
    list2.push_back(900);
    std::cout << "Test 24: " << (list2.at(3) == 900 ? "Passed" : "Failed") << std::endl;

    // Test 25: Reverse a larger list
    list2.reverse();
    std::cout << "Test 25: " << (list2.front() == 900 && list2.back() == 500 ? "Passed" : "Failed") << std::endl;

    // Test 26: Pop front of a large list
    list2.pop_front();
    std::cout << "Test 26: " << (list2.front() == 800 ? "Passed" : "Failed") << std::endl;

    // Test 27: Pop back of a large list
    list2.pop_back();
    std::cout << "Test 27: " << (list2.back() == 650 ? "Passed" : "Failed") << std::endl;

    // Test 28: Insert and erase alternation
    list2.push_front(1000);
    list2.erase(list2.begin() + 1);
    std::cout << "Test 28: " << (list2.front() == 1000 ? "Passed" : "Failed") << std::endl;

    // Test 29: Erase entire list
    while (!list2.empty()) {
        list2.pop_back();
    }
    std::cout << "Test 29: " << (list2.empty() ? "Passed" : "Failed") << std::endl;

    // Test 30: Assign a list of multiple elements
    list.assign(5, 777);
    std::cout << "Test 30: " << (list.size() == 5 && list.at(0) == 777 && list.at(4) == 777 ? "Passed" : "Failed") << std::endl;

    // Test 31: Insert at back after iterator
    it = list.end();
    list.insert_after(it, 888);
    std::cout << "Test 31: " << (list.back() == 888 ? "Passed" : "Failed") << std::endl;

    // Test 32: Insert in the middle using an iterator
    list.clear();
    list.push_back(1);
    list.push_back(3);
    it = list.begin();
    it += 1;  // Move to position between 1 and 3
    list.insert_after(it, 2);  // Insert 2 between 1 and 3
    std::cout << "Test 32: " << (list.at(1) == 2 && list.at(2) == 3 ? "Passed" : "Failed") << std::endl;


    // Test 33: Iterator boundary check (end)
    it = list.end();
    std::cout << "Test 33: " << (it.isAtEnd() ? "Passed" : "Failed") << std::endl;

    // Test 34: Boundary check (begin)
    it = list.begin();
    std::cout << "Test 34: " << (*it == 777 ? "Passed" : "Failed") << std::endl;

    // Test 35: Clear list after insertion
    list.clear();
    std::cout << "Test 35: " << (list.empty() ? "Passed" : "Failed") << std::endl;

    // Test 36: Reverse an empty list (again)
    list.reverse();
    std::cout << "Test 36: " << (list.empty() ? "Passed" : "Failed") << std::endl;

    // Test 37: Add and reverse sequentially
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.reverse();
    std::cout << "Test 37: " << (list.front() == 3 && list.back() == 1 ? "Passed" : "Failed") << std::endl;

    // Test 38: Test node walker for large indices
    try {
        list.at(100);
        std::cout << "Test 38: Failed" << std::endl;
    } catch (std::range_error&) {
        std::cout << "Test 38: Passed" << std::endl;
    }

    // Test 39: Test front exception
    list.clear();
    try {
        list.front();
        std::cout << "Test 39: Failed" << std::endl;
    } catch (std::range_error&) {
        std::cout << "Test 39: Passed" << std::endl;
    }

    // Test 40: Test back exception
    try {
        list.back();
        std::cout << "Test 40: Failed" << std::endl;
    } catch (std::range_error&) {
        std::cout << "Test 40: Passed" << std::endl;
    }

    // Test 41: Push front into empty list
    list.push_front(10);
    std::cout << "Test 41: " << (list.front() == 10 ? "Passed" : "Failed") << std::endl;

    // Test 42: Test if list remains intact after pop_back
    list.push_back(20);
    list.push_back(30);
    list.pop_back();
    std::cout << "Test 42: " << (list.back() == 20 ? "Passed" : "Failed") << std::endl;

    // Test 43: Erase the first element
    list.erase(list.begin());
    std::cout << "Test 43: " << (list.front() == 20 ? "Passed" : "Failed") << std::endl;

    // Test 44: Insert at the end using size-based insert
    list.insert_after(1, 40);
    std::cout << "Test 44: " << (list.back() == 40 ? "Passed" : "Failed") << std::endl;

    // Test 45: Test assignment operator with empty list
    DoublyLinkedList<int> empty_list;
    list = empty_list;
    std::cout << "Test 45: " << (list.empty() ? "Passed" : "Failed") << std::endl;

    // Test 46: Test size after multiple inserts and erases
    list.push_back(10);
    list.push_back(20);
    list.erase(list.begin());
    std::cout << "Test 46: " << (list.size() == 1 ? "Passed" : "Failed") << std::endl;

    // Test 47: Insert at different positions
    list.push_front(100);
    list.push_front(50);
    std::cout << "Test 47: " << (list.front() == 50 && list.back() == 10 ? "Passed" : "Failed") << std::endl;

    // Test 48: Reverse non-empty list and check order
    list.reverse();
    std::cout << "Test 48: " << (list.front() == 10 && list.back() == 50 ? "Passed" : "Failed") << std::endl;

    // Test 49: Test assignment of larger list into smaller
    list2.assign(10, 5);
    list = list2;
    std::cout << "Test 49: " << (list.size() == 10 ? "Passed" : "Failed") << std::endl;

    // Test 50: Test equality of assigned lists
    std::cout << "Test 50: " << (list == list2 ? "Passed" : "Failed") << std::endl;

    return 0;
}
