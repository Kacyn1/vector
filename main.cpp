#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

using namespace std;

struct uczen
{
        string imie, nazwisko, status;
        int numer;
};

class wektory
{
                vector <uczen> spis;
       
        public:
                void zapisz_do_pliku(const char *);
                void wczytaj_z_pliku(const char *);                
};

void wektory::wczytaj_z_pliku(const char *nazwa){
		ifstream plik1;
		struct uczen wprowadzany;
		regex imie("[A-Z]{1}[a-z]+");
		regex nazwisko("[A-Z]{1}[a-z]+");
		plik1.open(nazwa);
			while(!plik1.eof()){
					plik1>>wprowadzany.numer>>wprowadzany.imie>>wprowadzany.nazwisko;
				if(regex_match(wprowadzany.imie, imie) && regex_match(wprowadzany.nazwisko, nazwisko)){
					wprowadzany.status = "POPRAWNIE";
				} else {
					wprowadzany.status = "BLAD";
					}	
					spis.push_back(wprowadzany);
	}		
	
	
}

void wektory::zapisz_do_pliku(const char *nazwa)
{
        	ofstream plik2;
       		plik2.open(nazwa);
        	plik2<<"["<<endl;
        for (vector<uczen>::iterator it = spis.begin(); it != spis.end(); ++it){
		
        	
                plik2<<"{\"nr\":\""<<it->numer<<"\", \"imie\":\""<<it->imie<<"\", \"nazwisko\":\""<<it->nazwisko<<"\", \"status\":\""<<it->status<<"\"}\n";
        }
        		plik2<<"]";
         
}



int main(int argc, char** argv) {
        		
wektory s1;
s1.wczytaj_z_pliku("plik1.txt");	
s1.zapisz_do_pliku("plik2.txt");
        
        return 0;
}
