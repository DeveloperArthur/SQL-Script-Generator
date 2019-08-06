#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lerArquivo();
void gravarArquivo();

int main(){
  gravarArquivo();
  lerArquivo();
  return 0;
}

void lerArquivo(){
  FILE *ler;
  char Linha[100], *result;
  int i = 1;
  ler = fopen("table.sql", "rt");
  while (!feof(ler)){
    result = fgets(Linha, 100, ler);
    if (result) 
      printf("%s",Linha); 
      i++;
  }
  fclose(ler);
  printf("\n\nArquivo salvo na mesma pasta onde se encontra o programa.\n\n");
  system("pause");
}

void gravarArquivo(){
  FILE *gravar;
  gravar = fopen("table.sql", "w");
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
      printf("\n1-VARCHAR(50)\n2-INT\n3-FLOAT\n4-DATE\n5-Outro\n");
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
  fprintf(gravar, "CREATE TABLE %s (\n", nome_tabela);
  for(int i=0; i<quant_campos; i++){
      if(i == quant_campos-1){
          fprintf(gravar, "%s %s\n", arrayCampos[i], arrayTiposCampos[i]);
          break;
      }
      fprintf(gravar, "%s %s,\n", arrayCampos[i], arrayTiposCampos[i]);
  }
  fprintf(gravar, ");");
  fclose(gravar);
  printf("Arquivo table.sql gerado com sucesso!\n\n");
}
