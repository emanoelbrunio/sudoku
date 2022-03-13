#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void liberar_matriz (int **S, int n){
    int i;
    for(i = 0; i < n; i++)
        free(S[i]);
    free(S);
}

int **alocar_matriz(int m, int n){
    int **Matriz;
    int i;
 
    Matriz = (int **)malloc(sizeof(int *)*m);
    if(Matriz == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for(i = 0; i < m; i++){
        Matriz[i] = (int *)malloc(sizeof(int)*n);

        if(Matriz[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    return Matriz;
}

int num_rand(){ 
    return rand() % 9;
}

void imprimir(int **S){
    int i, j;
    printf("\n\n    1  2  3    4  5  6    7  8  9\n");
    printf("  ----------------------------------\n");

    for (i = 0; i < 9; i++){
        if (i == 0){
            printf("1 |");
        }
        else if (i == 1){
            printf("2 |");
        }
        else if (i == 2){
            printf("3 |");
        }
        else if (i == 3){
            printf("4 |");
        }
        else if (i == 4){
            printf("5 |");
        }
        else if (i == 5){
            printf("6 |");
        }
        else if (i == 6){
            printf("7 |");
        }
        else if (i == 7){
            printf("8 |");
        }
        else if (i == 8){
            printf("9 |");
        }
        for (j = 0; j < 9; j++){
            printf(" %d ", S[i][j]);
      
            if (j == 2 || j == 5 || j == 8){
             printf(" |");
            }
        }
        

        printf("\n");
        
        if (i == 2 || i == 5){
            printf("  | ");
            printf("- ");
            for (j = 1; j < 9; j++){
                printf(" - ");
                if (j == 2 || j == 5 || j == 8){
                    printf(" |");
                }
            }
        printf("\n");
        }
    }
    printf("  ----------------------------------\n");
}

int ver_linha(int **S, int vet, int i){
    int x, pos_na_linha;

    for (x = 0; x < 9; x++){  
        if (S[i][x] == vet){
            pos_na_linha = 0;
            break;
        }
        else {
            pos_na_linha = 1;
        }
    }
    return pos_na_linha;
}

int ver_col(int **S, int vet, int j){
    int x, pos_na_col;
    for (x = 0; x < 9; x++){

        if (S[x][j] == vet){
            pos_na_col = 0;
            break;
        }

        else {
            pos_na_col = 1;
        }
    }
    return pos_na_col;
}

int ver_quad(int i, int j, int **S, int vet){
    int pos_no_quad;

    if (i >= 0 && i < 3 && j >= 0 && j < 3){
        // a = i && b = j
        for (int a = 0; a < 3; a++){
            
            for (int b = 0; b < 3; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            } 
        }
    }

    else if (i >= 0 && i < 3 && j >= 3 && j < 6){
        // a = i && b = j
        for (int a = 0; a < 3; a++){
            for (int b = 3; b < 6; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            } 
        }   
    }

    else if (i >= 0 && i < 3 && j >= 6 && j < 9){
        // a = i && b = j
        for (int a = 0; a < 3; a++){
            
            for (int b = 6; b < 9; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            }
        }
    }

    else if (i >= 3 && i < 6 && j >= 0 && j < 3){
        // a = i && b = j
        for (int a = 3; a < 6; a++){ 
            for (int b = 0; b < 3; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            }
        }
    }

    else if (i >= 3 && i < 6 && j >= 3 && j < 6){
        // a = i && b = j
        for (int a = 3; a < 6; a++){ 
            for (int b = 3; b < 6; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            }
        }
    }

    else if (i >= 3 && i < 6 && j >= 6 && j < 9){
        // a = i && b = j
        for (int a = 3; a < 6; a++){ 
            for (int b = 6; b < 9; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            }
        }
    }

    else if (i >= 6 && i < 9 && j >= 0 && j < 3){
        // a = i && b = j
        for (int a = 6; a < 9; a++){ 
            for (int b = 0; b < 3; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            }
        } 
    }

    else if (i >= 6 && i < 9 && j >= 3 && j < 6){
        // a = i && b = j
        for (int a = 6; a < 9; a++){ 
            for (int b = 3; b < 6; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            } 
        }    
    }

    else if (i >= 6 && i < 9 && j >= 6 && j < 9){
        // a = i && b = j
        for (int a = 6; a < 9; a++){ 
            for (int b = 6; b < 9; b++){

                if (S[a][b] == vet){
                    pos_no_quad = 0;
                    break;
                } 
                else {
                    pos_no_quad = 1;
                }
            }
            if (pos_no_quad == 0){
                break;
            }
        }
    }

    return pos_no_quad;
}

int ver_elemento_add(int **S, int i, int j){
    int verificacao;

    if (S[i][j] == 0){
        verificacao = 1;
    }
    else if (S[i][j] != 0){
        verificacao = 0;
    }
    return verificacao;
}

int ver_elemento_remove(int **S, int i, int j, int **mat_ini){
    int verificacao;

    if (S[i][j] != 0 && mat_ini[i][j] == 0){
        verificacao = 1;
    }
    else if (S[i][j] == 0 || mat_ini[i][j] != 0){
        verificacao = 0;
    }
    return verificacao;
}

int verificacao(int i, int j, int vet, int **S){
    int resul;
    
    int pos_lin = ver_linha(S, vet, i);
    int pos_col = ver_col(S, vet, j);
    int pos_quad = ver_quad(i, j, S, vet);

    if (pos_col == 1 && pos_lin == 1 && pos_quad == 1){
        resul = 1;
    }
    else {
        resul = 0;
    }
    return resul;
}

void criarjogo (int **S, int **resp){
    
    int i, j, aux1, a, b;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            S[i][j] = 0; 
        }
    }

    for (int i = 0; i < 9; i++){
	    for (int j = 0; j < 9; j++){
	    	S[i][j] = (i*3 + i/3 + j) % (9) + 1;
        }
    }

    for (int mudar = 0; mudar < 39; mudar++){
        do {
            a = rand() % 3;
            b = rand() % 3;
        } while (a == b);

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 3; j++){
                aux1 = S[i][a];
                S[i][a] = S[i][b];
                S[i][b] = aux1;
            }
        }
        do {
            a =  3 + rand() % 3;
            b =  3 + rand() % 3;
        } while (a == b);

        for (int i = 3; i < 6; i++){
            for (int j = 0; j < 9; j++){
                aux1 = S[a][j];
                S[a][j] = S[b][j];
                S[b][j] = aux1;
            }
        }
        
        //

        do {
            a = 3 + rand() % 3;
            b = 3 + rand() % 3;
        } while (a == b);

        for (int i = 0; i < 9; i++){
            for (int j = 3; j < 6; j++){
                aux1 = S[i][a];
                S[i][a] = S[i][b];
                S[i][b] = aux1;
            }
        }
        do {
            a =  6 + rand() % 3;
            b =  6 + rand() % 3;
        } while (a == b);

        for (int i = 6; i < 9; i++){
            for (int j = 0; j < 9; j++){
                aux1 = S[a][j];
                S[a][j] = S[b][j];
                S[b][j] = aux1;
            }
        }
        
        
        //

        do {
            a = 6 + rand() % 3;
            b = 6 + rand() % 3;
        } while (a == b);

        for (int i = 0; i < 9; i++){
            for (int j = 6; j < 9; j++){
                aux1 = S[i][a];
                S[i][a] = S[i][b];
                S[i][b] = aux1;
            }
        }   

        do {
            a =  rand() % 3;
            b =  rand() % 3;
        } while (a == b);

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 9; j++){
                aux1 = S[a][j];
                S[a][j] = S[b][j];
                S[b][j] = aux1;
            }
        }     
        
        
        //
    }

    for (int w = 0; w < 9; w++){
        for(int e = 0; e < 9; e++){
            resp[w][e] = S[w][e];
        }
    }
}

