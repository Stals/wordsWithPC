#ifndef CHARFUNCS_H
#define CHARFUNCS_H
#include <string>

struct charFunc{
//���������� ��������� ������, ��� ���� ���������� ������������� ���� ��������� � � �
    char getLastLetter(const std::string str){

            char last=str[str.size()-1];//��������� ������
            if(last=='�'||last=='�'||last=='�'){
                    return last=str[str.size()-2];
            }else return last;
    }

    //���� ������ � ������ �� � � ���� ������ � ������ �� �
    void changeChar(char& letter){

            //������ �� � -> �
            if(letter=='�'){
                    letter='�';
            }
            //������ �� � -> �
            if(letter=='�'){
                    letter='�';
            }


    }


};
#endif //CHARFUNCS_H
