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

    //�������� ������ � ���� ������
    //TODO ����� ������������� � getStatusAsString?
    static std::string convertStatusToString(Status::Value status){

        switch (status){
        case Status::OK:
            return "���������� ����";
            break;
        case Status::WrongFirstLetter:
            return "������������ ������ ������";
            break;
        case Status::UsedWord:
            return "��� ����� ��� ��������������";
            break;
        case Status::NotRusWord:
            return "� ����� ������ ���� ������ ������� �����";
            break;
        case Status::TooShortWord:
            return "������� �������� �����";
            break;
        case Status::NoWord:
            return "������� ������� ���-������";
            break;
        case Status::WrongEnd:
            return "������������ ���������";
            break;
        case Status::SpaceInWord:
            return "� ����� �� ������ ���� ��������";
            break;
        case Status::NotNewWord:
            return "������� ������ �����";
        default:
            return "������";
        }
    }
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
