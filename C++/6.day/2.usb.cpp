/*************************************************************************
	> File Name: 2.usb.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 May 2024 11:31:39 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class USB_interface {
public :
    virtual string get() = 0;
    virtual void set(string) = 0;
    string msg;
};


class KeyBoard : public USB_interface {
public :
    string get() override {
        return "this messge come from key  board\n";
    }
    void set(string msg) {
        cout << "key borad receive msg : " << msg << endl;
    }
};
class Mouse : public USB_interface {
public :
    string get() override {
        return "mouse dida dida\n";
    }
    void set(string msg) {
        cout << "mouse receive msg" << msg << endl;
    }
};


int main() {
    srand(time(0));
    USB_interface *usb[2];
    int ind = rand() % 2;
    usb[ind] = new KeyBoard();
    usb[1 - ind] = new Mouse();
    for (int i = 0; i < 2; i++) {
        cout << "USB #" << i << ":" << endl;
        cout << usb[i]->get() << endl;
        usb[i]->set("over done!");
    } 
    return 0;
}
