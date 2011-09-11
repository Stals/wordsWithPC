#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "dictionary.h"

struct Status{
//������ ���������� �����
    enum Value{
        OK,              //���� ����������
        WrongFirstLetter,//������������ ������ ������
        UsedWord,        //����� ��� ���������������
        NotRusWord,      //�� ������� �����
        TooShortWord,    //������� �������� �����
        NoWord,          //����� 0 ������
        WrongEnd,        //������������ ���������
        SpaceInWord,     //� ����� ���� ������
        NotNewWord       //������������ �� ������� �������� ����� � �������
    };
};

//���� ����� ���������� ��������� ����� ��������� ������������� �� ������������
class Validator
{
public:
    Validator();
    //�������� �������� � ���������� true , ���� ����� ������ ��������
    bool isWordValid(const std::string& isWordValid,const char& pcLastLetter,Dictionary& dictionary);

    //������ ������ �� status
    void setCurrentStatus(Status::Value status);

    //���������� ������ ����� � ���� ������
    std::string getCurrentStatus();

private:

    //������� ���������
    Status::Value currentStatus; 

    //������ �� ������� ���������� true ,���� ������� ������������� + ������ currentStatus
    bool hasWrongLength(std::string);                //�������� ������ �����
    bool isNotRusWord(std::string);                  //���������� �������� �� ����� �������
    bool isUsedWord(std::string, Dictionary&);       //��������� ���� �� ������������� �����
    bool hasWrongFirstLast(char,char);               //��������� ������������ �� ������ ������ ����� ������ ���������� � ����� ����������
    bool hasWrongLastLetters(std::string);           //��������� ����� ��� ��������� ������� ������ � � � (�����)
    bool hasSpaces(std::string);                     //��������� ����� � ������ �� ���� �������
};

#endif // CHECK_H
