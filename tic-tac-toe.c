#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void menu();
void showTable();
void opcOne();
void opcTwo();
void turno();
void insertData(int fila, int columna, int turno, char mtz[3][3]);
int checkCell(int fila, int columna, char mtz[3][3]);
int Rules(char mtz[3][3], int turno);
int showWinner();
void resetGame(char mtz[3][3], int nTurno);  
//char u2='X';
//char u1='O';

int num;
int nTurno = 1;

char table[3][3] = {{' ',' ',' '},
                    {' ',' ',' '},
                    {' ',' ',' '}};

int main(){

    while(1){
        system("clear");
 
        resetGame(table, nTurno);

        menu();

        scanf(" %i", &num);

        switch(num){
            case 1: //Un jugador
                opcOne();
                break;
            case 2: // Dos jugadores
                opcTwo();
                printf("Nada para mostrar...");
                break;
            case 3:
                printf("[!] Saliendo...");
                exit(0);
                break;
            default:
                printf("Entada no conocida");
                break;
        }
        system("clear");
    }
    return 0;
}


void menu(){

    printf("================================================\n"); 
    printf("============== TIC - TAC - TOE =================\n");
    printf("================================================\n\n");
        
    printf("\t |        |        |        | \n");
    printf("\t |   X    |        |   O    | \n");
    printf("\t |        |        |        |\n");
    printf("\t |--------|--------|--------| \n");
    printf("\t |        |        |        |\n");
    printf("\t |        |   X    |        | \n");
    printf("\t |        |        |        | \n");
    printf("\t |--------|--------|--------| \n");
    printf("\t |        |        |        | \n");
    printf("\t |    O   |   O    |   X    | \n");
    printf("\t |        |        |        | \n\n");

    printf("Selecciona una opcion: \n");
    printf("1. Un jugador \n2. Dos jugadores\n3. Salir\n--> ");
    
}

void showTable(){

    printf("\n\n");
	printf("\t  __________________________\n");
	printf("\t |        |        |        |\n");
	printf("\t |    %c   |    %c   |    %c   |\n",table[0][0],table[0][1],table[0][2]);
	printf("\t |        |        |        |\n");
	printf("\t |--------|--------|--------|\n");
	printf("\t |        |        |        |\n");
	printf("\t |    %c   |    %c   |    %c   |\n",table[1][0],table[1][1],table[1][2]);
	printf("\t |        |        |        |\n");
	printf("\t |--------|--------|--------|\n");
	printf("\t |        |        |        |\n");
	printf("\t |    %c   |    %c   |    %c   |\n",table[2][0],table[2][1],table[2][2]);
	printf("\t |        |        |        |\n");
	printf("\t  --------------------------\n ");

}

void opcOne(){
    system("clear");

    do{
        showTable();

        if (showWinner() == 0 && nTurno > 2){
            getchar();
            break;
        }

        turno();

        system("clear");

    }while(nTurno <= 9);

system("clear");

}



void opcTwo(){
    system("clear"); 
    

    do{
        showTable();
        
        if (showWinner() == 0 && nTurno > 2){
            getchar();
            break;
        }

        turno();

        system("clear");
 
    }while(nTurno <= 9);

    system("clear");
}



void turno(){ //logica para 
   int pfila, pcolumna;
   int fila, columna;
   char u2='X';
   char u1='O';

   if((nTurno % 2) == 0){
       printf("Actual Turno: %i \t\t %c \n",nTurno, u2);
    }else{
        printf("Actual Turno: %i \t\t %c \n",nTurno, u1);
    }

    printf("Fila: ");
    scanf("%i",&fila);

    printf("Columna: ");
    scanf("%i",&columna);
    
    printf("\n"); // Linea que separa la entrada de la siguiente salida


    if(checkCell(fila,columna,table) == 1){
        printf("\n\n[!]Celda ocupada, elije otro campo \n Enter para continuar...\n\n");
        getchar();
        getchar();

    }else if((fila > 3 || fila  < 1) || (columna > 3 || columna  < 1 )){
        printf("\n\n[!] FUERA DE RANGO \n Enter para continuar...");
        getchar();
        getchar();
    }else{
        insertData(fila,columna,nTurno,table);
        nTurno++;
    }
}

