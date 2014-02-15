//
//  main.cpp
//  cppzapoctova
//
//  Created by Lukáš Machalík on 10.02.14.
//  Copyright (c) 2014 Machalik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream infile("test1.stack");
    string line;
    vector<pair<string,int>> radky;
    vector<int> stack;
    
    while (getline(infile, line))
    {
        istringstream iss(line);
        
        string prikaz;
        iss >> prikaz;
        int parametr = 0;
        iss >> parametr;
        
        radky.push_back(make_pair(prikaz,parametr));
    }
    
    for (auto i = radky.begin(); i != radky.end(); i++) {
        string prikaz = (*i).first;
        int parametr = (*i).second;
        //cout << prikaz << " " << parametr << endl;
        
        if (!prikaz.compare("ADD")) {
            
            stack[0] = stack[0] + stack[1];
            stack.erase(stack.begin()+1);
            
        } else if (!prikaz.compare("SUB")) {
            
            stack[0] = stack[1] - stack[0];
            stack.erase(stack.begin()+1);
            
        } else if (!prikaz.compare("HALT")) {
            
            for (auto j = stack.begin(); j != stack.end(); j++) {
                cout << *j << endl;
            }
            
        } else if (!prikaz.compare("LD")) {
            
            stack.insert(stack.begin(), parametr);
            
        } else if (!prikaz.compare("JMP")) {
            
            i += parametr-1;
            
        } else if (!prikaz.compare("JZ")) {
            
            if (stack[0] == 0) {
                i += parametr-1;
            }
            stack.erase(stack.begin());
            
        } else if (!prikaz.compare("JP")) {
            
            if (stack[0] > 0) {
                i += parametr-1;
            }
            stack.erase(stack.begin());
            
        } else if (!prikaz.compare("DUP")) {
            
            int value = stack[parametr];
            stack.insert(stack.begin(), value);
            
        } else if (!prikaz.compare("ST")) {
            
            stack[parametr] = stack[0];
            stack.erase(stack.begin());
            
        }
    }
    
    
    
    return 0;
}

