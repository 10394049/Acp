#include<iostream>

using namespace std;

class vettore{
    unsigned int n;
    float *p;
    public:
        // Constructor
        vettore(unsigned int n, float x=0): p(0), n(n) { //nullptr perché non funziona?
            p=new float[n]; //p è un puntatore a un vettore di n float
            for (int i=0; i<n; i++)
                p[i]=x;
        }
        // Copy Constructor
        vettore (const vettore &x): p(0), n(x.n) {
            p=new float[n];
            for (int i=0; i<n; i++)
            p[i]=x.p[i];
            }
        // Destructor
        ~vettore() {
                if (p != 0)
                delete []p;
                }

        float& operator[](const int i){return p[i];}; // e se voglio aggiungere valori al vettore???
        friend ostream& operator<<(ostream& o, vettore &v ); //const vettore?? const si riferisce a vettore o a &v?

        vettore& operator=(vettore &x){
            if (p!= 0)
                delete []p;
            n=x.n;
            p=new float[n];
            for (int i=0; i<n; i++)
            p[i]=x[i]; // potrei scrivere x[i] tanto ho fatto overload
            return *this;
         }

        friend vettore operator+ (vettore &v, vettore &w);
        friend vettore operator- (vettore &v, vettore &w);
        friend float operator* (vettore &v, vettore &w);
};

ostream& operator<< (ostream& o, vettore &v ){
    for (int i=0; i<v.n; i++)
        o << v.p[i] << " ";
        return o;
};

vettore operator+ (vettore &v, vettore &w){
        // dovrei controllare che i vettori abbiano stessa lunghezza
            vettore z=vettore(v.n);
            for (int i=0; i<z.n; i++)
            z[i]=v[i] + w[i];
            return z;
        }

vettore operator- (vettore &v, vettore &w){
        // dovrei controllare che i vettori abbiano stessa lunghezza
            vettore z=vettore(v.n);
            for (int i=0; i<z.n; i++)
            z[i]=v[i] - w[i];
            return z;
        }

float operator* (vettore &v, vettore &w){
        // dovrei controllare che i vettori abbiano stessa lunghezza
            float z=0;
            for (int i=0; i<v.n; i++)
            z=z+v[i] * w[i];
            return z;
        }


int main(){
    vettore v=vettore(3,2);
    vettore w=vettore(3,1);
    cout << "v" << v << endl;
    v[2]=4;
    cout << "v" << v << endl;
    cout << "w" << w << endl;
    vettore z=vettore(3);
    cout << "z" << z << endl;
    z=w;
    cout << "z" << z << endl;
//    z=v+w;
    cout << "z" << z << endl;
    float u=v*z;
    cout << "u" << u << endl;

return 0;
}
