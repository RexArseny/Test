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
        if (temp.extension() == ".txt")
        {
            string text;
            ifstream input(temp);
            input >> text;
            ofstream res("D:/a/result.txt", ios::app);
            res << text;
        }
        else search(temp);
    }
}

int main()
{
    fs::path dir = "D:/a/b";

    search(dir);

    return 0;
}
