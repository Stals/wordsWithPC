#ifndef FINDWORD_H
#define FINDWORD_H
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <vector>
#include <time.h>//for random
#include <stdlib.h>
class findWord
{
public:
    findWord();
    std::string findRandomWord(char lastLetter);//���� ��������� ����� � ��������
    void usedWord(std::string Word,char lastLetter);//��������� ����� � usedWords � ������� ��� �� dictionary ,���� ��� ��� ����
    bool checkUsed(std::string playerWord);//true ���� ������ ����� �� ��������������
private:
    void loadDicts();//��������� ������� �� ��������  � map - dictionary


       std::map<char,std::list<std::string> > dictionary;//��� ��������� ��� ��������� �������� ������ �����
       std::list<std::string> singleDict;//������� �� 1 ����� ������������ ������� ����
       std::vector<std::string> usedWords;//������ ��� �������������� ���� (������� �� �����, � �������� ������ �����������)
};
//(*mapIter).first; -��� ����� �� ������� � ������� ���������� �����
// (*mapIter).second; - ��� ������ ����, ��� ���� � ���������� ����� ���������� ����������
inline bool compareStr(const std::string &str1,const std::string &str2);
#endif // FINDWORD_H
