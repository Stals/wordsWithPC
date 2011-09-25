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

    ~Dictionary();

    //���� ��������� ����� � ��������
    std::string findRandomWord(char lastLetter);

    //��������� ����� � usedWords � ������� ��� �� dictionary ,���� ��� ��� ����
    void addUsedWord(std::string word);

    //������� ����� �� ������� ���� ��� ��� ����
    void removeWord(std::string word);

    //���������� true ���� ��� ����� ��� �������������� (����������� ��� �������������)
    bool isUsedWord(std::string playerWord);

    //���������� true ���� ����� ����� ��� � ��������
    bool isNewWord(std::string playerWord);

    //��������� ����� ����� � ������� �� �����
    void addNewWord(std::string playerWord);

private:
    //��������� ������� �� ��������  � map - dictionary
    void loadDicts();

    //����������� ���� � ����� � ������� ����� ��������� ����� newWord
    std::string getFileName(std::string newWord);

    //���������� true ���� ����� ���� � �������
    bool isInDictionary(std::string playerWord);

    //������ ��� ��������� �������� ������ ����������
    std::map<char, std::list<std::string> > dictionary;

    //������ ��� �������������� ����
    std::vector<std::string> usedWords;

};
//(*mapIter).first; -��� ����� �� ������� � ������� ���������� �����
//(*mapIter).second; - ��� ������ ����, ��� ���� � ���������� ����� ���������� ����������
inline bool compareStr(const std::string &str1, const std::string &str2);
#endif // FINDWORD_H