void modo(int **S, int n, int **inicial){
    int v = 81 - n;
    int v_lin, v_col;
   
    for (int i = 0; i < v; i++){
        v_lin = num_rand();
        v_col = num_rand();
        S[v_lin][v_col] = 0;
    }

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            inicial[i][j] = S[i][j];
        }
    }
}

int menu(){
    int resp;
    printf("\n");
    printf("|======================|\n");
    printf("|          MENU        |\n");
    printf("|======================|\n");
    printf("| 1 - Adicionar        |\n");
    printf("| 2 - Apagar           |\n");
    printf("| 3 - Ver resposta     |\n");
    printf("| 4 - Ver jogo inicial |\n");
    printf("| 5 - Sair do jogo     |\n");
    printf("|======================|\n");
    printf("|================|\n");
    printf("| Resposta: ");
    scanf("%d", &resp);
    printf("|================|\n");
    
    return resp;
}

int main(void){
    int **matriz = alocar_matriz(9, 9);
    int **mat_resposta = alocar_matriz(9, 9);
    int **m_inicial = alocar_matriz(9, 9);
    int resposta1;
    int l, c, vendo;
    int ver_elemento;
    int numero_add;
    int verificar_pos;
    int contador = 0;
    
    int resp, resp_dif;
   
    srand (time(NULL));
    
    printf("\n\n");
    printf("|=======================|\n");
    printf("| DESEJA CRIAR UM JOGO? |\n");
    printf("| 1 - Sim               |\n");
    printf("| 2 - Nao               |\n");
    printf("|=======================|\n");
    printf("| Resposta: ");
    scanf("%d", &resp);
    printf("|=======================|\n");
    printf("\n");

    if (resp == 1){
        printf("|======================|\n");
        printf("| Nivel de dificuldade |\n");
        printf("|======================|\n");
        printf("| 1 - Facil            |\n");
        printf("| 2 - Medio            |\n");
        printf("| 3 - Dificil          |\n");
        printf("|======================|\n");
        printf("| Resposta: ");
        scanf("%d", &resp_dif);
        printf("|======================|\n");
    
        if (resp_dif == 1){
            int n = 33;
            criarjogo(matriz, mat_resposta);
            modo(matriz, 33, m_inicial);
            imprimir(matriz);       
        }

        else if (resp_dif == 2){
            criarjogo(matriz,mat_resposta);
            modo(matriz, 30, m_inicial);
            imprimir(matriz);
        }

        else if (resp_dif == 3) {
            int n = 26;
            criarjogo(matriz, mat_resposta);
            modo(matriz, 26, m_inicial);
            imprimir(matriz);
        }

        int resposta;
        do {      
            resposta = menu();

            if (resposta == 1){
                do {
                    do {
                        fflush(stdin);
                        printf("|============================|\n");
                        printf("| DIGITE A LINHA: ");
                        scanf("%d", &l);
                        printf("|============================|\n");
                        printf("|============================|\n");
                        printf("| DIGITE A COLUNA: ");
                        scanf("%d", &c);
                        printf("|============================|\n");
                        
                                                
                        ver_elemento = ver_elemento_add(matriz, l-1, c-1);

                        if (ver_elemento == 0) {
                            printf("|==================================|\n");
                            printf("| JA EXISTE ELEMENTO NESSA POSICAO |\n");
                            printf("|       DIGITE OUTRA POSICAO       |\n");
                            printf("|==================================|\n");

                            printf("|=====================================|\n");
                            printf("|   RESPONDA 0 PARA ADICIONAR OUTRO   |\n");
                            printf("|   RESPONDA 1 PARA VOLTAR AO MENU    |\n");
                            printf("|=====================================|\n\n");
                            scanf("%d", &vendo);

                            if (vendo == 0){
                                ver_elemento = 0;
                            }
                            else {
                                ver_elemento = 10;
                            }
                        }
                        
                    } while (ver_elemento == 0);
                    
                    if (ver_elemento == 10) {
                        break;
                    }


                    do {
                        printf("|================================|\n");
                        printf("| DIGITE UM NUMERO DE 1 A 9: ");
                        scanf("%d", &numero_add);
                        printf("|================================|\n");

                        if (numero_add > 9 || numero_add < 1) {
                            printf("|==================================|\n");
                            printf("|         NUMERO INVALIDO          |\n");
                            printf("|       DIGITE OUTRO NUMERO        |\n");
                            printf("|==================================|\n");
                        }

                    } while(numero_add > 9 || numero_add < 1);
 
                    verificar_pos = verificacao(l-1, c-1, numero_add, matriz);
                    
                    if (verificar_pos == 1){
                        matriz[l-1][c-1] = numero_add;
                        printf("|==================================|\n");
                        printf("|        COLOCADO COM SUCESSO      |\n");
                        printf("|==================================|\n");
                        break;
                    }

                    else if (verificar_pos != 1){
                        printf("|=======================================|\n");
                        printf("| VOCE NAO PODE ADICIONAR NESSA POSICAO |\n");
                        printf("|             TENTE NOVAMENTE           |\n");
                        printf("|=======================================|\n\n");

                        printf("|=====================================|\n");
                        printf("|   RESPONDA 0 PARA ADICIONAR OUTRO   |\n");
                        printf("|   RESPONDA 1 PARA VOLTAR AO MENU    |\n");
                        printf("|=====================================|\n\n");
                        scanf("%d", &vendo);
                    }
                    if (vendo == 0){
                        verificar_pos = 0;
                    }
                    else {
                        verificar_pos = 1;
                    }

                } while (verificar_pos != 1);

                contador = 0;
                for(int y = 0; y < 9; y++){
                    for(int q = 0; q < 9; q++){
                        if(matriz[y][q] != 0){
                            contador = contador + 1;
                        }
                    }
                }
                if (contador == 81){
                    printf("\n\n|=====================================|\n");
                    printf("|  PARABENS, VOCE CONSEGUIU RESOLVER  |\n");
                    printf("|       VOCE EH O BICHAO MERMU! :O    |\n");
                    printf("|=====================================|\n\n");
                    return 0;
                }

                imprimir(matriz);
            }

            if (resposta == 2){
                
                do {
                    fflush(stdin);
                    printf("|============================|\n");
                    printf("| DIGITE A LINHA: ");
                    scanf("%d", &l);
                    printf("|============================|\n");
                    printf("|============================|\n");
                    printf("| DIGITE A COLUNA: ");
                    scanf("%d", &c);
                    printf("|============================|\n");
                    
                                            
                    ver_elemento = ver_elemento_remove(matriz, l-1, c-1, m_inicial);

                    if (ver_elemento == 0) {
                        printf("|=====================================|\n");
                        printf("|   NAO PODE REMOVER ESSE ELEMENTO    |\n");
                        printf("|          OU ELE NAO EXISTE          |\n");
                        printf("|         DIGITE OUTRA POSICAO        |\n");
                        printf("|=====================================|\n\n");

                        printf("|=====================================|\n");
                        printf("|    RESPONDA 0 PARA REMOVER OUTRO    |\n");
                        printf("|   RESPONDA 1 PARA VOLTAR AO MENU    |\n");
                        printf("|=====================================|\n\n");
                        scanf("%d", &ver_elemento);
                       
                    }
                    else {
                        matriz[l-1][c-1] = 0;
                    }
                    
                } while (ver_elemento == 0);
                imprimir(matriz);
            }
            
            if (resposta == 5){
                printf("|=====================================|\n");
                printf("|          JOGO FINALIZADO :)         |\n");
                printf("|         OBRIGADO POR JOGAR!         |\n");
                printf("|=====================================|\n");
                break;
            }
            
            if (resposta == 3){
                printf("\n|====================================|\n");
                printf("|               RESPOSTA             |");
                imprimir(mat_resposta);
                printf("|====================================|\n");
            }

            if (resposta == 4){
                printf("\n|====================================|\n");
                printf("|           MATRIZ INICIAL           |");
                imprimir(m_inicial);
                printf("|====================================|\n");
            }

        } while (resposta < 6);
        
    }
    
    else if (resp == 2) {
        printf("|=====================================|\n");
        printf("|      Vamos encerrar o programa :(   |\n");
        printf("|=====================================|\n");
    }
    
    liberar_matriz(matriz, 9);

    return 0;
}