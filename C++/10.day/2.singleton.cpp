/*************************************************************************
	> File Name: 2.singleton.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Jun 2024 04:38:40 PM CST
 ************************************************************************/

#include <iostream>
#include <mutex>
using namespace std;

class HttpServer {
public :
    static HttpServer *getInstance() {
        if (instance == nullptr) {
            instance = new HttpServer();
        }
        return instance;
    }
    
private :
    static HttpServer *instance;
    HttpServer() {};
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() {};
};

HttpServer *HttpServer::instance = nullptr;

int main() {
    HttpServer *t1 = HttpServer::getInstance();
    HttpServer *t2 = HttpServer::getInstance();
    return 0;
}
