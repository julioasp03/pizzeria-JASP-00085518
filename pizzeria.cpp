#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

#define PASSWORD "union" //defino la contrasenia//
using namespace std;
//creo mis enum//
enum maindish{pizza,pasta,lasagna};
enum drink{Beer,soda,tea};
enum entrance{garlicbread,pizzarolls,cheesesticks};
enum payment{cash,card};
//struct para la informacion de direccion//
struct address{
    string settlement,municipality, department;
    int housnumber;
    int cellphone;
};
//struct para la informacion personal//
struct maininfo{
    string name;
    maindish pdish;
    drink pdrink;
    entrance pdentrance;
    payment pay;
    int iDorder;
    float total;
    
};
//struct para las ordenes a domicilio//
struct delivery{
    address deliveryaddress,despach02;//subregistros para las ordenes a domicilio y despacho//
    maininfo deliveryinfo;//subrefistro para informacion personal//
    maininfo despach;//subregistro para informacion personal para el despacho//
};
//struct para las ordenes a restaurante//
struct houseorder{
    int ptable,ptable02;//ptable = numero de personas, ptable 02= numero de personas para el despacho//
    int cont;
    maininfo houseinfo;//subrefistro para informacion personal//
    maininfo despach03;//subregistro para informacion personal para el despacho//
};

//variables globales//
bool isadmin= false;
int idorder=0;
int add=1;
vector<delivery> orderDely,despadely;
vector<houseorder> orderRest,desparest;
delivery dely,Dd;
houseorder house,Dr;

//prototipos//
bool login();
void printmenu();
void addorderdely();
void addorderhouse();
void showdely();
void showhouse();
void despachdely();
void despachrest();
int timeDely();
int timeRest();
void erase();
double total();

int main(void){
    int option=0;
    if (login()==false)//inicio sesion//
    {
        return 0;
    }
    do
    {
        cout<<endl;
        printmenu(); cin>> option; //despliego menu e ingreso la opcion//
        cin.ignore();
        cout<<endl;
        switch (option)
        {
        case 1://ordenes a domicilio//
            addorderdely();
            break;
        
        case 2://ordenes a restaurante//
            addorderhouse();
            break;
        
        case 3:
            showdely();//mostrar ordenes a domicilio//
            break;
        
        case 4:
            showhouse();//mostrar ordenes a restaurante//
            break;
        case 5: despachdely(); break;//despachar ordenes a domicilio//
        case 6: despachrest(); break;//despachar ordenes a restaurante//
        case 7: cout<<"Tiempo estimado: "<<timeDely()<<" min"; break;//tiempo de espera a domicilio//
        case 8: cout<<"Tiempo estimado: "<<timeRest()<<" min"; break;//tiempo de espera restaurante//
        case 9: if(isadmin==true){//verifico si es administrador//
            erase();//eliminar cualquier orden//
            } 
            else
            {
                cout<<"Solo un administrador tiene autorizacion\n";
            }
            break;
            case 10:  
                cout<<"El total de ventas fue de: "<<total()<<"$";//el total gananci en ventas//
            break;
            case 11: main(); break;//cambio de usuario//
        }
    } while (option!=12);//cierro menu con opc 12.//
    return 0;
}

bool login(){
    string password;
    char option;
    cout<<"INICIO DE SESION"<< endl;
    cout<<"A - Administrador"<<endl;
    cout<<"E - Empleado"<<endl;
    cout<<"su opcion: "; cin>>option;//elige con que seion iniciar//
    switch (option)
    {
        case 'A':
        case 'a': //en caso que sea administrador pido contrasenia y verifico si es correcta//
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
            isadmin =false;//si no es administrador //
            return true;
        break;
    }
    return false;
}

