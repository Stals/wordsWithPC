#pragma once
#ifndef CHARFUNCS
#define CHARFUNCS
#include <string>
#include <string.h>
namespace charFuncs{
//Возвращает последний символ, при этом возвращает предпоследний если последний ь ъ ы или пробел
   inline char getLastLetter(const std::string str){

            char last=str[str.size()-1];//последний символ
            if(strchr("ъыь ", last)){
                    return last=str[str.size()-2];
            }else return last;
    }

    //если символ ё меняет на е и если символ й меняет на и
   inline void changeChar(char& letter){

            //делаем из ё -> е
            if(letter=='ё'){
                    letter='е';
            }
            //делаем из й -> и
            if(letter=='й'){
                    letter='и';
            }

        }

   inline bool rusLetter(char letter){//return true ,если буква русская
       if(strchr("абвгдеёжзийклмнопрстуфхцчшщьыъэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ",letter))
           return true;
       else
           return false;


   }
}

#endif //
