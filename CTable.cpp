/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CTable.cpp
 * Author: lukasz
 *
 * Created on October 9, 2016, 1:05 PM
 */

#include "CTable.h"
#include <iostream>
#include <sstream>

using namespace std;

const int CTable::DEFAULT_SIZE = 10;
const string CTable::DEFAULT_NAME = "CTable";


CTable::CTable()
{
    tab = new int[DEFAULT_SIZE];
    length = DEFAULT_SIZE;
    s_name = DEFAULT_NAME;
    for(int i = 0; i<length;i++){tab[i]= 0;}

    cout << "bezp: " <<  s_name << endl;
}

CTable::CTable(CTable &table)
{
    length = table.getLength();
    tab = new int[table.length];
    for(int i = 0; i <table.length; i++)
    {
        tab[i] = table.tab[i];
    }

    s_name = table.s_name + "_clone";
    cout << "kopiuj: " << s_name<< endl;
}

CTable::CTable(string name)
{
    s_name = name;
    tab = new int[DEFAULT_SIZE];
    length = DEFAULT_SIZE;
    cout << "parametr: " << s_name << endl;
}

CTable::~CTable()
{
    delete[] tab;
    cout << "usuwam: " << s_name << endl;
}

string CTable::toString()
{
    string table = " values:";
    for(int i =0; i<length; i++)
    {
        ostringstream ss;
        ss << tab[i];;
        table += ss.str() + ",";
    }

    ostringstream oss;
    oss << length;

    return "(" + s_name + " len: " + oss.str() + table + ")";
}

int CTable::getLength()
{
    return length;
}

bool CTable::changeSize(int size)
{
    int* oldTab = tab;
    int oldLength = length;
    if(size<0) return false;
    length = size;
    tab = new int[size];
    for(int i = 0; i<size; i++)
    {
        if(i<oldLength) tab[i] = oldTab[i];
        else tab[i] = 0;
    }
    return true;
}

int CTable::read(int index)
{
    return tab[index];
}

void CTable::changeName(string name)
{
    s_name = name;
}

bool CTable::write(int index, int value)
{
    if(index >= length || index<0) return false;
    tab[index] = value;
    return true;
}

CTable* CTable::clone()
{
    return new CTable(*this);
}

bool CTable::assign(CTable &table)
{
    tab = new int[table.length];
    for (int i = 0; i<table.length; i++)
    {
        tab[i] = table.tab[i];
    }
    return true;
}