void printmenu(){ //muestro el menu//
    cout<<"---------------------------------------\n";
    cout<<"Sistema de despacho pizzeria Santillana"<<endl;
    cout<<"---------------------------------------\n";
    cout<<"1. Agregar ordenes a domicilio."<<endl;
    cout<<"2. Agregar ordenes a restaurante."<<endl;
    cout<<"3. Ver ordenes a domicilio."<<endl;
    cout<<"4. Ver ordenes a restaurante."<<endl;
    cout<<"5. Despachar ordenes a domicilio."<<endl;
    cout<<"6. Despachar ordenes a restaurante."<<endl;
    cout<<"7. Ver tiempo promedio de espera a domicilio."<<endl;
    cout<<"8. Ver tiempo promedio de espera a restaurante."<<endl;
    cout<<"9. Eliminar orden realizada.\n";
    cout<<"10. Calcular total de ventas.\n";
    cout<<"11. Cambiar de usuario.\n";
    cout<<"12. Salir del menu.";
    cout<<endl;
    cout<<"Su opcion: "; 
    return;
}

void addorderdely(){
    int aux=0;
    float montototal=0;
    cout<<endl;
    cout<<"Nombre: "; getline(cin,dely.deliveryinfo.name);//ingreso toda la informacion necesaria de mi struct a domicilio//
    cout<<"****************************\n";
    cout<<"Direccion"<<endl;
    cout<<"Colonia: "; getline(cin,dely.deliveryaddress.settlement);
    cout<<"Municipio: "; getline(cin,dely.deliveryaddress.municipality);
    cout<<"Departamento: "; getline(cin,dely.deliveryaddress.department);
    cout<<"No. de casa: "; cin>>dely.deliveryaddress.housnumber; cin.ignore();
    cout<<"****************************\n";
    cout<<"Plato principal\n";
    cout<<"1. Pizza\n";
    cout<<"2. Pasta\n";
    cout<<"3. Ensalada\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore();
    cout<<endl;
    if (aux==1)
    {
        dely.deliveryinfo.pdish=pizza; //lleno mis enum//
        montototal=montototal+13.99;//acumulo el las ganancias en una variable//
    }
    else if(aux==2){
        dely.deliveryinfo.pdish= pasta;
        montototal=montototal+5.55;
    }
    else 
    {
        dely.deliveryinfo.pdish=lasagna;
        montototal=montototal+6.25;
    }   
            
    cout<<"Entrada principal\n";
    cout<<"1. Pan con ajo\n";
    cout<<"2. Pizza rolls\n";
    cout<<"3. Cheese sticks\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore();
    cout<<endl;
    if (aux==1)
    {
        dely.deliveryinfo.pdentrance=garlicbread; 
        montototal=montototal+3.99;
    }
    else if(aux==2){
        dely.deliveryinfo.pdentrance= pizzarolls;
        montototal=montototal+4.99;
    }
    else 
    {
        dely.deliveryinfo.pdentrance=cheesesticks;
        montototal=montototal+3.75;
    }          
    cout<<"Bebida principal\n";
    cout<<"1. Cerveza\n";
    cout<<"2. Soda\n";
    cout<<"3. Te\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore();
    cout<<endl;

    if (aux==1)
    {
        dely.deliveryinfo.pdrink=Beer;
        montototal=montototal+1.99; 
    }
    else if(aux==2){
        dely.deliveryinfo.pdrink= soda;
        montototal=montototal+0.95;
    }
    else 
    {
        dely.deliveryinfo.pdrink=tea;
        montototal=montototal+1.15;
    }        
    cout<<endl;
    idorder=idorder+1;//implemento un contador global que me servira como numero de orden//
    dely.deliveryinfo.iDorder=idorder;

    cout<<"Tipo de pago\n";
    cout<<"1. Efectivo\n";
    cout<<"2. Tarjeta\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore();//lleno mis enum y campo de mi struct//
    cout<<endl;
    if (aux==1)
    {
        dely.deliveryinfo.pay=cash; 
    }
    else
    {
        dely.deliveryinfo.pay=card;
    }
    dely.deliveryinfo.total=montototal;
    cout<<"Monto: "<<montototal<<"$";
    cout<<endl;
    cout<<"Telefono: "; cin>>dely.deliveryaddress.cellphone; cin.ignore();
    orderDely.insert(orderDely.end(),dely);//inserto todo en mi lista a domicilio//
    return;
    
}

