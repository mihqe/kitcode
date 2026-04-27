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
char linhas[3000][500]; int total_linhas = 0, ip = 0;

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
    while(fgets(linhas[total_linhas], 500, f)) {
        linhas[total_linhas][strcspn(linhas[total_linhas], "\n")] = 0;
        total_linhas++;
    }
    fclose(f);
    srand(time(NULL));

    while(ip < total_linhas) {
        char ln[500]; strcpy(ln, linhas[ip]);
        char p1[50], p2[50], p3[50], p4[50], p5[50];
        // Leitura inicial simples
        int lidos = sscanf(ln, "%s %s %s %s %s", p1, p2, p3, p4, p5);
        if(ln[0] == '#' || lidos < 1) { ip++; continue; }

        if(strcmp(p1, "diga") == 0) {
            char *ptr = strstr(ln, "diga") + 5;
            char *tok = strtok(ptr, " ");
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
        else if(strcmp(p1, "pergunta") == 0) {
            char *msg = strstr(ln, p2) + strlen(p2) + 1;
            printf("%s ", msg);
            char in[100]; scanf("%s", in);
            set_n(p2, atof(in));
        }
        else if(strcmp(p1, "hipo") == 0) {
            double r = sqrt(pow(get_n(p3), 2) + pow(get_n(p4), 2));
            set_n(p2, r);
        }
        else if(strcmp(p1, "limpar") == 0) printf("\033[H\033[J");
        else if(strcmp(p1, "cor") == 0) printf("\033[1;3%dm", (int)get_n(p2));

        ip++;
    }
    return 0;
}
