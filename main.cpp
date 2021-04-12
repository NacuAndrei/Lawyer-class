#include <iostream>
#include <string.h>

using namespace std;

int n;

class Avocat {

    //static int n;
    int cod;
    string nume;
    int nr_procese;
    int *vector_procese;

public:
    Avocat();
    ///Avocat(const Avocat&);
    Avocat(int, string, int, int*);
    ~Avocat();

    virtual void denumire() { cout << "Eu sunt un avocat.\n";}
    friend istream& operator>>(istream&, Avocat &);
    friend ostream& operator<<(ostream&, Avocat &);

    Avocat operator=(Avocat A);
    friend bool operator> (const Avocat &A, const Avocat &B);
};

Avocat::Avocat(){
    cod = 0;
    nume = "Nume initial";
    nr_procese = 0;
    vector_procese = new int[nr_procese];
}

/*
Avocat::Avocat(const Avocat &avocat)
{
    this->cod = avocat.cod;
    this->nume = avocat.nume;
    this->nr_procese = avocat.nr_procese;
    for(int i = 0; i < avocat.nr_procese; i++)
        this->vector_procese[i] = avocat.vector_procese[i];
}
*/
Avocat::Avocat(int cod, string nume, int nr_procese, int *vector_procese)
{
    this->cod = cod;
    this->nume = nume;
    this->nr_procese = nr_procese;
    for(int i = 0; i < nr_procese; i++)
        this->vector_procese[i] = vector_procese[i];
}

Avocat::~Avocat() {
    delete []vector_procese;
}

Avocat Avocat::operator=( Avocat A)
{
    cod = A.cod;
    nume = A.nume;
    nr_procese = A.nr_procese;
    for(int i = 0; i < A.nr_procese; i++)
        vector_procese[i] = A.vector_procese[i];

    return *this;
}

istream& operator>>(istream& in, Avocat & A)
{
    cout<<endl<<"Introduceti codul avocatului curent:"<<endl;
    in>>A.cod;

    cout<<"Introduceti numele avocatului:"<<endl;
    in>>A.nume;

    try
    {
        for(int i = 0; i < A.nume.length(); i++)
            if(isdigit(A.nume[i]))
                throw 0;
    }
    catch (...)
    {
        cout<<"Numele nu poate contine cifre. Incercati din nou!"<<endl;
        cin>>A.nume;
        cout<<endl;
    }


    cout<<"Introduceti numarul de procese al avocatului:"<<endl;
    in>>A.nr_procese;

    cout<<"Introduceti suma primita pentru fiecare proces:"<<endl;

    for(int i = 0 ; i < A.nr_procese; i++)
        in>>A.vector_procese[i];

    return in;
}

ostream& operator<<(ostream& out, Avocat & A)
{
    out<<"Informatiile avocatului curent sunt:"<<endl;

    out<<"Cod: "<<A.cod<<endl;
    out<<"Nume: "<<A.nume<<endl;
    out<<"Numar procese: "<<A.nr_procese<<endl;
    out<<"Suma primita pentru fiecare proces: "<<endl;
    for(int i = 0; i < A.nr_procese; i++)
        out<<A.vector_procese[i]<<" ";
    out<<endl<<endl;
    return out;
}

bool operator> (const Avocat &A, const Avocat &B)
{
    return A.nr_procese > B.nr_procese;
}

class Avocat_oficiu : public Avocat {

    string nume_client;
    int durata;

public:
    void denumire() { cout << "Eu sunt oficiul avocatului.\n";}
    Avocat_oficiu();
    Avocat_oficiu(const Avocat_oficiu&);
    ~Avocat_oficiu();

    int get_durata();

    Avocat_oficiu operator=(Avocat_oficiu A);

    ///Avocat_oficiu(int, string, int, int*, string, int);
    friend istream& operator>>(istream&, Avocat_oficiu &);
    friend ostream& operator<<(ostream&, Avocat_oficiu &);
};

/*
Avocat_oficiu::Avocat_oficiu(int cod, string nume, int nr_procese, int *vector_procese, string nume_client, int durata):Avocat(cod, nume, nr_procese, *vector_procese)
{
    this->durata = durata;
    this->nume_client = nume_client;
}
*/

int Avocat_oficiu::get_durata()
{
    return durata;
}

Avocat_oficiu::Avocat_oficiu()
{
    nume_client = "Neinitializat";
    durata = 0;
}

Avocat_oficiu::Avocat_oficiu(const Avocat_oficiu &avocat_oficiu)
{
    this->nume_client = avocat_oficiu.nume_client;
    this->durata = avocat_oficiu.durata;
}

Avocat_oficiu::~Avocat_oficiu()
{

}

