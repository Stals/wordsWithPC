#include "cases.h"

cases::cases()
{
    {
        Case letter={'А','а'};
        caseList.push_back(letter);
    }
    {
   Case letter={'Б','б'};
   caseList.push_back(letter);
   {
   Case letter={'В','в'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Г','г'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Д','д'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Е','е'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ё','ё'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ж','ж'};
   caseList.push_back(letter);
   }
   {
   Case letter={'З','з'};
   caseList.push_back(letter);
   }
   {
   Case letter={'И','и'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Й','й'};
   caseList.push_back(letter);
   }
   {
   Case letter={'К','к'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Л','л'};
   caseList.push_back(letter);
   }
   {
   Case letter={'М','м'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Н','н'};
   caseList.push_back(letter);
   }
   {
   Case letter={'О','о'};
   caseList.push_back(letter);
   }
   {
   Case letter={'П','п'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Р','р'};
   caseList.push_back(letter);
   }
   {
   Case letter={'С','с'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Т','т'};
   caseList.push_back(letter);
   }
   {
   Case letter={'У','у'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ф','ф'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Х','х'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ц','ц'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ч','ч'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ш','ш'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Щ','щ'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ь','ь'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ы','ы'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ъ','ъ'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Э','э'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Ю','ю'};
   caseList.push_back(letter);
   }
   {
   Case letter={'Я','я'};
   caseList.push_back(letter);
}
}
}
std::string cases::lowerCase(std::string word){

    for(int i=0;i<word.size();++i){
           for(std::vector <Case>::iterator it=caseList.begin();it!=caseList.end();++it){
               if(word[i]==(*it).up){
                    word[i]=(*it).low;
               }

           }
    }

return word;

}
std::string cases::upperCase(std::string word){

    for(int i=0;i<word.size();++i){
           for(std::vector <Case>::iterator it=caseList.begin();it!=caseList.end();++it){
               if(word[i]==(*it).low){
                    word[i]=(*it).up;
               }

           }
    }

return word;

}
bool cases::rusLetter(char letter){

    for(std::vector <Case>::iterator it=caseList.begin();it!=caseList.end();++it){
        if(letter==(*it).up||letter==(*it).low){
            return true;

        }
    }
    //если мы сюда дошли значит во всём словаре нет такой буквы
    return false;

}
