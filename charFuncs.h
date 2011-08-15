#pragma once
#ifndef CHARFUNCS
#define CHARFUNCS
#include <string>
#include <string.h>
namespace charFuncs{
//���������� ��������� ������, ��� ���� ���������� ������������� ���� ��������� � � �
inline char getLastLetter(const std::string str){
    if(str == "") return ' ';

    char lastChar = str[ str.size()-1 ];//��������� ������
    if(strchr("���", lastChar)){
        return lastChar=str[ str.size()-2 ];
    }else return lastChar;
}


//���� ������ � ������ �� � � ���� ������ � ������ �� �
inline void changeChar(char &letter){

    //������ �� � -> �
    if(letter == '�'){
        letter = '�';
    }
    //������ �� � -> �
    if(letter == '�'){
        letter = '�';
    }
}


//return true ,���� ����� �������
inline bool isRusLetter(char letter){
    if(strchr("�������������������������������������Ũ��������������������������",letter))
        return true;
    else
        return false;


}
}

#endif //
