#include "check.h"

check::check(){
    statusNum=OK;
}
void check::playerWord(const std::string& playerWord,const std::string& pcWord,cases& c,charFunc& cf){
    //������� ����������� ��� �������, � ������ ������� �� � ������� ��������
    playerFirstLetter=c.lowerCase(playerWord[0]);
    playerLastLetter=c.lowerCase(cf.getLastLetter(playerWord));
    pcLastLetter=c.lowerCase(cf.getLastLetter(pcWord));

    //�->� �->� ��� ��� ��� ��������� ����� � �����
    cf.changeChar(playerFirstLetter);
    cf.changeChar(playerLastLetter);


}
