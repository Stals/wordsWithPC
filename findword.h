#ifndef FINDWORD_H
#define FINDWORD_H
#include <string>
#include <iostream>
#include <list>
#include <map>
class findWord
{
public:
    findWord();
private:
       //std::map<std::string;std::list> dictionary;//��� ��������� ��� ��������� �������� ������ �����
       std::list<std::string> usedWords;//������ ��� �������������� ����
};

#endif // FINDWORD_H
