// Task2.cpp by Romanenko A.A.

#include <iostream>
#include <fstream>
#include <string>
#include <map>

bool Check(char c) {
    return(ispunct(c) || c == ' ');
}
int main()
{
    std::ifstream in("Input.txt");
    std::string str, tmp = "";
    std::map<std::string, int> mp;
    while (!in.eof()) {
        std::getline(in, str);
        for (auto x : str) {
            if (Check(x) && tmp != "") {
                if(tmp.size() < 4)
                    mp[tmp]++;
                tmp = "";
            }
            else {
                tmp += x;
            }
        }
        if (tmp.size() < 4 && tmp != "") {
            mp[tmp]++;
        }
        tmp = "";
    }
    
    std::map<std::string, int> :: iterator it = mp.begin();

    for (; it != mp.end() ; it++)
        if(it->second >6)
            std::cout << "Word: " << it->first << " Count: " << it->second << std::endl;
}
