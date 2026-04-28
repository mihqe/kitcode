#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

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

// Estruturas de dados existentes
typedef struct { char n[50]; double v; } Var;
Var mem[10000]; int total_vars = 0;
double vetores[200][200];
char linhas[5000][500]; int total_linhas = 0, ip = 0;

int loop_inicio[200], loop_conta[200], lvl_loop = 0, stack_se[200], lvl_se = 0;

// Novas estruturas para strings
typedef struct { char n[50]; char t[500]; } TextVar;
TextVar mem_texto[5000]; int total_textos = 0;

// Constantes predefinidas
#define PI 3.141592653589793
#define E 2.718281828459045
#define VERMELHO 1
#define VERDE 2
#define AMARELO 3
#define AZUL 4
#define MAGENTA 5
#define CIANO 6
#define BRANCO 7

// Funções existentes
void set_n(char *n, double v) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) { mem[i].v=v; return; }
    strcpy(mem[total_vars].n, n); mem[total_vars].v=v; total_vars++;
}
double get_n(char *n) {
    for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, n)==0) return mem[i].v;
    return atof(n);
}

// Novas funções para strings
void set_texto(char *n, char *t) {
    for(int i=0; i<total_textos; i++) if(strcmp(mem_texto[i].n, n)==0) { strcpy(mem_texto[i].t, t); return; }
    strcpy(mem_texto[total_textos].n, n); strcpy(mem_texto[total_textos].t, t); total_textos++;
}
char* get_texto(char *n) {
    for(int i=0; i<total_textos; i++) if(strcmp(mem_texto[i].n, n)==0) return mem_texto[i].t;
    return "";
}
void tamanho_texto(char *nome, char *resultado) {
    char *texto = get_texto(nome);
    set_n(resultado, strlen(texto));
}
void juntar_texto(char *dest, char *t1, char *t2) {
    char resultado[500];
    strcpy(resultado, t1);
    strcat(resultado, t2);
    set_texto(dest, resultado);
}
void pedaco_texto(char *dest, char *orig, int inicio, int fim) {
    char *texto = get_texto(orig);
    char resultado[500];
    int len = strlen(texto);
    if(inicio < 0) inicio = 0;
    if(fim >= len) fim = len - 1;
    if(inicio <= fim) {
        strncpy(resultado, texto + inicio, fim - inicio + 1);
        resultado[fim - inicio + 1] = '\0';
    } else {
        resultado[0] = '\0';
    }
    set_texto(dest, resultado);
}
void trocar_texto(char *dest, char *orig, char *velho, char *novo) {
    char *texto = get_texto(orig);
    char resultado[500];
    char *pos = strstr(texto, velho);
    if(pos) {
        int antes = pos - texto;
        strncpy(resultado, texto, antes);
        resultado[antes] = '\0';
        strcat(resultado, novo);
        strcat(resultado, pos + strlen(velho));
    } else {
        strcpy(resultado, texto);
    }
    set_texto(dest, resultado);
}
void maiuscula_texto(char *dest, char *orig) {
    char *texto = get_texto(orig);
    char resultado[500];
    for(int i = 0; texto[i]; i++) {
        resultado[i] = toupper(texto[i]);
    }
    resultado[strlen(texto)] = '\0';
    set_texto(dest, resultado);
}
void minuscula_texto(char *dest, char *orig) {
    char *texto = get_texto(orig);
    char resultado[500];
    for(int i = 0; texto[i]; i++) {
        resultado[i] = tolower(texto[i]);
    }
    resultado[strlen(texto)] = '\0';
    set_texto(dest, resultado);
}
void contem_texto(char *texto, char *busca, char *resultado) {
    set_n(resultado, strstr(texto, busca) != NULL ? 1 : 0);
}
void posicao_texto(char *texto, char *busca, char *resultado) {
    char *pos = strstr(texto, busca);
    if(pos) {
        set_n(resultado, pos - texto);
    } else {
        set_n(resultado, -1);
    }
}

