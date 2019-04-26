#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

bool NumeroPerfecto(int);
string NumeroPerfectoString(int);
int Captcha(string);
int CaptchaMitad(string);

int main ()
{
	int respuesta=1;
	while(respuesta==1)
	{	
		int opcion=0;
	cout<<" "<<endl;
	cout<<"Ingrese la funcion que desea:"<<endl;
	cout<<"1. Captcha:"<<endl;
	cout<<"2. Numeros perfectos"<<endl;
	cout<<"3. Permutaciones posibles"<<endl;
	cin>> opcion;
	while(opcion<0 || opcion>4)
	{
		cout<<"Opcion no valida, ingrese una opcion valida"<<endl;
		cin>>opcion;
	}
	string numero="";
	int opcion2=0;
	int perfecto=0;
	string digitos="";
	bool bandera=false;
	switch(opcion)
	{
		case 1: 	
			cout<<"Ingrese la cadena de numeros"<<endl;
			cin>>numero;
			while(numero.length()%2!=0)
			{
				cout<<"Debe ingresar una cadena distinta: "<<endl;
				cin>>numero;
			}
			cout<<"1. Todos los digitos"<<endl;
			cout<<"2. Suma desde la mitad"<<endl;
			cin>>opcion2;
			while(opcion2<1 || opcion2>2)
			{
				cout<<"Debe ingresar una opcion valida"<<endl;
				cin>>opcion2;
			}
			if(opcion2==1)
			{
				cout<<"El resultado es: "<<Captcha(numero)<<endl;;	
			}
			if (opcion2==2)
			{
				cout<<"El resultado es: "<<CaptchaMitad(numero)<<endl;
			}
			break;
		case 2: 
			cout<<"Ingrese el numero que desea saber si es perfecto:"<<endl;
			cin>>perfecto;
			if(NumeroPerfecto(perfecto))
			{
				cout<<"El numero si es perfecto"<<endl;
				cout<<"Los factores son " << NumeroPerfectoString(perfecto)<<endl;	
			}
			else
			{
				while(bandera==false)
				{
					if (perfecto==1)
					{
						cout<<"No hay numeros perfectos menores al numero ingresado"<<endl;
						bandera=true;
					}
					else
					{
						perfecto=perfecto-1;
						bandera=NumeroPerfecto(perfecto);
					}
				
					if(bandera==true && perfecto>1)
					{	
						cout<<"El numero ingresado no es perfecto"<<endl;
						cout<<"El numero perfecto mas cercano es "<<perfecto<<endl;
						cout<<NumeroPerfectoString(perfecto)<<endl;
					}
				}

			}
			break;
		case 3:

			break;
	}
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<"¿Desea repetir el programa? 1: Si ; 2:No"<<endl;
	cin>>respuesta;
	}
 return 0;
}



int Captcha(string numero)
{
	int total=0;
	int j=0;
	int inicio_int=0;
	for(int i=0; i<numero.length();i++)
	{
		j=i+1;
		inicio_int=numero[i]-48;
		if(j==numero.length())
		{
			j=0;
		}

		if(inicio_int==numero[j]-48)
		{
			total=total+inicio_int;	
		}	
	}
	return total;

}

int CaptchaMitad(string numero)
{
        int total=0;
        int j=numero.length()/2;
        int inicio_int=0;
        for(int i=0; i<numero.length();i++)
        {
                inicio_int=numero[i]-48;
                if(j==numero.length()+1)
                {
                        j=0;
                }

                if(inicio_int==numero[j]-48)
                {
                        total=total+inicio_int;
                }
		j=j+1;
        }
        return total*2;

}


bool NumeroPerfecto (int numero)
{
	int acumulador=0;
	for(int i=1;i<=numero/2;i++)
	{
		if(numero%i==0)
		{	
			acumulador=acumulador+i;
		}

	}
	if (acumulador==numero)
	{
		return true;
	}
	else
	{
		return false;	
	}
}

string NumeroPerfectoString(int numero)
{
	stringstream acumulador;
	for(int i=1;i<=numero/2;i++)
	{
		if (numero%i==0 && i!=numero/2)
		{	
            		 acumulador <<i <<"-";
		}
		if (i==numero/2)
		{
			acumulador<<i;
		}
        }
        return acumulador.str();
}

