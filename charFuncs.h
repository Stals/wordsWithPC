#pragma once
#ifndef CHARFUNCS
#define CHARFUNCS
#include <string>


//���������� ��������� ������, ��� ���� ���������� ������������� ���� ��������� � � �
   inline char getLastLetter(const std::string str){

            char last=str[str.size()-1];//��������� ������
            if(last=='�'||last=='�'||last=='�'){
                    return last=str[str.size()-2];
            }else return last;
    }

    //���� ������ � ������ �� � � ���� ������ � ������ �� �
   inline void changeChar(char& letter){

            //������ �� � -> �
            if(letter=='�'){
                    letter='�';
            }
            //������ �� � -> �
            if(letter=='�'){
                    letter='�';
            }

        }




#endif //
