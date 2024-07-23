#pragma once
#include <iostream>
using namespace std;

class ComputerRoom {
    private :
        int computerRoomId;
        int maxNum;

    public :
        ComputerRoom(); 
        ComputerRoom(int computerRoomId, int maxNum);  
        int getComputerRoomId();
        int getMaxNum(); 
};