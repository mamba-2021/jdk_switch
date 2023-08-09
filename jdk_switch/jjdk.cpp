#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread> 
#include <fstream>
#include <experimental/filesystem>
using namespace std;

/*获取当前路径*/

string getpath() {
    std::experimental::filesystem::path path = std::experimental::filesystem::current_path();
    //std::cout << "当前工作目录: " << path.string() << std::endl;
    return path.string();
}

string path = getpath();
string jdk8 = path + "\\java\\java8\\bin";
string jdk11 = path+"\\java\\java11\\bin";

void jdk8_s() {
   
    string setCmd = "setx /M PATH \"" + jdk8 + ";%PATH%\" > nul 2>&1"; // 将错误信息重定向到空设备
    bool a = system(setCmd.c_str());    // 设置新的 JDK 环境变量

    if (a == 0) {
        cout << "成功切换到" << jdk8 << endl;
    }
    else if (a == 1) {
        cout << "请使用管理员运行" << endl;
    }
}

void jdk11_s() {
    string setCmd = "setx /M PATH \"" + jdk11 + ";%PATH%\" > nul 2>&1"; // 将错误信息重定向到空设备
    bool a = system(setCmd.c_str());    // 设置新的 JDK 环境变量
    if (a == 0) {
        cout << "成功切换到" << jdk11 << endl;
    }
    else if (a == 1) {
        cout << "请使用管理员运行" << endl;
    }
}

int main() {
    string new_jdk_path;
    cout << "请输入切换JDK（jdk8/jdk11）: ";
    cin >> new_jdk_path;

    if (new_jdk_path == "jdk8") {
        jdk8_s();
    }
    else if (new_jdk_path == "jdk11") {
        jdk11_s();
    }
    else {
        cout << "请输入正确的版本" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        return 0;
    }
   

    // 延时3秒
    this_thread::sleep_for(chrono::seconds(3));

    return 0;
}
