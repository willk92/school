/*
William Kelley
CS415-Operating Systems
Command Line Interpreter

Sources:
https://stackoverflow.com/questions/16285623/how-to-get-the-to-get-path-to-the-current-file-pwd-in-linux-from-c/16285723#16285723
*/

#ifdef __unix__
    #define IS_POSIX 1
    #define _BSD_SOURCE
#else
    #define IS_POSIX 0
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

string showPWD();

int main (int argv, char **argc)
{
    fstream file("output.txt", ios::in | ios::out | ios::app);
    
    cout << "--- Wheel's Shell ---\n\n\n";

    string input;
    string command;
    string pieces[2];

    while(input != "exit") {
        input.clear();
        cout << "wheelsh::";
        getline(cin, input);

        if(input[0] == '>') {
            pieces[0] = input.substr(0, input.find(' '));
            pieces[0] = pieces[0].erase(0,1);

            if(pieces[0] == "cd") {
                pieces[1] = input.substr(input.find(' '));
                pieces[1] = pieces[1].erase(0,1);
                int chDirSuccess = chdir(pieces[1].c_str());
                if(chDirSuccess >= 0) {
                    cout << showPWD() << endl;
                }
                else {
                    cout << "chdir() failed" << endl;
                }
            }
            else if (pieces[0] == "pwd") {
                file << showPWD();
                cout << "pwd printed to output.txt" << endl;
            }
            else {
                cout << "No valid command entered" << endl;
            }
        }
        else if (input[0] == '<') {
            cout << "Requested file: " << input << endl;
            input.erase(0,1);
            fin.open(input.c_str());
            getline(fin, command);
            fin.close();
        }
        else if (input == "exit") {
            cout << "Good bye!" << endl;
        }
        else {
            cout << "No valid command entered\n";
        }
    }

    return 0;
}

string showPWD() {
    string Result;
    if (IS_POSIX == 1) {
        char buffer[500];
        FILE *output;

        // read output of a command
        output = popen("/bin/pwd", "r");
        char *pwd = fgets(buffer, sizeof(buffer), output);

        // strip '\n' on ending of a line
        pwd = strtok(pwd, "\n");

        Result = "\nPath info:";
        Result += pwd;
    }
    return Result;
}