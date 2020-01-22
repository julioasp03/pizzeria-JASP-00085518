#include <iostream>
#include <string>

#define PASSWORD "union"
using namespace std;

enum maindish{pizza,pasta,ensalada};
enum drink{beer,soda,tea};
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
void addorder(delivery *array);

int main(void){
    delivery *darray=NULL;
    houseorder *Harray=NULL;
    int option=0;
    if (login()==false)
    {
        return 0;
    }
    do
    {
        printmenu(); cin>> option;
        cin.ignore();
        switch (option)
        {
        case 1://ordenes a domicilio//
            addorder(darray);
            break;
        
        case 2://ordenes a restaurante//
            addorder(Harray);
            break;
        
        case 3:
            break;
        
        case 4:
            break;
        
        case :
            break;
        }
    } while (option!=0);
    


    return 0;
}

bool login(){
    string passsword;
    char option;
    cout<<"INICIO DE SESION"<< endl;
    cout<<"A - Administrador"<<endl;
    cout<<"E - Empleado"<<endl;
    cout<<"su opcion: "; cin>>option;
    switch (option)
    {
        case 'A':
        case 'a':
            cout<<"digite contrasenia: "; cin>> passsword;
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
    cout<<"Sistema de despacho pizzeria xxxxx"<<endl;
    cout<<" 1. agregar ordenes a domicilio"<<endl;
    cout<<"2. agregar ordenes a restaurante"<<endl;
    cout<<"3. ver ordenes a domicilio"<<endl;
    cout<<"4. ver ordenes a restaurante"<<endl;
    cout<<"su opcion: "; 
}

void addorder(delivery *array){
    int size;
    int aux=0;
    cout<<"cantidad de pedidos a ingresar: "; cin>>size;
    cin.ignore();
    array= new delivery[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Nombre:\t"; getline(cin, array[i].deliveryinfo.name);
        cout<<"Direccion:"<<endl;
        cout<<"Colonia:\t"; getline(cin,array[i].deliveryaddress.settlement);
        cout<<"Municipio:\t"; getline(cin,array[i].deliveryaddress.municipality);
        cout<<"Departamento:\t"; getline(cin,array[i].deliveryaddress.department);
        cout<<"nu. de casa:\t"; cin>>array[i].deliveryaddress.housnumber; cin.ignore();

        cout<<"plato principal\n";
        cout<<"1. pizza\n";
        cout<<"2. pasta\n";
        cout<<"3. ensalada\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].deliveryinfo.pdish=pizza; 
        }
        else if(aux==2){
            array[i].deliveryinfo.pdish= pasta;
        }
        else
        {
            array[i].deliveryinfo.pdish=ensalada;
        }
        
        cout<<"plato principal\n";
        cout<<"1. pizza\n";
        cout<<"2. pasta\n";
        cout<<"3. ensalada\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].deliveryinfo.pdish=pizza; 
        }
        else if(aux==2){
            array[i].deliveryinfo.pdish= pasta;
        }
        else
        {
            array[i].deliveryinfo.pdish=ensalada;
        }

        cout<<"Entrada principal\n";
        cout<<"1. pan con ajo\n";
        cout<<"2. pizza roll\n";
        cout<<"3. cheese sticks\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].deliveryinfo.pdentrance=garlicbread; 
        }
        else if(aux==2){
            array[i].deliveryinfo.pdentrance= pizzarolls;
        }
        else
        {
            array[i].deliveryinfo.pdentrance=cheesesticks;
        }
        
        cout<<"bebida principal\n";
        cout<<"1. cerbesa\n";
        cout<<"2. soda\n";
        cout<<"3. te\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].deliveryinfo.pdrink=beer; 
        }
        else if(aux==2){
            array[i].deliveryinfo.pdrink= soda;
        }
        else
        {
            array[i].deliveryinfo.pdrink=tea;
        }
        array[i].deliveryinfo.iDorder=idorder++;

        cout<<"Tipo de pago\n";
        cout<<"1. efectivo\n";
        cout<<"2. tarjeta\n";
        cout<<"3. ensalada\n";  cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].deliveryinfo.pay=cash; 
        }
        else
        {
            array[i].deliveryinfo.pay=card;
        }
        
        cout<<"Monto: "; cin>>array[i].deliveryinfo.total; cin.ignore();
        out<<"Telefono: "; cin>>array[i].deliveryaddress.housnumber; cin.ignore();
        
        
    }
    
}

