#include "../include/ComputerRoom.h"

ComputerRoom::ComputerRoom() {

}

ComputerRoom::ComputerRoom(int computerRoomId, int maxNum) {
    this->computerRoomId = computerRoomId;
    this->maxNum = maxNum;
}

int ComputerRoom::getComputerRoomId() {
    return this->computerRoomId;
}

int ComputerRoom::getMaxNum() {
    return this->maxNum;
}