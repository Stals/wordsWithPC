#include "validator.h"
#include <string.h> //strcmp

Validator::Validator(){
    currentStatus = Status::OK;
}


bool Validator::isWordValid( const std::string &playerWord,
                             const char &pcLastLetter, Dictionary &dictionary ){

    //Получим Необходимые нам символы
    playerFirstLetter = playerWord[0];
    playerLastLetter = charFuncs::getLastLetter( playerWord );

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
        currentStatus = Status::OK;
        return true;
    }
}


std::string Validator::getStatus(){
    switch (currentStatus){
    case Status::OK:
        return "Правильный ввод";
        break;
    case Status::WrongFirstLetter:
        return "Неправильный первый символ";
        break;
    case Status::UsedWord:
        return "Это слово уже использовалось";
        break;
    case Status::NotRusWord:
        return "Не русское слово";
        break;
    case Status::TooShortWord:
        return "Слишком короткое слово";
        break;
    case Status::NoWord:
        return "Сначала введите что-нибудь";
        break;
    case Status::WrongEnd:
        return "Неправильное окончание";
        break;
    case Status::SpaceInWord:
        return "В слове не должно быть пробелов";
        break;
    default:
        return "Ошибка";
    }
}


bool Validator::hasWrongLength(std::string playerWord){
    if(playerWord.length() == 0){
        currentStatus = Status::NoWord;
        return true;
    }
    if(playerWord.length() < 2){
        currentStatus = Status::TooShortWord;
        return true;
    }else{
        return false;
    }

}


bool Validator::isNotRusLetter(char letter){
    if(!charFuncs::isRusLetter( letter )){
        currentStatus = Status::NotRusWord;
        return true;
    }else{
        return false;
    }
}


bool Validator::isUsedWord(std::string playerWord, Dictionary &dictionary){
    if(dictionary.isUsedWord( playerWord )){
        currentStatus = Status::UsedWord;
        return true;
    }else{
        return false;
    }
}


bool Validator::hasWrongFirstLast(char playerFirstLetter, char pcLastLetter){
    if( playerFirstLetter == pcLastLetter){
        return false;

    //NOTE: Так как эти символы равнозначны ничего страшного если слово компьютера кончается на 'и' ,
    // а слово игрока будет начинаться на 'й' и наоборот
    }else if(( playerFirstLetter == 'и' && pcLastLetter == 'й' )||
             ( playerFirstLetter == 'е' && pcLastLetter == 'ё' )||
             ( playerFirstLetter == 'й' && pcLastLetter == 'и' )||
             ( playerFirstLetter == 'ё' && pcLastLetter == 'е' )){
        return false;

    //Если это первый ход
    }else if( pcLastLetter == ' ' ){
        return false;
    }else{
        currentStatus = Status::WrongFirstLetter;
        return true;
    }

}


bool Validator::hasWrongLastLetters(std::string playerWord){
    const int len=playerWord.length();
    if(strchr("ъыь", playerWord[ len-1 ]) && strchr("ъыь", playerWord[ len-2 ])){
        currentStatus = Status::WrongEnd;
        return true;
    }else{
        return false;
    }
}


bool Validator::hasSpaces(std::string playerWord){

    for(unsigned int i = 0; i < playerWord.length(); ++i){
        if(playerWord[i] == ' '){//Если в строке есть пробелы - это несколько слов
            currentStatus = Status::SpaceInWord;
            return true;
        }
    }
    //Если пробелов в слове небыло найдено
    return false;
}
