#include "check.h"
#include <string.h> //strcmp

Validator::Validator(){
    statusNum=OK;
}
bool Validator::checkPlayerWord(const std::string& playerWord,const std::string& pcWord,Dictionary& dictionary){
    //Получим Необходимые нам символы
    playerFirstLetter=playerWord[0];
    playerLastLetter=charFuncs::getLastLetter(playerWord);
    pcLastLetter=charFuncs::getLastLetter(pcWord);

    //ё->е й->и так как они считаются одним и темже
    charFuncs::changeChar(playerFirstLetter);
    charFuncs::changeChar(playerLastLetter);

    // playerWord[0]=playerFirstLetter;//чтобы слова с большой и мальнекой бувы были одинаковы

    //функции внутри меняют statusNum,если произошла ошибка
    if(checkLength(playerWord))//если ошибка в длинне
        return false;
    else if(checkLastLetters(playerWord))
        return false;
    else if(checkSingleWord(playerWord))
        return false;
    else if(checkRusLetter(playerLastLetter))
        return false;
    else if(checkUsedWord(playerWord,dictionary))
        return false;
    else if(pcWord!=""){//для любого хода кроме первого
        //проверим совпадает ли первая буква слова игрока с последней в слове компьютера
        if(checkFirstLast(playerFirstLetter,pcLastLetter))
            return false;
    }

    //playerWord удовлетворяет всем условиям

    statusNum=OK;
    return true;

}

std::string Validator::stringStatus(){
    switch (statusNum){
    case OK:
        return "Правильный ввод";
        break;
    case WrongFirstLetter:
        return "Неправильный первый символ";
        break;
    case UsedWord:
        return "Это слово уже использовалось";
        break;
    case NotRusWord:
        return "Не русское слово";
        break;
    case TooShortWord:
        return "Слишком короткое слово";
        break;
    case NoWord:
        return "Сначала введите что-нибудь";
        break;
    case WrongEnd:
        return "Неправильное окончание";
        break;
    case NotSingleWord:
        return "Введите только одно слово";
        break;
    }
    return "Ошибка";
}
bool Validator::checkLength(std::string playerWord){
    if(playerWord==""){
        statusNum=NoWord;
        return true;
    }
    if(playerWord.size()<2){
        statusNum=TooShortWord;
        return true;
    }else
        return false;

}
bool Validator::checkRusLetter(char letter){
    if(!charFuncs::rusLetter(letter)){
        statusNum=NotRusWord;
        return true;
    }else
        return false;

}
bool Validator::checkUsedWord(std::string playerWord,Dictionary& dictionary){
    if(!dictionary.checkUsed(playerWord)){
        statusNum=UsedWord;
        return true;
    }else
        return false;
}
bool Validator::checkFirstLast(char playerFirstLetter,char pcLastLetter){
    if( playerFirstLetter==pcLastLetter){
        statusNum=OK;
        return false;
    }else if( (playerFirstLetter=='и'&&pcLastLetter=='й')){
        statusNum=OK;
        return false;

    }else if(( playerFirstLetter=='е'&&pcLastLetter=='ё')){
        statusNum=OK;
        return false;
    }else{
        statusNum=WrongFirstLetter;
        return true;

    }

}

bool Validator::checkLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("ъыь", playerWord[len-1])&&strchr("ъыь", playerWord[len-2])){
        statusNum=WrongEnd;
        return true;
    }else{
        statusNum=OK;
        return false;
    }
}

bool Validator::checkSingleWord(std::string playerWord){

    for(int i = 0; i<playerWord.length();++i){
        if(playerWord[i]==' '){//Если в строке есть пробелы - это несколько слов
            statusNum=NotSingleWord;
            return true;
        }
    }
    return false; //Если пробелов в слове небыло найдено


}
