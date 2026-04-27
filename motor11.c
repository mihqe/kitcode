#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
    #define ESPERAR(s) Sleep((s) * 1000)
    #define DORMIR_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define ESPERAR(s) sleep(s)
    #define DORMIR_MS(ms) usleep((ms) * 1000)
#endif

// ESTRUTURA DE MEMÓRIA
typedef struct { char n[50]; double v; char t[500]; int is_txt; } Var;
Var mem[1000]; int total_vars = 0;
char linhas[2000][500]; int total_linhas = 0, ip = 0;

// SISTEMA DE VARIÁVEIS
void set_n(char *n, double v) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) { mem[i].v=v; mem[i].is_txt=0; return; }
    strcpy(mem[total_vars].n, n); mem[total_vars].v=v; mem[total_vars].is_txt=0; total_vars++;
}
void set_t(char *n, char *t) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) { strcpy(mem[i].t, t); mem[i].is_txt=1; return; }
    strcpy(mem[total_vars].n, n); strcpy(mem[total_vars].t, t); mem[total_vars].is_txt=1; total_vars++;
}
double get_n(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return mem[i].v;
    return atof(n);
}
Var* get_v(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return &mem[i];
    return NULL;
}

// FUNÇÕES DE DESIGN (VISUAL ENGINE)
void desenhar_janela(int x, int y, int l, int h, char *tit) {
    printf("\033[%d;%dH┌", y, x); for(int i=0;i<l-2;i++) printf("─"); printf("┐");
    for(int i=1;i<h-1;i++) { printf("\033[%d;%dH│", y+i, x); printf("\033[%d;%dH│", y+i, x+l-1); }
    printf("\033[%d;%dH└", y+h-1, x); for(int i=0;i<l-2;i++) printf("─"); printf("┘");
    printf("\033[%d;%dH %s ", y, x+(l/2)-(int)(strlen(tit)/2), tit);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { printf("KitCode 1.2 - Use: kit arquivo.kit\n"); return 1; }
    FILE *f = fopen(argv[1], "r"); if(!f) return 1;
    srand(time(NULL));
    while(fgets(linhas[total_linhas], 500, f)) {
        linhas[total_linhas][strcspn(linhas[total_linhas], "\n")] = 0;
        total_linhas++;
    }
    fclose(f);

    int stack[100], lvl = 0; stack[0] = 2;

    while(ip < total_linhas) {
        char ln[500]; strcpy(ln, linhas[ip]);
        int i = 0; while(ln[i] == ' ' || ln[i] == '\t') i++;
        if(ln[i] == '#' || ln[i] == '\0') { ip++; continue; }

        char p1[50]="", p2[50]="", p3[50]="", p4[50]="", p5[50]="";
        int lidos = sscanf(ln + i, "%49s %49s %49s %49s %49s", p1, p2, p3, p4, p5);

        // LÓGICA DE BLOCOS
        if(strcmp(p1, "se")==0) { lvl++; if(stack[lvl-1]!=2) stack[lvl]=1; else if(get_n(p2) == get_n(p4)) stack[lvl]=2; else stack[lvl]=1; ip++; continue; }
        if(strcmp(p1, "fim")==0) { if(lvl>0) lvl--; ip++; continue; }
        if(stack[lvl] != 2) { ip++; continue; }

        // --- AS 20 NOVAS FUNÇÕES ---

        // 1-4: DESIGN & LAYOUT
        if(strcmp(p1, "janela")==0) desenhar_janela(get_n(p2), get_n(p3), get_n(p4), get_n(p5), p5+1);
        else if(strcmp(p1, "pixel")==0) { printf("\033[%d;%dH%s", (int)get_n(p3), (int)get_n(p2), strstr(ln, p3)+strlen(p3)+1); }
        else if(strcmp(p1, "fundo")==0) printf("\033[4%dm", (int)get_n(p2)); // Muda cor do fundo
        else if(strcmp(p1, "reset")==0) printf("\033[0m"); // Reseta tudo

        // 5-8: MATEMÁTICA AVANÇADA
        else if(strcmp(p2, "raiz")==0) set_n(p1, sqrt(get_n(p3)));
        else if(strcmp(p2, "potencia")==0) set_n(p1, pow(get_n(p3), get_n(p4)));
        else if(strcmp(p2, "resto")==0) set_n(p1, (int)get_n(p3) % (int)get_n(p4));
        else if(strcmp(p2, "absoluto")==0) set_n(p1, fabs(get_n(p3)));

        // 9-12: SISTEMA & TEMPO
        else if(strcmp(p1, "data")==0) { time_t t=time(NULL); struct tm tm=*localtime(&t); printf("%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900); }
        else if(strcmp(p1, "hora")==0) { time_t t=time(NULL); struct tm tm=*localtime(&t); printf("%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec); }
        else if(strcmp(p1, "espera_ms")==0) DORMIR_MS((int)get_n(p2));
        else if(strcmp(p1, "os_nome")==0) { #ifdef _WIN32 
            set_t(p2, "Windows"); #else 
            set_t(p2, "Linux"); #endif 
        }

        // 13-16: STRINGS & TEXTO
        else if(strcmp(p1, "tamanho")==0) { Var *v=get_v(p3); if(v) set_n(p2, strlen(v->t)); }
        else if(strcmp(p1, "caixa_alta")==0) { Var *v=get_v(p2); if(v) for(int j=0; v->t[j]; j++) v->t[j]=toupper(v->t[j]); }
        else if(strcmp(p1, "caixa_baixa")==0) { Var *v=get_v(p2); if(v) for(int j=0; v->t[j]; j++) v->t[j]=tolower(v->t[j]); }
        else if(strcmp(p1, "limpa_linha")==0) printf("\033[K");

        // 17-20: CONTROLE DE CURSOR & INTERAÇÃO
        else if(strcmp(p1, "esconde_cursor")==0) printf("\033[?25l");
        else if(strcmp(p1, "mostra_cursor")==0) printf("\033[?25h");
        else if(strcmp(p1, "tecla")==0) { char c; scanf(" %c", &c); char ts[2]={c,0}; set_t(p2, ts); }
        else if(strcmp(p1, "beep")==0) printf("\a");

        // COMANDOS BASE MANTIDOS
        else if(strcmp(p1, "diga")==0 || strcmp(p1, "digite")==0) {
            char *ptr = strstr(ln, p1) + strlen(p1); while(*ptr == ' ') ptr++;
            char buffer[500]; strcpy(buffer, ptr); char *tok = strtok(buffer, " ");
            while(tok) { Var *v = get_v(tok); if(v) printf("%s ", v->is_txt?v->t:v->t); else printf("%s ", tok); tok = strtok(NULL, " "); }
            printf("\n");
        }
        else if(strcmp(p2, "=")==0 && lidos >= 3) set_n(p1, get_n(p3));
        else if(strcmp(p1, "limpar")==0) printf("\033[H\033[J");
        else if(strcmp(p1, "cor")==0) printf("\033[1;3%dm", (int)get_n(p2));

        ip++;
    }
    return 0;
}
