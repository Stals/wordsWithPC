#include "findword.h"

findWord::findWord()
{
    loadDicts();
}
void findWord::loadDicts(){

     std::string filesArray[] =  { "dict//1","dict//2","dict//3","dict//4","dict//5","dict//6","dict//7","dict//8","dict//9","dict//10","dict//11","dict//12","dict//13","dict//14","dict//15","dict//16","dict//17","dict//18","dict//19","dict//20","dict//21","dict//22","dict//23","dict//24","dict//25","dict//26","dict//27","dict//28","dict//29","dict//30","dict//31","dict//32","dict//33" };
     std::vector<std::string> files (filesArray, filesArray + sizeof(filesArray) / sizeof(std::string) );
     for( std::vector<std::string>::iterator it=files.begin();it!=files.end();++it){
         std::ifstream f((*it).c_str());
         int num;//number of words
         std::string letter;
         std::string newWord;
         f>>letter;
         f>>num;

             for(int i=0;i<num;++i){

                    f>>newWord;
                    singleDict.push_back(newWord);
              }
         f.close();
         dictionary.insert ( std::pair<std::string,std::list<std::string> >(letter,singleDict) );
         singleDict.clear();
      }

}
void findWord::usedWord(std::string Word){
//��������� � usedWords
    usedWords.push_back(Word);

  //������� �� dictionary ,���� ��� ��� ����
     std::map <std::string,std::list<std::string> >::iterator mapIter = dictionary.begin();
    for(;mapIter!=dictionary.end();++mapIter){
        if((*mapIter).first[0]==Word[0]){//���� � ������� ���� ������� �� ��� �����
            //������� ��� �����,���� ����
            (*mapIter).second.remove(Word);



            break;
        }

    }

}

std::string findWord::findRandomWord(char lastLetter){
srand(time(NULL));


        std::map <std::string,std::list<std::string> >::iterator mapIter = dictionary.begin();

        for(;mapIter!=dictionary.end();++mapIter){
            if((*mapIter).first[0]==lastLetter){//����� ��� ������ ,�� ������� ��������� �����  ������
                std::list<std::string>::iterator it = (*mapIter).second.begin();
                if((*mapIter).second.size()!=0){
                    for(unsigned int i=0;i<rand()%(*mapIter).second.size();++i){
                        ++it;
                    }
                //TODO: ����� ����������
                usedWord((*it));
                return (*it);

            }else{
                return "YOU WIN";
            }

            }

        }


        //TODO:
   //�������� ���� ���� �����
return "YOU WIN";
}

bool findWord::checkUsed(std::string playerWord){
    for(std::list<std::string>::iterator it=usedWords.begin();it!=usedWords.end();++it){

        if((*it)==playerWord){//����� ��� ����
            return false;
        }

    }
    //���� �� ���� ������ �� �������� ������ �����- ������� ��� ��� ��� �� ��������������
return true;


}
