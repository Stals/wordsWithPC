#include "check.h"

check::check(){
    statusNum=OK;
}
void check::playerWord(const std::string& playerWord,const std::string& pcWord,cases& c,charFunc& cf){
    //Получим Необходимые нам символы, а заодно приведём их к нижнему регистру
    playerFirstLetter=c.lowerCase(playerWord[0]);
    playerLastLetter=c.lowerCase(cf.getLastLetter(playerWord));
    pcLastLetter=c.lowerCase(cf.getLastLetter(pcWord));

    //ё->е й->и так как они считаются одним и темже
    cf.changeChar(playerFirstLetter);
    cf.changeChar(playerLastLetter);


}
