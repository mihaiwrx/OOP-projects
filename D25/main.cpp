#include <iostream>

using namespace std;

class Vector{

private:
    double v[20];
    int nr_el;

public:
    Vector(double,int);     ///initializarea cu un nr pe toate componentele
    Vector();               ///constructor initializare fara parametri
    Vector(const Vector&);  ///copiere vector

    double& operator[](int index){
        if (0 > index)
            index = 0;
        if (nr_el <= index)
            index = nr_el-1;
        return v[index];
    }

    friend Vector operator+(Vector& vect1, Vector& vect2){
        int i;
        Vector rez;
        if(vect1.nr_el!=vect2.nr_el){
            cout<<"Eroare!"<<endl;
        }
        else{
            rez.nr_el=vect1.nr_el;
            for(i=0;i<rez.nr_el;i++)
                rez.v[i]=vect1.v[i]+vect2.v[i];
        }
        return rez;
    }
    friend Vector& operator+(Vector& vect){
        for(int i=0; i<vect.nr_el; i++)
            if(vect.v[i]<0)
                vect.v[i]=vect.v[i]-2*vect.v[i];
        return vect;
    }

    friend Vector operator-(Vector& vect1, Vector& vect2){
        int i;
        Vector rez;
        if(vect1.nr_el!=vect2.nr_el)
            cout<<"Eroare!"<<endl;
        else{
            rez.nr_el=vect1.nr_el;
            for(i=0;i<rez.nr_el;i++)
                rez.v[i]=vect1.v[i]-vect2.v[i];
        }
        return rez;
    }
    friend Vector& operator-(Vector& vect){
        for(int i=0; i<vect.nr_el; i++)
            vect.v[i]=-vect.v[i];
        return vect;
    }

    friend Vector operator*(Vector& vect1, Vector& vect2){
        Vector rez;
        int i;
        if(vect1.nr_el!=vect2.nr_el)
            cout<<"Eroare!"<<endl;
        else{
            rez.nr_el=vect1.nr_el;
            for(i=0;i<rez.nr_el;i++)
                rez.v[i]=vect1.v[i]*vect2.v[i];
        }
        return rez;
        }
    friend Vector operator*(Vector& vect, double nr){
        Vector rez;
        rez.nr_el=vect.nr_el;
        for(int i=0; i<rez.nr_el; i++)
            rez.v[i]=nr*vect.v[i];
        return rez;
    }

    const Vector& operator=(const Vector& vect){
        nr_el=vect.nr_el;
        for(int i=0; i<nr_el; i++)
            v[i]=vect.v[i];
        return *this;
    }
    friend Vector& operator+=(Vector& vect1, Vector& vect2){
        int i, aux;
        if(vect1.nr_el<vect2.nr_el){
            aux=vect1.nr_el;
            vect1.nr_el=vect2.nr_el;
            for(i=aux;i<vect2.nr_el;i++)
                vect1.v[i]=0;
        }
        for(i=0;i<vect2.nr_el;i++)
            vect1.v[i]+=vect2.v[i];
        return vect1;
    }
    friend Vector& operator-=(Vector& vect1, Vector& vect2){
        int i, aux;
        if(vect1.nr_el<vect2.nr_el){
            aux=vect1.nr_el;
            vect1.nr_el=vect2.nr_el;
            for(i=aux;i<vect2.nr_el;i++)
                vect1.v[i]=0;
        }
        for(i=0;i<vect2.nr_el;i++)
            vect1.v[i]-=vect2.v[i];
        return vect1;
    }

    friend bool operator==(const Vector& vect1, const Vector& vect2){
        int ok=1;
        if(vect1.nr_el!=vect2.nr_el)
            ok=0;
        if(ok)
            for(int i=0; i<vect1.nr_el; i++)
                if(vect1.v[i]!=vect2.v[i])
                    ok=0;
        return ok;
    }
    friend bool operator==(double nr, Vector& vect){
        int ok=1;
        for(int i=0;i<vect.nr_el;i++)
            if(nr!=vect.v[i])
                ok=0;
        return ok;
    }
    bool operator==(double nr){
        int ok=1;
        for(int i=0;i<nr_el;i++)
            if(nr!=v[i])
                ok=0;
        return ok;
    }

    friend bool operator!=(const Vector& vect1, const Vector& vect2){
        if(vect1.nr_el!=vect2.nr_el)
            return true;
        else{
            int ok=0;
            for(int i=0;i<vect1.nr_el;i++)
                if(vect1.v[i]!=vect2.v[i])
                    ok=1;
        return ok;
        }
    }
    friend bool operator!=(double nr, Vector& vect){
        int ok=0;
        for(int i=0;i<vect.nr_el;i++)
            if(nr!=vect.v[i])
                ok=1;
        return ok;
    }
    bool operator!=(double nr){
        int ok=0;
        for(int i=0;i<nr_el;i++)
            if(nr!=v[i])
                ok=1;
        return ok;
    }

