#include <iostream>
#include <fstream>
#include "TomaString.h"
#include "TSList.h"

using namespace std;

bool getTextFromFile(TSList &list);
void printIntro();
void createProtocol(const TSList &list);
void createResult(const TSList &list);

int main() {

    TSList list;
    int count,i;
    TomaString additionalStr;

    if (getTextFromFile(list)) {
        createProtocol(list);
        printIntro();
        cin >> count;

        i = count;
        while (i) {
            cout << "Введите строку: " << endl;
            cin >> additionalStr;
            list.pushLastButOne(additionalStr);
            i--;
        }
        createResult(list);
        cout << "Сформирован файл с результатом. Количество добавленных строк: " << count << endl;
    }
    return 0;
}

bool getTextFromFile(TSList &list) {
    ifstream fin("Nevsky.txt", ios::in | ios::binary);
    if (!fin) {
        cout << "Ошибка открытия файла";
        return false;
    } else {
        char ch;
        TomaString str;
        int i;
        while (!fin.eof()) {
            str = "";
            i = TomaString::getMaxLength();
            while (!fin.eof() && (i > 0)) {
                fin.get(ch);
                if (!fin.eof() && ch != 13 && ch != 10) {
                    str.append(ch);
                    i--;
                } else break;
            }
            if (str.length() > 1) {
                list.pushBack(str);
            }
        }
        fin.close();
        return true;
    }
}

void printIntro() {
    cout << "Добро пожаловать!" << endl;
    cout << "Я программа, которая умеет вставлять выбранное количество строк почти перед концом текста=)" << endl;
    cout << "Вся работа со мной будет происходить через файлы" << endl;
    cout << "Вы уже загрузили в меня файл (иначе вы бы не читали это сообщение)" << endl;
    cout << "Кстати, в корневой папке проекта уже лежит файл с протоколом=)" << endl;
    cout << "Результат моей работы будет лежать там же" << endl;
    cout << endl;
    cout << "Что мы сейчас будет делать : " << endl;
    cout << "Вы введете сначала количество строк, которые хотите добавить (небольшого размера)" << endl;
    cout << "Далее введете с клавиатуры текст строк (на английском)" << endl;
    cout << "Я сделаю свои магические манипуляции и сформирую файл, куда добавлю ваш текст!" << endl;
    cout << "Погнали! Введите количество строк, которые вы хотите добавить: " << endl;
}

void createProtocol(const TSList &list) {
    ofstream fout("Protocol.txt");
    if (!fout) {
        cout << "Ошибка открытия файла";
    } else {
        fout << list;
        fout.close();
    }
}

void createResult(const TSList &list) {
    ofstream fout("Result.txt");
    if (!fout) {
        cout << "Ошибка открытия файла";
    } else {
        fout << list;
        fout.close();
    }
}
