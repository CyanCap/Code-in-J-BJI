#include<iostream>
using namespace std;
string id, name, courses;
int main()
{
    puts("Enter Student ID:");
    cin >> id;
    puts("Enter Student Name:");
    cin >> name;
    puts("Enter Student Courses:");
    cin >> courses;
    for (auto p1 = si.begin(); p1 != si.end();p1++)
        cout << *p1;
    puts("");
    for (auto p2 = sn.begin(); p2 != sn.end();p2++)
        cout << *p2;
    puts("");
    for (auto p3 = sc.begin(); p3 != sc.end();p3++)
        cout << *p3;
    return 0;
}
