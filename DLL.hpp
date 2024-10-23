#ifndef DLL
#define DLL


/** 
 * Evan Packard
*/

#include <iostream>
#include <stdlib.h>
#include <stdexcept>

template <class T>
class DoublyLinkedList
{
    public:
        class Node
        {
            public:
                Node() {
                    element_ = T{};
                    prev_ = nullptr;
                    next_ = nullptr;
                }
                Node(T element) {
                    element_ = element;
                    prev_ = nullptr;
                    next_ = nullptr;
                }

                Node(T element, Node* prev, Node* next) 
                : element_(element), prev_(prev), next_(next) {}

                void setPrevious(Node* prev) {
                    this->prev_ = prev;
                }

                void setPrev(Node* prev) {
                    this->prev_ = prev;
                }

                Node* getPrevious() {
                    return this->prev_;
                }

                Node* getPrev() {
                    return this->prev_;
                }

                void setNext(Node* next) {
                    this->next_ = next;
                }

                Node* getNext() {
                    return this->next_;
                }

                void setElement(T element) {
                    this->element_ = element;
                }

                T& getElement() { return this->element_; }

                T& operator*() { return this->element_; }
                
            private:
                T element_;
                Node* prev_;
                Node* next_;
        };
        class Iterator
        {
            public:
                Iterator() {}

                Iterator(Node* head, Node* tail) : head_(head), tail_(tail)
                {
                    this->cursor_ = this->end();
                }

                Iterator(Node* head, Node* tail, Node* cursor) : head_(head), tail_(tail), cursor_(cursor) {}

                Node* begin()
                {
                    if (head_ == nullptr) {
                        return end();
                    }
                    return head_;
                }

                Node* end()
                {
                    return nullptr;
                }

                Node* getCursor()
                {
                    return cursor_;
                }

                bool isAtEnd()
                {
                    if (this->cursor_ == nullptr) {
                        return true;
                    }
                    return false;
                }

                Iterator& operator=(const Iterator& other)
                {
                    if (this != &other) {
                    head_ = other.head_;
                    tail_ = other.tail_;
                    cursor_ = other.cursor_;
                    }

                    return *this;
                }

                bool operator==(const Iterator& other)
                {
                    if((head_ == other.head_) &&
                        (tail_ == other.tail_) &&
                        (cursor_ == other.cursor_)) {
                        return true;
                    }
                    return false;
                }

                bool operator!=(const Iterator& other)
                {
                    if((head_ != other.head_) ||
                        (tail_ != other.tail_) ||
                        (cursor_ != other.cursor_)) {
                        return true;
                    }
                    return false;
                }

                Iterator operator +(size_t add)
                {
                    Node* cursor = cursor_;
                    for (size_t i = 0; i < add; ++i) {
                        if (cursor == tail_) {
                            cursor = tail_;
                            break;
                        }
                        cursor = cursor->getNext();
                    }

                    return Iterator(head_, tail_, cursor);

                }

                Iterator operator -(size_t subtract)
                {
                    Node* cursor = cursor_;
                    for (size_t i = 0; i < subtract; ++i) {
                        if (cursor == head_) {
                            cursor = head_;
                            break;
                        }
                        cursor = cursor->getPrev();
                    }
                    return Iterator(head_, tail_, cursor);
                }

                Iterator& operator++()
                {
                    if (cursor_ != nullptr) {
                        cursor_ = cursor_->getNext();
                    }
                    return *this;
                }

                Iterator operator++(int)
                {
                    Iterator copy = *this;
                    if (cursor_ != nullptr) {
                        cursor_ = cursor_->getNext();
                    }
                    return copy;

                }

                Iterator& operator--()
                {
                    if (cursor_ != head_) {
                        cursor_ = cursor_->getPrev();
                    } else {
                        cursor_ = nullptr;
                    }
                    return *this;
                }

                Iterator operator--(int)
                {
                    Iterator copy = *this;
                    if (cursor_ != nullptr) {
                        cursor_ = cursor_->getPrev();
                    }
                    return copy;
                }

                Iterator operator +=(size_t add)
                {
                    for (size_t i = 0; i < add; ++i) {
                        if (cursor_ == nullptr) {
                            break;
                        }
                        cursor_ = cursor_->getNext();
                    }

                    return *this;
                }

