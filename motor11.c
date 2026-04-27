#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// --- AJUSTE UNIVERSAL (WINDOWS/LINUX) ---
#ifdef _WIN32
    #include <windows.h>
    #define ESPERAR(s) Sleep((s) * 1000)
    #define DORMIR_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define ESPERAR(s) sleep(s)
    #define DORMIR_MS(ms) usleep((ms) * 1000)
#endif

// --- CONFIGURAÇÕES DO MOTOR ---
char linhas[2000][500];
int total_linhas = 0, ip = 0; 
typedef struct { char n[50]; double v; char t[500]; int is_txt; } Var;
Var mem[1000]; int total_vars = 0;

// --- SISTEMA DE MEMÓRIA ---
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

// --- LÓGICA DE COMPARAÇÃO ---
int checar(char *v, char *o, char *val) {
    double v1 = get_n(v), v2 = get_n(val);
    if(strcmp(o,"==")==0||strcmp(o,"=")==0) return (v1==v2);
    if(strcmp(o,"!=")==0) return (v1!=v2);
    if(strcmp(o,"<")==0) return (v1<v2);
    if(strcmp(o,">")==0) return (v1>v2);
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { printf("Uso: kitcode arquivo.kit\n"); return 1; }
    FILE *f = fopen(argv[1], "r");
    if(!f) return 1;
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
        sscanf(ln + i, "%49s %49s %49s %49s %49s", p1, p2, p3, p4, p5);

        if(strcmp(p1, "se") == 0) {
            lvl++;
            if(stack[lvl-1] != 2) stack[lvl] = 1; 
            else if(checar(p2, p3, p4)) stack[lvl] = 2; else stack[lvl] = 1;
            ip++; continue;
        }
        else if(strcmp(p1, "senao") == 0) {
            stack[lvl] = (stack[lvl] == 2) ? 1 : 2;
            ip++; continue;
        }
        else if(strcmp(p1, "fim") == 0 && strcmp(p2, "se") == 0) {
            if(lvl > 0) lvl--; ip++; continue;
        }

        if(stack[lvl] != 2) { ip++; continue; }

        // --- COMANDOS ULTRA ---
        if(strcmp(p1, "digite") == 0) {
            char *ptr = strstr(ln + i, "digite") + 6; while(*ptr == ' ') ptr++;
            for(int j=0; ptr[j]; j++) { printf("%c", ptr[j]); fflush(stdout); DORMIR_MS(50); }
            printf("\n");
        }
        else if(strcmp(p1, "chance") == 0) {
            int prob = (int)get_n(p2);
            set_n("sorte", ((rand() % 100) < prob) ? 1 : 0);
        }
        else if(strcmp(p1, "salve") == 0) {
            char fname[60]; sprintf(fname, "%s.save", p2);
            FILE *fs = fopen(fname, "w");
            Var *v = get_v(p2);
            if(v) { if(v->is_txt) fprintf(fs, "T %s", v->t); else fprintf(fs, "N %f", v->v); }
            fclose(fs);
        }
        else if(strcmp(p1, "carregue") == 0) {
            char fname[60]; sprintf(fname, "%s.save", p2);
            FILE *fs = fopen(fname, "r");
            if(fs) {
                char type; fscanf(fs, " %c ", &type);
                if(type == 'T') { char txt[500]; fgets(txt, 500, fs); set_t(p2, txt); }
                else { double val; fscanf(fs, "%lf", &val); set_n(p2, val); }
                fclose(fs);
            }
        }
        else if(strcmp(p1, "comando") == 0) {
            char *cmd = strstr(ln + i, "comando") + 7; while(*cmd == ' ') cmd++;
            system(cmd);
        }
        else if(strcmp(p1, "diga") == 0) {
            char *ptr = strstr(ln + i, "diga") + 4; while(*ptr == ' ') ptr++;
            char buffer[500]; strcpy(buffer, ptr); char *tok = strtok(buffer, " ");
            while(tok) { Var *v = get_v(tok); if(v) { if(v->is_txt) printf("%s ", v->t); else printf("%g ", v->v); } else printf("%s ", tok); tok = strtok(NULL, " "); }
            printf("\033[0m\n");
        }
        else if(strcmp(p1, "pergunta") == 0) {
            char *msg = strstr(ln + i, p2) + strlen(p2); while(*msg == ' ') msg++;
            printf("%s ", msg); char in[300]; scanf(" %[^\n]", in);
            int n = 1; for(int j=0; in[j]; j++) if((in[j]<'0'||in[j]>'9')&&in[j]!='.') n=0;
            if(n && strlen(in)>0) set_n(p2, atof(in)); else set_t(p2, in);
        }
        else if(strcmp(p1, "cor") == 0) printf("\033[1;3%dm", (int)get_n(p2));
        else if(strcmp(p1, "limpar") == 0) printf("\033[H\033[J");
        else if(strcmp(p1, "espera") == 0) ESPERAR((int)get_n(p2));
        else if(strcmp(p1, "som") == 0) printf("\a");
        else if(strcmp(p1, "data") == 0) { time_t t = time(NULL); struct tm tm = *localtime(&t); printf("[%02d:%02d:%02d] ", tm.tm_hour, tm.tm_min, tm.tm_sec); }
        else if(strcmp(p2, "=") == 0) {
            if(strcmp(p3, "sorteia") == 0) set_n(p1, (rand() % ((int)get_n(p5) - (int)get_n(p4) + 1)) + (int)get_n(p4));
            else { double v1 = get_n(p3), v2 = get_n(p5); if(strcmp(p4,"+")==0) set_n(p1, v1+v2); else if(strcmp(p4,"-")==0) set_n(p1, v1-v2); else if(strcmp(p4,"*")==0) set_n(p1, v1*v2); else if(strcmp(p4,"/")==0) set_n(p1, (v2!=0)?v1/v2:0); else set_n(p1, get_n(p3)); }
        }
        ip++; 
    }
    return 0;
}