Avocat_oficiu Avocat_oficiu::operator=( Avocat_oficiu A)
{
    nume_client = A.nume_client;
    durata = A.durata;

    return *this;
}

istream& operator>>(istream& in, Avocat_oficiu & A)
{
    cout<<"Numele clientului: ";
    cin>>A.nume_client;
    try
    {
        for(int i = 0; i < A.nume_client.length(); i++)
            if(isdigit(A.nume_client[i]))
                throw 0;
    }
    catch (...)
    {
        cout<<"Numele clientului nu poate contine cifre. Incercati din nou!"<<endl;
        cin>>A.nume_client;
        cout<<endl;
    }

    cout<<"Timpul total petrecut cu clientul curent: ";
    cin>>A.durata;

    return in;
}

ostream& operator<<(ostream& out, Avocat_oficiu & A)
{
    cout<<"Numele clientului: "<<A.nume_client<<endl;
    cout<<"Timpul total petrecut cu clientul curent: "<<A.durata<<endl;

    return out;
}

int maximTimp(Avocat_oficiu q[])
{
    int m = 0, poz = 0;

    for(int i = 0; i < n; i++)
        if(q[i].get_durata() > m)
            {
                m = q[i].get_durata();
                poz = i;
            }
    return poz+1;
}

VerifRaspuns(int raspuns)
{
    cout<<endl;
    try
    {
        if(raspuns > 1)
            throw 0;
    }
    catch (...)
    {
        cout<<"Puteti introduce doar 0 sau 1! Vom presupune ca ati introdus 1."<<endl;
        cout<<endl;
    }

    return 1;
}

int main()
{
    cout<<"Introduceti numarul de avocati n :"<<endl;
    cin>>n;

    Avocat v[n];

    for(int i = 0; i < n; i++)
    {
            cin>>v[i];
            v[i].denumire();
    }

    int raspuns;
    cout<<"-----------------------------------------------------------------------"<<endl<<endl;
    cout<<"Doriti afisarea informatiilor despre avocati? (0.Nu ; 1.Da)"<<endl;
    cin>>raspuns;
    VerifRaspuns(raspuns);
    if(raspuns)
        {
            for(int i = 0; i < n; i++)
                cout<<v[i];
        }

    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<endl<<"Doriti sortarea listei avocatilor dupa numarul de procese? (0.Nu ; 1.Da)"<<endl;
    cin>>raspuns;
    VerifRaspuns(raspuns);
    if(raspuns)
    {

        for(int i = 0; i < n-1; i++)
            for(int j = i+1; j < n; j++)
                if(v[i]>v[j])
                    {
                        swap(v[i], v[j]);
                    }

        cout<<"Doriti afisarea listei avocatilor sortata dupa numarul de procese? (0.Nu ; 1.Da)"<<endl;
        cin>>raspuns;
        VerifRaspuns(raspuns);
        if(raspuns)
        {
            cout<<endl<<"Lista avocatilor sortata crescator dupa numarul de procese este: "<<endl<<endl;
            for(int i = 0; i < n; i++)
                cout<<v[i];
        }
    }

    cout<<"-----------------------------------------------------------------------"<<endl;

    Avocat_oficiu q[n];

    cout<<endl<<"Doriti introducerea informatiilor legate de oficiul fiecarui avocat? (0.Nu ; 1.Da)"<<endl;
    cin>>raspuns;
    VerifRaspuns(raspuns);
    if(raspuns)
    {
        cout<<endl<<"Vom citi numele clientului si durata petrecuta cu acesta pentru fiecare avocat:"<<endl<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<"Pentru avocatul "<<i<<":"<<endl;
            cin>>q[i];
            q[i].denumire();
            cout<<endl;
        }

        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<endl<<"Doriti afisarea informatiilor legate de oficiul fiecarui avocat? (0.Nu ; 1.Da)"<<endl;
        cin>>raspuns;
        VerifRaspuns(raspuns);
        if(raspuns)
        {
            cout<<endl<<"Informatiile legate de clienti sunt: "<<endl<<endl;
            for(int i = 0; i < n; i++)
            {
                cout<<"Pentru avocatul "<<i<<":"<<endl;
                cout<<q[i];
                cout<<endl;
            }
        }
    }

    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<endl<<"Doriti afisarea avocatului care a petrecut timpul maxim cu un client? (0.Nu ; 1.Da)"<<endl;
    cin>>raspuns;
    VerifRaspuns(raspuns);
    if(raspuns)
    {
        cout<<"Avocatul "<<maximTimp(q)<<" a petrecut timpul maxim cu un client"<<endl;
    }

    cout<<endl<<"-----------------------------------------------------------------------"<<endl;
    cout<<endl<<"Ati ajuns la finalul programului!"<<endl;
    cout<<endl<<"-----------------------------------------------------------------------"<<endl;

    return 0;
}
