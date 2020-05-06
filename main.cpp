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
    cout << "Команда\t\tКол-во игр\tВыигр\tНичьи\tПроигр\tЗабитых\tПропущенных\tОчки\tМесто" << endl;
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
        cout << "Доступные команды" << endl;
        cout << "----------------------------------" << endl;
        cout << "1) Вывести таблицу команд" << endl;
        cout << "2) Отсортировать таблицу команд по местам" << endl;
        cout << "3) Добавить тур" << endl;
        cout << "4) Показать результаты игр команды" << endl;
        cout << endl << "Что вы хотите сделать? (Пожалуйста, выберите номер пункта, 0 - выйти): ";
        cin >> answer;

        switch(answer){
        case 1: display();break;
        case 2: sortTableByPosition();break;
        case 3: add();break;
        case 4: searchTeam();break;
        }
        cout << endl << "Хотите продолжить(1 - да, 0 - нет) : ";
        cin >> question;
        cout << endl;
        if (question == 0){
            cout << "Всего хорошего!" << endl;
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
    cout  << endl << "Таблица команд" << endl << endl;
    show();
    getch();
}

void sortTableByPosition(){
    cout << endl << "Отсортированная таблица по местам" << endl << endl;
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
    cout << endl << "Добавление тура" << endl << endl;
    cout << "Список команд" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << group[i].name << endl;
    };

    do {
        cout << endl << endl << "Пожалуйста выберите 2 команды, которые участвует в туре(номера команд вводятся последовательно через пробел): ";
        cin >> c1 >> c2;

        if (c1 == c2){
            cout << endl << "Пожалуйста, выберите разные команды" << endl;
        };
    } while (c1 == c2);

    cout << endl << "Введите кол-во мячей, который забила каждая команда " << endl << endl;
    cout << "Команда\t\t\tМячи" << endl;
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
    cout << endl << "Обновленная таблица результатов" << endl << endl;
    sortTableByPoints();
    sortTableByName();
    show();
    getch();
}

void searchTeam(){
    cin.get();
    string team;
    cout << endl << "Поиск результатов команды " << endl << endl;
    cout << "Список команд" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << i+1 << ") " << group[i].name << endl;
    };

    cout << endl << "Введите название команды: ";
    cin >> team;
    cout << endl;
    team.resize(16);
    for (int i = 0; i < n; i++){
        if (team == group[i].name){
             cout << "Команда\t\tКол-во игр\tВыигр\tНичьи\tПроигр\tЗабитых\tПропущенных\tОчки\tМесто" << endl;
             cout << "---------------------------------------------------------------------------------------------" << endl;
             cout << group[i].name << "\t" << group[i].game << "\t" << group[i].win <<
                "\t" << group[i].draw << "\t" << group[i].lose << "\t" << group[i].hit <<
                "\t" << group[i].miss << "\t\t" << group[i].points << "\t" << group[i].position << endl;
        }
    }
    cout << endl;
    getch();
}
