#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>


// Getch Para Linux - Que difícil achar isso, puta merda.
char getch(){
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}


// Pega um char e marca o tempo que o usuário demorou para clickar.
char get_char(double *final){
    struct timespec start, stop;
    char c;

    clock_gettime(CLOCK_MONOTONIC, &start);
    c = getch();
    clock_gettime(CLOCK_MONOTONIC, &stop);
    *final = 1000.0*stop.tv_sec + 1e-6*stop.tv_nsec - (1000.0*start.tv_sec + 1e-6*start.tv_nsec);

    return c;
}


// Retorno 0        -> Retorno esperado.
// Retorno 1        -> Senha inválida.
// Não faz verificação de senha correta ou incorreta.
// Apenas verifica se a quantidade de characteres correspondem ao informado.
int get_password_time(int lenght, double *pass_time){
    int cont = 0;   
    char c;
    double final;

    while(c != '\n'){
        if(cont <= lenght){      
            c = get_char(&final);
            pass_time[cont] = final;
            printf("\n%c  -->  %lf", c, pass_time[cont]);
            cont++;
        }else{
            printf("\nSenha inválida!\n");
            return 0;
        }
    }
    if(cont != lenght){
        printf("\nSenha inválida!\n");
        return 0;
    }
    return 0;
}


// Faz o registro da maneira que o usuário digita a senha.
void register_password(){
    char password[] = "senhaforte123";
    int cont = 0, response = 0, quantity = 5;
    double pass_time[strlen(password) + 1], *pass_time_ptr = &pass_time[0];
    
    while(cont < quantity){
        response = get_password_time(strlen(password) + 1, pass_time_ptr);       // 1 do Enter
        
        
        if(response == 0){
            // Guardar e fazer a média no perfil do usuário.
        }else{
            printf("\nAlgo de errado não está certo!\n");
            return;
        }
        for(int i = 0; i < strlen(password) + 1; i ++){
            printf("\nTempo da senha: %lf", pass_time[i]);
        }
        cont++;
    }
}


// Armazenará como o usuário digita para posteriormente identificar se é o usuário que está no computador.
void text(){
    char current_c, last_c;
    double final;

    return;
}


void main(){
    double text[126][126];
    
    register_password();
}
