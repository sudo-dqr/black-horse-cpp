#include "../include/Menu.h"

void Menu::showMainMenu() {
    cout << "====================== 欢迎来到机房预约系统 =====================" << endl;
    cout << endl << "请输入您的身份" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1.学生代表           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2.老师               |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3.管理员             |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0.退出               |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择: " << endl;
}

void Menu::showManagerMenu(Manager *manager) {
    cout << "欢迎管理员: " << manager->getName() << " 登录!" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1.添加账号           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2.查看账号           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3.查看机房           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          4.清空预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0.注销登录           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择: " << endl;
}

void Menu::showStudentMenu(Student *student) {
    cout << "欢迎学生代表: " << student->getName() << " 登录!" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1.申请预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2.查看自身预约       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3.查看所有预约       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          4.取消预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0.注销登录           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择: " << endl;
}

void Menu::showTeacherMenu(Teacher *teacher) {
    cout << "欢迎老师: " << teacher->getName() << " 登录!" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1.查看所有预约       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2.审核预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0.注销登录           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择: " << endl;
}