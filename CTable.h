/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CTable.h
 * Author: lukasz
 *
 * Created on October 9, 2016, 1:05 PM
 */

#ifndef CTABLE_H
#define CTABLE_H
#include <string>

class CTable {
public:
    const static int DEFAULT_SIZE;
    const static std::string DEFAULT_NAME;

    //konstruktory:
    CTable();//DONE
    CTable(CTable &table);
    CTable(std::string name);//
    //destruktor
    virtual ~CTable();//DONE


    std::string toString();//TO FINISH
    int getLength();//DONE
    bool changeSize(int size);//DONE
    void changeName(std::string name);
    bool write(int index, int value);//DONE
    int read(int index);
    CTable* clone();//DONE
    bool assign(CTable &table);

    //operators overloading:
    void operator=(CTable* right);
    inline CTable operator+(const CTable* rigth);
    CTable operator-(CTable* rigth);
    CTable operator*(CTable* rigth);



private:
    int length;
    int* tab;
    std::string s_name;

};

#endif /* CTABLE_H */