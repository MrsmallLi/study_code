/*************************************************************************
	> File Name: 2.my_map.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Apr 2024 07:36:05 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <iterator>

namespace my {
    class map {
    public :
        map() : arr(new int[100]), size(100), flag(new int[100]) {
            memset(flag, 0, sizeof(int) * size);
        }
        //这里运用到了哈希表的防冲突的知识点
        int &operator[](const char *s) {
            int ind; 
            for (int i = 0; s[i]; i++) {
                ind = (ind + s[i]) % size;
            }
            int time = 1;
            while (ind < 100 && !flag[ind]) {
                ind += time * time; 
                ind %= size;
                time++;
            }
            return arr[ind];
        }
        int *arr;
        int size;
        int *flag;
    };

};


int main() {
    std::map<std::string, int> std_map; 
    //对于模板还没有学习，所以这里直接创建对象
    //要求就是下面的效果和std::map效果是一样的
    my::map my_map;
    std_map["hello"] = 123;
    std_map["world"] = 456;
    std_map["Li"] = 2131;
    std_map["gege"] = 12314;
    std::cout << std_map["gege"] << std::endl;

    for (auto x : std_map) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    my_map["hello"] = 123;
    my_map["world"] = 456;
    my_map["Li"] = 2131;
    my_map["gege"] = 12314;
    std::cout << my_map["gege"] << std::endl;
    /*
    for (auto x : my_map) {
        
    }
    */
    return 0;
}
