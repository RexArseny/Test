#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = filesystem;

void search(fs::path dir)
{
    for (auto& i : fs::directory_iterator(dir))
    {
        fs::path temp = i.path();
        if (temp.empty()) continue;
        if (temp.extension() == ".txt")
        {
            string text;
            ifstream input(temp);
            input >> text;
            ofstream res("D:/result.txt", ios::app);
            res << text;
        }
        else search(temp);
    }
}

int main()
{
    char dir[10] = "D:/a/b";

    search(dir);

    return 0;
}
