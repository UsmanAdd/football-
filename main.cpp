#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <conio.h>

using namespace std;
void read(),display(), sortTableByPosition(),
    add(),menu(),show(), sortTableByName(),
    sortTableByPoints(), editPosition(), searchTeam();

int n = 0;
int answer = 0;
int c1 = 0;
int c2 = 0;
int g1 = 0;
int g2 = 0;
int question = 0;

struct{
    string name;
    int game;
    int win;
    int draw;
    int lose;
    int hit;
    int miss;
    int points;
    int position;

} group[20];

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    ofstream record;
    record.open("D:\pz1-1.txt");
    for (int i = 0; i < n; i++){
        record << group[i].name << "\t" << group[i].game << "\t" << group[i].win <<
        "\t" << group[i].draw << "\t" << group[i].lose << "\t" << group[i].hit <<
        "\t" << group[i].miss << "\t" << group[i].points << "\t" << group[i].position << endl;
    }
    record.close();
    return 0;
}

void show(){
    cout << "�������\t\t���-�� ���\t�����\t�����\t������\t�������\t�����������\t����\t�����" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << group[i].name << "\t" << group[i].game << "\t" << group[i].win <<
        "\t" << group[i].draw << "\t" << group[i].lose << "\t" << group[i].hit <<
        "\t" << group[i].miss << "\t\t" << group[i].points << "\t" << group[i].position << endl;
    }
    cout << endl;

}

void sortTableByName(){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(group[i].name > group[j].name){
                swap(group[i],group[j]);
            }
        }
    }
}
void sortTableByPoints(){
     for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(group[i].points < group[j].points){
                swap(group[i],group[j]);
            }
        }
    }
    editPosition();
}

void editPosition(){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(group[i].position > group[j].position){
                swap(group[i].position, group[j].position);
            } else if (group[i].position == group[j].points){
                if(group[i].game < group[j].game){
                    swap(group[i],group[j]);
                } else if (group[i].game == group[j].game){
                    if(group[i].win > group[j].win){
                        swap(group[i].position, group[j].position);
                    } else if (group[i].win == group[j].win){
                        if((group[i].hit - group[i].miss) > (group[j].hit - group[i].miss)){
                            swap(group[i].position, group[j].position);
                        }
                    }
                }
            }
        }
    }
}

void menu(){
    read();
    do {
        cout << "��������� �������" << endl;
        cout << "----------------------------------" << endl;
        cout << "1) ������� ������� ������" << endl;
        cout << "2) ������������� ������� ������ �� ������" << endl;
        cout << "3) �������� ���" << endl;
        cout << "4) �������� ���������� ��� �������" << endl;
        cout << endl << "��� �� ������ �������? (����������, �������� ����� ������, 0 - �����): ";
        cin >> answer;

        switch(answer){
        case 1: display();break;
        case 2: sortTableByPosition();break;
        case 3: add();break;
        case 4: searchTeam();break;
        }
        cout << endl << "������ ����������(1 - ��, 0 - ���) : ";
        cin >> question;
        cout << endl;
        if (question == 0){
            cout << "����� ��������!" << endl;
            break;
        }
    } while(answer != 0);
}

void read(){
    ifstream table;
    table.open("D:\pz1.txt");
    while(!table.eof()){
        table >> group[n].name >> group[n].game  >> group[n].win >>
        group[n].draw >> group[n].lose >> group[n].hit >>
        group[n].miss >> group[n].points >> group[n].position;
        group[n].name.resize(16);
        n++;
    }
    table.close();
}

void display(){
    cout  << endl << "������� ������" << endl << endl;
    show();
    getch();
}

void sortTableByPosition(){
    cout << endl << "��������������� ������� �� ������" << endl << endl;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (group[i].position > group[j].position){
                swap(group[i],group[j]);
            }
        }
    }
    show();
    getch();
}

void add(){
    sortTableByName();
    cout << endl << "���������� ����" << endl << endl;
    cout << "������ ������" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << group[i].name << endl;
    };

    do {
        cout << endl << endl << "���������� �������� 2 �������, ������� ��������� � ����(������ ������ �������� ��������������� ����� ������): ";
        cin >> c1 >> c2;

        if (c1 == c2){
            cout << endl << "����������, �������� ������ �������" << endl;
        };
    } while (c1 == c2);

    cout << endl << "������� ���-�� �����, ������� ������ ������ ������� " << endl << endl;
    cout << "�������\t\t\t����" << endl;
    cout << "---------------------------" << endl;
    cout << group[c1-1].name << "\t";
    cin >> g1;
    cout << group[c2-1].name << "\t";
    cin >> g2;

    group[c1-1].game += 1;
    group[c2-1].game += 1;

    if (g1 == g2){
        group[c1-1].draw += 1;
        group[c1-1].hit += g1;
        group[c1-1].miss += g2;
        group[c1-1].points += 1;
        ///////////////////////
        group[c2-1].draw += 1;
        group[c2-1].hit += g2;
        group[c2-1].miss += g1;
        group[c2-1].points += 2;
    } else if (g1 > g2){
        group[c1-1].win += 1;
        group[c1-1].hit += g1;
        group[c1-1].miss += g2;
        group[c1-1].points += 5;
        ///////////////////////
        group[c2-1].lose += 1;
        group[c2-1].hit += g2;
        group[c2-1].miss += g1;

    } else {
        group[c1-1].lose += 1;
        group[c1-1].hit += g1;
        group[c1-1].miss += g2;
        //////////////////////
        group[c2-1].win += 1;
        group[c2-1].hit += g2;
        group[c2-1].miss += g1;
        group[c2-1].points += 5;

    }
    cout << endl << "����������� ������� �����������" << endl << endl;
    sortTableByPoints();
    sortTableByName();
    show();
    getch();
}

void searchTeam(){
    cin.get();
    string team;
    cout << endl << "����� ����������� ������� " << endl << endl;
    cout << "������ ������" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << group[i].name << endl;
    };

    cout << endl << "������� �������� �������: ";
    cin >> team;
    cout << endl;
    team.resize(16);
    for (int i = 0; i < n; i++){
        if (team == group[i].name){
             cout << "�������\t\t���-�� ���\t�����\t�����\t������\t�������\t�����������\t����\t�����" << endl;
             cout << "---------------------------------------------------------------------------------------------" << endl;
             cout << group[i].name << "\t" << group[i].game << "\t" << group[i].win <<
                "\t" << group[i].draw << "\t" << group[i].lose << "\t" << group[i].hit <<
                "\t" << group[i].miss << "\t\t" << group[i].points << "\t" << group[i].position << endl;
        }
    }
    cout << endl;
    getch();
}
