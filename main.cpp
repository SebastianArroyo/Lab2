#include <iostream>
#include "p7.h"
#include <stdlib.h>
#include <algorithm>
using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void fun(char cadena1[],char cadena2[]);
void funcion(int numer, char palabra[]);
bool estr(float ,float, float, float, float);
void corte(int x,int y, int a, int l, int x1, int y1, int a1, int l1);
void imprimir_matriz(int mat[5][5]);
void fun_c(double *a, int n, double *promedio, double *suma);

int main()

{
    int sel1=0,sel2=0,sel3=0, sel4=0,num=0,cantidad=0;
    while (true) {
        cout <<"Ingrese: 1=ejercicios y 2=problemas : ";
        cin >> sel1;
        switch (sel1) {
        case 1:
            cout << "Ingrese el numero del ejercicio a ejecutar: ";
            cin >> sel2;
            switch(sel2){
            case 1:
            {
                int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
                fun_b(array, 10);
                cout << "1. La direccion de memoria de 'array' es " << &array << " y se dedican 4 bytes por cada elemento" << endl; //0x5ce100
                cout << "2. La direccion de memoria de 'array[3]' es " << &array[3] << " y tiene un valor de " << array[3] << endl; //0x5ce10c
                cout << "3. El efecto que tiene la funcion 'fun_b' es que cambia los valores del array." << endl;
                cout << "Cambia el valor en la primera direccion de memoria con la ultima del array." << endl;
                cout << "Por ejemplo: 0 con el 9, 9 con el 0 y asi con los demas." << endl;
            }

            case 2:
            {
                double a[]={0,1,2,3,4,5,6,7,8,9}, promedio=0, suma=0;
                int n=10;
                fun_c(a,n,&promedio,&suma);
                break;
            }
            case 3:
            {
                unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};
                cout << "La direccion de b[0][0] es: "<< &b[0][0] << endl;
                cout << "La direccion de b[0][1] es: "<< &b[0][1] << endl;
                cout << "La direccion de b[1][0] es: "<< &b[1][0] << endl;
                cout << "La direccion de b[1][1] es: "<< &b[1][1] << endl;
                cout << "La direccion de b[2][0] es: "<< &b[2][0] << endl;
                cout << "La direccion de b[2][1] es: "<< &b[2][1] << endl;
                cout << "La direccion de b[3][0] es: "<< &b[3][0] << endl;
                cout << "La direccion de b[3][1] es: "<< &b[3][1] << endl;

                cout << "El valor de b es: " << *b <<  endl;
                cout << "El valor de b+2 es: " << *b+2 << endl;
                cout << "El valor de *(b+2) es: " << *(b+2) << endl;
                cout << "El valor de *(b+2)+1 es: " << *(b+2)+1 << endl;
                cout << "El valor de *(*(b+2)+1) es: " << *(*(b+2)+1) << endl;
                cout << "El valor de b[3][1] es: " << b[3][1] << endl;
                cout << "El valor de *b++ es: " << *b+1 << endl;
            }
            break;

            case 4:
            {
                cout << "Ingrese el numero del caso a ejecutar: ";
                cin >> sel4;
                switch(sel4){
                case 1:
                {
                    int (*ptr)[2];
                    int a[2][2] = {1000, 2000, 3000};
                    ptr = a;
                    cout << "Para el caso 1:" << endl;
                    cout << "El valor de **ptr es: " << **ptr << endl;
                    cout << "El valor de **(ptr+1) es: " << **(ptr+1) << endl;
                }
                break;
                case 2:
                {
                    int (*ptr)[2];
                    int a[2][2] = {{1000}, {2000, 3000}};
                    ptr = a;
                    cout << "Para el caso 2:" << endl;
                    cout << "El valor de **ptr es: " << **ptr << endl;
                    cout << "El valor de **(ptr+1) es: " << **(ptr+1) << endl;
                }
                break;

                default:
                    cout << "Este caso no esta definido." << endl;
                break;
                }
            }
            break;

            default:
                cout << "Este ejercicio no esta definido." << endl;
            break;
            }
        break;

        case 2:
            cout << "Ingrese el numero del problema a ejecutar: ";
            cin >> sel3;
            switch(sel3){
            case 1:
            {
                int billetes[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};
                cout << "Ingrese un valor: ", cin >> num;
                for (int i=0;i<=10;i++) {
                    if (i==10) {
                        cout << "Faltante: " << num << endl;
                        break;
                    }
                    cantidad=num/billetes[i];
                    cout << billetes[i] << ": " << cantidad << endl;
                    num=num-(cantidad*billetes[i]);
                }
            }
            break;

            case 2:
            {
                int dim=0;
                char cadena[200], B;
                for(int j=0;j<200;j++){
                    cadena[j]=rand() %26 + 65;
                    cout << cadena[j];
                }
                cout << endl;
                for(int i=0; i<200;i++){
                    B=cadena[i];
                    for(int j=0;j<200;j++){
                        if(B==cadena[j]){
                            dim+=1;
                            cadena[j]='*';
                        }
                    }
                    if(B!='*'){
                    cout <<B<<": "<<dim<<endl;
                    }
                    dim=0;
                }
            }
            break ;

            case 3:
            {
                char cad1[999]="",cad2[999]="";
                cout << "Ingrese la primera cadena de caracteres (sin espacios): "; cin >> cad1;
                cout << "Ingrese la segunda cadena de caracteres (sin espacios): "; cin >> cad2;
                fun(cad1,cad2);
            }
            break;

            case 4:
            {
                char a[100];
                int num;
                cout << "Ingrese los caracteres" << endl;
                cin>>a;
                num = atoi(a);
                cout<<num<<endl;
            }
            break ;

            case 5:
            {
                int nument=0;
                char pal[]="";
                cout << "Ingrese un numero entero: "; cin >> nument;
                funcion(nument,pal);
                cout << "'" << pal << "'" << endl;
            }
            break;

            case 6:
            {
                char cadena[100];
                cout<<"Ingrese una cadena de caracteres: "<<endl;
                cin>>cadena;
                for(int i=0;cadena[i]!='\0';i++){
                    if(cadena[i]>=97 && cadena[i]<=122){
                        cout<<char(cadena[i]-32);
                    }
                    else{cout<<cadena[i];}
                }
                cout<<endl;
            }
            break;

            case 7:
            {
                {
                    int dim=0;
                    char *cad = new char[dim+1];
                    cout << "Ingrese la cadena de caracteres: ";
                    cad[dim]='\0';
                    fflush(stdin);
                    gets(cad);
                    elim_rep(cad,dim);
                    delete[] cad;
//                    return 0;
                }
            }
            break;

            case 8:
            {
                char cadena[100];
                int t=0, n=0, n2=0, contnum=0, context=0;
                cout<<"Cuantos caracteres tiene la cadena?: ";
                cin>>n2;
                cout<<"Ingrese la cadena de letras y numeros: ";
                cin>>cadena;
                for(int i=0;i<=n2;i++){
                    if((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]>=97 && cadena[i]<=122)){
                        context+=1;
                    }
                    else if(cadena[i]>=48 && cadena[i]<=57){
                        contnum+=1;
                    }
                }
                char num[contnum], texto[context];
                for(int i=0;i<n2;i++){
                    if(n<=contnum){
                        if(cadena[i]>=48 && cadena[i]<=57){
                        num[n]=cadena[i];
                        n++;
                        }
                    }
                }
                for(int i=0;i<n2;i++){
                    if(t<=context){
                        if((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]>=97 && cadena[i]<=122)){
                        texto[t]=cadena[i];
                        t++;
                        }
                    }
                }
                cout<<"Original: "<<cadena<<endl;
                cout<<"Texto: "<<texto<<endl;
                cout<<"Numero: "<<num<<endl;
            }
            break;

            case 9:
            {
                int n=0,nu=0,i=0,mul=1,lar=0,tot=0,Ttot=0;
                char cade[99]="";
                cout << "Ingrese la cadena: "; cin >> cade;
                cout << "Ingrese n: "; cin >> n;
                while (cade[lar]!='\0') lar++;
                lar--;
                for (;lar>=0;) {
                    for (;i<n ;i++) {
                        if (lar==-1) {
                            break;
                        }
                        nu=int(cade[lar]-48);
                        tot=tot+(nu*mul);
                        lar--;
                        mul*=10;
                    }
                    i=0;
                    mul=1;
                    Ttot+=tot;
                    tot=0;
                }
                cout << "Original: " << cade << endl;
                cout << "Suma: " << Ttot << endl;
            }
            break;


            case 10:
            {
                int pos1=0, tam;
                cout<<"Ingrese el tamanio del numero romano: ";
                cin>>tam;
                char *rom=new char[30];
                cout<<"Ingrese numero romano : ";
                fflush(stdin);
                gets(rom);
                while(true){

                    if(rom[pos1]==rom[pos1+1]&&rom[pos1]==rom[pos1+2]&&rom[pos1]==rom[pos1+3]){
                     cout <<"numero incorrecto, ingrese uno nuevo"<< endl;
                        }
                    else{break;}
                }
                int  rint [tam];
                int Arabigo=0;
                int aux=0;


                for(int i=0;i<tam;i++){ //ciclo que cambia las denominaciones de las letras por su denominacion en arabigo
                    if(rom[i]=='M'){
                        rint[i]=1000;}
                    else if(rom[i]=='D'){
                        rint[i]=500;}
                    else if(rom[i]=='C'){
                        rint[i]=100;}
                    else if(rom[i]=='L'){
                        rint[i]=50;}
                    else if(rom[i]=='X'){
                        rint[i]=10;}
                    else if(rom[i]=='V'){
                        rint[i]=5;}
                    else if(rom[i]=='I'){
                        rint[i]=1;}
                }

                if (tam==1){Arabigo=rint[0];}

                while(pos1<tam){
                    if(tam>1){
                        if(rint[pos1]==rint[pos1+1]&&rint[pos1]==rint[pos1+2]){
                            aux=rint[pos1]+rint[pos1+1]+rint[pos1+2];
                            Arabigo+=aux;
                            pos1+=3;}
                        else{

                        if(rint[pos1]>=rint[pos1+1]){
                            aux=rint[pos1]+rint[pos1+1];
                            Arabigo+=aux;
                            pos1+=2;}

                        else if(rint[pos1]<rint[pos1+1]){
                            aux=rint[pos1+1]-rint[pos1];
                            Arabigo+=aux;

                            pos1+=2;}
                        }
                }
                }
                cout << rom <<" es en arabigo: "<<Arabigo <<endl;
            }
            break;

            case 11:
            {
                char tab[16][21]={{'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','-','+','+','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','-'},
                                  {'x','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','-'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','-'},
                                  {'x','-','+','+','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','-'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','-','+','+','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','-'},
                                  {'x','-','+','-','+','+','+','-','+','+','+','-','+','+','+','-','+','+','+','-','-'}};

                while (true) {
                    int opc=0;
                    char k=' ',let;
                    cout << "Desea 1=reservar ; 2=cancelar:"; cin >> opc;
                    cout << endl;
                    switch (opc) {
                    case 1:
                    {
                        cout << "Asientos libres (-)." << endl;
                        cout << "Asientos ocupados (+)." << endl;
                        cout << endl;
                        int fil=0, col=0,contador=1,letra=64;
                        bool ban=false;
                        while (ban==false) {
                            for (fil=0;fil<16;fil++,letra++) {
                                for (col=0;col<21;col++,contador++) {
                                    if (fil==0 && col==0) {
                                        cout << "x";
                                        cout << "  ";
                                    }
                                    if (fil==0 && col<20) {
                                        cout << '|' << contador;
                                    }
                                    if (fil>0 && col==0) {
                                        cout << char(letra);
                                    }
                                    if (fil>0 && col>0) {
                                        cout << '|' << tab[fil][col];
                                    }
                                    if (col>9 && fil>0) {
                                        cout << k;
                                    }
                                    cout << k << k;
                                }
                                cout << endl;
                            }
                            cout << endl;
                            cout << "Ingrese letra: "; cin >> let;
                            if (int(let)>90) fil=int(let)-96;
                            if (int(let)<=90)fil=int(let)-64;
                            cout << "Ingrese numero: "; cin >> col;
                            if (fil<=0 || col<=0 || fil>=16 || col>=21) {
                                cout << "Debe ingresar un valor correcto." << endl;
                            }
                            if (tab[fil][col]=='+') {
                                cout << "Ese lugar ya esta ocupado." << endl;
                            }
                            if (tab[fil][col]=='-') {
                                tab[fil][col]='+';
                                ban=true;
                                cout << "Reservado exitosamente!" << endl;
                            }
                            fil=0, col=0,contador=1,letra=64;
                        }
                    }
                    break;

                    case 2:
                    {
                        cout << "Asientos libres (-)." << endl;
                        cout << "Asientos ocupados (+)." << endl;
                        cout << endl;
                        int fil=0, col=0,contador=1,letra=64;
                        bool ban=false;
                        while (ban==false) {
                            for (fil=0;fil<16;fil++,letra++) {
                                for (col=0;col<21;col++,contador++) {
                                    if (fil==0 && col==0) {
                                        cout << "x";
                                        cout << "  ";
                                    }
                                    if (fil==0 && col<20) {
                                        cout << '|' << contador;
                                    }
                                    if (fil>0 && col==0) {
                                        cout << char(letra);
                                    }
                                    if (fil>0 && col>0) {
                                        cout << '|' << tab[fil][col];
                                    }
                                    if (col>9 && fil>0) {
                                        cout << k;
                                    }
                                    cout << k << k;
                                }
                                cout << endl;
                            }
                            cout << endl;
                            cout << "Ingrese letra: "; cin >> let;
                            if (int(let)>90) fil=int(let)-96;
                            if (int(let)<=90)fil=int(let)-64;
                            cout << "Ingrese numero: "; cin >> col;
                            if (fil<=0 || col<=0 || fil>=16 || col>=21) {
                                cout << "Debe ingresar un valor correcto." << endl;
                            }
                            if (tab[fil][col]=='-') {
                                cout << "Ese lugar sigue disponible." << endl;
                            }
                            if (tab[fil][col]=='+') {
                                tab[fil][col]='-';
                                ban=true;
                                cout << "Cancelado exitosamente!" << endl;
                            }
                            fil=0, col=0,contador=1,letra=64;
                        }
                    }
                    break;

                    default:
                        cout << "Debe ingresar 1 o 2.";
                    break;
                    }
                }
            }
            break;

            case 12:
            {
                int fil,col;
                    int n,sum=0,diagonal1=0,diagonal2=0,fila=0,columna=0,sumfila=0,sumcolumna=0,sumdiagonal1=0,sumdiagonal2=0;
                    bool flag=true;
                    cout << "Ingrese el tamanio de la matriz cuadrada: "; cin >> fil;
                    col=fil;
                    int ** cuadra;
                    cuadra = new int *[fil];

                    for(int i=0;i<col;i++){
                        cuadra[i]= new int[col];
                    }
                    for(int i=0;i<fil;i++)
                    {
                        for(int j=0;j<col;j++)
                        {
                            cout<<"Ingrese elemento en la posicion ["<<i+1<<"]"<<"["<<j+1<<"]"<< endl;
                            cin >> n;
                            *(*(cuadra+i)+j)=n;
                        }
                    }
                    for(int i = 0; i <fil ; i++)
                    {
                        for(int j = 0; j < fil; j++)
                        {
                            if(*(*(cuadra + i) + j) < 10)
                                cout<<" "<<*(*(cuadra + i) + j)<<" ";
                            else
                                cout<<*(*(cuadra + i) + j)<<" ";
                        }
                        cout<<endl;
                    }
                    while (flag==true){
                        for(int i=0;i<fil;i++){
                            diagonal1=*(*(cuadra+i)+i);
                            sumdiagonal1+= diagonal1;
                        }
                        for(int i=0;i<fil;i++){
                            diagonal2=*(*(cuadra+(fil-1-i))+i);
                            sumdiagonal2+= diagonal2;
                        }
                        if (sumdiagonal1!=sumdiagonal2){
                           flag=false;
                           break;
                        }
                        else {
                            for(int j=0;j<fil;j++){
                                    fila=cuadra[0][j];
                                    columna=cuadra[j][0];
                                    sumfila+=fila;
                                    sumcolumna+=columna;
                            }
                        }
                        for(int i=0;i<fil;i++){
                            sum=0;
                            for (int j=0;j<fil;j++){
                                sum+=cuadra[i][j];
                            }
                            if(sum!=sumdiagonal1){
                                flag=false;
                                break;
                            }
                        }
                        for(int i=0;i<fil;i++){
                            sum=0;
                            for (int j=0;j<fil;j++){
                                sum+=cuadra[j][i];
                            }
                            if(sum!=sumcolumna){
                                flag=false;
                                break;
                            }
                        }
                        if (flag==true){
                            cout << "La matriz es un cuadradado magico" << endl;
                            flag=false;
                        }
                    }
                    if (sumcolumna != sumfila || sumdiagonal1 != sumdiagonal2){
                        cout << "La matriz no es un cuadradado magico" << endl;
                    }
                    for (int i = 0; i < fil; i++){
                       delete [] cuadra[i];
                    }
                    delete [] cuadra;
            }
            break;

            case 13:
            {
                cout << endl;
                int fil=1,col=1,estre=0;
                bool ban;
                float arre[6][8]={{0,3,4,0,0,0,6,8},
                                  {5,13,6,0,0,0,2,3},
                                  {2,6,2,7,3,0,10,0},
                                  {0,0,4,15,4,1,6,0},
                                  {0,0,7,12,6,9,10,4},
                                  {5,0,6,10,6,4,8,0}};
                for (fil=1;fil<5;fil++) {
                    for (col=1;col<7;col++) {
                        ban=estr(*(*(arre+fil)+col),*(*(arre+(fil-1))+col),*(*(arre+(fil+1))+col),*(*(arre+fil)+(col-1)),*(*(arre+fil)+(col+1)));
                        if (ban==true) {
                            estre++;
                        }
                    }
                }
                cout << "Las posibles estrellas que pueden existir son: " << estre << endl;
                cout << endl;
            }
            break;

            case 14:
            {
                cout<<"Matriz original"<<endl;
                int original[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
                imprimir_matriz(original);

                int matriz[5][5], col=4;
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        matriz[j][col]=original[i][j];
                    }
                    cout<<endl;
                    col-=1;
                }
                cout<<"Matriz 90 grados"<<endl;
                imprimir_matriz(matriz);
                col=4;
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        original[j][col]=matriz[i][j];
                    }
                    cout<<endl;
                    col-=1;
                }
                cout<<"Matriz 180 grados"<<endl;
                imprimir_matriz(original);
                col=4;
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        matriz[j][col]=original[i][j];
                    }
                    cout<<endl;
                    col-=1;
                }
                cout<<"Matriz 270 grados"<<endl;
                imprimir_matriz(matriz);
                cout<<endl;
            }
            break;

            case 15:
            {
                int a[4]={}, b[4]={};

                cout <<"Ingrese la posicion x del primer rectangulo: ";
                cin >>a[0];
                cout <<"Ingrese la posicion y del primer rectangulo: ";
                cin >>a[1];
                cout <<"Ingrese el ancho del primer rectangulo: ";
                cin >>a[2];
                cout <<"Ingrese el largo del primer rectangulo: ";
                cin >>a[3];
                cout <<"Ingrese la posicion x del segundo rectangulo: ";
                cin >>b[0];
                cout <<"Ingrese la posicion y del segundo rectangulo: ";
                cin >>b[1];
                cout <<"Ingrese el ancho del segundo rectangulo: ";
                cin >>b[2];
                cout <<"Ingrese el largo del segundo rectangulo: ";
                cin >>b[3];

                if (a[0]<=b[0]){
                    corte(a[0],a[1],a[2],a[3],b[0],b[1],b[2],b[3]);
                }
                else if (a[0]>=b[0]){
                    corte(b[0],b[1],b[2],b[3],a[0],a[1],a[2],a[3]);
                }
            }
            break;

            case 16:
            {
                int n;
                long long int factorial=1, cam, A;
                cout << "Ingrese  el tamanio de la matriz" << endl;
                cin>>n;

                for(int i=1;i<=n;i++){
                    factorial=factorial*i;
                }
                A=factorial;
                factorial=1;
                for(int i=1;i<=(n*2);i++){
                    factorial=factorial*i;
                }
                cam=factorial/(A*A);
                cout<<"Para una matriz de "<<n<<" x "<<n<<" hay "<<cam<<" caminos"<<endl;
            }
            break;

            case 17:
            {
                int valor=1,i=1,cn1=0,cn2=0,en,sum=0,cparr=0,j=0;
                int esamig[99999]={};
                bool banda;
                cout << "Ingrese un valor: "; cin >> en;
                    for (;valor<en;valor++) {
                        banda=true;
                        for (j=0;esamig[j]!='\0';j++) {
                            if (esamig[j]==valor) banda=false;
                        }
                        if (banda==true) {
                            for (i=1,cn1=0;i<=(valor/2);i++) {
                                if (valor%i==0) {
                                    cn1+=i; //cn va a ser el numero que valide
                                }
                            }
                            for (i=1,cn2=0;i<=(cn1/2);i++) {
                                if (cn1%i==0) {
                                    cn2+=i;
                                }
                            }
                            if (valor==cn2) {
                                cout << cn2 << " es amigable con " << cn1 << endl;
                                if (cn1==cn2) {
                                    esamig[cparr]=cn2;
                                    cparr++;
                                    sum=sum+cn2;
                                }
                                else if (cn1!=cn2) {
                                    esamig[cparr]=cn2;
                                    cparr++;
                                    esamig[cparr]=cn1;
                                    cparr++;
                                    sum=sum+cn1+cn2;
                                }
                            }
                        }
                    }
                    cout << "El resultado de la suma es: " << sum << endl;
            }
            break;

            case 18:
            {
                int cadena[] = {0,1,2,3,4,5,6,7,8,9}, n;
                cout << "Ingrese el numero de la permutacion: " << endl;
                cin >> n;

                for(int i=1;i<n;i++){
                    next_permutation(cadena,cadena+10);
                }
                cout<<"La permutacion numero: "<<n<<" es ";
                for(int i=0;i<=9;i++){
                    cout << cadena[i];
                    }
                cout<<endl;
            }
            break;

            default:
                cout << "Este ejercicio no esta definido." << endl;
            break;
            }
        break;

        default:
            cout << "Escriba 1 o 2." << endl;
        break;
        }
    }
    return 0;
}