                Iterator operator -=(size_t add)
                {
                    for (size_t i = 0; i < add; ++i) {
                        if (cursor_ == nullptr) {
                            break;
                        }
                        cursor_ = cursor_->getPrev();
                    }

                    return *this;
                }

                Iterator operator +=(int add)
                {
                    if (add > 0) {
                        for (auto i = 0; i < add; ++i) {
                            if (cursor_ == nullptr) {
                                break;
                            }
                            cursor_ = cursor_->getNext();
                        }
                    } else if (add < 0) {
                        for (auto i = 0; i < -add; ++i) {
                            if (cursor_ == nullptr || cursor_ == head_) {
                                break;
                            }
                            cursor_ = cursor_->getPrev();
                        }
                    }

                    return *this;
                }

                Iterator operator -=(int subtract)
                {
                    if (subtract > 0) {
                        return *this += -subtract;
                    }

                    for (auto i = 0; i < -subtract; ++i) {
                        if (cursor_ == nullptr) {
                            break;
                        }
                        cursor_ = cursor_->getPrev();
                    }

                    return *this;
                }

                T& operator*()
                {
                    return cursor_->getElement();
                }
            
            private:
                Node* head_ = nullptr;

                Node* tail_ = nullptr;

                Node* cursor_ = nullptr;
            
            friend class DoublyLinkedList;
        };

        DoublyLinkedList()
        {
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }

        DoublyLinkedList(DoublyLinkedList& other)
        {
            for (Node* p = other.head_; p != nullptr; p = p->getNext()) {
                push_back(p->getElement());
            }
        }

        ~DoublyLinkedList()
        {
            clear();
        }

        void sandwich_insert(Node* prev, Node* next, const T& value) {
            Node* N = new Node(value, prev, next);

            if (prev != nullptr) {
                prev->setNext(N);
            } else {
                head_ = N;
            }

            if (next != nullptr) {
                next->setPrev(N);
            } else {
                tail_ = N;
            }
            size_++;
        }

        Node* node_walker(size_t i_) {
            if (head_ == nullptr || i_ >= size_) {
                throw std::range_error("invalid");
            }
            Node* N = head_;
            for (size_t i = 0; i < i_; ++i) {
                if (N == nullptr) {
                    throw std::range_error("null pointer");
                }
                N = N->getNext();
            }
            return N;
        }

        void assign(size_t count, const T& value)
        {
            clear();
            for (size_t i = 0; i < count; ++i) {
                push_back(value);
            }
        }

        void assign(Iterator first, Iterator last) //assign with different specific arguments
        {

            clear();

            Iterator sp = this->begin();

            if (first.getCursor() < last.getCursor() && last.getCursor() == nullptr) {
                for (Iterator p = first; p != last; ++p) {
                    sp = insert_after(sp, *p);
                }
            }

            else if (first.getCursor() > last.getCursor() && last.getCursor() == nullptr) {
                for (Iterator p = first; p != last; ++p) {
                    sp = insert_after(sp, *p);
                }
            }

            else if (first.getCursor() < last.getCursor()) {
                for (Iterator p = first; p != last + 1; ++p) {
                    if (p.getCursor() == nullptr) {
                        break;
                    }
                    sp = insert_after(sp, *p);
                }

            } else if (first.getCursor() > last.getCursor()) {
                if (first.getCursor() != nullptr) {
                    Iterator dp = first;
                    while (sp != this->end()) {
                        insert_after(this->end(), *dp);
                    }
                }
            }
        }

        Node* head() const
        {
            return head_;
        }

        Node* tail() const
        {
            return tail_;
        }

        Iterator begin() const
        {
            return Iterator(head_, tail_, head_);
        }

        Iterator last() const
        {
            return Iterator(head_, tail_, tail_);
        }

        Iterator end() const
        {
            return Iterator(head_, tail_, nullptr);
        }

        bool empty() const
        {
            if (size_ == 0) {
                return true;
            }
            return false;
        }

        size_t size() const
        {
            return size_;
        }

