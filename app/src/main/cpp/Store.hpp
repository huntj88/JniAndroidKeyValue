//
//  Store.hpp
//  KeyValueStore
//
//  Created by James Hunt on 4/14/19.
//  Copyright © 2019 James Hunt. All rights reserved.
//

#ifndef Store_hpp
#define Store_hpp

#include <stdio.h>
#include <string>
#include "Node.hpp"

class Store {
public:
    ~Store();
    std::string getVal(std::string key);
    void putVal(std::string key, std::string value);
private:
    Node * rootNode = nullptr;
};

#endif /* Store_hpp */
