//
//  QueueNode.hpp
//  mtmchkin
//
//  Created by Abdul Hadi Yasin on 23/05/2022.
//

#ifndef QueueNode_hpp
#define QueueNode_hpp

#include <stdio.h>

template <class T> class QueueNode {
public:
    /**
     * C'tor of QueueNode class
     *
     * @param value - The value of the node.
    */
    QueueNode(const T& value): m_value(value) {
        // Initialize node.
    }
    
    /**
     * D'tor of Queue class
    */
    ~QueueNode() {
        delete[] m_value;
        delete[] m_next;
    }
    
    /**
     * Returns node's value.
     *
     * @return Value of the receiver.
    */
    T getValue() const {
        return m_value;
    }
    
    /**
     * Sets the receiver (Node) to a new value.
     *
     * @param newValue - The new value to set.
     * @return
     *      Value of the receiver.
    */
    T setValue(T newValue) {
        m_value = newValue;
    }
    
    /**
     * Adds a new node after the receiver with the provided newValue.
     *
     * @param newNext - The value to add as the next node of the receiver.
     * @return A reference to the node after the receiver after the update.
    */
    QueueNode addNext(const T& newNext) {
        QueueNode newNode(newNext);
        newNode.setNext(m_next);
        m_next = newNode;
        return newNode;
    }
    
    /**
     * Returns reference to the node after the receiver.
     *
     * @return A reference to the node after the receiver, if there's no such node returns NULL.
    */
    QueueNode getNext() const {
        return m_next;
    }
    
    /**
     * Sets the node after the receiver (Node) to be a new node.
     * @note You are responsible of deleting the previous `next` when needed.
     *
     * @param newNext - The other node to set as next of the receiver.
     * @return A reference to the node that was after the receiver before the update. Or NULL if there wasn't.
    */
    QueueNode setNext(QueueNode newNext) {
        QueueNode oldNext = m_next;
        m_next = newNext;
        return oldNext;
    }
    
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    QueueNode(const QueueNode&) = default;
    QueueNode& operator=(const QueueNode& other) = default;
    
private:
    T m_value;
    QueueNode m_next = NULL;
};

#endif /* QueueNode_hpp */