void addorderhouse(){
    int aux=0;
    float montototal=0;
    cout<<endl;             //ingreso toda la informacion necesaria de mi struct a restaurante//
    cout<<"Nombre: "; getline(cin,house.houseinfo.name);
    cout<<"Numero de personas: ";cin>>house.ptable; cin.ignore();
    cout<<endl;
    cout<<"Plato principal\n";
    cout<<"1. Pizza\n";
    cout<<"2. Pasta\n";
    cout<<"3. Ensalada\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore();
    cout<<endl;
    if (aux==1)
    {
        house.houseinfo.pdish=pizza; //lleno mis enum//
        montototal=montototal+13.99; //acumulo el las ganancias en una variable//
    }
    else if(aux==2){
        house.houseinfo.pdish= pasta;
        montototal=montototal+5.55;
    }
    else
    {
        house.houseinfo.pdish=lasagna;
        montototal=montototal+6.25;
    }        
    cout<<"Entrada principal\n";
    cout<<"1. Pan con ajo\n";
    cout<<"2. Pizza rolls\n";
    cout<<"3. Cheese sticks\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore();
    cout<<endl;

    if (aux==1)
    {
        house.houseinfo.pdentrance=garlicbread; 
        montototal=montototal+3.99;
    }
    else if(aux==2){
        house.houseinfo.pdentrance= pizzarolls;
        montototal=montototal+4.99;
    }
    else
    {
        house.houseinfo.pdentrance=cheesesticks;
        montototal=montototal+3.75;
    }
            
    cout<<"Bebida principal\n";
    cout<<"1. Cerveza\n";
    cout<<"2. Soda\n";
    cout<<"3. Te\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore();
    cout<<endl;
    if (aux==1)
    {
        house.houseinfo.pdrink=Beer;
        montototal=montototal+1.99; 
    }
    else if(aux==2){
        house.houseinfo.pdrink= soda;
        montototal=montototal+0.95;
    }
    else
    {
        house.houseinfo.pdrink=tea;
        montototal=montototal+1.15;
    }
    cout<<endl;
    idorder=idorder+1;  //implemento un contador global que me servira como numero de orden//
    house.houseinfo.iDorder=idorder;

    cout<<"Tipo de pago\n";
    cout<<"1. Efectivo\n";
    cout<<"2. Tarjeta\n";
    cout<<"Su opcion: "; cin>>aux; cin.ignore(); //lleno mis enum y campo de mi struct//
    cout<<endl;
    if (aux==1)
    {
       house.houseinfo.pay=cash; 
    }
    else
    {
        house.houseinfo.pay=card;
    }
    house.houseinfo.total=montototal;
    cout<<"Monto: "<<montototal<<"$";
    cout<<endl;
    orderRest.insert(orderRest.end(),house);//inserto todo en mi lista a restaurante//
    return;
}

