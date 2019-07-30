#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("tables.sql", "w");
    char nome_tabela[20];
    int quant_campos=0, opcaoTipo=0, quantCaracteres=0;
    printf("\nSQL Script Generator");
    printf("\n\nQual sera o nome da tabela? ");
    fflush(stdin);
	  gets(nome_tabela);
    printf("%s tera quantos campos? ", nome_tabela);
    scanf("%i", &quant_campos);
    char arrayCampos[quant_campos][20];
    char arrayTiposCampos[quant_campos][20];
    for(int i=0; i<quant_campos; i++){
        printf("\n\n");
        printf("Nome do campo %i: ",i+1);
        scanf("%s", &arrayCampos[i]);
        printf("Selecione o tipo do campo %s: ", arrayCampos[i]);
        printf("\n1-VARCHAR\n2-INT\n3-FLOAT\n4-DATE\n5-Outro\n");
        scanf("%i", &opcaoTipo);
        switch(opcaoTipo){
            case 1:
                strcpy(arrayTiposCampos[i], "VARCHAR(50)");
                break;
            case 2:
                strcpy(arrayTiposCampos[i], "INT");
                break;
            case 3:
                strcpy(arrayTiposCampos[i], "FLOAT");
                break;
            case 4:
                strcpy (arrayTiposCampos[i], "DATE");
                break;
            default:
                printf("Tipo do campo: ");
                scanf("%s", &arrayTiposCampos[i]);
                break;
        }
    }
    printf("\n\n\n");
    fprintf(arquivo, "CREATE TABLE %s (\n", nome_tabela);
    for(int i=0; i<quant_campos; i++){
        if(i == quant_campos-1){
            fprintf(arquivo, "%s %s\n", arrayCampos[i], arrayTiposCampos[i]);
            break;
        }
        fprintf(arquivo, "%s %s,\n", arrayCampos[i], arrayTiposCampos[i]);
    }
    fprintf(arquivo, ");");
    printf("Arquivo tables.sql gerado com sucesso!\nAssim que gerado, o arquivo é salvo automaticamente na mesma pasta onde se encontra o programa");
    system("cd downloads");
    system("tables.sql");
}
