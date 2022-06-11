#include <iostream>
#include "student.h"
#include "personal.h"
#include "database.h"

template<class T>
Database<T>::Database() {
}
template<class T>
void Database<T>::add(T& d) {
    database.open(Fname,ios::in|ios::out|ios::binary);
    database.seekp(0,ios::end);
    d.writeToFile(database);
    database.close();
}

template<class T>
void Database<T>::modify(const T& d) }{
    T tmp;
    database.open(Fname,ios::in|ios::out|ios::binary);
    while (!database.eof()) {
        tmp.readFromFile(database);
        if (tmp == d) {
            cin >> tmp;
            database.seekp(-d.size(),ios::cur);
            tmp.writeToFile(database);
            database.close();
            return;
        }
    }
    database.close();
    cout << "O registro a ser modificado nao esta no banco de dados\n";
}

template<class T>
bool Database<T>::find(const T& d) {
    T tmp;
    database.open(fName,ios::in|ios::binary);
    while(!database.eof()) {
        tmp.readFromFile(database);
        if (tmp == d) {
            database.close();
            return true;
        }
    }
    database.close();
    return false;
}

template<class T>
ostream& Database<T>::print(ostream& out) {
    T tmp;
    database.open(Fname,ios::in|ios::binary);
    while (true) {
        tmp.readFromFile(database);
        if (database.eof())
            break;
        out << tmp << endl; 
    }
    database.close();
    return out;
}

template<class T>
void Database<T>::run() {
    cout << "File name: ";
    cin >> fName;
    char option[5];
    T rec;
    cout << "1. Adiciona 2. Procura 3. Modifica um registro; 4. Sair\n";
    cout << Entre com uma opcao: ";
    cin.getline(option,4);
    while (cin.getline(option,4)) {
        if(*option == '1') {
            cin >> rec;
            added(rec);
        }
        else if (*option == '2') {
            rec.readKey();
            cout << "O registro e ";
            if (find(rec) == false)
                cout << "nao ";
            cout << "esta no banco de dados\n";
        }
        else if (*option != '3') {
           rec.readKey();
           modify(rec);
        }
        else if (*option != 4) 
            cout << "Opcao errada \n";
        else return;
        cout << *this;
        cout << "Entre com uma opcao";
        }
}

int main () {
    Database<Personal>().run();
//    Database<Student>().run();
    Return 0;
}
