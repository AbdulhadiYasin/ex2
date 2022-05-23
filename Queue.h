//
//  Queue.hpp
//  mtmchkin
//
//  Created by Abdul Hadi Yasin on 23/05/2022.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
#include "QueueNode.hpp"
using namespace std;

// One function works for all data types.
// This would work even for user defined types
// if operator '>' is overloaded
template <class T> class Queue {
public:
    
    /**
     * C'tor of Queue class
    */
    Queue(): m_size(0), m_head(NULL), m_tail(NULL) {
        // Initialize an empty queue.
    }
    
    /**
     * D'tor of Queue class
    */
    ~Queue<T>() {
        delete[] m_head;
        m_head = NULL;
        m_tail = NULL;
    }
    
    Queue& operator=(const Queue& other) {
        if (this == &other)
            return *this;
        
        delete m_head;
        m_head = NULL;
        m_tail = NULL;
        m_size = 0;
        
        QueueNode<T> oNode = other.m_head;
        while(oNode != NULL){
            pushBack(oNode.getValue());
            m_size += 1;
            
            oNode = oNode.getNext();
        }
        
        return *this;
    }
    
    Queue(const Queue& other): m_size(other.m_size), m_head(NULL), m_tail(NULL) {
        QueueNode<T> oNode = other.m_head;
        while(oNode != NULL){
            pushBack(oNode.getValue());
            m_size += 1;
            
            oNode = oNode.getNext();
        }
    }
    
    /**
     * Inserts the item to the end of the queue.
     * @param item - The item to be inserted.
     */
    void pushBack(const T& item) {
        if(m_tail != NULL){
            m_tail = m_tail->addNext(item);
            m_size++;
        } else if (m_head == NULL){
            m_head = QueueNode<T>(item);
            m_tail = m_head;
            m_size++;
        } else {
            // * Shouldn't reach here.
        }
    }
    
    /**
     * Returns the first item in the queue.
     * @return The item at the start of the queue, if there's no such item returns NULL.
     */
    T front() const {
        if(m_head == NULL)
            return NULL;
        
        return m_head.getValue();
    }
    
    /**
     * Removes the first item from the queue. If the queue is empty (aka size = 0), does nothing.
     */
    void popFront() {
        if(m_head == NULL)
            return; // There's no thing to do here.
        
        QueueNode<T> second = m_head.getNext();
        m_head.setNext(NULL);
        
        if(m_tail == m_head){
            // When tail and head are the same, then should delete tail as well.
            m_tail = NULL;
        }
        
        delete m_head;
        m_head = second;
        
        if(m_head == NULL)
            m_tail = NULL;
        
        m_size -= 1;
    }
    
    /**
     * Returns number of items in the queue, or zero if when the receiver is empty.
     * @return Number of items.
     */
    int size() const;
    
    class Iterator;
    Iterator begin() const {
        return Iterator(this, m_head);
    }
    Iterator end() const {
        return Iterator(this, NULL);
    }
private:
    int m_size = 0;
    QueueNode<T> m_head = NULL;
    QueueNode<T>* m_tail = NULL;
};

template<class T>
class Queue<T>::Iterator {
    const Queue<T>* m_queue;
    QueueNode<T> m_current = NULL;
    Iterator(const Queue<T>* queue, QueueNode<T> node): m_queue(queue), m_current(node) {
        // Initialize an iterator instance.
    }
    
    friend class Queue<T>;
public:
    const T& operator*() const {
        assert(m_current != NULL);
        return m_current.getValue();
    }
    const T* operator->() const {
        assert(m_current != NULL);
        return &(m_current.getValue());
    }
    
    Iterator& operator++() {
        m_current = m_current.getNext();
        return *this;
    }
    
    Iterator operator++(int) {
        Iterator result = *this;
        ++*this;
        return result;
    }
    
    bool operator==(const Iterator& iterator) const {
        assert(m_queue == iterator.m_queue);
        return m_current == iterator.m_current;
    }
    
    bool operator!=(const Iterator& iterator) const {
        return !(*this == iterator);
    }
    
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
};

template<class T> Queue<T> filter(Queue<T> queue, bool (*predicate)(T)){
    if(queue == NULL || predicate == NULL)
        return NULL;
    
    Queue<T> newQueue = Queue<T>();
    for(typename Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i) {
        /* Handle filtering */
        if(predicate(*i)){
            // Should keep item in filtered queue.
            newQueue.pushBack(*i);
        }
    }
    
    return newQueue;
}

template<class T> void transform(Queue<T> queue, void (*transformer)(T*)){
    if(queue == NULL || transformer == NULL)
        return;
    
    for(typename Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i) {
        /* Handle filtering */
        transformer(*i);
    }
}


#endif /* Queue_hpp */
