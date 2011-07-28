#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "findword.h"

//������ ���������� �����
enum status{
    OK,              //���� ����������
    WrongFirstLetter,//������������ ������ ������
    UsedWord,        //����� ��� ���������������
    NotRusWord,      //�� ������� �����
    TooShortWord,    //������� �������� �����
    NoWord,          //����� 0 ������
    WrongEnd         //������������ ���������
};

//���� ����� ���������� ��������� ����� ��������� ������������� �� �����������
class Check
{
public:
    Check();
    //�������� �������� � ���������� true , ���� ����� ������ ��������
    bool playerWord(const std::string& playerWord,const std::string& pcWord,Dictionary& dictionary);

    //���������� ������ ����� � ���� ������
    std::string stringStatus();

    //������ ������� ���������
    status statusNum;


private:
    char playerFirstLetter;
    char playerLastLetter;
    char pcLastLetter;

    //������ �� ������� ���������� true ,���� ������� ������������� + ������ statusNum
    bool checkLength(std::string); //�������� ������ �����
    bool rusLetter(char); //���������� �������� �� ����� �������
    bool usedWord(std::string,Dictionary&); //��������� ���� �� ������������� �����
    bool firstLast(char,char);//��������� ������������ �� ������ ������ ����� ������ ���������� � ����� ����������
    bool lastLetters(std::string);//��������� ����� ��� ��������� ������� ������ � � � ��� �������� (�����)
};

#endif // CHECK_H