void addorder(houseorder *array){
     int size;
    int aux=0;
    cout<<"cantidad de pedidos a ingresar: "; cin>>size;
    cin.ignore();
    array= new houseorder[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Nombre:\t"; getline(cin, array[i].houseinfo.name);

        cout<<"plato principal\n";
        cout<<"1. pizza\n";
        cout<<"2. pasta\n";
        cout<<"3. ensalada\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].houseinfo.pdish=pizza; 
        }
        else if(aux==2){
            array[i].houseinfo.pdish= pasta;
        }
        elsecout<<"Direccion:"<<endl;
        cout<<"Colonia:\t"; getline(cin,array[i].deliveryaddress.settlement);
        cout<<"Municipio:\t"; getline(cin,array[i].deliveryaddress.municipality);
        cout<<"Departamento:\t"; getline(cin,array[i].deliveryaddress.department);
        cout<<"nu. de casa:\t"; cin>>array[i].deliveryaddress.housnumber; cin.ignore();

        {
            array[i].houseinfo.pdish=ensalada;
        }
        
        cout<<"plato principal\n";
        cout<<"1. pizza\n";
        cout<<"2. pasta\n";
        cout<<"3. ensalada\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)cout<<"Direccion:"<<endl;
        cout<<"Colonia:\t"; getline(cin,array[i].deliveryaddress.settlement);
        cout<<"Municipio:\t"; getline(cin,array[i].deliveryaddress.municipality);
        cout<<"Departamento:\t"; getline(cin,array[i].deliveryaddress.department);
        cout<<"nu. de casa:\t"; cin>>array[i].deliveryaddress.housnumber; cin.ignore();

        {
            array[i].houseinfo.pdish=pizza; 
        }
        else if(aux==2){
            array[i].houseinfo.pdish= pasta;
        }
        else
        {
            array[i].houseinfo.pdish=ensalada;
        }

        cout<<"Entrada principal\n";
        cout<<"1. pan con ajo\n";
        cout<<"2. pizza roll\n";
        cout<<"3. cheese sticks\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].houseinfo.pdentrance=garlicbread; 
        }
        else if(aux==2){
            array[i].houseinfo.pdentrance= pizzarolls;
        }
        else
        {
            array[i].houseinfo.pdentrance=cheesesticks;
        }
        
        cout<<"bebida principal\n";
        cout<<"1. cerbesa\n";
        cout<<"2. soda\n";
        cout<<"3. te\n";
        cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].houseinfo.pdrink=beer; 
        }
        else if(aux==2){
            array[i].houseinfo.pdrink= soda;
        }
        else
        {
            array[i].houseinfo.pdrink=tea;
        }
        array[i].houseinfo.iDorder=idorder++;

        cout<<"Tipo de pago\n";
        cout<<"1. efectivo\n";
        cout<<"2. tarjeta\n";
        cout<<"3. ensalada\n";  cout<<"su opcion\t"; cin>>aux; cin.ignore();

        if (aux==1)
        {
            array[i].houseinfo.pay=cash; 
        }
        else
        {
            array[i].houseinfo.pay=card;
        }
        
        cout<<"Monto: "; cin>>array[i].houseinfo.total; cin.ignore();
        cout<<"Telefono: "; cin>>array[i].cellphone;
        
        
    }
    
}

void searchname(delivery *array,int size){
    bool userexist= false;
    string aux="";
    cout<<"nombre a buscar: "; getline(cin,aux);

    for (int i = 0; i < size i++)
    {
        if (aux.compare(array[i].deliveryinfo.name)==0)
        {
            userexist=true;
        }
        
    }
    (!userexist)? cout<<"no existe el usuario" : cout<<"";
}

void searchname(houseorder *array,int size){
    bool userexist= false;
    string aux="";
    cout<<"nombre a buscar: "; getline(cin,aux);

    for (int i = 0; i < size i++)
    {
        if (aux.compare(array[i].houseinfo.name)==0)
        {
            userexist=true;
        }
        
    }
    (!userexist)? cout<<"no existe el usuario" : cout<<"";
}