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
    NotSingleWord    //��������� ���� � �� ����
};

//���� ����� ���������� ��������� ����� ��������� ������������� �� �����������
class Validator
{
public:
    Validator();
    //�������� �������� � ���������� true , ���� ����� ������ ��������
    bool checkPlayerWord(const std::string& checkPlayerWord,const std::string& pcWord,Dictionary& dictionary);

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
    bool checkRusLetter(char); //���������� �������� �� ����� �������
    bool checkUsedWord(std::string,Dictionary&); //��������� ���� �� ������������� �����
    bool checkFirstLast(char,char);//��������� ������������ �� ������ ������ ����� ������ ���������� � ����� ����������
    bool checkLastLetters(std::string);//��������� ����� ��� ��������� ������� ������ � � � (�����)
    bool checkSingleWord(std::string);//��������� ����� � ������ ���� ������ ���� �����
};

#endif // CHECK_H
