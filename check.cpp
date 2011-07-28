#include "check.h"
#include <string.h> //strcmp

Check::Check(){
    statusNum=OK;
}
bool Check::playerWord(const std::string& playerWord,const std::string& pcWord,Dictionary& dictionary){
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
    else if(lastLetters(playerWord))
        return false;
    else if(rusLetter(playerLastLetter))
        return false;
    else if(usedWord(playerWord,dictionary))
        return false;
    else if(pcWord!=""){//для любого хода кроме первого
        //проверим совпадает ли первая буква слова игрока с последней в слове компьютера
        if(firstLast(playerFirstLetter,pcLastLetter))
            return false;
    }

    //playerWord удовлетворяет всем условиям

    statusNum=OK;
    return true;

}

std::string Check::stringStatus(){
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
    }
    return "Ошибка";
}
bool Check::checkLength(std::string playerWord){
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
bool Check::rusLetter(char letter){
    if(!charFuncs::rusLetter(letter)){
        statusNum=NotRusWord;
        return true;
    }else
        return false;

}
bool Check::usedWord(std::string playerWord,Dictionary& dictionary){
    if(!dictionary.checkUsed(playerWord)){
        statusNum=UsedWord;
        return true;
    }else
        return false;
}
bool Check::firstLast(char playerFirstLetter,char pcLastLetter){
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

bool Check::lastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("ъыь ", playerWord[len-1])&&strchr("ъыь ", playerWord[len-2])){
        statusNum=WrongEnd;
        return true;
    }else{
        statusNum=OK;
        return false;
    }
}
