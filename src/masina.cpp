#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

class masina
{
    string marca;
    string model;
    string nr_usi;
    string combustibil;
    public:
    void set_val(string _marca,string _model,string _nr_usi,string _combustibil)
    {
        marca=_marca;
        model=_model;
        nr_usi= _nr_usi;
        combustibil = _combustibil;
    }

    void print_f()//functie de printare in fisier
    {
        ofstream f;
        f.open("alegere.txt",ios::app);//deschid fisierul pentru scriere
        f<<endl<<marca<<" "<<model<<" "<<nr_usi<<" "<<combustibil;//scriu in fisier
        f.close();//inchid fisierul
    }

    void print()//functie de printare in consola a obiectului apelant
    {
        cout<<endl<<"Modelul ales este: "<<endl<<marca<<" "<<model<<" "<<nr_usi<<" "<<combustibil<<endl;
    }

    masina()    //constuctor implicit
    {
    }

    ~masina()   //destructor
    {
    }

};
void cauta()
{
    int i;
    int cont=0;
    int poz,ok=0;
    char s[20];
    masina masina_mea;//obiect al clasei masina
    string mycar[10];//vector de stringuri in care memorez configuratia user-ului
    string aux[10];
    string marca[10]={"Audi","Volkswagen","Skoda","Seat","Porsche"};
    string masini[15][5]={"Audi","S5","3 usi","benzina","5L/100km",
                          "Volkswagen","Golf V","5 usi","benzina","10L/100km",
                          "Skoda","Octavia","5 usi","benzina","8L/100km",
                          "Seat","Leon","4 usi","motorina","6L/100km",
                          "Porsche","Cayenne","5 usi","benzina","5L/100km",
                          "Audi","A4","4 usi","benzina","7L/100km",
                          "Volkswagen","Passat","4 usi","motorina","7L/100km",
                          "Skoda","Fabia","3 usi","benzina","5L/100km",
                          "Seat","Ibiza","5 usi","benzina","7L/100km",
                          "Porsche","911","3 usi","benzina","5L/100km",
                          "Audi","A6","2 usi","benzina","12L/100km",
                          "Volkswagen","Jetta","5 usi","benzina","9L/100km",
                          "Skoda","Superb","5 usi","benzina","8L/100km",
                          "Seat","Cordoba","5 usi","benzina","5L/100km",
                          "Porsche","928","2 usi","benzina","5L/100km"};

    cout<<"Alegeti marca masinii: "<<endl;
    cout<<"Apasati: "<<endl;
    for(i=0;i<5;i++)//bucla pentru afisarea masinilor(marca) din stoc
        cout<<i+1<<". pentru "<<marca[i]<<endl;
    do//bucla pentru citirea marcii masinii. Se repeta pana cand este introdusa o optiune corecta
    {
        cin>>poz;//citesc o valoare drept marca masinii
        if(poz<1)//verificare daca valoarea introdusa este corecta
         cout<<"Optiune incorecta!Reincercati!"<<endl;
        else
            if(poz>5)//verificare daca valoarea introdusa este corecta
                cout<<"Optiune incorecta!Reincercati!"<<endl;
            else//in caz ca valoarea e corecta, ok=1 pentru a iesi din bucla
                ok=1;
    }
    while(!ok);
    mycar[0]=marca[poz-1];//memorez marca masinii
    ok=0;//ok devine 1 dupa bucla precedenta,iar pentru urmatorul test bucla se va repeta cat timp ok=0
    cout<<"Alegeti modelul:"<<endl<<"Apasati: "<<endl;
    for(i=0;i<15;i++)//afisarea modelelor cu marca selectata
        if(masini[i][0]==mycar[0])//verific daca marca aleasa precedent se potriveste cu cea din matrice,iar in caz afirmativ afisez modelul
        {
            cout<<cont+1<<". pentru "<<masini[i][1]<<endl;
            aux[cont]=masini[i][1];
            cont++;
        }
    do//bucla pentru citirea modelului masinii. Se repeta pana cand este introdusa o optiune corecta
    {
        cin>>poz;
        if(poz<1)
            cout<<"Optiune incorecta!Reincercati!"<<endl;
        else
            if(poz>cont)
                cout<<"Optiune incorecta!Reincercati!"<<endl;
            else
                ok=1;
    }
    while(!ok);
    ok=0;//ok devine 1 dupa bucla precedenta,iar pentru urmatorul test bucla se va repeta cat timp ok=0
    mycar[1]=aux[poz-1];//memorez modelul masinii
    for(i=0;i<=cont;i++)//vectorul auxiliar folosit pentru memorarea modelelor devine gol
        aux[i]=" ";
    cont=0;//contorul devine 0,pt a putea numara cate 'nr de usi' sunt disponibile
    cout<<"Alegeti numar usi: "<<endl<<"Apasati: "<<endl;
    for(i=0;i<16;i++)//verific daca marca si modelul alese precedent se potriveste cu cea din matrice,iar in caz afirmativ afisez numarul de usi
        if(masini[i][0]==mycar[0] && masini[i][1]==mycar[1])
        {
            cout<<cont+1<<". pentru "<<masini[i][2]<<endl;
            aux[cont]=masini[i][2];
            cont++;
        }
    do//bucla pentru citirea numarului de usi ale masinii. Se repeta pana cand este introdusa o optiune corecta
    {
        cin>>poz;
        if(poz<1)
            cout<<"Optiune incorecta!Reincercati!"<<endl;
        else
            if(poz>cont)
                cout<<"Optiune incorecta!Reincercati!"<<endl;
            else
                ok=1;
    }
    while(!ok);
    ok=0;
    mycar[2]=aux[poz-1];// numarul de usi
    for(i=0;i<=cont;i++)//vectorul auxiliar folosit pt memorarea numarului de usi devine gol
        aux[i]="";
    cont=0;//contorul devine 0,pt a putea numara cate tipuri de combustibil sunt disponibile
    cout<<"Alegeti combustibilul:"<<endl<<"Apasati: "<<endl;
    for(i=0;i<16;i++)
        if(masini[i][0]==mycar[0] && masini[i][1]==mycar[1] && masini[i][2]==mycar[2])
        {
            cout<<cont+1<<". pentru "<<masini[i][3]<<endl;//afisez combustibilul
            aux[cont]=masini[i][3];//memorez combustibilul
            cont++;//incrementez contorul
        }
    do
    {
        cin>>poz;
        if(poz<1)
            cout<<"Optiune incorecta!Reincercati!"<<endl;
        else
            if(poz>cont)
                cout<<"Optiune incorecta!Reincercati!"<<endl;
            else
                ok=1;
    }
    while(!ok);
    ok=0;
    mycar[3]=aux[poz-1];
    masina_mea.set_val(mycar[0],mycar[1],mycar[2],mycar[3]);
    masina_mea.print();
    cout<<"Doriti salvarea configuratiei? (da/nu)"<<endl;
    do
    {
        fflush(stdin);
        cin.getline(s,20);
        if(strcmp(s,"da")==0)
         ok=1;
        else
            if(strcmp(s,"nu")==0)

                {
                    ok=1;
                }
            else
            {
                cout<<"Optiune incorecta!Reincercati!"<<endl;
            }


    }
    while(!ok);
    if(strcmp(s,"da")==0)// daca utilizatorul a apasat 'da' (doreste sa salveze alegerea) este apelata functia de printare in fisier print a clasei my_car
        masina_mea.print_f();
}
