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
    std::string findRandomWord(char lastLetter, std::string playerWord);//���� ��������� ����� � ��������

private:
    void loadDicts();//��������� ������� �� ��������  � map - dictionary

        void usedWord(std::string Word);//��������� ����� � usedWords � ������� ��� �� dictionary ,���� ��� ��� ����
       std::map<std::string,std::list<std::string> > dictionary;//��� ��������� ��� ��������� �������� ������ �����
       std::list<std::string> singleDict;//������� �� 1 ����� ������������ ������� ����
       std::list<std::string> usedWords;//������ ��� �������������� ����
};
//*mapIter).first; -��� ����� �� ������� � ������� ���������� �����
// (*mapIter).second; - ��� ������ ����, ��� ���� � ���������� ����� ���������� ����������
#endif // FINDWORD_H
