#include <string>


#ifndef enumName.cpp
#define enumName.cpp

using namespace std;

string static names[] ={"CM","m","km","sec","min","hour","g","kg","ton"};

string static getEnumName(int i) {
    return names[i];
}

#endif