// Funções matemáticas avançadas
void seno_funcao(char *resultado, double angulo) {
    set_n(resultado, sin(angulo * PI / 180.0));
}
void cosseno_funcao(char *resultado, double angulo) {
    set_n(resultado, cos(angulo * PI / 180.0));
}
void tangente_funcao(char *resultado, double angulo) {
    set_n(resultado, tan(angulo * PI / 180.0));
}
void logaritmo_funcao(char *resultado, double numero) {
    if(numero > 0) {
        set_n(resultado, log(numero));
    } else {
        set_n(resultado, 0);
    }
}
void log10_funcao(char *resultado, double numero) {
    if(numero > 0) {
        set_n(resultado, log10(numero));
    } else {
        set_n(resultado, 0);
    }
}
void exponencial_funcao(char *resultado, double valor) {
    set_n(resultado, exp(valor));
}
void raizcubica_funcao(char *resultado, double numero) {
    set_n(resultado, cbrt(numero));
}
void arredondar_funcao(char *resultado, double numero) {
    set_n(resultado, round(numero));
}
void teto_funcao(char *resultado, double numero) {
    set_n(resultado, ceil(numero));
}
void chao_funcao(char *resultado, double numero) {
    set_n(resultado, floor(numero));
}
void absoluto_funcao(char *resultado, double numero) {
    set_n(resultado, fabs(numero));
}
void sinal_funcao(char *resultado, double numero) {
    if(numero > 0) set_n(resultado, 1);
    else if(numero < 0) set_n(resultado, -1);
    else set_n(resultado, 0);
}
void fatorial_funcao(char *resultado, double numero) {
    int n = (int)numero;
    if(n < 0) {
        set_n(resultado, 0);
        return;
    }
    double fat = 1;
    for(int i = 1; i <= n; i++) {
        fat *= i;
    }
    set_n(resultado, fat);
}
void minimo_funcao(char *resultado, double a, double b) {
    set_n(resultado, a < b ? a : b);
}
void maximo_funcao(char *resultado, double a, double b) {
    set_n(resultado, a > b ? a : b);
}
void modulo_funcao(char *resultado, double divisor, double dividendo) {
    if(divisor != 0) {
        set_n(resultado, fmod(dividendo, divisor));
    } else {
        set_n(resultado, 0);
    }
}

