#include <algorithm>
#include "../include/Manager.h"
#include "../include/Menu.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
    this->name = name;
    this->password = pwd;
    this->initVector();
    this->initComputerRoom();
}

void Manager::initVector() {
    int fId;
    string fName;
    string fPwd;
    this->students.clear();
    this->teachers.clear();
    ifstream ifs(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
        Student s(fId, fName, fPwd);
        this->students.push_back(s);
    }
    ifs.close();
    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        return;
    }
    while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
        Teacher t(fId, fName, fPwd);
        this->teachers.push_back(t);
    }
    ifs.close();
}

void Manager::initComputerRoom() {
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
    cout << "当前机房数量为: " << this->computerRooms.size() << endl;
}

string Manager::getName() {
    return this->name;
}

void Manager::operate() {
    while (true) {
        Menu().showManagerMenu(this);
        int select = 0;
        cin >> select;
        if (select == 1) {
            cout << "添加账号" << endl;
            this->addPerson();
        } else if (select == 2) {
            cout << "查看账号" << endl;
            this->showPerson();
        } else if (select == 3) {
            cout << "查看机房" << endl;
            this->showComputer();
        } else if (select == 4) {
            cout << "清空预约" << endl;
            this->cleanFile();
        } else if (select == 0) {
            cout << "注销登录" << endl;
            delete this;
            return;
        } else {
            cout << "输入有误，请重新输入" << endl;
            return;
        }
    }

}

bool Manager::checkRepeat(int id, int type) {
    if (type == 1) {
        for (vector<Student>::iterator it = this->students.begin(); it != this->students.end(); it++) {
            if (id == it->getId()) {
                return true;
            }
        }
    } else if (type == 2) {
        for (vector<Teacher>::iterator it = this->teachers.begin(); it != this->teachers.end(); it++) {
            if (id == it->getId()) {
                return true;
            }
        }
    }
    return false;
}

void Manager::addPerson() {
    cout << "请输入添加账号的类型" << endl;
    cout << "1.添加学生" << endl;
    cout << "2.添加老师" << endl;
    string fileName;
    string tip;
    string errorTip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    if (select == 1) {
        fileName = STUDENT_FILE;
        tip = "请输入学号: ";
        errorTip = "学号重复，请重新输入";
    } else if (select == 2) {
        fileName = TEACHER_FILE;
        tip = "请输入职工号: ";
        errorTip = "职工号重复，请重新输入";
    } else {
        cout << "输入有误，请重新输入" << endl;
        return;
    }
    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout << tip << endl;
    while (true) {
        cin >> id;
        if (this->checkRepeat(id, select)) {
            cout << errorTip << endl;
        } else {
            break;
        }
    }
    cout << "请输入用户名: " << endl;
    cin >> name;
    cout << "请输入密码: " << endl;
    cin >> pwd;
    ofs << id << " " << name << " " << pwd << endl;
    cout << "添加成功" << endl;
    if (select == 1) {
        Student s(id, name, pwd);
        this->students.push_back(s);
    } else if (select == 2) {
        Teacher t(id, name, pwd);
        this->teachers.push_back(t);
    }
    ofs.close();
}

void printStudent(Student & s) {
    cout << "学号: " << s.getId() << " 姓名: " << s.getName() 
    << " 密码: " << s.getPassword() << endl;
}

void printTeacher(Teacher & t) {
    cout << "职工号: " << t.getId() << " 姓名: " << t.getName() 
    << " 密码: " << t.getPassword() << endl;
}

void Manager::showPerson() {
    cout << "请选择查看内容" << endl;
    cout << "1.查看学生" << endl;
    cout << "2.查看老师" << endl;
    int select = 0;
    cin >> select;
    if (select == 1) {
        for_each(this->students.begin(), this->students.end(), printStudent);
    } else if (select == 2) {
        for_each(this->teachers.begin(), this->teachers.end(), printTeacher);
    } else {
        cout << "输入有误，请重新输入" << endl;
    }
}

void Manager::showComputer() {
    cout << "机房信息如下: " << endl;
    for (vector<ComputerRoom>::iterator it = this->computerRooms.begin(); it != this->computerRooms.end(); it++) {
        cout << "机房编号: " << it->getComputerRoomId() << " 最大容量: " << it->getMaxNum() << endl;
    }
}

void Manager::cleanFile() {
    cout << "确定清空<Y/N>" << endl;
    char select;
    cin >> select;
    if (select != 'Y' && select != 'y') {
        cout << "取消清空" << endl;
        return;
    }
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "清空成功" << endl;
}