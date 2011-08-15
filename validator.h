#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "dictionary.h"

//������ ���������� �����
enum status{
    OK,              //���� ����������
    WrongFirstLetter,//������������ ������ ������
    UsedWord,        //����� ��� ���������������
    NotRusWord,      //�� ������� �����
    TooShortWord,    //������� �������� �����
    NoWord,          //����� 0 ������
    WrongEnd,        //������������ ���������
    SpaceInWord      //� ����� ���� ������
};

//���� ����� ���������� ��������� ����� ��������� ������������� �� ������������
class Validator
{
public:
    Validator();
    //�������� �������� � ���������� true , ���� ����� ������ ��������
    bool isWordValid(const std::string& isWordValid,const char& pcLastLetter,Dictionary& dictionary);

    //���������� ������ ����� � ���� ������
    std::string getStatus();

    //������ ������� ���������
    status currentStatus;

private:
    char playerFirstLetter;
    char playerLastLetter;

    //������ �� ������� ���������� true ,���� ������� ������������� + ������ currentStatus
    bool hasWrongLength(std::string);                //�������� ������ �����
    bool isNotRusLetter(char);                         //���������� �������� �� ����� �������
    bool isUsedWord(std::string, Dictionary&);       //��������� ���� �� ������������� �����
    bool hasWrongFirstLast(char,char);               //��������� ������������ �� ������ ������ ����� ������ ���������� � ����� ����������
    bool hasWrongLastLetters(std::string);           //��������� ����� ��� ��������� ������� ������ � � � (�����)
    bool hasSpaces(std::string);                     //��������� ����� � ������ �� ���� �������
};

#endif // CHECK_H
