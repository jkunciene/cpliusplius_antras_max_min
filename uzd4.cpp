#include <fstream>
#include <iostream>

using namespace std;

ifstream in("duom.txt");
ofstream out("rez.txt");

int kiekis();
void skaitymas(int Masyvas[], int kiek);
void rasom(int Masyvas[], int kiek, string tekstas);
void rasomVienaReiksme(int sk, string koks);
void rikiavimas(int Masyvas[], int kiek);
void radimas(int Masyvas[], int kiek, int &antrasMax, int kelintasPglDydi);
void rikiavimasMin(int Masyvas[], int kiek);
void radimas(int Masyvas[], int kiek, int &antrasMin, int kelintasPglDydi);


int main(){
    int n;
    n=kiekis();
    cout<<n<<endl;
    int A[n];
    skaitymas(A, n);
    rasom(A, n, "A");
    rikiavimas(A, n);
    rasom(A, n, "Surikiuotas mazejancia masyvas");
    int antras, suma;
    radimas(A, n, antras, 2);
    suma=antras;
    cout<<antras<<endl;
    rasomVienaReiksme(antras, " yra Antras didziausias");
    rikiavimasMin(A, n);
    rasom(A, n, "Surikiuotas didejancia tvarka masyvas");
    int antrasMin;
    radimas(A, n, antrasMin, 2);
    cout<<antrasMin<<endl;
    rasomVienaReiksme(antrasMin, " yra Antras maziausias");
    suma+=antrasMin;
    cout<<suma;
    rasomVienaReiksme(suma, " yra didziausio ir maziausio suma");

    in.close();
    out.close();
    return 0;
}

int kiekis(){
    int kiek;
    in>>kiek;
    return kiek;}
void skaitymas(int Masyvas[], int kiek){
    for(int i=0; i<kiek; i++){in>>Masyvas[i];}
}
void rasom(int Masyvas[], int kiek, string tekstas){
    out<<"Masyvas  "<<tekstas<<endl;
    for(int i=0; i<kiek; i++){out<<Masyvas[i]<<"  ";}out<<endl;}
void rasomVienaReiksme(int sk, string koks){
    out<<sk<<koks<<endl;}
void rikiavimas(int Masyvas[], int kiek){
    int laikinas;
    for(int i=0; i<kiek; i++){
        for(int j=1; j<kiek-1; j++){
            if (Masyvas[j-1]<=Masyvas[j]){
                laikinas=Masyvas[j];
                Masyvas[j]=Masyvas[j-1];
                Masyvas[j-1]=laikinas;
            }
        }
    }
}
void radimas(int Masyvas[], int kiek, int &antrasMax, int kelintasPglDydi){
    int k=1;
    for(int i=1; i<kiek; i++){
        if(Masyvas[i]!=Masyvas[i-1]){
            k++;
            if(k==kelintasPglDydi){antrasMax=Masyvas[i];break;}
        }
    }
}

void rikiavimasMin(int Masyvas[], int kiek){
    int laikinas;
    for(int i=0; i<kiek; i++){
        for(int j=1; j<kiek-1; j++){
            if (Masyvas[j-1]>=Masyvas[j]){
                laikinas=Masyvas[j];
                Masyvas[j]=Masyvas[j-1];
                Masyvas[j-1]=laikinas;
            }
        }
    }
}
void radimasMin(int Masyvas[], int kiek, int &antrasMin, int kelintasPglDydi){
    int k=1;
    for(int i=1; i<kiek; i++){
        if(Masyvas[i]!=Masyvas[i-1]){
            k++;
            if(k==kelintasPglDydi){antrasMin=Masyvas[i];break;}
        }
    }
}

