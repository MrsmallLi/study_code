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
#include <functional>

namespace my {

    std::string get_key(const std::pair<std::string, int> &v) {
        return v.first; 
    }

    class Node {
    public :
        typedef std::pair<std::string, int> value_type;
        Node(const value_type &data = value_type("", 0), Node *father = nullptr) 
        : data(data), lchild(nullptr), rchild(nullptr), father(father){}
        value_type data;
        Node *lchild, *rchild, *father;
    };
    class binary_search_tree {
    public : 
        typedef std::string key_type;
        typedef std::pair<std::string, int> value_type;
        typedef std::function<std::string(const value_type &)> select_key;
        binary_search_tree(select_key key) : key(key){}
        Node *getNewNode(const value_type &v, Node *father = nullptr) {
            Node *node = new Node(v, father);
            return node;
        }
        Node *insert(Node *root,const value_type &v, Node *father) {
            if (root == nullptr)  return getNewNode(v, father);
            if (key(root->data) == key(v)) return root;
            if (key(root->data) > key(v)) {
                root->lchild = insert(root->lchild, v, root);
            } else {
                root->rchild = insert(root->rchild, v, root);
            }
            return root;
        }
        Node *find(Node *root,const key_type &k) {
            if (root == nullptr) return root;
            if (key(root->data) == k) return root;
            if (key(root->data) > k) return find(root->lchild, k);
            else return find(root->rchild, k);
        }
        static Node *leftmost(Node *root) {
            Node *temp = root;
            while (temp->lchild) temp = temp->lchild;
            return temp;
        }
        static Node *successors(Node *root) {
            if (root->rchild) return leftmost(root->rchild);
            Node *father = root->father;
            while (root != father->lchild) {
                root = father;
                father = root->father;
            }
            return father;
        }
    private :
        select_key key;
    };

    class binary_search_tree_iterator {
    public :
        typedef std::pair<std::string, int> value_type;
        typedef binary_search_tree_iterator iterator;
        binary_search_tree_iterator(Node *node) : node(node) {}
        value_type *operator->() {
            return &node->data;
        }
        bool operator==(const binary_search_tree_iterator &iter) {
            return node == iter.node;
        }
        bool operator!=(const binary_search_tree_iterator &iter) {
            return !(*this == iter);
        }
        iterator operator++(int) {
            binary_search_tree_iterator iter(*this);
            node = binary_search_tree::successors(node);
            return iter;
        }
        iterator &operator++() {
            node = binary_search_tree::successors(node);
            return *this;
        }
        value_type &operator*() { return node->data; }
    private :
        Node *node;
    };
    class map {
    public :
        typedef std::string key_type;
        typedef int data_type;
        typedef std::pair<key_type, data_type> value_type;
        typedef binary_search_tree_iterator iterator;
        map() : tree(get_key), root(new Node()){}
        iterator begin() {
            return tree.leftmost(root->lchild);
        }
        iterator end() { return root; }
        iterator find(const key_type &key) {
            Node *ret = tree.find(root->lchild, key);
            if (ret == nullptr) return root;
            return ret;
        }
        data_type &operator[](const std::string &key_value) {
            if (find(key_value) == end()) {
                root->lchild = tree.insert(root->lchild, value_type(key_value, 0), root);
            }
            return find(key_value)->second;
        }
    private :
        binary_search_tree tree;
        Node *root;
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

    for (std::map<std::string, int>::iterator iter = std_map.begin(); iter != std_map.end(); iter++) {
        std::cout << iter->first << " " << iter->second << std::endl; 
    }
    my_map["hello"] = 123;
    my_map["world"] = 456;
    my_map["Li"] = 2131;
    my_map["gege"] = 12314;
    std::cout << my_map["gege"] << std::endl;
    std::cout << my_map["hello"] << std::endl;
    std::cout << my_map["Li"] << std::endl;
    std::cout << my_map["gege"] << std::endl;
    std::cout << "=================================" << std::endl;
    for (my::map::iterator iter = my_map.begin(); iter != my_map.end(); iter++) {
        std::cout << iter->first << " " << iter->second << std::endl; 
    }
    for (auto x : my_map) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    return 0;
}
