#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread> 
#include <fstream>
#include <experimental/filesystem>
using namespace std;

/*��ȡ��ǰ·��*/

string getpath() {
    std::experimental::filesystem::path path = std::experimental::filesystem::current_path();
    //std::cout << "��ǰ����Ŀ¼: " << path.string() << std::endl;
    return path.string();
}

string path = getpath();
string jdk8 = path + "\\java\\java8\\bin";
string jdk11 = path+"\\java\\java11\\bin";

void jdk8_s() {
   
    string setCmd = "setx /M PATH \"" + jdk8 + ";%PATH%\" > nul 2>&1"; // ��������Ϣ�ض��򵽿��豸
    bool a = system(setCmd.c_str());    // �����µ� JDK ��������

    if (a == 0) {
        cout << "�ɹ��л���" << jdk8 << endl;
    }
    else if (a == 1) {
        cout << "��ʹ�ù���Ա����" << endl;
    }
}

void jdk11_s() {
    string setCmd = "setx /M PATH \"" + jdk11 + ";%PATH%\" > nul 2>&1"; // ��������Ϣ�ض��򵽿��豸
    bool a = system(setCmd.c_str());    // �����µ� JDK ��������
    if (a == 0) {
        cout << "�ɹ��л���" << jdk11 << endl;
    }
    else if (a == 1) {
        cout << "��ʹ�ù���Ա����" << endl;
    }
}

int main() {
    string new_jdk_path;
    cout << "�������л�JDK��jdk8/jdk11��: ";
    cin >> new_jdk_path;

    if (new_jdk_path == "jdk8") {
        jdk8_s();
    }
    else if (new_jdk_path == "jdk11") {
        jdk11_s();
    }
    else {
        cout << "��������ȷ�İ汾" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        return 0;
    }
   

    // ��ʱ3��
    this_thread::sleep_for(chrono::seconds(3));

    return 0;
}
