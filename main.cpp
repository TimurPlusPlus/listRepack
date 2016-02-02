#include <iostream>
#include <forward_list>
#include <vector>
#include <sstream>

using namespace std;

forward_list <string> repackList(forward_list <string> fList)  //4! OK!
{
    vector <string> vList;                                                          //Для хранения элементов списка.
    for(forward_list <string>::iterator i = fList.begin(); i != fList.end(); i++)   //Перекладываем элементы в вектор,
        vList.push_back(*i);                                                        //чтобы итерироваться.

    forward_list <string> fListRepack;                                              //Перепакованный список.

    fListRepack.emplace_front(vList.at(vList.size() / 2));                          //Помещаем в начало нового списка элемент из середины.
    if(vList.size() % 2 == 0)                                                       //Если чётное число элементов.
        fListRepack.emplace_front(vList.at((vList.size() - 1) / 2));                //Значит центральных элементов 2. Второй тоже заносим в новый список.

    for(int i = (vList.size() - 3) / 2, j = vList.size() / 2 + 1; i >= 0 && j < vList.size(); i--, j++) //Идём из центра к краям.
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
        fList.emplace_front(str); //Вставка В НАЧАЛО
    }
    fList = repackList(fList);
    for(forward_list <string>::iterator i = fList.begin(); i != fList.end(); i++)
        cout << *i << "  ";
    return 0;
}
