#include <iostream>
#include "Parse.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, int> variables;

int checkOutput(){
    read_next_token();
    if(next_token_type == NUMBER){
        return token_number_value;
    }
    string next = next_token();
    if(next.compare("+") == 0){return checkOutput() + checkOutput();}
    else if(next.compare("-") == 0){return checkOutput() - checkOutput();}
    else if(next.compare("*") == 0){return checkOutput() * checkOutput();}
    else if(next.compare("/") == 0){return checkOutput() / checkOutput();}
    else if(next.compare("%") == 0){return checkOutput() % checkOutput();}
    else if(next.compare("&&") == 0){return checkOutput() && checkOutput();}
    else if(next.compare("||") == 0){return checkOutput() || checkOutput();}
    else if(next.compare("<") == 0){return checkOutput() < checkOutput();}
    else if(next.compare(">") == 0){return checkOutput() > checkOutput();}
    else if(next.compare("==") == 0){return checkOutput() == checkOutput();}
    else if(next.compare("!=") == 0){return checkOutput() != checkOutput();}
    else if(next.compare("<=") == 0){return checkOutput() <= checkOutput();}
    else if(next.compare(">=") == 0){return checkOutput() >= checkOutput();}
    else if(next.compare("!") == 0){return !checkOutput();}
    else if(next.compare("~") == 0){return -1 * checkOutput();}

    return variables[next_token()];
}

void run() {
    read_next_token();
    while (next_token_type != END) {
        std::string next = next_token();
        if (next_token_type == NAME) {
            if (next.compare("text") == 0) {
                read_next_token();
                std::cout << next_token();
            } else if (next.compare("output") == 0) {
                std::cout << checkOutput();
            } else if (next.compare("var") == 0) {
                read_next_token();
                string varName = next_token();
                if (variables.count(next_token()) == 1) {
                    std::cout << "variable " << varName << " incorrectly re-initialized" << std::endl;
                }
                variables[varName] = checkOutput();
            } else if (next.compare("set") == 0) {
                read_next_token();
                string varName = next_token();
                if (variables.count(next_token()) == 0) {
                    std::cout << "variable " << varName << " not declared" << std::endl;
                }
                variables[varName] = checkOutput();
            }
        } else if (next_token_type == SYMBOL) {
            if (next.compare("//") == 0) {
                skip_line();
            }
        }
        read_next_token();
    }
}

int main(void) {
    set_input("extra_test10.blip");
    run();
}