#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "globalFile.h"
using namespace std;

class OrderFile {
    public :
        OrderFile();
        void updateOrder();
        void mapInsert(map <string, string> & order, string entry);
        int getSize();
        map<int, map<string, string>> & getOrderData();

    private :    
        // key: order number, value: order information (key: order attribute, value: order value)
        map<int, map<string, string>> orderData;
        int size;
};