        void clear()
        {
            Node* p = this->head_;
            while (p != nullptr) {
                Node* forward = p->getNext();
                delete p;
                p = forward;
            }
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }

        Iterator insert_after(Iterator pos, const T& value)
        {
            if (empty()) {
                sandwich_insert(nullptr, nullptr, value);
                return Iterator(head_, tail_, head_);
            }

            if (pos == end()) {
                sandwich_insert(tail_, nullptr, value);
                return Iterator(head_, tail_, tail_);
            }

            Node* position = pos.getCursor();
            sandwich_insert(position, position->getNext(), value);
            return Iterator(head_, tail_, position->getNext());
        }

        Iterator insert_after(size_t pos, const T& value)
        {
            if (empty()) {
                sandwich_insert(nullptr, nullptr, value);
                return Iterator(head_, tail_, head_);
            }

            if (pos >= size_) {
                sandwich_insert(tail_, nullptr, value);
                return Iterator(head_, tail_, tail_);
            }

            Node* NW = node_walker(pos);
            sandwich_insert(NW, NW->getNext(), value);
            return Iterator(head_, tail_, NW->getNext());
        }

        Iterator erase(Iterator pos)
        {
            Node* eraseit = pos.getCursor();
            if (eraseit == nullptr) {
                throw std::range_error("dwadwadwadasaaaa");
            }

            if (eraseit->getPrev() != nullptr) {
                eraseit->getPrev()->setNext(eraseit->getNext());
            } else {
                head_ = eraseit->getNext();
            }

            if (eraseit->getNext() !=nullptr) {
                eraseit->getNext()->setPrev(eraseit->getPrev());
            } else {
                tail_ = eraseit->getPrev();
            }
            Node* N = eraseit->getNext();
            delete eraseit;
            size_--;
            if (N == nullptr) {
                return this->end();
            }
            return Iterator(head_, tail_, N);
        }

        Iterator push_after(Iterator pos, const T& value)
        {
            return insert_after(pos, value);
        }

        void push_front(const T& value)
        {
            if (empty()) {
                sandwich_insert(nullptr, nullptr, value);
            } else {
                sandwich_insert(nullptr, head_, value);
            }
        }

        Iterator push_back(const T& value)
        {
            return insert_after(Iterator(head_, tail_, tail_), value);
        }

        void pop_front()
        {
            if(empty()) {
                throw std::range_error("empty");
            }
            erase(Iterator(head_, tail_, head_));
        }

        void pop_back()
        {
            if(empty()) {
                throw std::range_error("empty");
            }
            erase(Iterator(head_, tail_, tail_));
        }

        T& front()
        {
            if(empty()) {
                throw std::range_error("empty");
            }
            return head_->getElement();
        }

        T& back()
        {
            if(empty()) {
                throw std::range_error("empty");
            }
            return tail_->getElement();
        }

        T& at(size_t index)
        {
            if (index >= size_) {
                throw std::range_error("not possible");
            }

            Node* N = node_walker(index);
            return N->getElement();
        }

        void reverse()
        {	
            Node* start = tail_;
            
            while (start != nullptr) {
                Node* swap = start->getPrev();

                start->setPrev(start->getNext());
                start->setNext(swap);
                start = start->getNext();
            }

            Node* fortail = head_;
            head_ = tail_;
            tail_= fortail;
        }

        DoublyLinkedList<T>& operator =(DoublyLinkedList<T>& other)
        {
                clear();
                for (auto p = other.begin(); p != other.end(); ++p) {
                    push_back(*p);
                }
            return *this;
        }

        bool operator ==(DoublyLinkedList<T>& other)
        {
            if (this->size_ != other.size_) {
                return false;
            }

            auto comp1 = this->begin();
            auto comp2 = other.begin();

            while ((comp1 != this->end() && comp2 != other.end())) {
                if (*comp1 != *comp2) {
                    return false;
                }
                ++comp1;
                ++comp2;
            }
            return true;
        }

        bool operator !=(DoublyLinkedList<T>& other)
        {
            if (this->size_ != other.size_ ) {
                return true;
            }
            return false;
        }
        
    private:
        
        Node* head_ = nullptr;
        Node* tail_ = nullptr;
        size_t size_ = 0;
};

#endif