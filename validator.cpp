#include "validator.h"
#include <string.h> //strcmp

Validator::Validator(){
    currentStatus=OK;
}
status Validator::checkPlayerWord(const std::string& playerWord,const std::string& pcWord,Dictionary& dictionary){
    //Получим Необходимые нам символы
    playerFirstLetter=playerWord[0];
    playerLastLetter=charFuncs::getLastLetter(playerWord);
    pcLastLetter=charFuncs::getLastLetter(pcWord);

    //ё->е й->и так как они считаются одним и темже
    //TODO попробывать убрать в mainwindow , так как не логично что класс который проверяет что-то начинает менять данные
    charFuncs::changeChar(playerFirstLetter);
    charFuncs::changeChar(playerLastLetter);

    //функции внутри меняют statusNum,если произошла ошибка
    if(checkLength(playerWord))
        return currentStatus;

    else if(checkLastLetters(playerWord))
        return currentStatus;

    else if(checkSpaces(playerWord))
        return currentStatus;

    else if(checkRusLetter(playerLastLetter))
        return currentStatus;

    else if(checkUsedWord(playerWord,dictionary))
        return currentStatus;

    else if(pcWord!=""){//для любого хода кроме первого
        if(checkFirstLast(playerFirstLetter,pcLastLetter))
            return currentStatus;
    }else{
        //playerWord удовлетворяет всем условиям
        currentStatus=OK;
    }
    return currentStatus;

}

std::string Validator::getStatus(){
    switch (currentStatus){
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
    case SpaceInWord:
        return "В слове не должно быть пробелов";
        break;
    }
    return "Ошибка";
}
bool Validator::checkLength(std::string playerWord){
    if(playerWord==""){
        currentStatus=NoWord;
        return true;
    }
    if(playerWord.size()<2){
        currentStatus=TooShortWord;
        return true;
    }else
        return false;

}
bool Validator::checkRusLetter(char letter){
    if(!charFuncs::rusLetter(letter)){
        currentStatus=NotRusWord;
        return true;
    }else
        return false;

}
bool Validator::checkUsedWord(std::string playerWord,Dictionary& dictionary){
    if(!dictionary.checkUsed(playerWord)){
        currentStatus=UsedWord;
        return true;
    }else
        return false;
}
bool Validator::checkFirstLast(char playerFirstLetter,char pcLastLetter){
    if( playerFirstLetter==pcLastLetter){
        currentStatus=OK;
        return false;

        //NOTE: Так как в слове игрока уже преобразовано й в и , ё в е , а в словах компьютера нет, нужны эти проверки
    }else if( (playerFirstLetter=='и'&&pcLastLetter=='й')){
        currentStatus=OK;
        return false;

    }else if(( playerFirstLetter=='е'&&pcLastLetter=='ё')){
        currentStatus=OK;
        return false;
    }else{
        currentStatus=WrongFirstLetter;
        return true;

    }

}

bool Validator::checkLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("ъыь", playerWord[len-1])&&strchr("ъыь", playerWord[len-2])){
        currentStatus=WrongEnd;
        return true;
    }else{
        currentStatus=OK;
        return false;
    }
}

bool Validator::checkSpaces(std::string playerWord){

    for(unsigned int i = 0; i<playerWord.length();++i){
        if(playerWord[i]==' '){//Если в строке есть пробелы - это несколько слов
            currentStatus=SpaceInWord;
            return true;
        }
    }
    //Если пробелов в слове небыло найдено
    return false;


}