// Funções existentes mantidas
void desenhar_linha(int x0, int y0, int x1, int y1, int cor, char *c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;
    printf("\033[1;3%dm", cor);
    while(1) {
        printf("\033[%d;%dH%s", y0, x0, c);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
    fflush(stdout);
}

void pergunta_seguro(char *prompt, char *variavel) {
    printf("%s ", prompt);
    char in[100];
    if(fgets(in, sizeof(in), stdin)) {
        in[strcspn(in, "\n")] = '\0';
        set_n(variavel, atof(in));
    }
}

// Função principal expandida
void executar_linha(char *ln) {
    char p1[50]="", p2[50]="", p3[50]="", p4[50]="", p5[50]="", p6[50]="", p7[50]="", p8[50]="", p9[50]="";
    int lidos = sscanf(ln, "%49s %49s %49s %49s %49s %49s %49s %49s %49s", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if(ln[0] == '#' || lidos < 1) return;

    // Estruturas de controle existentes
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

    // Comandos de texto (strings)
    if(strcmp(p1, "texto") == 0) {
        char *ptr = strstr(ln, p2) + strlen(p2) + 1;
        while(*ptr == ' ' || *ptr == '\t') ptr++; if(*ptr == '\"') ptr++; 
        char buffer[500]; strcpy(buffer, ptr);
        int len = strlen(buffer); if(len > 0 && buffer[len-1] == '\"') buffer[len-1] = '\0'; 
        set_texto(p2, buffer);
    }
    else if(strcmp(p1, "diga_texto") == 0) {
        printf("%s\n", get_texto(p2));
    }
    else if(strcmp(p1, "tamanho") == 0) tamanho_texto(p2, p3);
    else if(strcmp(p1, "juntar") == 0) juntar_texto(p2, get_texto(p3), get_texto(p4));
    else if(strcmp(p1, "pedaco") == 0) pedaco_texto(p2, p3, (int)get_n(p4), (int)get_n(p5));
    else if(strcmp(p1, "trocar") == 0) trocar_texto(p2, p3, p4, p5);
    else if(strcmp(p1, "maiuscula") == 0) maiuscula_texto(p2, p3);
    else if(strcmp(p1, "minuscula") == 0) minuscula_texto(p2, p3);
    else if(strcmp(p1, "contem") == 0) contem_texto(get_texto(p2), p3, p4);
    else if(strcmp(p1, "posicao") == 0) posicao_texto(get_texto(p2), p3, p4);

    // Comandos matemáticos avançados
    else if(strcmp(p1, "seno") == 0) seno_funcao(p2, get_n(p3));
    else if(strcmp(p1, "cosseno") == 0) cosseno_funcao(p2, get_n(p3));
    else if(strcmp(p1, "tangente") == 0) tangente_funcao(p2, get_n(p3));
    else if(strcmp(p1, "logaritmo") == 0) logaritmo_funcao(p2, get_n(p3));
    else if(strcmp(p1, "log10") == 0) log10_funcao(p2, get_n(p3));
    else if(strcmp(p1, "exponencial") == 0) exponencial_funcao(p2, get_n(p3));
    else if(strcmp(p1, "raizcubica") == 0) raizcubica_funcao(p2, get_n(p3));
    else if(strcmp(p1, "arredondar") == 0) arredondar_funcao(p2, get_n(p3));
    else if(strcmp(p1, "teto") == 0) teto_funcao(p2, get_n(p3));
    else if(strcmp(p1, "chao") == 0) chao_funcao(p2, get_n(p3));
    else if(strcmp(p1, "absoluto") == 0) absoluto_funcao(p2, get_n(p3));
    else if(strcmp(p1, "sinal") == 0) sinal_funcao(p2, get_n(p3));
    else if(strcmp(p1, "fatorial") == 0) fatorial_funcao(p2, get_n(p3));
    else if(strcmp(p1, "minimo") == 0) minimo_funcao(p2, get_n(p3), get_n(p4));
    else if(strcmp(p1, "maximo") == 0) maximo_funcao(p2, get_n(p3), get_n(p4));
    else if(strcmp(p1, "modulo") == 0) modulo_funcao(p2, get_n(p3), get_n(p4));

    // Comandos existentes mantidos
    else if(strcmp(p1, "diga") == 0) {
        char *ptr = strstr(ln, "diga") + 4;
        while(*ptr == ' ' || *ptr == '\t') ptr++; if(*ptr == '\"') ptr++; 
        char buffer[500]; strcpy(buffer, ptr);
        int len = strlen(buffer); if(len > 0 && buffer[len-1] == '\"') buffer[len-1] = '\0'; 
        char *tok = strtok(buffer, " ");
        while(tok) {
            int achou = 0;
            for(int i=0; i<total_vars; i++) if(strcmp(mem[i].n, tok) == 0) { printf("%g ", mem[i].v); achou = 1; break; }
            if(!achou) {
                for(int i=0; i<total_textos; i++) if(strcmp(mem_texto[i].n, tok) == 0) { printf("%s ", mem_texto[i].t); achou = 1; break; }
            }
            if(!achou) printf("%s ", tok); tok = strtok(NULL, " ");
        } printf("\n");
    }
    else if(strcmp(p1, "ponto") == 0) { 
        printf("\033[1;3%dm\033[%d;%dH%s", (int)get_n(p4), (int)get_n(p3), (int)get_n(p2), p5); fflush(stdout); 
    }
    else if(strcmp(p1, "linha") == 0) {
        desenhar_linha((int)get_n(p2), (int)get_n(p3), (int)get_n(p4), (int)get_n(p5), (int)get_n(p6), p7);
    }
    else if(strcmp(p1, "bloco") == 0) {
        int x = get_n(p2), y = get_n(p3), w = get_n(p4), h = get_n(p5), cor = get_n(p6);
        printf("\033[1;3%dm", cor);
        for(int i=0; i<h; i++) {
            printf("\033[%d;%dH", y+i, x);
            for(int j=0; j<w; j++) printf("%s", p7);
        }
        fflush(stdout);
    }
    else if(strcmp(p1, "var") == 0) set_n(p2, get_n(p3));
    else if(strcmp(p1, "tecla") == 0) set_n(p2, ler_tecla());
    else if(strcmp(p1, "desenha") == 0) { printf("\033[%d;%dH%s", (int)get_n(p3), (int)get_n(p2), p4); fflush(stdout); }
    else if(strcmp(p1, "esconde") == 0) printf("\033[?25l");
    else if(strcmp(p1, "mostra") == 0) printf("\033[?25h");
    else if(strcmp(p1, "pergunta") == 0) {
        char *ptr = strstr(ln, p2) + strlen(p2) + 1;
        pergunta_seguro(ptr, p2);
    }
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
    
    // Novos comandos de sistema
    else if(strcmp(p1, "versao") == 0) printf("KitCode v6.0 - Super Expansão\n");
    else if(strcmp(p1, "constante") == 0) {
        if(strcmp(p3, "PI") == 0) set_n(p2, PI);
        else if(strcmp(p3, "E") == 0) set_n(p2, E);
        else if(strcmp(p3, "VERMELHO") == 0) set_n(p2, VERMELHO);
        else if(strcmp(p3, "VERDE") == 0) set_n(p2, VERDE);
        else if(strcmp(p3, "AZUL") == 0) set_n(p2, AZUL);
        else if(strcmp(p3, "BRANCO") == 0) set_n(p2, BRANCO);
        else set_n(p2, atof(p3));
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); stack_se[0] = 2;
    if(argc == 1) {
        printf("\033[H\033[J\033[1;36m=== KITCODE SHELL 6.0 SUPER EXPANSÃO ===\033[0m\nDigite comandos...\n");
        char linha[500];
        while(1) { printf("\033[1;32m>\033[0m "); fgets(linha, 500, stdin); linha[strcspn(linha, "\r\n")] = 0; executar_linha(linha); }
    }
    FILE *f = fopen(argv[1], "r"); if(!f) return 1;
    while(fgets(linhas[total_linhas], 500, f)) { linhas[total_linhas][strcspn(linhas[total_linhas], "\r\n")] = 0; total_linhas++; }
    fclose(f);
    while(ip < total_linhas) { executar_linha(linhas[ip]); ip++; }
    printf("\033[?25h\n\033[0m"); return 0;
}
