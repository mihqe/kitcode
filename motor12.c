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

typedef struct { char n[50]; double v; char t[500]; int is_txt; } Var;
Var mem[5000]; int total_vars = 0;
char linhas[3000][500]; int total_linhas = 0, ip = 0;

void set_n(char *n, double v) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) { mem[i].v=v; mem[i].is_txt=0; return; }
    strcpy(mem[total_vars].n, n); mem[total_vars].v=v; mem[total_vars].is_txt=0; total_vars++;
}
double get_n(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return mem[i].v;
    return atof(n);
}
Var* get_v(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return &mem[i];
    return NULL;
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

        // --- COMANDOS SIMPLIFICADOS ---

        if(strcmp(p1, "diga") == 0) {
            char *ptr = strstr(ln, "diga") + 5;
            char buffer[500]; strcpy(buffer, ptr); char *tok = strtok(buffer, " ");
            while(tok) {
                Var *v = get_v(tok);
                if(v) printf("%g ", v->v); else printf("%s ", tok);
                tok = strtok(NULL, " ");
            }
            printf("\n");
        }
        else if(strcmp(p1, "limpar") == 0) printf("\033[H\033[J");
        else if(strcmp(p1, "cor") == 0) printf("\033[1;3%dm", (int)get_n(p2));
        else if(strcmp(p1, "pergunta") == 0) {
            printf("%s ", strstr(ln, p2) + strlen(p2) + 1);
            char in[100]; scanf(" %s", in); set_n(p2, atof(in));
        }

        // --- SUPER MATEMÁTICA (Avançada e Simples) ---
        
        // Ex: raiz resultado 144
        else if(strcmp(p1, "raiz") == 0) set_n(p2, sqrt(get_n(p3)));
        
        // Ex: pot resultado base exp
        else if(strcmp(p1, "pot") == 0) set_n(p2, pow(get_n(p3), get_n(p4)));

        // Ex: hipo resultado cateto1 cateto2 (Pitágoras direto!)
        else if(strcmp(p1, "hipo") == 0) set_n(p2, sqrt(pow(get_n(p3),2) + pow(get_n(p4),2)));

        // Ex: calc resultado = 10 + 5
        else if(strcmp(p1, "calc") == 0) {
            double v1 = get_n(p3), v2 = get_n(p5);
            if(strcmp(p4, "+") == 0) set_n(p2, v1 + v2);
            else if(strcmp(p4, "-") == 0) set_n(p2, v1 - v2);
            else if(strcmp(p4, "*") == 0) set_n(p2, v1 * v2);
            else if(strcmp(p4, "/") == 0) set_n(p2, v2 != 0 ? v1 / v2 : 0);
        }

        ip++;
    }
    return 0;
}
