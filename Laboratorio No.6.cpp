#include <iostream>
#include <conio.h>

using namespace std;

void menu_principal();
void opciones(int&);
void promedio();
void nota_maxima();
void nota_minima();
void agregar_nota();
void eliminar_nota();

struct alumno{
	char nombre[15];
	int nota[4];
	bool registro;
}alumno[5];

int main (){
	setlocale(LC_ALL, "spanish");
	menu_principal();
	return 0;
}

void menu_principal(){
	int m;
	system ("title Sistema de alumnos: menú");
	system ("cls");
	cout<<"\tMenu principal"<<endl;
	cout<<"1. Promedio."<<endl;
	cout<<"2. Nota máxima."<<endl;
	cout<<"3. Nota mínima."<<endl;
	cout<<"4. Agregar notas."<<endl;
	cout<<"5. Eliminar notas."<<endl;
	cout<<"0. Salir del programa."<<endl;
	cout<<"Digite la opción a seguir: "; cin>>m;
	while((((((m!=1)&&(m!=2))&&(m!=3))&&(m!=4))&&(m!=5))&&(m!=0)){
		cerr<<"\aEl número digitado es inválido, intente de nuevo... "; getch();
		cerr<<"Digite la opción a seguir: "; cin>>m;
	}
	if (m==0){
		cout<<"Gracias por usar este programa."<<endl;
	}
	opciones (m);
}

void opciones(int& op){
	switch (op){
		case 0:
			exit(1);
		break;
		case 1:
			promedio();
		break;
		case 2:
			nota_maxima();
		break;
		case 3:
			nota_minima();
		break;
		case 4:
			agregar_nota();
		break;
		case 5:
			eliminar_nota();
		break;
	}	
	cout<<"\nIngrese cualquier tecla para volver al menú principal... "; getch();
	menu_principal();
}

void promedio(){
	int clave;
	float promedio;
	system ("Title Sistema de alumnos: promedio");
	cout<<"\tPromedio"<<endl;
	cout<<"Digite la clave del alumno para calcular su promedio (1-5): "; cin.ignore(); cin>>clave;
	if ((clave<1)||(clave>5)){
		cerr<<"\aEl numero ingresado es inválido."<<endl;
		return;
	}else if(alumno[clave].registro==false){
		cerr<<"\aNo hay notas registradas en esta clave."<<endl;
		return;
	}else{
		for(int i=1;i<=4;i++){
			promedio+=alumno[clave].nota[i];
		}
		promedio/=4;
		cout<<"El promedio de "<<alumno[clave].nombre<<" es: "<<promedio<<" puntos."<<endl;
	}
}

void nota_maxima(){
	system ("Title Sistema de alumnos: nota máxima");
	int max=0, clave, nota;
	cout<<"\tNota máxima"<<endl;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=4;j++){
			if(alumno[i].registro==true){
				if(alumno[i].nota[j]>max){	
					max=alumno[i].nota[j];
					clave=i; nota=j;
				}
			}	
		}
	}
	cout<<alumno[clave].nombre<<" tiene la nota más alta."<<endl;
	cout<<"Su puntuación es: "<<alumno[clave].nota[nota]<<endl;
	cout<<"Su calificación es del bimestre "<<nota<<endl;
}

void nota_minima(){
	system ("Title Sistema de alumnos: nota mínima");
	int min=101, clave, nota;
	cout<<"\tNota mínima"<<endl;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=4;j++){
			if(alumno[i].registro==true){
				if(alumno[i].nota[j]<min){
					min=alumno[i].nota[j];
					clave=i; nota=j;
				}
			}
		}
	}
	cout<<alumno[clave].nombre<<" tiene la nota más baja."<<endl;
	cout<<"Su puntuación es: "<<alumno[clave].nota[nota]<<endl;
	cout<<"Su calificación es del bimestre "<<nota<<endl;
}

void agregar_nota(){
	system ("Title Sistema de alumnos: agregar notas");
	int clave=0;
	cout<<"\tAgregar notas"<<endl;	
	cout<<"Digite la clave del alumno para agregar sus notas (1-5): "; cin>>clave;
	if((clave<1)||(clave>5)){
		cerr<<"\aEl numero ingresado es inválido."<<endl;
	}else if (alumno[clave].registro==true){
		cerr<<"\aPara reemplazar los datos de un alumno primero debe eliminar sus notas."<<endl;
	}else{
		cout<<"Ingrese el nombre del alumno: "; cin.ignore(); cin.getline(alumno[clave].nombre,15,'\n');
		for(int i=1;i<=4;i++){
			do{
				cout<<"\nIngrese la nota del bimestre "<<i<<": "; cin>>alumno[clave].nota[i];
				if((alumno[clave].nota[i]<0)||(alumno[clave].nota[i]>100)){
					cerr<<"\n\aIngresa una calificación valida entre 0 y 100."<<endl; getch();
				}
			}while((alumno[clave].nota[i]<0)||(alumno[clave].nota[i]>100));
		}
		alumno[clave].registro=true;
		cout<<"Los datos han sido registrados con éxito."<<endl;
	}
}

void eliminar_nota(){
	system ("Title Sistema de alumnos: eliminar notas");
	cout<<"\tEliminar notas"<<endl;
	int clave;
	char x;
	cout<<"Digite la clave del alumno para eliminar sus notas (1-5): "; cin>>clave;
	if((clave<1)||(clave>5)){
		cerr<<"\aEl numero ingresado es inválido."<<endl;
	}else if(alumno[clave].registro==false){
		cerr<<"\aNo hay notas registradas en esta clave."<<endl;
	}else{
		cout<<"\nDatos por eliminar"<<endl<<endl;
		cout<<"Nombre del alumno: "<<alumno[clave].nombre<<endl;
		for(int i=1;i<=4;i++){
			cout<<"Nota del bimestre "<<i<<": "<<alumno[clave].nota[i]<<endl;
		}
		do{
			cout<<"Desea eliminar estos datos? (s/n): "; cin>>x;
			if ((x=='s')||(x=='S')){
				for(int i=1;i<=15;i++){
					alumno[clave].nombre[i]=0;
					for(int j=1;j<=4;j++){
						alumno[clave].nota[j]=0;
					}
				}
				alumno[clave].registro=false;
				cout<<"Los datos han sido eliminados con éxito."<<endl;
			}else if ((x=='n')||(x=='N')){
				cout<<"No se eliminarán los datos."<<endl;
			}else{
				cerr<<"\aEl carácter digitado es inválido, intente de nuevo."<<endl;
			}
		}while ((((x!='s')&&(x!='S'))&&(x!='n'))&&(x!='N'));
	}
}
