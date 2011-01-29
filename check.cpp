#include "check.h"

check::check(){
    statusNum=OK;
}
bool check::playerWord(std::string& playerWord,const std::string& pcWord,cases& c,findWord& fw){
    //Получим Необходимые нам символы, а заодно приведём их к нижнему регистру
    playerFirstLetter=c.lowerCase(playerWord[0]);
    playerLastLetter=c.lowerCase(getLastLetter(playerWord));
    pcLastLetter=c.lowerCase(getLastLetter(pcWord));

    //ё->е й->и так как они считаются одним и темже
    changeChar(playerFirstLetter);
    changeChar(playerLastLetter);

   // playerWord[0]=playerFirstLetter;//чтобы слова с большой и мальнекой бувы были одинаковы

    //функции внутри меняют statusNum,если произошла ошибка
    if(checkLength(playerWord))//если ошибка в длинне
        return false;
    else if(rusLetter(playerLastLetter,c))
        return false;
    else if(usedWord(playerWord,fw))
        return false;

    else if(pcWord!=""){//для любого хода кроме первого
           //проверим совпадает ли первая буква слова игрока с последней в слове компа
          if(firstLast(playerFirstLetter,pcLastLetter))
              return false;
    }

     //playerWord удовлетворяет всем условиям

     statusNum=OK;
     return true;

}

std::string check::stringStatus(){
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
    }
    return "Ошибка";
}
bool check::checkLength(std::string playerWord){
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
bool check::rusLetter(char letter,cases& c){
    if(!c.rusLetter(letter)){
        statusNum=NotRusWord;
        return true;
    }else
        return false;

}
bool check::usedWord(std::string playerWord,findWord& fw){
 if(!fw.checkUsed(playerWord)){
     statusNum=UsedWord;
     return true;
 }else
     return false;
}
bool check::firstLast(char playerFirstLetter,char pcLastLetter){
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
