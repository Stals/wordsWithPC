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

//����� ������ ������� ������� ���������� ��������� � ����� ������������� ����� ������� ��� ������ �� �������
class Dictionary
{
public:
    Dictionary();

    //���� ��������� ����� � ��������
    std::string findRandomWord(char lastLetter);

    //��������� ����� � usedWords � ������� ��� �� dictionary ,���� ��� ��� ����
    void usedWord(std::string Word, char lastLetter);

    //���������� true ���� ������ ����� �� ��������������
    bool checkUsed(std::string playerWord);

private:
    //��������� ������� �� ��������  � map - dictionary
    void loadDicts();

    //������ ��� ��������� �������� ������ ����������
    std::map<char, std::list<std::string> > dictionary;

    //������ ��� �������������� ����
    std::vector<std::string> usedWords;
};
//(*mapIter).first; -��� ����� �� ������� � ������� ���������� �����
//(*mapIter).second; - ��� ������ ����, ��� ���� � ���������� ����� ���������� ����������
inline bool compareStr(const std::string &str1, const std::string &str2);
#endif // FINDWORD_H
