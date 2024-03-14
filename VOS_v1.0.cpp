#include <iostream>
#include <map>
#include <string>
#include <Windows.h>

void saveNewKnowledge(std::map<std::string, std::string>& knowledgeBase, const std::string& question, const std::string& answer) {
    knowledgeBase[question] = answer;
}
int main() {
    std::map<std::string, std::string > knowledgeBase;
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    std::cout << "Приветвиую Вас! Чем могу быть полезен?" << std::endl;
    std::string userInput;
    while (true) {
        std::cout << "> "; std::getline(std::cin, userInput);
        auto it = knowledgeBase.find(userInput);
        if (it != knowledgeBase.end()) {
            std::cout << it->second << std::endl;
        }
        else {
            std::cout << "Извините, я не знаю ответа на этот вопрос." << std::endl;
            std::cout << "Введите новый ответ на вопрос: " << userInput << std::endl;
            std::string newAnswer;
            std::cout << "> "; std::getline(std::cin, newAnswer);
            saveNewKnowledge(knowledgeBase, userInput, newAnswer);
            std::cout << "Спасибо! Я запомнил Ваш новый ответ." << std::endl;
        }
    }
    return 0;
}