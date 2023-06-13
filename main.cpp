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
            cout << "������ ��ப�: " << endl;
            cin >> additionalStr;
            list.pushLastButOne(additionalStr);
            i--;
        }
        createResult(list);
        cout << "��ନ஢�� 䠩� � १���⮬. ������⢮ ����������� ��ப: " << count << endl;
    }
    return 0;
}

bool getTextFromFile(TSList &list) {
    ifstream fin("Nevsky.txt", ios::in | ios::binary);
    if (!fin) {
        cout << "�訡�� ������ 䠩��";
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
    cout << "���� ����������!" << endl;
    cout << "� �ணࠬ��, ����� 㬥�� ��⠢���� ��࠭��� ������⢮ ��ப ���� ��। ���殬 ⥪��=)" << endl;
    cout << "��� ࠡ�� � ���� �㤥� �ந�室��� �१ 䠩��" << endl;
    cout << "�� 㦥 ����㧨�� � ���� 䠩� (���� �� �� �� �⠫� �� ᮮ�饭��)" << endl;
    cout << "����, � ��୥��� ����� �஥�� 㦥 ����� 䠩� � ��⮪����=)" << endl;
    cout << "������� ���� ࠡ��� �㤥� ������ ⠬ ��" << endl;
    cout << endl;
    cout << "�� �� ᥩ�� �㤥� ������ : " << endl;
    cout << "�� ������ ᭠砫� ������⢮ ��ப, ����� ��� �������� (������讣� ࠧ���)" << endl;
    cout << "����� ������ � ���������� ⥪�� ��ப (�� ������᪮�)" << endl;
    cout << "� ᤥ��� ᢮� �����᪨� �������樨 � ��ନ��� 䠩�, �㤠 ������� ��� ⥪��!" << endl;
    cout << "�������! ������ ������⢮ ��ப, ����� �� ��� ��������: " << endl;
}

void createProtocol(const TSList &list) {
    ofstream fout("Protocol.txt");
    if (!fout) {
        cout << "�訡�� ������ 䠩��";
    } else {
        fout << list;
        fout.close();
    }
}

void createResult(const TSList &list) {
    ofstream fout("Result.txt");
    if (!fout) {
        cout << "�訡�� ������ 䠩��";
    } else {
        fout << list;
        fout.close();
    }
}
