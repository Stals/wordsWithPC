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
    std::string findRandomWord(char firstLetter);
private:

       std::map<std::string,std::list<std::string> > dictionary;//��� ��������� ��� ��������� �������� ������ �����
       std::list<std::string> usedWords;//������ ��� �������������� ����
};

#endif // FINDWORD_H
