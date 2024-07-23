#include <iostream>
#include "../include/Login.h"
#include "../include/Menu.h"
using namespace std;

int main() {
    int select = 0;
    while (true) {
        Menu().showMainMenu();
        cin >> select;
        switch (select) {
            case 1:
                Login().login(STUDENT_FILE, 1);
                break;
            case 2:
                Login().login(TEACHER_FILE, 2);
                break;
            case 3:
                Login().login(ADMIN_FILE, 3);
                break;
            case 0:
                cout << "欢迎下一次使用" << endl;
                return 0;
            default:
                cout << "输入有误，请重新输入" << endl;
                break;
        }
    }

    return 0;
}