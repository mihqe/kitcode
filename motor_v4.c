#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
    #define DORMIR(ms) Sleep(ms)
    int ler_tecla() { if(_kbhit()) return _getch(); return 0; }
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #define DORMIR(ms) usleep((ms) * 1000)
    int ler_tecla() {
        struct termios oldt, newt; int ch;
        tcgetattr(STDIN_FILENO, &oldt); newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        if(ch < 0) return 0; return ch;
    }
#endif

typedef struct { char n[50]; double v; } Var;
Var mem[5000]; int total_vars = 0;
double vetores[100][100];
char linhas[3000][500]; int total_linhas = 0, ip = 0;

int loop_inicio[100], loop_conta[100], lvl_loop = 0;
int stack_se[100], lvl_se = 0;

void set_n(char *n, double v) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) { mem[i].v=v; return; }
    strcpy(mem[total_vars].n, n); mem[total_vars].v=v; total_vars++;
}
double get_n(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return mem[i].v;
    return atof(n);
}

void executar_linha(char *ln) {
    char p1[50]="", p2[50]="", p3[50]="", p4[50]="", p5[50]="";
    int lidos = sscanf(ln, "%49s %49s %49s %49s %49s", p1, p2, p3, p4, p5);
    if(ln[0] == '#' || lidos < 1) return;

    // --- BLOCOS DE LÓGICA ---
    if(strcmp(p1, "se") == 0) {
        lvl_se++; if(stack_se[lvl_se-1] == 1) stack_se[lvl_se] = 1;
        else if(get_n(p2) == get_n(p4)) stack_se[lvl_se] = 2; else stack_se[lvl_se] = 1; return;
    }
    if(strcmp(p1, "repetir") == 0) { lvl_loop++; loop_inicio[lvl_loop] = ip; loop_conta[lvl_loop] = (int)get_n(p2); return; }
    if(strcmp(p1, "fim") == 0) {
        if(lvl_loop > 0) { loop_conta[lvl_loop]--; if(loop_conta[lvl_loop] > 0) ip = loop_inicio[lvl_loop]; else lvl_loop--; }
        else if(lvl_se > 0) lvl_se--; return;
    }
    if(lvl_se > 0 && stack_se[lvl_se] == 1) return;

    // --- SISTEMA INTELIGENTE DE TEXTO ---
    if(strcmp(p1, "diga") == 0) {
        char *ptr = strstr(ln, "diga") + 4;
        while(*ptr == ' ' || *ptr == '\t') ptr++; if(*ptr == '\"') ptr++; 
        char buffer[500]; strcpy(buffer, ptr);
        int len = strlen(buffer); if(len > 0 && buffer[len-1] == '\"') buffer[len-1] = '\0'; 
        char *tok = strtok(buffer, " ");
        while(tok) {
            int achou = 0;
            for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, tok) == 0) { printf("%g ", mem[i].v); achou = 1; break; }
            if(!achou) printf("%s ", tok); tok = strtok(NULL, " ");
        } printf("\n");
    }
    
    // --- O MOTOR 2D E CONTROLES (NOVO) ---
    else if(strcmp(p1, "var") == 0) set_n(p2, get_n(p3));
    else if(strcmp(p1, "tecla") == 0) set_n(p2, ler_tecla());
    else if(strcmp(p1, "desenha") == 0) { printf("\033[%d;%dH%s", (int)get_n(p3), (int)get_n(p2), p4); fflush(stdout); }
    else if(strcmp(p1, "esconde") == 0) printf("\033[?25l");
    else if(strcmp(p1, "mostra") == 0) printf("\033[?25h");

    // --- UI, MATEMÁTICA, FÍSICA E SORTE (MOTOR 3.0) ---
    else if(strcmp(p1, "pergunta") == 0) { printf("%s ", strstr(ln, p2) + strlen(p2) + 1); char in[100]; scanf("%s", in); set_n(p2, atof(in)); }
    else if(strcmp(p1, "limpar") == 0) printf("\033[H\033[J");
    else if(strcmp(p1, "cor") == 0) printf("\033[1;3%dm", (int)get_n(p2));
    else if(strcmp(p1, "ir") == 0) printf("\033[%d;%dH", (int)get_n(p3), (int)get_n(p2));
    else if(strcmp(p1, "espera") == 0) DORMIR((int)get_n(p2));
    else if(strcmp(p1, "grafico") == 0) {
        int val = (int)get_n(p2), max = (int)get_n(p3); int barras = (val * 20) / (max > 0 ? max : 1); 
        printf("["); for(int i=0; i<20; i++) { if(i < barras) printf("■"); else printf("-"); } printf("] %d/%d\n", val, max);
    }
    else if(strcmp(p1, "janela") == 0) {
        int x = get_n(p2), y = get_n(p3), l = get_n(p4), h = get_n(p5);
        printf("\033[%d;%dH┌", y, x); for(int i=0; i<l-2; i++) printf("─"); printf("┐");
        for(int i=1; i<h-1; i++) { printf("\033[%d;%dH│", y+i, x); printf("\033[%d;%dH│", y+i, x+l-1); }
        printf("\033[%d;%dH└", y+h-1, x); for(int i=0; i<l-2; i++) printf("─"); printf("┘");
    }
    else if(strcmp(p1, "calc") == 0) {
        double v1=get_n(p3), v2=get_n(p5);
        if(strcmp(p4,"+")==0) set_n(p2, v1+v2); else if(strcmp(p4,"-")==0) set_n(p2, v1-v2);
        else if(strcmp(p4,"*")==0) set_n(p2, v1*v2); else if(strcmp(p4,"/")==0) set_n(p2, v2!=0?v1/v2:0);
    }
    else if(strcmp(p1, "pot") == 0) set_n(p2, pow(get_n(p3), get_n(p4)));
    else if(strcmp(p1, "raiz") == 0) set_n(p2, sqrt(get_n(p3)));
    else if(strcmp(p1, "hipo") == 0) set_n(p2, sqrt(pow(get_n(p3),2) + pow(get_n(p4),2)));
    else if(strcmp(p1, "queda") == 0) set_n(p2, 0.5 * 9.81 * get_n(p3) * get_n(p3));
    else if(strcmp(p1, "forca") == 0) set_n(p2, get_n(p3) * get_n(p4));
    else if(strcmp(p1, "sorteia") == 0) set_n(p2, get_n(p3) + (rand() % (int)(get_n(p4) - get_n(p3) + 1)));
    else if(strcmp(p1, "lista") == 0) vetores[(int)get_n(p2)][(int)get_n(p3)] = get_n(p4);
    else if(strcmp(p1, "pega_lista") == 0) set_n(p4, vetores[(int)get_n(p2)][(int)get_n(p3)]);
    else if(strcmp(p1, "sair") == 0) exit(0);
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); stack_se[0] = 2;
    if(argc == 1) {
        printf("\033[H\033[J\033[1;36m=== KITCODE SHELL 4.1 ===\033[0m\nDigite comandos ou 'sair'.\n");
        char linha[500];
        while(1) { printf("\033[1;32m>\033[0m "); fgets(linha, 500, stdin); linha[strcspn(linha, "\r\n")] = 0; executar_linha(linha); }
    }
    FILE *f = fopen(argv[1], "r"); if(!f) return 1;
    while(fgets(linhas[total_linhas], 500, f)) { linhas[total_linhas][strcspn(linhas[total_linhas], "\r\n")] = 0; total_linhas++; }
    fclose(f);
    while(ip < total_linhas) { executar_linha(linhas[ip]); ip++; }
    printf("\033[?25h\n"); return 0;
}
