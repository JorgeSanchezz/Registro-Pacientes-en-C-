#include<iostream>
#include<conio.h>
#include<windows.h>    
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct nodo {
       int cod;
       char nom[30];
       char apll[30];
       char drc[30];
       long int tel;
       
       nodo * siguiente;
       } *primero, *ultimo;


void gotoxy(int x, int y)
{
     HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y = y;
     SetConsoleCursorPosition(hcon, dwPos);
     
}

void tabla();
void insertar();
void mostrar();
void busqueda();
void eliminar();
void modificarLista(nodo*lista,string n,string n1, int op);

int main(){
	system ("color f5");
int opc ;  
	int res,x,lim,op;
	long int cod,tel;
	string n2;
	string nom,ape,dom,n,n1;
	nodo *lista=NULL;
     do{
     system("cls");
     gotoxy(40,4);cout<<"* * * * * * * * * H O S P I T A L * * * * * * * * * "<<endl;
     gotoxy(50,6);cout<<"1) Registro de Paciente: "<<endl;
     gotoxy(50,7);cout<<"2) Mostrar Datos Pacientes: "<<endl;
     gotoxy(50,8);cout<<"3) Buscar Datos Pacientes: "<<endl;  
     gotoxy(50,9);cout<<"4) Eliminar Pacientes: "<<endl;
     gotoxy(50,10);cout<<"5) Modificar: "<<endl;
     gotoxy(50,11);cout<<"6) Salir del Programa."<<endl;
     gotoxy(50,12);cout <<"Seleccione una opcion ";
     gotoxy(50,13);cin>>opc;
     
     switch (opc){
            case 1:
                 
                 system("cls");
                 insertar();
                 system("pause");
                 break;
            case 2:      
                    
                 system("cls");
                 mostrar();
                 system("pause");
                 break;
           case 3:
                
                 system("cls");
                 busqueda();
                 system("pause");
                 break; 

           case 4:
                
                 system("cls");
                 eliminar();
                 system("pause");
                 break;                  
          
		  case 5:
					system("cls");
					gotoxy(50,6);cout<<"1)Codigo";
					gotoxy(50,7);cout<<"2)Nombre";
					gotoxy(50,8);cout<<"3)Apellido";
					gotoxy(50,9);cout<<"4)Domicilio";
					gotoxy(50,10);cout<<"5)Telefono"<<endl;
					gotoxy(50,11);cin>>op;
        			system("cls");
        			switch(op){
    					case 1:
    					
                       		gotoxy(50,6);cout<<"Codigo actual"<<endl;
                       		gotoxy(50,7);cin>>n;
                           	gotoxy(50,8);cout<<"Codigo modificando: ";
                           	gotoxy(50,9);cin>>n1;
                       		modificarLista(lista,n,n1,op);
                           	getch(	);
                       	break;
                       	case 2:
                       		
                       		gotoxy(50,6);cout<<"Nombre actual"<<endl;
                       		gotoxy(50,7);cin>>n;
                           	gotoxy(50,8);cout<<"Nombre modificado: ";
                           	gotoxy(50,9);cin>>n1;
                           	modificarLista(lista,n,n1,op);
                           	getch();
                       	break;
                       	case 3:
                       		
                       		gotoxy(50,6);cout<<"Apellido actual"<<endl;
                       		gotoxy(50,7);cin>>n;
                           	gotoxy(50,8);cout<<"Apellido modificado: ";
                           	gotoxy(50,9);cin>>n1;
                           	modificarLista(lista,n,n1,op);
                           	getch();
                       	break;
                       	case 4:
                       		
                       		gotoxy(50,6);cout<<"Domicilio actual"<<endl;
                       		gotoxy(50,7);cin>>n;
                           	gotoxy(50,8);cout<<"Domicilio modificado: ";
                           	gotoxy(50,9);cin>>n1;
                           	modificarLista(lista,n,n1,op);
                           	getch();
                       	break;
                       	case 5:
                       		
                       		gotoxy(50,6);cout<<"Telefono actual"<<endl;
                       		gotoxy(50,7);cin>>n;
                           	gotoxy(50,8);cout<<"Telefono modificado: ";
                           	gotoxy(50,9);cin>>n1;
                           	modificarLista(lista,n,n1,op);
                           	getch();
                       	break;
					}
					break;
               break;
          
		          
          case 6:
               exit(0);
               break;
          
          default:
                  cout<<"No existe opcion"<<endl;
                  getch();
                 }

     }while(opc !=0);
    
    getch();
       }
       
       
       
void tabla(){   
     int y; 
                 gotoxy(0,0);cout<<"Codigo";
                 gotoxy(15,0);cout<<"Nombre";
                 gotoxy(30,0);cout<<"Apellido";
                 gotoxy(45,0);cout<<"Direccion";
                 gotoxy(60,0);cout<<"Telefono";        
     }   
     
         
