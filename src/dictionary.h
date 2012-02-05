#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "utils/randomVector.h"

//����� ������ ������� ������� ���������� ��������� � ����� ������������� ����� ������� ��� ������ �� �������
class Dictionary
{
public:
    Dictionary();
    ~Dictionary();

    // ���������� ��������� ����� ������������ �� lastLetter � ������� ��� �� dictionary
    std::string getRandomWord(char lastLetter);

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
    std::map<char, randomVector<std::string> > dictionary;

    //������ ��� �������������� ����
    std::vector<std::string> usedWords;

};
//(*mapIter).first; -��� ����� �� ������� � ������� ���������� �����
//(*mapIter).second; - ��� ������ ����, ��� ���� � ���������� ����� ���������� ����������

#endif // DICTIONRY_H
