#include <iostream>
#include <string>

#define PASSWORD "union"
using namespace std;

enum maindish{pizza,pasta,ensalada};
enum drink{Water,soda,tea};
enum entrance{garlicbread,pizzarolls,cheesesticks};
enum payment{cash,card};

struct address{
    string settlement,municipality, department;
    int housnumber;
};

struct maininfo{
    string name;
    maindish pdish;
    drink pdrink;
    entrance pdentrance;
    payment pay;
    int iDorder;
    float total;
    
};

struct delivery{
    address deliveryaddress;
    maininfo deliveryinfo;
};

struct houseorder{
    int ptable,cellphone;
    maininfo houseinfo;
};
//variables globales//
bool isadmin= false;
int idorder=1;
//prototipos//
bool login();
void printmenu();
void addorderdely(delivery *darray,int *size);
void addorderhouse(houseorder *Harray,int *size);
void searchnamedely(delivery *array,int *size);
void searchnamehouse(houseorder *array,int *size);

int main(void){
    delivery *darray=NULL;
    houseorder *Harray=NULL;
    int size=0;
    int* p=&size;
    int option=0;
    if (login()==false)
    {
        return 0;
    }
    do
    {
        cout<<endl;
        printmenu(); cin>> option;
        cin.ignore();
        cout<<endl;
        switch (option)
        {
        case 1://ordenes a domicilio//
            addorderdely(darray,p);
            break;
        
        case 2://ordenes a restaurante//
            addorderhouse(Harray,p);
            break;
        
        case 3:
            searchnamedely(darray,p);
            break;
        
        case 4:
            searchnamehouse(Harray,p);
            break;
        }
    } while (option!=0);
    


    return 0;
}

bool login(){
    string password;
    char option;
    cout<<"INICIO DE SESION"<< endl;
    cout<<"A - Administrador"<<endl;
    cout<<"E - Empleado"<<endl;
    cout<<"su opcion: "; cin>>option;
    switch (option)
    {
        case 'A':
        case 'a':
            cout<<"digite contrasenia: "; cin>> password; cin.ignore();
            if (password.compare(PASSWORD)==0)
            {
                isadmin= true;
                return true;
            }
            else
            {
                cout<<"contrasenia incorrecta"<<endl;
            }
            
            
        break;
        
        case 'E':
        case 'e':
            isadmin =false;
            return true;
        break;
    }
    return false;
}

void printmenu(){
    cout<<"---------------------------------------\n";
    cout<<"Sistema de despacho pizzeria santillana"<<endl;
    cout<<"---------------------------------------\n";
    cout<<"1. Agregar ordenes a domicilio"<<endl;
    cout<<"2. Agregar ordenes a restaurante"<<endl;
    cout<<"3. Ver ordenes a domicilio"<<endl;
    cout<<"4. Ver ordenes a restaurante"<<endl;
    cout<<"Su opcion: "; 
}

void addorderdely(delivery *darray,int *size){
    int aux=0;
    cout<<"Cantidad de pedidos a ingresar: "; cin>>*size;
    cin.ignore();
    darray= new delivery[*size];
    for (int i = 0; i < *size; i++)
    {
        cout<<"Nombre:\t"; getline(cin, darray[i].deliveryinfo.name);
        cout<<"****************************\n";
        cout<<"Direccion"<<endl;
        cout<<"Colonia: "; getline(cin,darray[i].deliveryaddress.settlement);
        cout<<"Municipio: "; getline(cin,darray[i].deliveryaddress.municipality);
        cout<<"Departamento: "; getline(cin,darray[i].deliveryaddress.department);
        cout<<"No. de casa: "; cin>>darray[i].deliveryaddress.housnumber; cin.ignore();
        cout<<"****************************\n";
        cout<<"Plato principal\n";
        cout<<"1. Pizza\n";
        cout<<"2. Pasta\n";
        cout<<"3. Ensalada\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();

        if (aux==1)
        {
            darray[i].deliveryinfo.pdish=pizza; 
        }
        else if(aux==2){
            darray[i].deliveryinfo.pdish= pasta;
        }
        else
        {
            darray[i].deliveryinfo.pdish=ensalada;
        }
        
        cout<<"Entrada principal\n";
        cout<<"1. Pan con ajo\n";
        cout<<"2. Pizza roll\n";
        cout<<"3. Cheese sticks\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();

        if (aux==1)
        {
            darray[i].deliveryinfo.pdentrance=garlicbread; 
        }
        else if(aux==2){
            darray[i].deliveryinfo.pdentrance= pizzarolls;
        }
        else
        {
            darray[i].deliveryinfo.pdentrance=cheesesticks;
        }
        
        cout<<"Bebida principal\n";
        cout<<"1. Agua\n";
        cout<<"2. Soda\n";
        cout<<"3. Te\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();
        cout<<endl;

        if (aux==1)
        {
            darray[i].deliveryinfo.pdrink=Water; 
        }
        else if(aux==2){
            darray[i].deliveryinfo.pdrink= soda;
        }
        else
        {
            darray[i].deliveryinfo.pdrink=tea;
        }
        darray[i].deliveryinfo.iDorder=idorder++;

        cout<<"Tipo de pago\n";
        cout<<"1. Efectivo\n";
        cout<<"2. Tarjeta\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();
        cout<<endl;
        if (aux==1)
        {
            darray[i].deliveryinfo.pay=cash; 
        }
        else
        {
            darray[i].deliveryinfo.pay=card;
        }
        
        cout<<"Monto: "; cin>>darray[i].deliveryinfo.total; cin.ignore();
        cout<<"Telefono: "; cin>>darray[i].deliveryaddress.housnumber; cin.ignore();
        
        
    }
    
}

