#include "cases.h"

cases::cases()
{
    {
        Case letter={'�','�'};
        caseList.push_back(letter);
    }
    {
   Case letter={'�','�'};
   caseList.push_back(letter);
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
   caseList.push_back(letter);
   }
   {
   Case letter={'�','�'};
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
bool cases::rusLetter(char letter){
    bool check=false;
    for(std::vector <Case>::iterator it=caseList.begin();it!=caseList.end();++it){
        if(letter==(*it).up||letter==(*it).low){
            return true;

        }


    }
    //���� �� ���� ����� ������ �� ��� ������� ��� ����� �����
    return false;


}
