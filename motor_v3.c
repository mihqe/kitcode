#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define DORMIR(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define DORMIR(ms) usleep((ms) * 1000)
#endif

typedef struct { char n[50]; double v; } Var;
Var mem[5000]; int total_vars = 0;
double vetores[100][100];
char linhas[3000][500]; int total_linhas = 0, ip = 0;
int loop_inicio[100], loop_conta[100], lvl_loop = 0;

// Lista de comandos oficiais da sua linguagem para o corretor saber o que existe
char *comandos_oficiais[] = {"diga", "limpar", "cor", "ir", "janela", "repetir", "fim", "pot", "lista", "pega_lista", "espera", "esconde", "mostra"};
int num_comandos = 13;

void set_n(char *n, double v) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) { mem[i].v=v; return; }
    strcpy(mem[total_vars].n, n); mem[total_vars].v=v; total_vars++;
}
double get_n(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return mem[i].v;
    return atof(n);
}

// O CÉREBRO DO CORRETOR AUTOMÁTICO
void corretor_ortografico(char *digitado) {
    if(strlen(digitado) < 2) return; // Ignora se for só uma letra
    
    printf("\033[1;31m[ERRO]\033[0m Comando '%s' desconhecido.\n", digitado);
    
    for(int i=0; i<num_comandos; i++) {
        // Se as duas primeiras letras baterem, ele sugere o comando!
        if(strncmp(digitado, comandos_oficiais[i], 2) == 0) {
            printf("\033[1;33m[DICA]\033[0m Voce quis dizer '\033[1;32m%s\033[0m'?\n", comandos_oficiais[i]);
            return;
        }
    }
    printf("\033[1;33m[DICA]\033[0m Verifique a ortografia ou consulte o manual.\n");
}

void executar_linha(char *ln) {
    char p1[50]="", p2[50]="", p3[50]="", p4[50]="", p5[50]="";
    int lidos = sscanf(ln, "%49s %49s %49s %49s %49s", p1, p2, p3, p4, p5);
    if(ln[0] == '#' || lidos < 1) return;

    int comando_valido = 0;

    if(strcmp(p1, "diga") == 0) {
        comando_valido = 1;
        char *ptr = strstr(ln, "diga") + 4;
        while(*ptr == ' ' || *ptr == '\t') ptr++; 
        if(*ptr == '\"') ptr++; 
        char buffer[500]; strcpy(buffer, ptr);
        int len = strlen(buffer);
        if(len > 0 && buffer[len-1] == '\"') buffer[len-1] = '\0'; 

        char *tok = strtok(buffer, " ");
        while(tok) {
            int achou = 0;
            for(int i=0; i<total_vars; i++) {
                if(strcmp(mem[i].n, tok) == 0) { printf("%g ", mem[i].v); achou = 1; break; }
            }
            if(!achou) printf("%s ", tok);
            tok = strtok(NULL, " ");
        }
        printf("\n");
    }
    else if(strcmp(p1, "limpar") == 0) { printf("\033[H\033[J"); comando_valido = 1; }
    else if(strcmp(p1, "cor") == 0) { printf("\033[1;3%dm", (int)get_n(p2)); comando_valido = 1; }
    else if(strcmp(p1, "pot") == 0) { set_n(p2, pow(get_n(p3), get_n(p4))); comando_valido = 1; }
    // (Adicione aqui os outros comandos do Motor 2.1... resumi para focar no corretor)
    else if(strcmp(p1, "sair") == 0) { printf("Fechando KitCode...\n"); exit(0); }
    
    // SE O COMANDO NÃO FOR RECONHECIDO, CHAMA O CORRETOR!
    if(!comando_valido && strcmp(p1, "repetir") != 0 && strcmp(p1, "fim") != 0) {
        corretor_ortografico(p1);
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    // MODO 1: MODO INTERATIVO (SHELL)
    if(argc == 1) {
        printf("\033[H\033[J"); // Limpa a tela
        printf("\033[1;36m=== KITCODE SHELL 3.0 ===\033[0m\n");
        printf("Digite comandos ao vivo ou 'sair'.\n\n");
        
        char linha_interativa[500];
        while(1) {
            printf("\033[1;32mKit>\033[0m ");
            fgets(linha_interativa, 500, stdin);
            linha_interativa[strcspn(linha_interativa, "\r\n")] = 0; // Limpa o enter
            if(strlen(linha_interativa) > 0) executar_linha(linha_interativa);
        }
        return 0;
    }

    // MODO 2: LEITURA DE ARQUIVO (Como era antes)
    FILE *f = fopen(argv[1], "r"); 
    if(!f) { printf("Erro ao abrir %s\n", argv[1]); return 1; }
    
    while(fgets(linhas[total_linhas], 500, f)) {
        linhas[total_linhas][strcspn(linhas[total_linhas], "\r\n")] = 0;
        total_linhas++;
    }
    fclose(f);

    while(ip < total_linhas) {
        executar_linha(linhas[ip]);
        ip++;
    }
    return 0;
}
