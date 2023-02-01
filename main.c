#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct{
    int prontuario;
    char nome[50];
    char curso[50];
    double nota1;
    double nota2;
    double media;
}alunos;
int menu(){
    int a;
    printf("---------------------------------------");
    printf("\nEscolha uma                           |\n");
    printf("1. Criar arquivo                      |\n");
    printf("2. Incluir aluno                      |\n");
    printf("3. Consultar alunos por curso         |\n");
    printf("4. Consultar alunos por situacao      |\n");
    printf("5. Finalizar                          |\n");
    printf("---------------------------------------\n");
    scanf("%d",&a);
    return a;
}

int main(){
    int aux,aux1,aux5,i,n,x=0,qtd=0,pron[MAX];
    char aux4[20];
    alunos p;
    aux=0;
    aux=menu();
    while(aux!=5){
        if(aux==1){
                FILE *pont_arq;
                pont_arq = fopen("Alunos.dat","ab");
                fclose(pont_arq);
                pont_arq = fopen("Alunos.dat","rb");
                qtd=fread(&p, sizeof(alunos), 1, pont_arq);
                fclose(pont_arq);
                aux1=1;
                if(qtd==1){
                    printf("Deseja sobrescrever o arquivo e, consequentemente, perder os dados?");
                    printf("\n1. Sim\n");
                    printf("2. Nao\n");
                    scanf("%d",&aux1);
                }
                if(aux1==1){
                    FILE *pont_arq;
                    pont_arq = fopen("Alunos.dat","wb");
                    printf("arquivo Criado\n");
                    fclose(pont_arq);
                    }
                if(aux1==2){
                    printf("encerrando...");
                    break;
                }
        }
        if(aux==2){
            FILE *pont_arq;
            pont_arq = fopen("Alunos.dat","ab");
            if (pont_arq == NULL){
                printf("ERRO! O arquivo não foi aberto!\n");
            }
            else{
                printf("Escreva o prontuario: ");
                scanf("%i",&p.prontuario);
                getchar();

                printf("Escreva o nome: ");
                scanf("%[^\n]",p.nome);
                getchar();

                printf("Escreva o curso: ");
                scanf("%[^\n]",p.curso);
                getchar();

                printf("Escreva a nota 1: ");
                scanf("%lf",&p.nota1);

                printf("Escreva nota 2: ");
                scanf("%lf",&p.nota2);
                printf("\n");
                fwrite(&p, sizeof(p), 1, pont_arq);
            }
            fclose(pont_arq);
            pont_arq = fopen("Alunos.dat","rb");
            x=0;
            fread(&p, sizeof(alunos), 1, pont_arq);
                while(!feof(pont_arq)){
                    pron[x]=p.prontuario;
                    x++;
                    fread(&p, sizeof(alunos), 1, pont_arq);
                }
            for(i=0;i<x-1;i++){
                if(pron[x-1]==pron[i]){
                        printf("prontuario iguai a de um aluno ja inscrito\nNAO PODE!!\n\n");
                    }
            }
            fclose(pont_arq);
        }
        if(aux==3){
            FILE *pont_arq;
            pont_arq = fopen("Alunos.dat","rb");
            x=0;
            printf("Escreva o curso: ");
            scanf("%s", aux4);
            fread(&p, sizeof(alunos), 1, pont_arq);
            while(!feof(pont_arq)){
                if(strcmp(aux4,p.curso)==0){
                    printf("nome: %s\n",p.nome);
                }
                fread(&p, sizeof(alunos), 1, pont_arq);
            }
            fclose(pont_arq);
        }
        if(aux==4){
            /*Obs.1: Aprovado: média ≥ 6;
            Exame: 4 ≤ média < 6;
            Reprovado: média < 4.
            Obs. 2: Exibir prontuário, nome e média aritmética entre as duas notas.
            */
            FILE *pont_arq;
            pont_arq = fopen("Alunos.dat","rb");
            printf("Escolha um:\n");
            printf("1. Aprovado\n");
            printf("2. Exame\n");
            printf("3. Reprovado\n");
            scanf("%d",&aux5);
            fread(&p, sizeof(alunos), 1, pont_arq);
            x=0;
            while(!feof(pont_arq)){
                    p.media=(p.nota1+p.nota2)/2;
                if(x==0){
                    printf("-------------\n");
                }
                if(aux5==1){
                        if(p.media>=6){
                            printf("nome: %s\nprontuario: %d\nmedia:%.2lf\n-------------\n",p.nome,p.prontuario, p.media);
                        }
                }
                if(aux5==2){
                        if(p.media>=4 && p.media<6){
                            printf("nome: %s\nprontuario: %d\nmedia:%.2lf\n-------------\n",p.nome,p.prontuario, p.media);
                        }
                }
                if(aux5==3){
                        if(p.media<4){
                            printf("nome: %s\nprontuario: %d\nmedia:%.2lf\n-------------\n",p.nome,p.prontuario, p.media);
                        }
                }
                x++;
                fread(&p, sizeof(alunos), 1, pont_arq);
            }
            fclose(pont_arq);
        }
        if(aux==5){


        }
            aux=menu();
    }


    return 0;
}
