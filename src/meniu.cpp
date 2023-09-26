#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "meniu.h"
#include<fstream>
#include"masina.h"
#include "logo.h"
#define COLOR_SELECTED 14
#define COLOR_DEFAULT 7

using namespace std;

int selectare_optiune()
{
    static int option=1;
    char c;
    do//bucla ce se repeta pana cnd este actionata tasta enter
    {
        system("cls");
        printMenu(option);
        if((c=getch())==0x00)
            c=getch();

        if(c==72)//72-cod pt tasta sus
            option--;

        if(c==80)//80 cod pt tasta jos
            option++;
        if(option==0)//daca se apasa tasta 'up' iar pozitia curenta este primul rand al meniului se trece la randul 6(ultimul rand)
            option=6;
        if(option==7)//daca se apasa tasta 'down' iar pozitia curenta este ultimul rand al meniului se trece la randul 1(primul rand)
            option=1;

    }
    while(c!='\r');
    return option;
}

void printMenu(int option)//cod pentru afisarea meniului initial
{

    logo::afisare_logo();
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\n";
    if(option==1)
        SetConsoleTextAttribute(hConsole, COLOR_SELECTED);
    cout << "1. Alegere noua" << endl;
    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
    if(option==2)
        SetConsoleTextAttribute(hConsole, COLOR_SELECTED);
    cout << "2. Afiseaza alegerea facuta" << endl;
    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
    if(option==3)
        SetConsoleTextAttribute(hConsole, COLOR_SELECTED);
    cout << "3. Help" << endl;
    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
    if(option==4)
        SetConsoleTextAttribute(hConsole, COLOR_SELECTED);
    cout << "4. Info autor" << endl;
    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
    if(option==5)
        SetConsoleTextAttribute(hConsole, COLOR_SELECTED);
    cout << "5. Sterge fisier" << endl;
    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
    if(option==6)
        SetConsoleTextAttribute(hConsole, COLOR_SELECTED);
    cout << "6. Exit" << endl;
    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);

}

void someInfo(int _n)//de fiecare data cand este selectata o optiune din meniul initial aceasta functie este apelata cu o valoare corespunzatoare
                     //optiunii selectate
{
    if(_n==1)//valoarea 1 este corespunzatoare unei configuratii noi
    {
        cauta();//se apeleaza functia pentru o noua configuratie

    }
    if(_n==2)//valoarea 2 este corespunzatoare afisarii datelor memorate in fisier
    {
        ifstream f;//ifstream=functie pentru deschiderea unui fisier in modul 'citire'
        f.open("alegere.txt");//deschid fisierul
        string s;
        if (f.is_open())//daca s-a reusit deschiderea fisierului
        {
            while (!f.eof())//cat timp nu s-a ajuns la sfarsitul fisierului
            {
              getline(f,s);//citesc cate o linie din fisier
              cout<<s<<endl;//o afisez pe ecran(consola)
            }
        }
        f.close();//fisierul este inchis
    }
    if(_n==3)//valoarea 3 este corespunzatoare optiunii help
    {
        cout<<"Programul simuleaza o reprezentanta auto unde poti alege dotarile unei masini"<<endl;
        cout<<"Utilizatorul poate alege dintr-o serie de parametrii pentru a-si gasi o masina dorita"<<endl;
    }
    if(_n==4)//valoarea 4 este corespunzatoare optiunii info,si sunt afisate date despre autor
        cout <<"\nStudent Pentelescu Claudiu Gabriel\nGrupa 3122C\nAn universitar 2020-2021"<<endl;
    if(_n==5)//valoarea 5 este corespunzatoare optiunii de stergere din fisier
    {
        cout<<"Datele din fisier au fost sterse";
        ofstream f;
        f.open("alegere.txt");//deschid fisierul pentru scriere,fara optiunea de append,deci toate datele sunt sterse
        f.close();//inchid fisierul
    }
    if(_n==6)//valoarea 5 este corespunzatoare optiunii exit.
        exit(0);
    getch();
}
