#pragma once
#ifndef CHARFUNCS
#define CHARFUNCS
#include <string>
#include <string.h>
namespace charFuncs{
//���������� ��������� ������, ��� ���� ���������� ������������� ���� ��������� � � � ��� ������
   inline char getLastLetter(const std::string str){

            char last=str[str.size()-1];//��������� ������
            if(strchr("��� ", last)){
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

   inline bool rusLetter(char letter){//return true ,���� ����� �������
       if(strchr("�������������������������������������Ũ��������������������������",letter))
           return true;
       else
           return false;


   }
}

#endif //
