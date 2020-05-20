
/*Realizar el siguiente ejercicio utilizando funciones, estructuras y punteros:


La Unicef desea obtener información estadística sobre las guarderias ubicadas en el territorio guatemalteco, dado que por cada niño se ingresa la siguiente información: Nombre, Sexo, Edad, Nombre de Guarderia, Departamento (ubicacion geográfica)

Para lo cual se debe generar los siguientes reportes:
a) Porcentaje de niños ubicados en el departamento de guatemala, respecto al total del país.
b) Número de niños por grupo, los cuales se definen con base en la edad, teniendo en cuenta lo siguiente:

Grupo 1: Edad menor a 1 año
Grupo 2: Edad comprendida entre 1 y 3 años
Grupo 3: Edad comprendida entre 4 y 6 años
Grupo 4: Edad mayor de 6 años
c) Establecer el grupo que tiene la mayor cantidad de niños.*/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<string>
#include <regex> 	
#include <fstream>
#include <stdio.h>
#include <sstream> 
#include <regex>
#include <iomanip>

#define datos "datos.txt"
#define datos1 "datos1.txt"

using namespace std;



void mostrarregistro()

{
ifstream principal; 
	principal.open(datos,ios::in);
		int nregistro,numerodelineas,reg ; string linea1,fecha,flag,inota;
string edad ,peso,altura,departamento;
string totalc;
			cout<<setw(3)<<"EDAD"<<"|"<<setw(6)<<"PESO"<<"|"<<setw(4)<<"ALTURA"<<"|"<<setw(20)<<"DEPARTAMENTO"<<endl;

	while (principal>>edad>>peso>>altura>>departamento	){
		
			cout<<setw(3)<<edad<<"|"<<setw(6)<<peso<<"|"<<setw(4)<<altura<<"|"<<setw(20)<<departamento<<endl;
			}	
		principal.close();
}





int  numlineas(){
	int lin=0;
 try{
    				ifstream lectura;

		lectura.open(datos,ios::in);

    	  while(lectura.good()) if(lectura.get()=='\n') lin++;
  lectura.close();	}
		catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");	}
   return lin;
}






int main()
{
	int x=1,eleccion;
   					remove(datos1);


	string tpeso,tedad,taltura,tdepartamento;
		string speso,sedad,saltura,sdepartamento;

	while(x==1)
	{
		cout<<"BIENVENIDOS, ESTADISTICAS DE GUARDERIAS EN GUATEMALA  \n ""Seleccione alguna opcion \n 1.Ingreso de datos. \n 2.Estadisticas."<<endl;
		cin>>eleccion;
		system("cls");
		
		if (eleccion==1)
		
		{
			
		ofstream ingresodatos;
		ingresodatos.open(datos,ios::app);
		
	
		
		
				cout<<"Ingrese el peso de la persona"<<endl;
		cin>>speso;
			cout<<"Ingrese la edad de la persona"<<endl	;
		cin>>sedad;
			cout<<"Ingrese la altura  de la persona"<<endl;
		cin>>saltura;
			cout<<"Ingrese el departamento de la persona"<<endl;
		cin>>sdepartamento;
		ingresodatos<<sedad<<"\t"<<speso<<"\t"<<saltura<<"\t"<<sdepartamento<<endl;
		ingresodatos.close();
				
		ifstream lectura;
		lectura.open(datos,ios::in);
			int indice=numlineas();

		int a1=0;
			string peso[indice],edad[indice],altura[indice],departamento[indice];

	
			while(lectura>>tedad>>tpeso>>taltura>>tdepartamento)
		{
			
			peso[a1]=tpeso;
			edad[a1]=tedad;
			altura[a1]=taltura;
			departamento[a1]=tdepartamento;
		
			a1=a1+1;
			
		}
	
	
		
		int v1,v2,i,j;string temp,temp1,temp2,temp3;
		for (int i=0; i<indice-1; i++){
          for (j=0 ; j<indice -1	; j++)
          {
		  v1=atoi(edad[j].c_str()); 
		  v2=atoi(edad[j+1].c_str());
               if (v1	> v2){
			   
                    temp = edad[j];
                    edad[j] = edad[j+1];
                   edad[j+1] = temp;
                   
                     temp1 = peso[j];
                    peso[j] = peso[j+1];
                   peso[j+1] = temp1;
                   
                     temp2 = altura[j];
                    altura[j] = altura[j+1];
                   altura[j+1] = temp2;
                   
                    temp3 = departamento[j];
                    departamento[j] = departamento[j+1];
                   departamento[j+1] = temp3;
                   
                   
                   
                   
                   
                   
			}
			}	 

			  }
                   
   ofstream temporal;
   temporal.open(datos1,ios::app);
   
   for (int i1=0 ;i1<indice ;i1++)
   {

   	temporal<<edad[i1] <<"\t"<<peso[i1]<<"\t"<<altura[i1]<<"\t"<<departamento[i1]<<endl;
   	
   }
   
   temporal.close();
   lectura.close();
   					remove(datos);
		rename(datos1,datos);  	
		
		cout<<"Desea regresar al menu principal escriba 1, de lo contrario cualquier digito  "<<endl;
		cin>>x;
		
			
			
			
		}
		else {
			
			
			if(eleccion==2)
			{
				 mostrarregistro();
				 float sumaedad=0,sumapeso,sumaaltura,promedad,prompeso,promaltura;
				 ifstream principal; 
			int	 cantidaddatos= numlineas();
	principal.open(datos,ios::in);
				 string edad ,peso,altura,departamento;

				 	while (principal>>edad>>peso>>altura>>departamento	){
						  sumaedad=sumaedad+atoi(edad.c_str());
						  sumapeso=sumapeso+atoi(peso.c_str());
						  sumaaltura=sumaaltura+atoi(altura.c_str());
			}	
			promedad=sumaedad/cantidaddatos;
			prompeso=sumapeso/cantidaddatos;
			promaltura=sumaaltura/cantidaddatos;
			
			
			cout<<"El promedio de edad es de  "<<promedad<<endl;
			cout<<"El promedio de altura es de  "<<promaltura<<endl;			
			cout<<"El promedio de peso es de  "<<prompeso<<endl;
				cout<<"Desea regresar al menu principal escriba 1, de lo contrario cualquier digito  "<<endl;
		cin>>x;
			}
		}
	}
}
		
		
		
