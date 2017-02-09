#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.size();
    set<char> dis;
    for(int i = 0 ; i < l; i++)
        dis.insert(s[i]);
    int number = dis.size();
    if(number%2 != 0)
        cout << "IGNORE HIM!" << endl;
    else
        cout << "CHAT WITH HER!" << endl;
}
