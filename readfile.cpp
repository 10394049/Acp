// Funzione di lettura da file
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

void dim (ifstream &file,int &m, int&n){
    char car=0;
    char virgola=0;
    int i=0;
    while(file){
        string str;
            if (!getline(file,str)) break;//va bene come controllo??
        istringstream sstr(str);
        while(sstr) {
            sstr >> car >> virgola ;
            i++;
        };
        if(m==0)n=i;
        if(i!=n){
            cout<<"le righe non sono della stessa lunghezza"<<endl;
            break;
        }
        i=0;
        m++;
    }
}

void readfile(vector < vector < int > > &bvet, vector < vector < int > > &rvet, ifstream &file ){

    int row=0;
    int col=0;
    char virgola;
    while(file){
        string str;
        if (!getline(file,str)) break;//va bene come controllo??
        istringstream sstr(str);
        int num;
        col=0;
        while (sstr){
            sstr >> num >> virgola; //così però prende anche le virgole come elementi
            if (num==1) //meglio differenziare il numero che indica la macchina?
                bvet[col].push_back(row);
            if (num==2) //meglio differenziare il numero che indica la macchina?
                rvet[row].push_back(col);
            col++;
            // controlli nel caso i caratteri non siano quelli aspettati
        }//devo fare anche controlli che le righe acquisite siano lunghe uguali
        row++; //posso cercare il modo di memorizzare le dimensioni della matrice
    }
    if ( !file.eof()){
        cerr << "Fooey!" <<endl;
    }
}



int main(){
    int m=0;
    int n=0;

    ifstream filedim("problem.csv");// se non dovessimo leggere due volte il file sarebbe meglio
    dim (filedim,m,n);// se non dovessimo leggere due volte il file sarebbe meglio
    cout<<"colonne: "<< n << endl;
    cout<<"righe:   "<< m << endl;
    vector < vector < int > > bvet(n);
    vector < vector < int > > rvet(m);
    ifstream file("problem.csv");// se non dovessimo leggere due volte il file sarebbe meglio
    readfile(bvet, rvet, file );// se non dovessimo leggere due volte il file sarebbe meglio

    //for (vector < vector < int > >::iterator i=bvet.begin(); i!=bvet.end(); i++){
    cout << "Struttura blu" <<endl;
    for (int i=0; i<n; i++){
        for (vector<int>::iterator j=bvet[i].begin(); j!=bvet[i].end(); j++){
            cout << *j;
        }
        cout << endl;
    }

    cout << "Struttura rossi" <<endl;
    for (int i=0; i<n; i++){
        for (vector<int>::iterator j=rvet[i].begin(); j!=rvet[i].end(); j++){
            cout << *j;
        }
        cout << endl;
    }
}
