/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: lukasz
 *
 * Created on October 9, 2016, 1:03 PM
 */

#include <cstdlib>
#include <iostream>
#include "CTable.h"
#include <vector>

using namespace std;

/*
 *
 */

const string QUIT = "quit";
const string NEW = "new";
const string PRINTALL = "printall";
const string PRINT = "print";
const string SIZE = "size";
const string DELETE = "delete";
const string CLEAR = "clear";
const string CHANGENAME = "changename";
const string CHANGESIZE = "changesize";
const string WRITE = "write";
const string CLONE = "clone";
const string NOTHING = "nothing";
const string HELP = "help";

int inputInt()
{
    int out;
    cin >> out;
    if(cin.fail())
    {
        cout << "nie wpisano liczby! " << endl;
        cin.clear();
        out = -1;
    }
    return out;
}

void nothing(CTable ctab)
{

}

void console()
{
    std::vector<CTable*> tables;
    bool running = true;
    while(running)
    {
        cout << ">";
        string command;
        cin.clear();
        cin >> command;

        if(command == QUIT) running = false;
        if(command == NEW)
        {
            CTable* ct = new CTable();
            tables.push_back(ct);
        }
        if(command == PRINTALL)
        {
            cout << "Istniejace tablice:" << endl;
            for(int i = 0; i<tables.size(); i++)
            {
                cout << "    #" << i << " " << tables.at(i)->toString() << endl;
            }
        }
        if(command == PRINT)
        {
            cout << "Wpisz indeks tablicy ktora chcesz wydrukowac: ";
            int index = inputInt();
            if(index >= tables.size() || index < 0) cout << "Zly indeks" << endl;
            else cout << tables.at(index)->toString() << endl;
        }
        if(command == SIZE)
        {
            cout << tables.size() << endl;
        }
        if(command == DELETE)
        {
            cout << "Wpisz indeks tablicy ktora chcesz usunac: ";
            int index = inputInt();
            if(index<0 || index>=tables.size())
            {
                cout << "zly indeks" << endl;
            }
            else
            {
                delete tables.at(index);
                tables.erase(tables.begin() + index);
            }
        }
        if(command == CLEAR)
        {
            for(int i = 0; i<tables.size(); i++)
            {
                delete* &tables.at(i);
            }
            tables.clear();
        }
        if(command == CHANGENAME)
        {
            cout << "Wpisz indeks tablicy ktorej nazwe chcesz zmienic: ";
            int index = inputInt();
            if(index<0 || index>tables.size())
            {
                cout << "zly indeks" << endl;
            }
            else
            {
                cout << "Wpisz nowe imie: ";
                string newName;
                cin >> newName;
                tables.at(index)->changeName(newName);
            }
        }
        if(command == CHANGESIZE)
        {
            cout << "Wpisz indeks tablicy ktorej nazwe chcesz zmienic: ";
            int index = inputInt();
            if(index<0 || index>tables.size())
            {
                cout << "zly indeks" << endl;
            }
            else
            {
                cout << "Wpisz nowy rozmiar: ";
                int newSize = inputInt();

                bool test;
                if(!(test = tables.at(index)->changeSize(newSize)))
                {
                    cout << "zly indeks" << endl;
                }
            }
        }
        if(command == WRITE)
        {
            cout << "Wpisz indeks tablicy ktora chcesz zmienic: ";
            int index = inputInt();
            if(index < 0 || index >= tables.size())
            {
                cout << "zly indeks" << endl;
            }
            else
            {
                cout << "Wpisz indeks komorki tablicy: ";
                int ind = inputInt();
                if(ind<0 || ind > tables.at(index)->getLength())
                {
                    cout << "zly indeks"<< endl;
                }
                else
                {
                    cout << "Wpisz wartosc: ";
                    int value = inputInt();
                    tables.at(index)->write(ind, value);
                }

            }
        }
        if(command == CLONE)
        {
            cout << "Wpisz indeks tablicy ktora chcesz skopiowac: ";
            int index = inputInt();
            if(index < 0 || index >= tables.size())
            {
                cout << "zly indeks" << endl;
            }
            else
            {
                tables.push_back(new CTable(*tables.at(index)));
            }
        }
        if(command == NOTHING)
        {
            cout << "wpisz indeks: ";
            int index = inputInt();
            if(index < 0 || index >= tables.size())
            {
                cout << "zly indeks" << endl;
            }
            else
            {
                nothing(*tables.at(index));
            }

        }
        if(command == HELP)
        {
            cout << "quit \nnew \nprint \nprintall \nsize \ndelete \nclear \nchangename \nchangesize \nwrite \nclone \nnothing\n";
        }
        cin.clear();

    }
}

int main(int argc, char** argv)
{
    console();

    return 0;
}