//Mattia Secondin Parenti
#include <iostream>
#include <string>
using namespace std;
const int N = 100;
	struct treni{
		string codice;
		string destinazione;
		int partenza;
	};

void CARICA(treni a[N], int &c){
	string domanda="si";
	for(int i=0; i<N  && domanda=="si"; i++){
		cout << endl << "TRENO " << i+1 << endl;
		cout << "Codice: ";
		cin >> a[i].codice;
		cout << "Destinazione: ";
		cin >> a[i].destinazione;
		cout << "Ora di partenza: ";
		cin >> a[i].partenza;
		cout << endl;
		c++;
		cout << "Vuoi aggiungere un altro treno [si][no] \n";
		cin >> domanda;
	}
}

void VISUALIZZA(treni a[N], int c){
	for(int i=0; i<c; i++){
		cout << "TRENO " << i+1 << endl;
		cout << "Codice:" << a[i].codice << endl;
		cout << "Destinazione:" << a[i].destinazione << endl;
		cout << "Ora di partenza:" << a[i].partenza << endl << endl;
	}
}

void VISUALIZZA_10_12(treni a[N], int c){
	cout << endl << "I treni in partenza fra le 10 e le 12 sono:" << endl;
	for(int i=0; i<c; i++){
		if(a[i].partenza >= 10 && a[i].partenza <= 12){
			cout << "TRENO " << i+1 << endl;
			cout << "Codice:" << a[i].codice << endl;
			cout << "Destinazione:" << a[i].destinazione << endl;
			cout << "Ora di partenza:" << a[i].partenza << endl << endl;
		}
	}
}

int CONTA_TRENI(treni a[N], int c, string in){
	int cont=0;	
	for(int i=0; i<c; i++){
		if(a[i].destinazione == in){
			cont++;
		}
	}
	return cont;
}

bool ESISTE(treni a[N], int c, string in, int in2){
	bool var = false;
	for(int i=0; i<c && var==false; i++){
		if(a[i].destinazione == in && a[i].partenza == in2){
			var = true;
		}
	}
	return var;
}

int main(int argc, char** argv) {
	int cont=0;
	string input;
	int input2;
	treni arr[N];
	
	CARICA(arr, cont);
	VISUALIZZA(arr, cont);
	VISUALIZZA_10_12(arr, cont);
	
	cout << endl << "Scegli una stazione di destinazione: ";
	cin >> input;
	cout << "Da questa stazione partiranno " << CONTA_TRENI(arr, cont, input) << " treni";
	
	cout << endl << endl << "Scegli una stazione di destinazione: ";
	cin >> input;
	cout << "Scegli un orario di partenza: ";
	cin >> input2;
	if(ESISTE(arr, cont, input, input2)==true){
		cout << "Il treno con destinazione " << input << " all'ora " << input2 << " esiste";
	}
	else{
		cout << "Il treno con destinazione " << input << " all'ora " << input2 << " non esiste";
	}
	return 0;
}

