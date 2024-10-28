# DoublyLinkedList (DLL)

## Overview

This project provides a generic implementation of a **Doubly Linked List (DLL)** in C++, supporting basic operations like insertion, deletion, access, and traversal through a custom iterator. The implementation is flexible and efficient, offering key functionality for list manipulation with the added benefit of reverse traversal.

## Features

- **Generic Implementation**: The list can store any data type, thanks to the use of templates.
- **Bidirectional Traversal**: Both forward and reverse traversal of the list is supported using a custom iterator.
- **Efficient Insertion/Deletion**: Provides efficient `O(1)` insertion and deletion at both the front and back of the list.
- **Custom Iterator**: Allows for iteration and manipulation of the list elements through a custom iterator class.
- **Element Access**: Access elements via their position (`at()`, `front()`, `back()`).
- **Reversal**: Reverse the entire list in-place with `reverse()`.
- **Exception Handling**: Throws appropriate exceptions (e.g., `std::range_error`) for invalid operations like out-of-bounds access.

## Class Overview

### `DoublyLinkedList<T>`

- **Node Class**: Represents a single node in the list. Each node holds an element and pointers to both the next and previous nodes.
- **Iterator Class**: Supports forward and reverse traversal of the list, allowing element access, increment, and decrement operations.
- **Key Methods**:
  - `push_front()`, `push_back()`: Insert elements at the front and back.
  - `pop_front()`, `pop_back()`: Remove elements from the front and back.
  - `insert_after()`: Insert an element after a given iterator or position.
  - `erase()`: Remove an element at a given iterator.
  - `front()`, `back()`, `at()`: Access elements by position or at the front and back of the list.
  - `size()`: Get the current number of elements in the list.
  - `empty()`: Check if the list is empty.
  - `clear()`: Clear the entire list.
  - `reverse()`: Reverse the list in-place.

## Getting Started

### Prerequisites

To compile and run the code, you need a C++ compiler that supports C++11 or higher.

### Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/doublylinkedlist.git
cd doublylinkedlist
```

### Compilation

You can compile your project using any C++ compiler. For example, using `g++`:

```bash
g++ -std=c++11 -o test test_cases.cpp
```

### Running the Tests

The project includes 50 test cases that ensure the correctness of the implementation. Once compiled, run the tests:

```bash
./test
```

This will output the results of each test case, indicating whether they passed or failed.

## Usage

Here’s a simple example of how to use the `DoublyLinkedList` class:

```cpp
#include "DLL.hpp"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;

    // Inserting elements
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    // Accessing elements
    std::cout << "Front element: " << list.front() << std::endl; // 5
    std::cout << "Back element: " << list.back() << std::endl;  // 20

    // Reversing the list
    list.reverse();
    std::cout << "Front after reverse: " << list.front() << std::endl; // 20

    // Iterating over the list
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Output:
```
Front element: 5
Back element: 20
Front after reverse: 20
20 10 5 
```
