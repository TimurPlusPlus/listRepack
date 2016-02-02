#include <iostream>
#include <forward_list>
#include <vector>
#include <sstream>

using namespace std;

forward_list <string> repackList(forward_list <string> fList)  //4! OK!
{
    vector <string> vList;                                                          //��� �������� ��������� ������.
    for(forward_list <string>::iterator i = fList.begin(); i != fList.end(); i++)   //������������� �������� � ������,
        vList.push_back(*i);                                                        //����� �������������.

    forward_list <string> fListRepack;                                              //�������������� ������.

    fListRepack.emplace_front(vList.at(vList.size() / 2));                          //�������� � ������ ������ ������ ������� �� ��������.
    if(vList.size() % 2 == 0)                                                       //���� ������ ����� ���������.
        fListRepack.emplace_front(vList.at((vList.size() - 1) / 2));                //������ ����������� ��������� 2. ������ ���� ������� � ����� ������.

    for(int i = (vList.size() - 3) / 2, j = vList.size() / 2 + 1; i >= 0 && j < vList.size(); i--, j++) //��� �� ������ � �����.
    {
        fListRepack.emplace_front(vList.at(j));
        fListRepack.emplace_front(vList.at(i));
    }

    //delete fList;
    return fListRepack;
}

int main()
{
    forward_list <string> fList;
    stringstream out;
    string str;
    for(int i = 100; i > 0; i--)
    {
        out << i;
        out >> str;
        out.clear();
        fList.emplace_front(str); //������� � ������
    }
    fList = repackList(fList);
    for(forward_list <string>::iterator i = fList.begin(); i != fList.end(); i++)
        cout << *i << "  ";
    return 0;
}
