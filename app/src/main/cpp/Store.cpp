//
//  Store.cpp
//  KeyValueStore
//
//  Created by James Hunt on 4/14/19.
//  Copyright © 2019 James Hunt. All rights reserved.
//

#include "Store.hpp"

std::string Store::getVal(std::string key) {
    return *(rootNode->get(std::move(key)));
};

void Store::putVal(std::string key, std::string value) {
    if(rootNode) {
        rootNode->insert(&rootNode, key, value);
    } else {
        rootNode = new Node(key, value);;
    }
}

Store::~Store() {
    delete rootNode;
}
