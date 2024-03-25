#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <Windows.h>

using namespace std;

void Encodings() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void saveNewKnowledge(map<string, string>& knowledgeBase, const string& question, const string& answer) {
    knowledgeBase[question] = answer;
}

void saveKnowledgeToFile(const map<string, string>& knowledgeBase, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : knowledgeBase) {
            file << entry.first << " :: " << entry.second << endl;
        }
        file.close();
        cout << "База знаний успешно сохранена в файле: " << filename << endl;
    }
    else {
        cout << "Ошибка открытия файла для сохранения базы знаний." << endl;
    }
}

int main() {
    Encodings();

    map<string, string > knowledgeBase;
    string userInput;

    cout << "Приветвиую Вас! Чем могу быть полезен?" << endl;
    auto it = knowledgeBase.find(userInput);
    while (true) {
        cout << "> "; getline(cin, userInput);

        if (userInput == "сохранить") {
            cout << "Введите имя файла для сохранения базы знаний" << endl;
            string filename;
            cout << "> "; getline(cin, filename);
            saveKnowledgeToFile(knowledgeBase, filename);
        }
        else {
            it = knowledgeBase.find(userInput);
            if (it != knowledgeBase.end()) {
                cout << it->second << ". " << "Чем могу еще помочь?" << endl;
            }
            else {
                cout << "Извините, я не знаю ответа на этот вопрос." << endl;
                cout << "Введите новый ответ на вопрос: " << userInput << endl;
                string newAnswer;
                cout << "> "; getline(cin, newAnswer);
                saveNewKnowledge(knowledgeBase, userInput, newAnswer);
                cout << "Спасибо! Я запомнил Ваш новый ответ." << endl;
            }
        }
    }

    return 0;
}