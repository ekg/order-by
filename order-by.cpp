#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<string>
&split(const string &s,
       char delim,
       vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main(int argc, char** argv) {

    if (argc < 4) {
        cout << "usage: " << argv[0] << " [file1] [column] [file2]" << endl
             << "sort the first file according to the order of the field [column] in the second" << endl
             << "[file1] should have tab-delimited records, [file2] should be one-per-line" << endl;
        return 1;
    }

    map<string, long> order;
    map<long, list<string> > result;
    list<string> unordered;

    int col = atoi(argv[2]) - 1;
    ifstream f1, f2;
    f2.open(argv[3]);
    f1.open(argv[1]);
    string line;
    long idx = 0;

    while(getline(f2, line)) {
        order[line] = idx++;
    }

    while(getline(f1, line)) {
        vector<string> fields;
        split(line, '\t', fields);
        string key = fields[col];
        map<string, long>::iterator pos = order.find(key);
        if (pos == order.end()) {
            unordered.push_back(line);
        } else {
            result[pos->second].push_back(line);
        }
    }

    for (map<long, list<string> >::iterator r = result.begin(); r != result.end(); ++r) {
        for (list<string>::iterator l = r->second.begin(); l != r->second.end(); ++l) {
            cout << *l << endl;
        }
    }
    for (list<string>::iterator l = unordered.begin(); l != unordered.end(); ++l) {
        cout << *l << endl;
    }

    return 1;
}
