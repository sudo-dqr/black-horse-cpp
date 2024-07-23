#include "../include/Student.h"
#include "../include/Menu.h"

Student::Student() {

}

Student::Student(int id, string name, string pwd) {
    this->id = id;
    this->name = name;
    this->password = pwd;
    this->initComputerRoom();
}

void Student::initComputerRoom() {
    this->computerRooms.clear();
    ifstream ifs(COMPUTER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    int roomId;
    int maxNum;
    while (ifs >> roomId && ifs >> maxNum) {
        ComputerRoom c(roomId, maxNum);
        this->computerRooms.push_back(c);
    }
    ifs.close();
}

void Student::operate() {
    while (true) {
        Menu().showStudentMenu(this);
        int select = 0;
        cin >> select;
        if (select == 1) {
            this->applyOrder();
        } else if (select == 2) {
            this->showMyOrder();
        } else if (select == 3) {
            this->showAllOrder();
        } else if (select == 4) {
            this->cancelOrder();
        } else if (select == 0) {
            cout << "注销成功" << endl;
            delete this;
            return;
        } else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
}

void Student::applyOrder() {
    cout << "机房开放时间为周一至周五!" << endl;
    cout << "请输入申请预约的时间:" << endl;
    cout << "1.周一" << endl;
    cout << "2.周二" << endl;
    cout << "3.周三" << endl;
    cout << "4.周四" << endl;
    cout << "5.周五" << endl;
    int date = 0;
    int interval = 0;
    int room = 0;
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "请输入申请预约的时间段:" << endl;
    cout << "1.上午" << endl;
    cout << "2.下午" << endl;
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "请选择机房:" << endl;
    cout << "机房信息如下:" << endl;
    for (vector<ComputerRoom>::iterator it = this->computerRooms.begin(); it != this->computerRooms.end(); it++) {
        cout << "机房编号: " << it->getComputerRoomId() << " 机房最大容量: " << it->getMaxNum() << endl;
    }
    while (true) {
        cin >> room;
        if (room >= 1 && room <= this->computerRooms.size()) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "预约成功!审核中" << endl;
    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->id << " ";
    ofs << "stuName:" << this->name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;
    ofs.close();
}

void Student::showMyOrder() {
    OrderFile of;
    if (of.getSize() == 0) {
        cout << "无预约记录" << endl;
        return;
    }
    map<int, map<string, string>> orderData = of.getOrderData();
    for (int i = 0; i < of.getSize(); i++) {
        if (atoi(orderData[i]["stuId"].c_str()) == this->id) {
            cout << "预约日期: 周" << orderData[i]["date"];
            cout << " 时段: " << (atoi(orderData[i]["interval"].c_str()) == 1 ? "上午" : "下午");
            cout << " 机房编号: " << orderData[i]["roomId"];
            string status = " 状态: ";
            if (atoi(orderData[i]["status"].c_str()) == 1) {
                status += "审核中";
            } else if (atoi(orderData[i]["status"].c_str()) == 2) {
                status += "预约成功";
            } else if (atoi(orderData[i]["status"].c_str()) == -1) {
                status += "审核不通过";
            } else {
                status += "预约已取消";
            }
            cout << status << endl;
        }
    }
}

void Student::showAllOrder() {
    OrderFile of;
    if (of.getSize() == 0) {
        cout << "无预约记录" << endl;
        return;
    }
    map<int, map<string, string>> orderData = of.getOrderData();
    for (int i = 0; i < of.getSize(); i++) {
        cout << "预约日期: 周" << orderData[i]["date"];
        cout << " 时段: " << (atoi(orderData[i]["interval"].c_str()) == 1 ? "上午" : "下午");
        cout << " 学号: " << orderData[i]["stuId"];
        cout << " 姓名: " << orderData[i]["stuName"];
        cout << " 机房编号: " << orderData[i]["roomId"];
        string status = " 状态: ";
        if (atoi(orderData[i]["status"].c_str()) == 1) {
            status += "审核中";
        } else if (atoi(orderData[i]["status"].c_str()) == 2) {
            status += "预约成功";
        } else if (atoi(orderData[i]["status"].c_str()) == -1) {
            status += "审核不通过";
        } else {
            status += "预约已取消";
        }
        cout << status << endl;
    }

}

void Student::cancelOrder() {
    OrderFile of;
    if (of.getSize() == 0) {
        cout << "无预约记录" << endl;
        return;
    }
    map<int, map<string, string>> & orderData = of.getOrderData(); // 注意这里 返回引用也要用引用接收
    cout << "审核中或预约成功的记录可以取消,请输入取消的记录" << endl;
    int index = 1;
    vector<int> v; // 存放有效预约
    for (int i = 0; i < of.getSize(); i++) {
        if (this->id == atoi(orderData[i]["stuId"].c_str())) {
            if (atoi(orderData[i]["status"].c_str()) == 1 || atoi(orderData[i]["status"].c_str()) == 2) {
                v.push_back(i);
                cout << index++ << ". ";
                cout << "预约日期: 周" << orderData[i]["date"];
                cout << " 时段: " << (atoi(orderData[i]["interval"].c_str()) == 1 ? "上午" : "下午");
                cout << " 机房编号: " << orderData[i]["roomId"];
                string status = " 状态: ";
                if (atoi(orderData[i]["status"].c_str()) == 1) {
                    status += "审核中";
                } else if (atoi(orderData[i]["status"].c_str()) == 2) {
                    status += "预约成功";
                }
                cout << status << endl;
            }
        }
    }
    cout << "请输入取消的记录, 输入0返回" << endl;
    int select = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select != 0) {
                orderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "取消成功" << endl;
            }
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
}

int Student::getId() {
    return this->id;
}

string Student::getName() {
    return this->name;
}

string Student::getPassword() {
    return this->password;
}