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

void set_n(char *n, double v) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) { mem[i].v=v; return; }
    strcpy(mem[total_vars].n, n); mem[total_vars].v=v; total_vars++;
}
double get_n(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return mem[i].v;
    return atof(n);
}

int main(int argc, char *argv[]) {
    if(argc < 2) return 1;
    FILE *f = fopen(argv[1], "r"); if(!f) return 1;
    srand(time(NULL));
    while(fgets(linhas[total_linhas], 500, f)) {
        linhas[total_linhas][strcspn(linhas[total_linhas], "\n")] = 0;
        total_linhas++;
    }
    fclose(f);

    while(ip < total_linhas) {
        char ln[500]; strcpy(ln, linhas[ip]);
        char p1[50]="", p2[50]="", p3[50]="", p4[50]="", p5[50]="";
        int lidos = sscanf(ln, "%49s %49s %49s %49s %49s", p1, p2, p3, p4, p5);
        if(ln[0] == '#' || lidos < 1) { ip++; continue; }

        // --- SISTEMA DE DIGA INTELIGENTE (CORRIGIDO) ---
        if(strcmp(p1, "diga") == 0) {
            char *ptr = strstr(ln, "diga") + 5;
            // Remove aspas se existirem
            if(*ptr == '\"') ptr++;
            char buffer[500]; strcpy(buffer, ptr);
            char *end = strrchr(buffer, '\"'); if(end) *end = '\0';

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
        // --- LOOPS E OUTROS ---
        else if(strcmp(p1, "repetir") == 0) { lvl_loop++; loop_inicio[lvl_loop] = ip; loop_conta[lvl_loop] = (int)get_n(p2); }
        else if(strcmp(p1, "fim") == 0) {
            if(lvl_loop > 0) {
                loop_conta[lvl_loop]--;
                if(loop_conta[lvl_loop] > 0) { ip = loop_inicio[lvl_loop]; }
                else lvl_loop--;
            }
        }
        else if(strcmp(p1, "ir") == 0) printf("\033[%d;%dH", (int)get_n(p3), (int)get_n(p2));
        else if(strcmp(p1, "pot") == 0) set_n(p2, pow(get_n(p3), get_n(p4)));
        else if(strcmp(p1, "lista") == 0) vetores[(int)get_n(p2)][(int)get_n(p3)] = get_n(p4);
        else if(strcmp(p1, "pega_lista") == 0) set_n(p4, vetores[(int)get_n(p2)][(int)get_n(p3)]);
        else if(strcmp(p1, "limpar") == 0) printf("\033[H\033[J");
        else if(strcmp(p1, "cor") == 0) printf("\033[1;3%dm", (int)get_n(p2));
        else if(strcmp(p1, "espera") == 0) DORMIR((int)get_n(p2));
        else if(strcmp(p1, "esconde") == 0) printf("\033[?25l");
        else if(strcmp(p1, "mostra") == 0) printf("\033[?25h");

        ip++;
    }
    return 0;
}
