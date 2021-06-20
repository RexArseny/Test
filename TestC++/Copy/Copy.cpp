#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void search(fs::path dir_from, fs::path dir_to)
{
    for (auto& i : fs::directory_iterator(dir_from))
    {
        fs::path temp = i.path();
        if (temp.extension() == "")
        {
            dir_to += "/";
            dir_to += temp.filename();
            fs::create_directories(dir_to);
            search(temp, dir_to);
            dir_to = dir_to.parent_path();
        }
        else fs::copy(temp, dir_to, fs::copy_options::skip_existing);
    }
}

int main()
{
    fs::path dir_from = "D:/a/b";
    fs::path dir_to = "D:/a/b2";

    search(dir_from, dir_to);

    return 0;
}
