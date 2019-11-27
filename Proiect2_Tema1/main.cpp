#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
class Vector{

private:
    int dim;
    int *a;

public:
    Vector();
    Vector(int di, int v[]);
    Vector(const Vector& v);
    ~Vector();
    void afisare();
    Vector& operator=(const Vector& v){
        dim = v.dim;
        a = new int[dim];
        for(int i = 0; i < dim; i++)
            a[i] = v.a[i];
        return *this;
    }
    void setDim(int dim){
        a = new int[dim];
        this->dim = dim;
    }
    int getDim(){
        return dim;
    }
    void setA(int *a){
        this->a = new int[dim];
        for(int i = 0; i < dim; i++)
            this->a[i] = a[i];
    }
    int* getA(){
        return a;
    }
};

class Matrice{

protected:
    Vector* v;

public:
    Matrice();
    Matrice(const Vector& v);
    ~Matrice();
    virtual void afisare()=0;
};

class Matrice_oarecare:Matrice{

protected:
    int lin;

public:
    Matrice_oarecare();
    Matrice_oarecare(int lin, Vector *vec);
    Matrice_oarecare(const Matrice_oarecare& mo);
    ~Matrice_oarecare();
    Matrice_oarecare& operator=(const Matrice_oarecare& mo){
        lin = mo.lin;
        for(int i=0; i<lin; i++)
            v[i] = mo.v[i];
        return *this;
    }
    void setLin(int lin){
        this->lin = lin;
    }
    int getLin(){
        return lin;
    }
    void setLinieMo(int linie,Vector v1){
        v[linie]=v1;
    }
    void afisare();
};

class Matrice_patratica:Matrice{

private:
    int dim;

public:
    Matrice_patratica();
    Matrice_patratica(int dim, Vector *vec);
    Matrice_patratica(const Matrice_patratica& mp);
    ~Matrice_patratica();
    Matrice_patratica& operator=(const Matrice_patratica& mp){
        dim = mp.dim;
        for(int i=0; i<dim; i++)
            v[i] = mp.v[i];
        return *this;
    }
    void setDim(int dimm){
        this->dim = dimm;
    }
    int getDim(){
        return dim;
    }
    void setLinieMp(int linie,const Vector v1){
        v[linie] = v1;
    }
    bool diagonala();
    void afisare();
};

Vector::Vector(){
    dim = 1;
    a = new int[dim];
    a[0] = 0;
}

Vector::Vector(int di, int v[]){
    dim = di;
    a = new int[di];
    for(int i = 0; i< dim; i++)
        a[i] = v[i];
}

Vector::Vector(const Vector& v){
    dim = v.dim;
    a = new int[dim];
    for(int i = 0; i < dim; i++)
        a[i] = v.a[i];
}

Vector::~Vector(){
    delete a;
}

void Vector::afisare(){
    cout<<"Dimensiune vector: "<<dim<<endl;
    for(int i = 0; i < dim; i++)
        cout<<a[i]<<' ';
    cout<<endl;
}

istream& operator>>(istream& in, Vector& v){
    int dimm;
   // cout<<"Nr elemente: ";
    in>>dimm;
    int v1[dimm];
    for(int i=0; i<dimm; i++)
        in>>v1[i];
    v.setDim(dimm);
    v.setA(v1);
    return in;
}

ostream& operator<<(ostream& out, Vector& v){
    v.afisare();
    return out;
}


Matrice::Matrice(){
    v = new Vector();
}

Matrice::Matrice(const Vector& v1){
    v = new Vector(v1);
}

Matrice::~Matrice(){
    delete v;
}

void Matrice::afisare(){
    v->afisare();
}


Matrice_oarecare::Matrice_oarecare():Matrice(){
    lin = 1;
}

Matrice_oarecare::Matrice_oarecare(int lin, Vector *vec){
    this->lin = lin;
    v = new Vector[lin];
    for(int i = 0; i < lin; i++){
        v[i].setDim(vec[i].getDim());
        v[i].setA(vec[i].getA());
    }
}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare& mo){
    this->lin = mo.lin;
    v = new Vector[this->lin];
    for(int i=0; i<this->lin; i++){
        v[i].setDim(mo.v[i].getDim());
        v[i].setA(mo.v[i].getA());
    }
}

Matrice_oarecare::~Matrice_oarecare(){
    delete v;
}

void Matrice_oarecare::afisare(){
    for(int i=0; i<lin; i++){
        v[i].afisare();
    }
}

istream& operator>>(istream& in, Matrice_oarecare& mo){
    int linn;
    Vector v;
    cout<<"Nr linii: ";
    in>>linn;
    mo.setLin(linn);
    for(int i=0; i<linn; i++){
        in>>v;
        mo.setLinieMo(i,v);
    }
    return in;
}

ostream& operator<<(ostream& out, Matrice_oarecare& mo){
    mo.afisare();
    return out;
}


Matrice_patratica::Matrice_patratica():Matrice(){
    dim = 1;
}

Matrice_patratica::Matrice_patratica(int dim, Vector *vec){
    this->dim = dim;
    v = new Vector[dim];
    for(int i = 0; i < dim; i++){
        v[i].setDim(vec[i].getDim());
        v[i].setA(vec[i].getA());
    }
}

Matrice_patratica::Matrice_patratica(const Matrice_patratica& mp){
    this->dim = mp.dim;
    v = new Vector[this->dim];
    for(int i=0; i<this->dim; i++){
        v[i].setDim(mp.v[i].getDim());
        v[i].setA(mp.v[i].getA());
    }
}

Matrice_patratica::~Matrice_patratica(){
    delete v;
}

istream& operator>>(istream& in, Matrice_patratica& mp){
    int dimm;
    Vector v;
    //cout<<"Dimensiune: ";
    in>>dimm;
    mp.setDim(dimm);
    for(int i=0; i<dimm; i++){
        in>>v;
        mp.setLinieMp(i,v);
    }
    return in;
}

ostream& operator<<(ostream& out, Matrice_patratica& mp){
    mp.afisare();
    return out;
}

bool Matrice_patratica::diagonala(){
    for(int i=0; i<dim; i++)
        for(int j=0; j<dim && j!=i; j++)
            if(*(v[i].getA()+j)!=0)
                return 0;
    return 1;
}

void Matrice_patratica::afisare(){
    for(int i = 0; i < dim; i++)
        v[i].afisare();
}


int main(){
    int n;
    f>>n;
    Matrice_patratica *m1;
    m1 = new Matrice_patratica[n];
    for(int i=0; i<n; i++)
        f>>m1[i];
    for(int i=0; i<n; i++)
        cout<<"======================="<<endl<<m1[i];
    for(int i=0; i<n; i++)
        cout<<m1[i].diagonala()<<" ";
    f.close();
    return 0;
}
