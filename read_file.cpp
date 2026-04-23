#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int open_and_read_file()
{
    ifstream file("data.txt");
    if(!file) {
        cerr << "Error opening file!\n";
        return 1;
    }
    string line;
    

    file.close();
    return 0;
}
