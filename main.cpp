/* 
 * File:   main.cpp
 * Author: Soloist Dio
 *
 * Created on 25 Май 2014 г., 17:43
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


/*
 * 
 */

int main(int argc, char** argv) {
    ifstream inStream;
    inStream.open("E:\\programs\\microsql\\nbproject\\rootf\\conf.txt");
    
    if (inStream.fail()) {
       cout << "file is opening. \n";
       exit(true);
    }
       
    char symbol;
    string root_folder;
 
    while (! inStream.eof()) {
        inStream.get(symbol);
        root_folder.push_back(symbol);
    }
    inStream.close();
    
    int pos = root_folder.find_first_not_of("root_folder", 0);
    int posn = root_folder.find('\n', pos);
    
    string newstr = root_folder.substr(pos, posn);
    pos = newstr.find('\"', 0);
    posn = newstr.find('\"', pos+1);
    
    newstr = newstr.substr(pos, posn);
    
    cout << newstr;
    return 0;
}