void showdely(){
    if(!orderDely.size()==0){//mientras mi lista no este vacia//
        for (int i = 0; i < orderDely.size(); i++)//recorro la lista//
        {
            cout<<"********************************\n"; //muestro los campos de mi primer puesto en la lista y si hay mas continuo//
            cout<<"Nombre del cliente: "<<orderDely[i].deliveryinfo.name<<endl; 
            cout<<"Reside en la colonia: "<<orderDely[i].deliveryaddress.settlement<<endl;
            cout<<"Municipio: "<<orderDely[i].deliveryaddress.municipality<<endl;
            cout<<"Departamento: "<<orderDely[i].deliveryaddress.department<<endl;
            cout<<"No. de casa: "<<orderDely[i].deliveryaddress.housnumber<<endl;
            cout<<"Plato principal: ";            
            switch (orderDely[i].deliveryinfo.pdish)//vero que num es//
            {
            case 0:
                cout<<" Pizza\n";
            break;
                
            case 1: cout<<" Pasta\n";
                break;
            case 2: cout<<" Lasagna\n"; break;
            }
            cout<<"Entrada principal: ";
            switch (orderDely[i].deliveryinfo.pdentrance)
            {
            case 0:
                cout<<" Pan con ajo\n";
                break;
            
            case 1: cout<<" Pizza rolls\n";
                break;
            case 2: cout<<" Cheese sticks\n"; break;
            }
            cout<<"Bebida: ";
            switch (orderDely[i].deliveryinfo.pdrink)
            {
            case 0:
                cout<<" Cerveza\n";
                break;
            
            case 1: cout<<" Soda\n";
                break;
            case 2: cout<<" Te\n"; break;
            }
            cout<<"Id de orden: "<<orderDely[i].deliveryinfo.iDorder<<endl;
            cout<<"Monto: "<<orderDely[i].deliveryinfo.total<<"$"<<endl;
            cout<<"Metodo de pago: ";
            switch (orderDely[i].deliveryinfo.pay)
            {
            case 0:
                cout<<" Efectivo\n";
                break;
            
            case 1:cout<<" Tarjeta\n";
                break;
            }
            cout<<"Telefono: "<<orderDely[i].deliveryaddress.cellphone<<endl;
            cout<<"********************************\n";
        }
    }
    else
    {
        cout<<"No hay ordenes a domicilio.\n";
    }
    
    return;  
}

void showhouse(){
    if(!orderRest.size()==0){ //mientras mi lista no este vacia//
        for (int i = 0; i < orderRest.size(); i++)
        {
            cout<<"********************************\n";//muestro los campos de mi primer puesto en la lista y si hay mas continuo//
            cout<<"Nombre del cliente: "<<orderRest[i].houseinfo.name<<endl; 
            cout<<"Numero de comensales; "<<orderRest[i].ptable<<endl;
            cout<<"Plato principal: ";    
            switch (orderRest[i].houseinfo.pdish) //vero que num es//
            {
                case 0:
                    cout<<" Pizza";
                break;
                
                case 1: cout<<" Pasta";
                    break;
                case 2: cout<<" Lasagna"; break;
            }
           cout<<" ";
            
            cout<<endl;
            cout<<"Entrada principal: ";
            
            switch (orderRest[i].houseinfo.pdentrance)
            {
                case 0:
                    cout<<" Pan con ajo";
                    break;
                
                case 1: cout<<" Pizza rolls";
                    break;
                case 2: cout<<" Cheese sticks"; break;
            }
            cout<<" ";
            cout<<endl;
            cout<<"Bebida: ";
            switch (orderRest[i].houseinfo.pdrink)
            {
                case 0:
                    cout<<" Cerveza";
                break;
                
                case 1: cout<<" Soda";
                    break;
                case 2: cout<<" Te"; break;
            }
            cout<<" ";
            cout<<endl;
            cout<<"Id order: "<<orderRest[i].houseinfo.iDorder<<endl;
            cout<<"Monto: "<<orderRest[i].houseinfo.total<<"$"<<endl;
            cout<<"Metodo de pago: ";
            switch (orderRest[i].houseinfo.pay)
            {
            case 0:
                cout<<" Efectivo\n";
                break;
            
            case 1:cout<<" Tarjeta\n";
                break;
            }
            cout<<"********************************\n";
        }
    }
    else
    {
        cout<<"No hay ordenes a restaurante.\n";
    }
    
    return;  

}

