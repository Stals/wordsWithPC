#ifndef FINDWORD_H
#define FINDWORD_H
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <vector>
class findWord
{
public:
    findWord();
    std::string findRandomWord(char firstLetter, std::string playerWord);//���� ��������� ����� � ��������

private:
    void loadDicts();//��������� ������� �� ��������  � map - dictionary

        void usedWord(char firstLetter, std::string playerWord);//��������� ����� � usedWords � ������� ��� �� dictionary ,���� ��� ��� ����
       std::map<std::string,std::list<std::string> > dictionary;//��� ��������� ��� ��������� �������� ������ �����
       std::list<std::string> singleDict;//������� �� 1 ����� ������������ ������� ����
       std::list<std::string> usedWords;//������ ��� �������������� ����
};

#endif // FINDWORD_H
