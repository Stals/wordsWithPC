#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "cases.h"
#include "charFuncs.h"
#include "dictionary.h"



//���� ����� ���������� ��������� ����� ��������� ������������� �� ������������
class Validator
{
public:
    Validator();
    //�������� �������� � ���������� true , ���� ����� ������ ��������
    bool isWordValid(const std::string& isWordValid,const char& pcLastLetter,Dictionary& dictionary);

    //������ ������ �� notNewWord
    void notNewWord();

    //���������� ������ ����� � ���� ������
    std::string getStatus();

private:

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

    //������� ���������
    Status::Value currentStatus;

    char playerFirstLetter;
    char playerLastLetter;

    //������ �� ������� ���������� true ,���� ������� ������������� + ������ currentStatus
    bool hasWrongLength(std::string);                //�������� ������ �����
    bool isNotRusLetter(char);                       //���������� �������� �� ����� �������
    bool isUsedWord(std::string, Dictionary&);       //��������� ���� �� ������������� �����
    bool hasWrongFirstLast(char,char);               //��������� ������������ �� ������ ������ ����� ������ ���������� � ����� ����������
    bool hasWrongLastLetters(std::string);           //��������� ����� ��� ��������� ������� ������ � � � (�����)
    bool hasSpaces(std::string);                     //��������� ����� � ������ �� ���� �������
};

#endif // CHECK_H