void insertData(int fila, int columna, int turno, char mtz[3][3]){

    if((turno % 2) == 0){
        mtz[fila-1][columna-1] = 'X';
    }else{
        mtz[fila-1][columna-1] = 'O';
    }    
}

int checkCell(int fila, int columna, char mtz[3][3]){
    if(mtz[fila-1][columna-1] == 'X' || mtz[fila-1][columna-1] == 'O'){
        return 1;
    }
    return 0;
}

int Rules(char mtz[3][3], int turno){
    if(mtz[0][0] == 'X' && mtz[1][1] == 'X' && mtz[2][2] == 'X'){ //Diagonal principal
        return 0;
    }else if(mtz[0][2] == 'X' && mtz[1][1] == 'X' && mtz[2][0] == 'X'){ //Diagonal pricipal tranpuesta
       return 0;
    } else if(mtz[0][0] == 'X' && mtz[0][1] == 'X' && mtz[0][2] == 'X'){ //horizontal 1
       return 0;
    }else if(mtz[1][0] == 'X' && mtz[1][1] == 'X' && mtz[1][2] == 'X'){ // horizontal 2
       return 0;
    }else if(mtz[2][0] == 'X' && mtz[2][1] == 'X' && mtz[2][2] == 'X'){ // horizontal 3
       return 0;
    }else if(mtz[0][0] == 'X' && mtz[1][0] == 'X' && mtz[2][0] == 'X'){
        return 0;
    }else if(mtz[0][1] == 'X' && mtz[1][1] == 'X' && mtz[2][1] == 'X'){
        return 0;
    }else if(mtz[0][2] == 'X' && mtz[1][2] == 'X' && mtz[2][2] == 'X'){
       return 0;
    }else if((mtz[0][0] == 'O') && (mtz[1][1] == 'O') && (mtz[2][2] == 'O')){ //Diagonal principal
        return 1;
    }else if(mtz[0][2] == 'O' && mtz[1][1] == 'O' && mtz[2][0] == 'O'){ //Diagonal pricipal tranpuesta
        return 1;
    } else if(mtz[0][0] == 'O' && mtz[0][1] == 'O' && mtz[0][2] == 'O'){ // horizontal 1
        return 1;
    }else if(mtz[1][0] == 'O' && mtz[1][1] == 'O' && mtz[1][2] == 'O'){ // horizontal 2
        return 1;
    }else if(mtz[2][0] == 'O' && mtz[2][1] == 'O' && mtz[2][2] == 'O'){ // horizontal 3
        return 1;
    }else if(mtz[0][0] == 'O' && mtz[1][0] == 'O' && mtz[2][0] == 'O'){
        return 1;
    }else if(mtz[0][1] == 'O' && mtz[1][1] == 'O' && mtz[2][1] == 'O'){
        return 1;
    }else if(mtz[0][2] == 'O' && mtz[1][2] == 'O' && mtz[2][2] == 'O'){
        return 1;
    }else if(turno >= 9){
        return 2;
    }
    return 3;
}

int showWinner(){
    if(Rules(table, nTurno) == 0){
        printf("\n");
        printf("\t\t================\n");
        printf("\t\t|    GANO X    |\n");
        printf("\t\t================\n");
        printf("\n");

        printf("[!] Enter para continuar...\n");
        getchar();
        return 0;
       
    }else if(Rules(table, nTurno) == 1){
        printf("\n");
        printf("\t\t================\n");
        printf("\t\t|    GANO O    |\n");
        printf("\t\t================\n");
        printf("\n");

        printf("[!] Enter para continuar...\n");
        getchar();
        return 0;
    
    }else if(Rules(table, nTurno) == 2){
        printf("\n");
        printf("\t\t================\n");             
        printf("\t\t|    EMPATE    |\n");
        printf("\t\t================\n");
        printf("\n");

        printf("\n\n [!] Enter para continuar...\n");
        getchar();
        return 0;
    }
    return 1;
}

void resetGame(char mtz[3][3], int nTurno){
    nTurno = 1;

    for(int i = 0 ; i<3; i++){
        for(int j = 0; j< 3; j++){
            mtz[i][j] = ' ';
        }
    }
}


