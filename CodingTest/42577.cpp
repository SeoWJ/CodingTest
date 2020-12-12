#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    Node* child[10] = { NULL };
};

class Tree {
public:
    Node* root;
    Tree() { root = new Node(); }
};

bool compare(string s1, string s2);
bool solution(vector<string> phone_book);

int main() {
    vector<string> phone_book;
    phone_book.push_back("119");
    phone_book.push_back("97674223");
    phone_book.push_back("1195524421");

    cout << solution(phone_book) << endl;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), compare);

    Tree* t = new Tree();
    
    for (unsigned int y = 0; y < phone_book.size(); y++) {
        bool success = true;
        Node* iter = t->root;

        for (unsigned int x = 0; x < phone_book[y].size(); x++) {
            if (iter->child[phone_book[y][x] - '0'] != NULL) {
                iter = iter->child[phone_book[y][x] - '0'];
            }
            else {
                success = false;
                iter->child[phone_book[y][x] - '0'] = new Node;
                iter = iter->child[phone_book[y][x] - '0'];
            }
        }

        if (success == true) {
            answer = false;
            break;
        }
    }
    
    return answer;
}

bool compare(string s1, string s2) {
    if (strlen(s1.c_str()) == strlen(s2.c_str())) {
        int result = strcmp(s1.c_str(), s2.c_str());

        if (result < 0)
            return true;
        else
            return false;
    }
    else
        return strlen(s1.c_str()) > strlen(s2.c_str());
}