#pragma once
#ifndef CHARFUNCS
#define CHARFUNCS
#include <string>
#include <string.h>

namespace charFuncs{

//Возвращает последний символ, при этом возвращает предпоследний если последний - ь ъ ы
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

// меняет ё на е , й на и для всего слова
inline void changeString(std::string &str){
    for(size_t i = 0; i < str.size(); ++i){
        changeChar(str[i]);
    }
}

//return true ,если буква русская , иначе false
inline bool isRusLetter(char letter){
// Частотность взята отсуда: http://dict.ruslang.ru/freq.php?act=show&dic=freq_letters&title=%D7%E0%F1%F2%EE%F2%ED%EE%F1%F2%FC%20%E1%F3%EA%E2%20%F0%F3%F1%F1%EA%EE%E3%EE%20%E0%EB%F4%E0%E2%E8%F2%E0
    if(strchr("оеаинтсрвлкмдпуяыьгзбчйхжшюцщэфъё", letter))
        return true;
    else
        return false;


}
}

#endif //