void despachdely(){ //guardo todo los campos de mi primer puesto en mi lista a domicilio en una campo difernete de mi struct//
  
    Dd.despach.name=orderDely[0].deliveryinfo.name; 
    Dd.despach02.settlement=orderDely[0].deliveryaddress.settlement;
    Dd.despach02.municipality=orderDely[0].deliveryaddress.municipality;
    Dd.despach02.department=orderDely[0].deliveryaddress.department;
    Dd.despach.pdish=orderDely[0].deliveryinfo.pdish;
    Dd.despach.pdentrance=orderDely[0].deliveryinfo.pdentrance;
    Dd.despach.pdrink=orderDely[0].deliveryinfo.pdrink;
    Dd.despach.pay=orderDely[0].deliveryinfo.pay;
    Dd.despach.total=orderDely[0].deliveryinfo.total;
    Dd.despach02.cellphone=orderDely[0].deliveryaddress.cellphone;
    despadely.insert(despadely.end(),Dd); //meto mi nuevo campo en una lista de despacho a domicilio//
    orderDely.erase(orderDely.begin());//borro el primer puesto de mi lista a domicilio//
    cout<<"Oreden despachada\n";
    return;
}

void despachrest(){ //guardo todo los campos de mi primer puesto en mi lista a restaurante en una campo difernete de mi struct//
    Dr.despach03.name=orderRest[0].houseinfo.name; 
    Dr.ptable02=orderRest[0].ptable;
    Dr.despach03.pdish=orderRest[0].houseinfo.pdish;
    Dr.despach03.pdentrance=orderRest[0].houseinfo.pdentrance;
    Dr.despach03.pdrink=orderRest[0].houseinfo.pdrink;
    Dr.despach03.pay=orderRest[0].houseinfo.pay;
    Dr.despach03.total=orderRest[0].houseinfo.total;
    desparest.insert(desparest.end(),Dr); //meto mi nuevo campo en una lista de despacho a restaurante//
    orderRest.erase(orderRest.begin()); //borro el primer puesto de mi lista a restaurante//
    cout<<"Oreden despachada\n";
    return;
}

int timeDely(){
    float timedely;
    int cont=0,a=0;
    if(orderDely.size()!=0){
        
        for (int i = 0; i < orderDely.size(); i++)  //calculo las ordenes que tengo a domicilio//
        {
            cont++;
        }
        timedely=((cont*1.10)+(cont*1.5)+(cont*1.35))+15;//calculo el tiempo por cada orden//
        a=static_cast<int>(timedely);//transformo mi flotante a entero//  
    }
    return a;
    
}

int timeRest(){
    float timerest=0;
    int cont=0;
    int b=0;
    if (orderRest.size()!=0)
    {
    for (int i = 0; i < orderRest.size(); i++) //calculo las ordenes que tengo a restaurante//
    {
        cont++;
    }
    timerest=((cont*1.10)+(cont*1.5)+(cont*1.35)); //calculo el tiempo por cada orden//
    b=static_cast<int>(timerest); //transformo mi flotante a entero//
    }
    
    return b;
}

void erase(){
    int n;
    cout<<"Ingrese el Id de orden a eliminar: "; cin>>n; cin.ignore();//busco el id de la orden a eliminar//
    for (auto iter = orderDely.begin(); iter !=orderDely.end(); ++iter)//elimino la orden//
    {
       if ((*iter).deliveryinfo.iDorder==n)
       {
           iter=orderDely.erase(iter);
           cout<<"Orden eliminada.\n";
           break;
        }
        else
        {
           
        }
            
    }
    for (auto iter = orderRest.begin(); iter !=orderRest.end(); ++iter)
    {
       if ((*iter).houseinfo.iDorder==n)
       {
           iter=orderRest.erase(iter);
           cout<<"Orden eliminada.\n";
           break;
        }
        else
        {
           cout<<"Orden no encontrada\n";
        }
            
    }
    return;
}
double total(){
    double total=0,iva=0;
    for (int i = 0; i < despadely.size(); i++)//recorro mi lista a domicilio//
    {
        iva=(iva+despadely[i].despach.total)+((despadely[i].despach.total*13)/100);//calculo el monto mas el iva//
        total=total+iva;        //la guardo en una variable a retornar//
    }
    for (int i = 0; i < desparest.size(); i++)//recorro mi lista a restaurante//
    {
        iva=(iva+desparest[i].despach03.total)+((desparest[i].despach03.total*13)/100);//calculo el monto mas el iva//
        total=total+iva; //la guardo en una variable a retornar//
    }
    return total;
}