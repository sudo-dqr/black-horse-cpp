#include "../include/orderFile.h"

OrderFile::OrderFile() {
    ifstream ifs(ORDER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        this->size = 0;
        ifs.close();
        return;
    }
    string date;
    string interval;
    string stuId;
    string stuName;
    string roomId;
    string status;
    this->size = 0;
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
        map<string, string> order;
        mapInsert(order, date);
        mapInsert(order, interval);
        mapInsert(order, stuId);
        mapInsert(order, stuName);
        mapInsert(order, roomId);
        mapInsert(order, status);
        this->orderData.insert(make_pair(this->size, order));
        this->size++;
    }
    ifs.close();
}

void OrderFile::mapInsert(map<string, string> & order, string entry) {
    int pos = entry.find(":");
    if (pos != -1) {
        string key = entry.substr(0, pos);
        string value = entry.substr(pos + 1, entry.size() - pos - 1);
        order.insert(make_pair(key, value));
    }
}

void OrderFile::updateOrder() {
    if (this->size == 0) {
        return;
    }

    ofstream ofs(ORDER_FILE, ios::trunc | ios::out);
    for (int i = 0; i < this->size; i++) {
        ofs << "date:" << this->orderData[i]["date"] << " ";
        ofs << "interval:" << this->orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->orderData[i]["roomId"] << " ";
        ofs << "status:" << this->orderData[i]["status"] << endl;
    }
}

int OrderFile::getSize() {
    return this->size;
}

map<int, map<string, string>> & OrderFile::getOrderData() {
    return this->orderData;
}