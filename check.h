#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "findword.h"
enum status{
    OK,             //���� ����������
    WrongFirstLetter,//������������ ������ ������
    UsedWord,       //����� ��� ���������������
    NotRusWord,     //�� ������� �����
    TooShortWord,   //������� �������� �����
    NoWord          //����� 0 ������
};
class check
{
public:
    check();
    bool playerWord(const std::string&,const std::string&,cases&,findWord&); //��������� �������� � ���������� true , ���� ����� ������ ��������
    status statusNum;//������ ������� ���������

    std::string stringStatus();//���������� ������ � ����������� �� �������� �������
private:
    char playerFirstLetter;
    char playerLastLetter;
    char pcLastLetter;

    //true ,���� ������� ������������� + ������ statusNum
    bool checkLength(std::string);
    bool rusLetter(char,cases&);
    bool usedWord(std::string,findWord&);
    bool firstLast(char,char);//��������� ������������ �� ������ ������ ����� ������ ���������� � ������ �����
};

#endif // CHECK_H
