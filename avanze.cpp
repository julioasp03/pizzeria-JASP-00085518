#include <iostream>
#include <string>
using namespace std;

struct delivery{
    string name,adrees;
    int phone,check,pay,plate,entrance,drink;
};

struct restaurant{
    string name;
    int check,pay,plate,entrance,drink,people;
};

void menu(bool exit);
void deli(int num);

int main(void){

    string password;
    bool flag= false;

    while(flag==false){
        cout<<"digite la contrasenia: "; cin>>password;
        if(password=="union")
        {
            menu(flag);
        }
        else
        {
            cout<<"contrasenia incorrecta vuelva a intentarlo\n";
        }
    }    
    return 0;
}

void menu(bool exit){
    int num;
    cout<<"\tmenu principal:\n";
    cout<<"opcion 1: agregar un pedido a domicilio\n";
    cout<<"opcion 2: agregar un cargo a restaurante\n";
    cout<<"opcion 3: ver pedidos a domicilio\n";
    cout<<"opcion 4: ver encargos en el restaurante\n";
    cout<<"opcion 5: ver total de ventas\n\n";
    cout<<"digite el numero de la opcion a escoger: "; cin>>num; cin.ignore();
    cout<<endl; 
    switch (num)
    {
    case 1:

        deli(num,exit);
        
        break;
    
    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;
    }

}

void deli(int num, bool flag){
    struct delivery x;
    cout<<"digite su nombre completo: "; getline(cin,x.name);
    cout<<"digite su direccion: "; getline(cin,x.adrees);
    cout<<"digite su numero de telefono: "; cin>>x.phone; cin.ignore();
    cout<<"eliga un plato:\nopcion 1: pizza\nopcion 2: ensalada\nopcion 3: pasta\n"; cin>>x.plate;
    cout<<"eliga una entrada:\nopcion 1: pan con ajo\nopcion 2: dedos de queso\n"; cin>>x.entrance;
    cout<<"eliga una bebida:\nopcion 1: soda\nopcion 2: te\n"; cin>>x.drink;
    flag==true;
}