    friend bool operator<(const Vector& vect1, const Vector& vect2){
        int ok=1;
        if(vect1.nr_el<vect2.nr_el)
            return true;
        else if(vect1.nr_el>vect2.nr_el)
            return false;
        else{
            for(int i=0; i<vect2.nr_el; i++)
                if(vect1.v[i]>=vect2.v[i])
                    ok=0;
        return ok;
        }
    }
    friend bool operator<(double nr, Vector& vect){
        int ok=1;
        for(int i=0;i<vect.nr_el;i++)
            if(nr>=vect.v[i])
                ok=0;
        return ok;
    }
    bool operator<(double nr){
        int ok=1;
        for(int i=0;i<nr_el;i++)
            if(v[i]>=nr)
                ok=0;
        return ok;
    }

    friend bool operator>(const Vector& vect1, const Vector& vect2){
        int ok=1;
        if(vect1.nr_el>vect2.nr_el)
            return true;
        else if(vect1.nr_el<vect2.nr_el)
            return false;
        else{
            for(int i=0; i<vect1.nr_el; i++)
                if(vect1.v[i]<=vect2.v[i])
                    ok=0;
        return ok;
        }
    }
    friend bool operator>(double nr, Vector& vect){
        int ok=1;
        for(int i=0;i<vect.nr_el;i++)
            if(nr<=vect.v[i])
                ok=0;
        return ok;
    }
    bool operator>(double nr){
        int ok=1;
        for(int i=0;i<nr_el;i++)
            if(v[i]<=nr)
                ok=0;
        return ok;
    }

    friend bool operator>=(const Vector& vect1, const Vector& vect2){
        int ok=1;
        if(vect1.nr_el>vect2.nr_el)
            return true;
        else if(vect1.nr_el<vect2.nr_el)
            return false;
        else{
            for(int i=0; i<vect1.nr_el; i++)
                if(vect1.v[i]<vect2.v[i])
                    ok=0;
        return ok;
        }
    }
    friend bool operator>=(double nr, Vector& vect){
        int ok=1;
        for(int i=0;i<vect.nr_el;i++)
            if(nr<vect.v[i])
                ok=0;
        return ok;
    }
    bool operator>=(double nr){
        int ok=1;
        for(int i=0;i<nr_el;i++)
            if(v[i]<nr)
                ok=0;
        return ok;
    }

    friend bool operator<=(const Vector& vect1, const Vector& vect2){
        int ok=1;
        if(vect1.nr_el<vect2.nr_el)
            return true;
        else if(vect1.nr_el>vect2.nr_el)
            return false;
        else{
            for(int i=0; i<vect2.nr_el; i++)
                if(vect1.v[i]>vect2.v[i])
                    ok=0;
        return ok;
        }
    }
    friend bool operator<=(double nr, Vector& vect){
        int ok=1;
        for(int i=0;i<vect.nr_el;i++)
            if(nr>vect.v[i])
                ok=0;
        return ok;
    }
    bool operator<=(double nr){
        int ok=1;
        for(int i=0;i<nr_el;i++)
            if(v[i]>nr)
                ok=0;
        return ok;
    }

    friend bool operator!(Vector& vect){
        for(int i=0;i<vect.nr_el;i++)
            if(vect.v[i]!=0)
                return 1;
        return 0;
    }

    void citire(){
        cout<<"Numar elemente= ";
        cin>>nr_el;
        int i;
        for(i=0; i<nr_el; i++)
        {
            cout<<"v["<<i<<"]= ";
            cin>>v[i];
        }
    }
    void afisare(){
        cout<<"Numar elemente: "<<nr_el<<endl;
        for(int i=0; i<nr_el; i++)
            cout<<v[i]<<' ';
        cout<<endl;
    }
    void reactualizare(double numar_nou, int nr_comp){
        nr_el=nr_comp;
        for(int i=0; i<nr_el; i++)
            v[i]=numar_nou;
    }

    friend void length(Vector& vect, int nr_nou);
};


Vector::Vector(double nr, int nre){
    nr_el=nre;
    for(int i=0; i<nre; i++)
        v[i]=nr;
}
Vector::Vector(){
    nr_el=1;
    v[0]=0;
}
Vector::Vector(const Vector& vect){
    nr_el=vect.nr_el;
    for(int i=0; i<nr_el; i++)
        v[i]=vect.v[i];
}

void length(Vector& vect, int nr_nou){
    int aux=vect.nr_el;
    vect.nr_el=nr_nou;
    for(int i=aux; i<nr_nou; i++)
        vect.v[i]=0;
}

int main(){
    Vector v1(1.54,3);
    Vector v2(2,3);
    Vector v3=v1+v2;
    length(v3,6);
    v3.afisare();
    return 0;
}
