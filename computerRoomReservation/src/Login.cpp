#include "../include/Login.h"

void Login::login(string fileName, int type) {
    Identity * person = NULL;
    ifstream ifs(fileName, ios::in);
    if(!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    int id;
    string name;
    string pwd;
    if (type == 1) {
        cout << "请输入你的学号: " << endl;
        cin >> id;
    } else if (type == 2) {
        cout << "请输入你的职工号: " << endl;
        cin >> id;
    }
    cout << "请输入用户名: " << endl;
    cin >> name;
    cout << "请输入密码: " << endl;
    cin >> pwd;
    if (type == 1) {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if ((id == fId) && (fName == name) && (fPwd == pwd)) {
                cout << "学生验证登录成功! " << endl;
                person = new Student(id, name, pwd);
                person->operate();
                return;
            }
        }
    } else if (type == 2) {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if ((id == fId) && (fName == name) && (fPwd == pwd)) {
                cout << "教师验证登录成功! " << endl;
                person = new Teacher(id, name, pwd);
                person->operate();
                return;
            }
        }
    } else {
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {
            if ((fName == name) && (fPwd == pwd)) {
                cout << "管理员验证登录成功! " << endl;
                person = new Manager(name, pwd);
                person->operate();
                return;
            }
        }
    }
}