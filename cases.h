#ifndef CASES_H
#define CASES_H
#include <string>
#include <vector>
struct Case{
    char up;
    char low;

};
class cases
{
public:
    cases();
    std::string lowerCase(std::string word);
    std::string upperCase(std::string word);
    bool rusLetter(char letter);//возвращает true если буква русская
private:
    std::vector <Case> caseList;
};

#endif // CASES_H