void addorderhouse(houseorder *Harray,int *size){
    int aux=0;
    cout<<"Cantidad de pedidos a ingresar: "; cin>>*size;
    cin.ignore();
    Harray= new houseorder[*size];
    for (int i = 0; i < *size; i++)
    {
        cout<<"Nombre:\t"; getline(cin, Harray[i].houseinfo.name);

        cout<<"Plato principal\n";
        cout<<"1. Pizza\n";
        cout<<"2. Pasta\n";
        cout<<"3. Ensalada\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();
        cout<<endl;
        if (aux==1)
        {
            Harray[i].houseinfo.pdish=pizza; 
        }
        else if(aux==2){
            Harray[i].houseinfo.pdish= pasta;
        }
        else
        {
            Harray[i].houseinfo.pdish=ensalada;
        }
        
        cout<<"Entrada principal\n";
        cout<<"1. Pan con ajo\n";
        cout<<"2. Pizza roll\n";
        cout<<"3. Cheese sticks\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();
        cout<<endl;
        if (aux==1)
        {
            Harray[i].houseinfo.pdentrance=garlicbread; 
        }
        else if(aux==2){
            Harray[i].houseinfo.pdentrance= pizzarolls;
        }
        else
        {
            Harray[i].houseinfo.pdentrance=cheesesticks;
        }
        
        cout<<"Bebida principal\n";
        cout<<"1. Agua\n";
        cout<<"2. Soda\n";
        cout<<"3. Te\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();
        cout<<endl;
        if (aux==1)
        {
            Harray[i].houseinfo.pdrink=Water; 
        }
        else if(aux==2){
            Harray[i].houseinfo.pdrink= soda;
        }
        else
        {
            Harray[i].houseinfo.pdrink=tea;
        }
        Harray[i].houseinfo.iDorder=idorder++;

        cout<<"Tipo de pago\n";
        cout<<"1. Efectivo\n";
        cout<<"2. Tarjeta\n";
        cout<<"Su opcion: "; cin>>aux; cin.ignore();

        if (aux==1)
        {
            Harray[i].houseinfo.pay=cash; 
        }
        else
        {
           Harray[i].houseinfo.pay=card;
        }
        
        cout<<"Monto: "; cin>>Harray[i].houseinfo.total; cin.ignore();
        cout<<"Telefono: "; cin>>Harray[i].cellphone;
        
        
    }
    
}

void searchnamedely(delivery *array,int *size){
    bool userexist= false;
    string aux="";
    cout<<"Nombre a buscar: "; getline(cin,aux);

    for (int i = 0; i < *size; i++)
    {
        if (aux.compare(array[i].deliveryinfo.name)==0)
        {
            cout<<"***************************\n";
            cout<<"Orden encontrada:\n";
            cout<<"***************************\n";
            cout<<"Nombre del cliente: "<<array[i].deliveryinfo.name<<endl;
            cout<<"Plato principal: "<<array[i].deliveryinfo.pdish<<endl;
            cout<<"Entrada: "<<array[i].deliveryinfo.pdentrance<<endl;
            cout<<"Bebida: "<<array[i].deliveryinfo.pdrink<<endl;
            cout<<"Metodo de pago: "<<array[i].deliveryinfo.pay<<endl;
            cout<<endl;
            userexist=true;
        }
        
    }
    (!userexist)? cout<<"No existe el usuario" : cout<<"";
}

void searchnamehouse(houseorder *array,int *size){
    bool userexist= false;
    string aux;
    cout<<"Nombre a buscar: "; getline(cin,aux);

    for (int i = 0; i < *size; i++)
    {
        if (aux.compare(array[i].houseinfo.name)==0)
        {
            cout<<"***************************\n";
            cout<<"Orden encontrada:\n";
            cout<<"***************************\n";
            cout<<"Nombre del cliente: "<<array[i].houseinfo.name<<endl;
            cout<<"Plato principal: "<<array[i].houseinfo.pdish<<endl;
            cout<<"Entrada: "<<array[i].houseinfo.pdentrance<<endl;
            cout<<"Bebida: "<<array[i].houseinfo.pdrink<<endl;
            cout<<"Metodo de pago: "<<array[i].houseinfo.pay<<endl;
            cout<<endl;
            userexist=true;
        }
        
    }
    (!userexist)? cout<<"No existe el usuario" : cout<<"";
}