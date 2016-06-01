#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream st;
    st.open("main.cpp");
    if (!st.is_open()){
        cout << "Ошибка открытия файла! :( \n";
        return 1;
    }
    int i = 0, j = 0, k = 0, n = 0;
    bool flag = true;
    string str;
    while (getline(st, str))
    {
            n = str.find("\\func");
            k = n + 6;
            if (n != string::npos)
            {
                j++;
                cout << j << ". ";
                n = str.find("*/");
                if (n != string::npos)
                while (n != k)
                {
                    cout<< str[k];
                    k++;
                }
                else
                {
                    cout << str.substr(k);
                }
                cout << endl;
            }
            else
            {
                flag = true;
                do
                {
                    getline(st, str);
                    n = str.find("\\func");
                    k = n + 6;
                    if(n != string::npos)
                    {
                        flag = false;
                        j++;
                        cout << j << ". ";
                        n = str.find("*/");
                        if (n != string::npos)
                            while (n != k)
                            {
                                cout<< str[k];
                                k++;
                            }
                        else
                        {
                            cout << str.substr(k);
                        }
                        cout << endl;
                    }
                    if(st.eof()) break;
                } while (flag);
            }
    }
    st.close();
    return 0;
}

