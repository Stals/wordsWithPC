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
    void playerWord(std::string,std::string,cases,charFunc);
};

#endif // CHECK_H