void insertar(){
     nodo * nvo_n = new nodo();
     
     gotoxy(45,3);cout<<"D a t o s   D e l   P a c i e n t e"<<endl;
     gotoxy(50,5);cout<<"Codigo: ";
     gotoxy(50,6);cin>>nvo_n -> cod;    
     gotoxy(50,7);cout<<"Nombre: ";
     gotoxy(50,8);cin>>nvo_n -> nom;
     gotoxy(50,9);cout<<"Apellido: ";
     gotoxy(50,10);cin>>nvo_n -> apll;
     gotoxy(50,11);cout<<"Direccion: ";
     gotoxy(50,12);cin>>nvo_n -> drc;
     gotoxy(50,13);cout<<"Telefono: ";
     gotoxy(50,14);cin>>nvo_n -> tel;
     
     if (primero == NULL){
                 primero = nvo_n;
                 primero->siguiente = NULL;
                 ultimo = nvo_n;
                 
                 }else{
                       ultimo -> siguiente = nvo_n;
                       nvo_n -> siguiente = NULL;
                       ultimo = nvo_n;
                       }            
     gotoxy(50,16);cout<<"Registro Completado";
     cout<<"  "<<endl;
     
     }
     
void mostrar(){

     int y=1;
     nodo * actual = new nodo();
     actual = primero;
     
     if(primero != NULL){
                while (actual != NULL){
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;
                      actual = actual -> siguiente;
                      y++;                    
                      
               }
          }
     }     


void busqueda(){

     int opc, y=1;
     char buscarNom[30],buscarApll[30],buscarDrc[30];
     int  buscarCod,buscarTel;
     
     nodo * actual = new nodo();
     actual = primero;
     bool encontrado = false;
     
     
      gotoxy(45,4);cout<<"*** C o n s u l t a r   P a c i e n t e ***"<<endl;
      gotoxy(50,6);cout<<"Buscar por: "<<endl;
      gotoxy(50,7);cout<<"1) Codigo"<<endl;
      gotoxy(50,8);cout<<"2) Nombre"<<endl;
      gotoxy(50,9);cout<<"3) Apellido"<<endl;
      gotoxy(50,10);cout<<"4) Direccion"<<endl;
      gotoxy(50,11);cout<<"5) Telefono"<<endl;
      gotoxy(50,12);cout<<"6) Regresar al menu "<<endl;     
      gotoxy(50,13);cout<<"Seleccione una opcion ";
  	  gotoxy(50,14);cin>>opc;
     
     switch(opc){
                 
                case 1:
                     gotoxy(50,18);cout<<"Ingrese el codigo: ";
                     cin>>buscarCod;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (actual -> cod == buscarCod){
                      encontrado = true;
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;       
                                     
                      y++;
                            }
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                break;                 
                 
                case 2:
                     gotoxy(50,18);cout<<"Ingrese el nombre: ";
                     cin>>buscarNom;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (strcmp(actual -> nom,buscarNom) == 0){
                      encontrado = true;
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;     
                                       
                      y++;
                            }
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                break;    
                                   
                case 3:
                     gotoxy(50,18);cout<<"Ingrese el apellido: ";
                     cin>>buscarApll;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (strcmp(actual -> apll,buscarApll) == 0){
                      encontrado = true;
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;       
                                     
                      y++;
                            }
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }                     
                     
                break;
                
                case 4:
                     gotoxy(50,18);cout<<"Ingrese la direccion: ";
                     cin>>buscarDrc;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (strcmp(actual -> drc,buscarDrc) == 0){
                      encontrado = true;
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl; 
                                           
                      y++;
                            }
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                break;
                
                case 5:
                     gotoxy(50,18);cout<<"Ingrese el telefono: ";
                     cin>>buscarTel;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (actual -> tel == buscarTel){
                      encontrado = true;
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;       
                                     
                      y++;
                            }
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                break; 
                                                 
                case 6:
                break;                
                }
     }


