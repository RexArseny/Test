#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <mysql.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int count = 0;
    char pas[20];
    ofstream out("D:/result.json");
    map <string, string> data[100];
    MYSQL* con;
    MYSQL_RES* res;
    MYSQL_ROW row;

    cout << "Enter password" << endl;
    cin >> pas;
    con = mysql_init(NULL);
    mysql_real_connect(con, "localhost", "root", pas, "mtuci", NULL, NULL, 0);
    mysql_query(con, "SET NAMES cp1251");
    mysql_query(con, "SELECT *FROM student");
    res = mysql_store_result(con);
    while (row = mysql_fetch_row(res))
    {
        for (int i = 0; i < mysql_num_fields(res); i++) data[count].emplace(pair <string, string>(mysql_fetch_field_direct(res, i)->name, row[i]));
        count++;
    }
    for (size_t i = 0; i < sizeof(data) / sizeof(*data); i++)
    {
        if (data[i].empty()) break;
        out << "{";
        for (auto it = data[i].begin(); it != data[i].end(); it++)
        {
            if (next(it) == data[i].end()) out << it->first << " : " << it->second;
            else out << it->first << " : " << it->second << ",";
        }
        out << "}";
    }

    mysql_close(con);

    return 0;
}