void imprimir_matriz(int mat[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(1<=mat[i][j] && mat[i][j]<=9){
                cout<<mat[i][j]<<"  ";
            }else{
            cout<<mat[i][j]<<" ";}
        }
        cout<<endl;
    }
}


void fun_a(int *px, int *py){
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

void fun_b(int a[], int tam){
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--)
        fun_a(&b[f], &b[l]);
}

//corección ejercicio2
void fun_c(double *a, int n, double *promedio, double *suma){

    *suma=0.0;
    for (int i=0; i<n;i++)
        *suma += *(a+i);
    *promedio=*suma/n;
    cout<<*promedio<<endl;
}
void fun(char cadena1[],char cadena2[]){ //Problema 3
    int largo1=0,largo2=0,i=0;
    bool bandera=true;
    while (cadena1[largo1]!='\0') largo1++;
    while (cadena2[largo2]!='\0') largo2++;
    if (largo1!=largo2) {
        bandera=false;
    }
    else if (largo1==largo2) {
        for (;i<=largo1;i++){
            if (cadena1[i]!=cadena2[i]) {
                bandera=false;
            }
            else if (cadena1[i]==cadena2[i]){
                bandera=true;
            }
            if (bandera==false){
                break;
            }
        }
    }
    if (bandera==true){
        cout << "Verdadero." << endl;
    }
    else {
        cout << "Falso." << endl;
    }
}
void funcion(int numer,char palabra[]){ //Problema 5
    int i=0,canum,mul=1,cifras=0,orig=0;
    orig=numer;
    while (numer!=0) {
        numer/=10;
        cifras++;
        mul*=10;
    }
    mul/=10;
    for (;i<cifras;i++,mul/=10) {
        canum=orig/mul;
        palabra[i]=char(canum+48);
        orig=orig-(canum*mul);
    }
}
bool estr(float centro, float up, float down, float iz, float der) { //Problema 13
    float total=0;
    total=centro+up+down+iz+der;
    if (total/5>6) {
        return true;
    }
}
void corte(int x,int y, int a, int l, int x1, int y1, int a1, int l1){ //Problema 15
    int xp,yp,ap,lp,px,py,px1,py1;
    px=x+a;
    py=y+l;
    px1=x1+a1;
    py1=y1+l1;
    if (x<=x1){
        if (y<=y1) {
            xp=x1;
            yp=y1;
            ap=abs(px1-(px1-px)-(x1-x)-x);
            lp=abs(py1-(py1-py)-(y1-y)-y);
            cout <<"La interseccion es: {"<< xp << ","<< yp << ","<< ap << ","<< lp <<"}"<<endl;
        }
        if (y>=y1) {
            xp=px-(px-x1);
            yp=py1-(py1-y);
            ap=px-x1;
            lp=py1-y;
            cout <<"La interseccion es: {"<< xp << ","<< yp << ","<< ap << ","<< lp <<"}"<<endl;
        }
     }
}