void eliminar (){

     int opc, y=1;
     char buscarNom[30],buscarApll[30],buscarDrc[30],resp;
     int  buscarCod,buscarTel;
     
     nodo * actual = new nodo();
     actual = primero;
     
     nodo * anterior = new nodo();
     anterior=NULL;
     
     bool encontrado = false;
     
     
     gotoxy(45,4);cout<<"*** E L I M I N A R  P A C I E N T E ***"<<endl;
     gotoxy(50,5);cout<<"Eliminar por"<<endl;
     gotoxy(50,6);cout<<"1) Codigo"<<endl;
     gotoxy(50,7);cout<<"2) Nombre"<<endl;
     gotoxy(50,8);cout<<"3) Apellido"<<endl;
     gotoxy(50,9);cout<<"4) Direccion"<<endl;
     gotoxy(50,10);cout<<"5) Telefono"<<endl;
     gotoxy(50,11);cout<<"6) Regresar al menu principal"<<endl; 
     gotoxy(50,12);cout<<"Elija opcion ";
     cin>>opc;
     
     switch(opc){
                 
                case 1:
                     gotoxy(50,18);cout<<"Ingrese el codigo: ";
                     cin>>buscarCod;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (actual -> cod == buscarCod){
                      encontrado = true;
                      system("cls");
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;
                      y++;     
            
            cout<<"Eliminar este registro s/n ";
            cin>>resp;
            
            if(resp == 's'){                               
                      if (actual == primero)
                      {
                       primero = primero -> siguiente;
                      }
                       else if(actual == ultimo)
                      { 
                       anterior -> siguiente = NULL;
                       ultimo = anterior;   
                      }
                      else
                      {
                      anterior -> siguiente = actual -> siguiente;
                      }
                      cout<<"Registro eliminado"<<endl;
                      getch();
                      }else if (resp == 'n'){
                            cout<<"Registro no eliminado"<<endl;
                            getch();
                            }
                      }
                      
                anterior = actual;
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                break;                 
                 
                case 2:
                     gotoxy(50,18);cout<<"Ingrese el nombre: ";
                     cin>>buscarNom;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (strcmp(actual -> nom,buscarNom) == 0){
                                        
                      encontrado = true;
                      system("cls");
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;
                      y++;     
            
            cout<<"Desea eliminar este registro s/n ";
            cin>>resp;
            
            if(resp == 's'){                               
                      if (actual == primero)
                      {
                       primero = primero -> siguiente;
                      }
                       else if(actual == ultimo)
                      { 
                       anterior -> siguiente = NULL;
                       ultimo = anterior;   
                      }
                      else
                      {
                      anterior -> siguiente = actual -> siguiente;
                      }
                      cout<<"Registro eliminado"<<endl;
                      getch();
                      }else if (resp == 'n'){
                            cout<<"Registro no eliminado"<<endl;
                            getch();
                            }
                      }
                      
                anterior = actual;
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                     
                break;
                
                case 4:
                     gotoxy(50,18);cout<<"Imgrese la direccion: ";
                     cin>>buscarDrc;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (strcmp(actual -> drc,buscarDrc) == 0){
                                        
                      encontrado = true;
                      system("cls");
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;
                      y++;     
            
            cout<<"Desea eliminar este registro s/n ";
            cin>>resp;
            
            if(resp == 's'){                               
                      if (actual == primero)
                      {
                       primero = primero -> siguiente;
                      }
                       else if(actual == ultimo)
                      { 
                       anterior -> siguiente = NULL;
                       ultimo = anterior;   
                      }
                      else
                      {
                      anterior -> siguiente = actual -> siguiente;
                      }
                      cout<<"Registro eliminado"<<endl;
                      getch();
                      }else if (resp == 'n'){
                            cout<<"Registro no eliminado"<<endl;
                            getch();
                            }
                      }
                      
                anterior = actual;
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                break;
                
                case 5:
                     gotoxy(50,18);cout<<"Ingrese el telefono: ";
                     cin>>buscarTel;
                     system("cls");
                     
     if(primero != NULL){
                while ((actual != NULL) && (encontrado != true)){
                      if (actual -> tel == buscarTel){
                      encontrado = true;
                       system("cls");
                      
                      tabla();
                      gotoxy(1,y);cout<<actual -> cod<<endl;
                      gotoxy(15,y);cout<<actual -> nom<<endl;
                      gotoxy(31,y);cout<<actual -> apll<<endl;
                      gotoxy(46,y);cout<<actual -> drc<<endl;
                      gotoxy(61,y);cout<<actual -> tel<<endl;
                      y++;     
            
            cout<<"Desea eliminar este registro s/n ";
            cin>>resp;
            
            if(resp == 's'){                               
                      if (actual == primero)
                      {
                       primero = primero -> siguiente;
                      }
                       else if(actual == ultimo)
                      { 
                       anterior -> siguiente = NULL;
                       ultimo = anterior;   
                      }
                      else
                      {
                      anterior -> siguiente = actual -> siguiente;
                      }
                      cout<<"Registro eliminado"<<endl;
                      getch();
                      }else if (resp == 'n'){
                            cout<<"Registro no eliminado"<<endl;
                            getch();
                            }
                      }
                      
                anterior = actual;
                actual = actual -> siguiente;
                encontrado = false;

                          }
                       }
                break; 
                                                 
                case 6:
                break;                
                }
            }

                

void modificarLista(nodo*lista,string n,string n1, int op){ 
	bool band=false;
	nodo*actual=new nodo();
	actual=lista;
	while(actual!=NULL){
		if(actual->cod==atoi(n.c_str()) && op==1){
			band=true;
			actual->cod=atoi(n1.c_str());
		}
		if(actual->nom==n && op==2){
			band=true;
			actual->nom==n1;
		}
		if(actual->apll==n && op==3){
			band=true;
			actual->apll==n1;
		}
		if(actual->tel==atoi(n.c_str()) && op==4){
			band=true;
			actual->tel=atoi(n1.c_str());
		}
		if(actual->drc==n && op==5){
			band=true;
			actual->drc==n1;
		}
		actual = actual -> siguiente;
	}
	if(band==true){
		gotoxy(50,9);cout<<"Paciente modificado con exito";
		
	}
	
}

