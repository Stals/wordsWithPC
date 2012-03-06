#pragma once
#ifndef CHARFUNCS
#define CHARFUNCS
#include <string>
#include <string.h>

namespace charFuncs{

//���������� ��������� ������, ��� ���� ���������� ������������� ���� ��������� - � � �
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

// ������ � �� � , � �� � ��� ����� �����
inline void changeString(std::string &str){
    for(size_t i = 0; i < str.size(); ++i){
        changeChar(str[i]);
    }
}

//return true ,���� ����� ������� , ����� false
inline bool isRusLetter(char letter){
// ����������� ����� ������: http://dict.ruslang.ru/freq.php?act=show&dic=freq_letters&title=%D7%E0%F1%F2%EE%F2%ED%EE%F1%F2%FC%20%E1%F3%EA%E2%20%F0%F3%F1%F1%EA%EE%E3%EE%20%E0%EB%F4%E0%E2%E8%F2%E0
    if(strchr("���������������������������������", letter))
        return true;
    else
        return false;


}
}

#endif //
