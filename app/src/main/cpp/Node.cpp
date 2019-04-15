//
//  Node.cpp
//  KeyValueStore
//
//  Created by James Hunt on 4/14/19.
//  Copyright © 2019 James Hunt. All rights reserved.
//

#include <iostream>
#include "Node.hpp"

Node::Node(std::string key, std::string value) {
    this->key = key;
    this->value = value;
}

void Node::insert(Node ** rootNode, std::string newKey, std::string newValue) {

    // replace value of existing node with matching key
    if(newKey == key) {
        value = newValue;
        return;
    }

    // replace as the root if less than first node
    if(newKey < key) {
        auto newNode = new Node(newKey, newValue);
        newNode->next = this;
        *rootNode = newNode;
        return;
    }

    // if a next node exists and the new node should fit between this node and the next
    if(next && newKey > key && newKey < next->key) {
        auto newNode = new Node(newKey, newValue);
        newNode->next = next;
        next = newNode;
    } else if(!next) {
        // if no next node, then set the new one as the next
        next = new Node(newKey, newValue);
    } else {
        // if next exists delegate the next node to handle insert
        next->insert(rootNode, newKey, newValue);
    }
}

std::string * Node::get(std::string key) {
    if(this->key == key) {
        return &value;
    } else if(next) {
        return next->get(key);
    } else {
        return nullptr;
    }
}

Node::~Node() {
    delete next;
}
