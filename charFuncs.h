#pragma once
#ifndef CHARFUNCS
#define CHARFUNCS
#include <string>
#include <string.h>
namespace charFuncs{
//Возвращает последний символ, при этом возвращает предпоследний если последний ь ъ ы
inline char getLastLetter(const std::string str){
    if(str == "") return ' ';

    char lastChar = str[ str.size()-1 ];//последний символ
    if(strchr("ъыь", lastChar)){
        return lastChar=str[ str.size()-2 ];
    }else return lastChar;
}


//если символ ё меняет на е и если символ й меняет на и
inline void changeChar(char &letter){

    //делаем из ё -> е
    if(letter == 'ё'){
        letter = 'е';
    }
    //делаем из й -> и
    if(letter == 'й'){
        letter = 'и';
    }
}


//return true ,если буква русская
inline bool isRusLetter(char letter){
    if(strchr("абвгдеёжзийклмнопрстуфхцчшщьыъэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ",letter))
        return true;
    else
        return false;


}
}

#endif //
