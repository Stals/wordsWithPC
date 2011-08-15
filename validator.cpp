#include "validator.h"
#include <string.h> //strcmp

Validator::Validator(){
    currentStatus = OK;
}
bool Validator::isWordValid( const std::string &playerWord,
                             const char &pcLastLetter, Dictionary &dictionary ){

    //Получим Необходимые нам символы
    playerFirstLetter = playerWord[0];
    playerLastLetter = charFuncs::getLastLetter( playerWord );

    //ё->е й->и так как они считаются одним и темже
    //TODO попробывать убрать в mainwindow , так как не логично что класс который проверяет что-то начинает менять данные
    charFuncs::changeChar( playerFirstLetter );
    charFuncs::changeChar( playerLastLetter );

    //Каждая из функций возвращает true ,если нашлось несоответсвие + меняет currentStatus
    // Если хоть одно из условий вернёт true - значит в слово не прошло проверку
    if( hasWrongFirstLast( playerFirstLetter, pcLastLetter )||
        hasWrongLength( playerWord )||
        hasWrongLastLetters( playerWord )||
        hasSpaces( playerWord )||
        isNotRusLetter( playerLastLetter )||
        isUsedWord( playerWord, dictionary )
        ){
            return false;
    }else{
        //иначе слово удовлетворяет всем уcловиям
        currentStatus = OK;
        return true;
    }
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
    default:
        return "Ошибка";
    }
}
bool Validator::hasWrongLength(std::string playerWord){
    if(playerWord.length() == 0){
        currentStatus=NoWord;
        return true;
    }
    if(playerWord.length() < 2){
        currentStatus=TooShortWord;
        return true;
    }else{
        return false;
    }

}
bool Validator::isNotRusLetter(char letter){
    if(!charFuncs::isRusLetter( letter )){
        currentStatus=NotRusWord;
        return true;
    }else{
        return false;
    }
}
bool Validator::isUsedWord(std::string playerWord, Dictionary &dictionary){
    if(dictionary.isUsedWord( playerWord )){
        currentStatus = UsedWord;
        return true;
    }else{
        return false;
    }
}
bool Validator::hasWrongFirstLast(char playerFirstLetter, char pcLastLetter){
    if( playerFirstLetter == pcLastLetter){
        return false;

    //NOTE: Так как в слове игрока уже преобразовано й в и , ё в е , а в словах компьютера нет, нужны эти проверки
    }else if(( playerFirstLetter == 'и' && pcLastLetter == 'й' )||
             ( playerFirstLetter == 'е' && pcLastLetter == 'ё' )){
        return false;
    }else if( pcLastLetter == ' ' ){//Если это первый ход
        return false;
    }else{
        currentStatus=WrongFirstLetter;
        return true;
    }

}

bool Validator::hasWrongLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("ъыь", playerWord[ len-1 ]) && strchr("ъыь", playerWord[ len-2 ])){
        currentStatus=WrongEnd;
        return true;
    }else{
        return false;
    }
}

bool Validator::hasSpaces(std::string playerWord){

    for(unsigned int i = 0; i < playerWord.length(); ++i){
        if(playerWord[i] == ' '){//Если в строке есть пробелы - это несколько слов
            currentStatus=SpaceInWord;
            return true;
        }
    }
    //Если пробелов в слове небыло найдено
    return false;

}
