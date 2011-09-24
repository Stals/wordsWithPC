#ifndef CASES_H
#define CASES_H
#include <string>
#include <locale>
namespace cases{

//ѕриводит все буквы в слове к нижнему регистру
inline std::string toLowerCase(std::string& word){
    for(size_t i = 0; i < word.length(); ++i){
        //NOTE : ѕри сборке в новом qt 4.7 приводит к нижнему регистру даже русские буквы
        word[i] = tolower( word[i] );
    }
    return word;
}
}

#endif // CASES_H
