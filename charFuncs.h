#ifndef CHARFUNCS_H
#define CHARFUNCS_H
#include <string>

struct charFunc{
//Возвращает последний символ, при этом возвращает предпоследний если последний ь ъ ы
    char getLastLetter(const std::string str){

            char last=str[str.size()-1];//последний символ
            if(last=='ы'||last=='ь'||last=='ъ'){
                    return last=str[str.size()-2];
            }else return last;
    }

    //если символ ё меняет на е и если символ й меняет на и
    void changeChar(char& letter){

            //делаем из ё -> е
            if(letter=='ё'){
                    letter='е';
            }
            //делаем из й -> и
            if(letter=='й'){
                    letter='и';
            }


    }


};
#endif //CHARFUNCS_H
