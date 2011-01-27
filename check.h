#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
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
    void playerWord(const std::string&,const std::string&,cases&,charFunc&);
    status statusNum;

private:
    char playerFirstLetter;
    char playerLastLetter;
    char pcLastLetter;
};

#endif // CHECK_H
