#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
    for (int j = 1; j < argc; j++) {
        Stack s;
        bool match = true;
        bool tooManyClose = false;

        for (int i = 0; i < strlen(argv[j]); i++) {
            char currentChar = argv[j][i];

            switch (currentChar) {
                case '[':
                case '{':
                    s.push(currentChar);
                    break;
                case ']':
                    char data = s.pop();
                    if (data != '[') {
                        match = false;
                    }
                    if (data == '\0') {
                        tooManyClose = true;
                    }
                    break;
                case '}':
                    char data = s.pop();
                    if (data != '{') {
                        match = false;
                    }
                    if (data == '\0') {
                        tooManyClose = true;
                    }
                    break;
                default:
                    break;
            }

            if (!match) {
                break;
            }
        }

        if (s.getSize() > 0) {
            match = false;
        }

        if (!match) {
            cout << "Parentheses do not match ";
            if (tooManyClose) {
                cout << "with too many closing parentheses" << std::endl;
            } else if (s.getSize() > 0) {
                cout << "with too many open parentheses" << std::endl;
            } else {
                cout << std::endl;
            }
        } else {
            cout << "Parentheses match" << std::endl;
        }
    }
}




