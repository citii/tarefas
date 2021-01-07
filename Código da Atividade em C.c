#include <stdio.h>
#include <math.h>
 
int main() {
int matricula[5], qtd_faltas[5], i;
float comissao, salario[5], salario_base=1540.50, vendas_sem1[5], vendas_sem2[5], vendas_sem3[5], vendas_sem4[5], vendas_final[5], frequencia[5];
int opcao, icontrol=0, excluir, alterar;
do{
 printf("----------------------MENU----------------------\n");
 printf("1- CADASTRAR VENDEDOR\n");
 printf("2- REMOVER VENDEDOR\n");
 printf("3- ALTERAR\n");
 printf("4- VENDEDORES CADASTRADOS\n");
 printf("5- VENDEDORES SENIOR\n");
 printf("6- VENDEDORES PLENO COM FREQUENCIA MAIOR QUE 80%%\n");
 printf("7- VENDEDORES COM FREQUENCIA ABAIXO DE 60%%\n");
 printf("0- SAIR\n");
 printf("------------------------------------------------\n");
 scanf("%d", &opcao);
   switch(opcao){
       case 1:{
           if(icontrol == 5){
             printf("\nNAO A ESPACO PARA NOVO CADASTRO\n");
             break;
           }
          
           printf("MATRICULA PARA CADASTRO:\n");
           scanf("%d", &matricula[icontrol]);
 
           do{
             printf("INFORME A QUANTIDADE DE FALTAS:\n");
             scanf("%d", &qtd_faltas[icontrol]);
             if(qtd_faltas[icontrol] < 0){
               printf("\nA QUANTITADE DE FALTAS E INVALIDA\n\n");
             }
             else if(qtd_faltas[icontrol] > 26){
               printf("\nA QUANTITADE DE FALTAS E INVALIDA\n\n");
             }
           }while(qtd_faltas[icontrol] < 0||qtd_faltas[icontrol] > 26);
          
           printf("Semana 1:\n");
           scanf("%f", &vendas_sem1[icontrol]);
           printf("Semana 2:\n");
           scanf("%f", &vendas_sem2[icontrol]);
           printf("Semana 3:\n");
           scanf("%f", &vendas_sem3[icontrol]);
           printf("Semana 4:\n");
           scanf("%f", &vendas_sem4[icontrol]);
        
           vendas_final[icontrol] = vendas_sem1[icontrol]+vendas_sem2[icontrol]+vendas_sem3[icontrol]+vendas_sem4[icontrol];
           if(vendas_final[icontrol] > 10000){
             comissao = (vendas_final[icontrol]/4)*0.15;
           }
           else if(vendas_final[icontrol] > 5000 && vendas_final[icontrol] <= 10000){
                 comissao = (vendas_final[icontrol]/4)*0.10;
           }
           if(vendas_final[icontrol] <= 5000){
                 comissao = (vendas_final[icontrol]/4)*0.05;
           }
           frequencia[icontrol]= 100-((qtd_faltas[icontrol]*100)/26);
           salario[icontrol] =  salario_base+comissao;
           icontrol++;
           break;
       }
       case 2:{
           if(icontrol == 0){
             printf("NAO HA VENDEDORES CADASTRADOS\n");
             break;
           }
           printf("INFORME A MATRICULA QUE DESEJA EXCLUIR\n");
           scanf("%d", &excluir);
           for(i=0; i<5; i++){
             if(excluir == matricula[i]){
               matricula[i] = -1;
               vendas_sem1[i] = -1;
               vendas_sem2[i] = -1;
               vendas_sem3[i] = -1;
               vendas_sem4[i] = -1;
               salario[i] = -1;
               qtd_faltas[i] = -1;
               icontrol = icontrol - 1;
               printf("REMOVIDO\n");
               break;
             }
             else{
             printf("MATRICULA DE VENDEDOR NAO CADASTRADA\n");
             }
             break;
           }
           break;
       }
       case 3:{
         if(icontrol == 0){
             printf("NAO HA VENDEDORES CADASTRADOS\n");
             break;
           }
           printf("INFORME A MATRICULA QUE DESEJA ALTERAR\n");
           scanf("%d", &alterar);
           for(i=0; i<icontrol; i++){
             if(alterar == matricula[i]){
               printf("INFORME A QUANTIDADE DE FALTAS\n");
               scanf("%d", &qtd_faltas[i]);
               printf("INFORME A SEMANA 1\n");
               scanf("%f", &vendas_sem1[i]);
               printf("INFORME A SEMANA 2\n");
               scanf("%f", &vendas_sem2[i]);
               printf("INFORME A SEMANA 3\n");
               scanf("%f", &vendas_sem3[i]);
               printf("INFORME A SEMANA 4\n");
               scanf("%f", &vendas_sem4[i]);
               vendas_final[i] = vendas_sem1[i]+vendas_sem2[i]+vendas_sem3[i]+vendas_sem4[i];
              if(vendas_final[i] > 10000){
                comissao = (vendas_final[i]/4)*0.15;
              }
              else if(vendas_final[i] > 5000 && vendas_final[i] <= 10000){
                    comissao = (vendas_final[i]/4)*0.10;
              }
              if(vendas_final[i] <= 5000){
                    comissao = (vendas_final[i]/4)*0.05;
              }
               frequencia[i]= 100-((qtd_faltas[i]*100)/26);
               salario[i] = salario_base+comissao;
            
              break;
             }
             else{
             printf("MATRICULA DE VENDEDOR NAO CADASTRADA\n");
             }
             break;
           }
           break;
       }
       case 4:{
           if(icontrol == 0){
             printf("\nNAO HA VENDEDORES CADASTRADOS\n");
             break;
           }
           else{
           printf("-------------VENDEDORES CADASTRADOS-------------\n");
           for(i=0; i<icontrol; ++i){
             printf("MATRICULA: %d\n", matricula[i]);
           }
           for(i=0; i<icontrol; ++i){
             printf("SALARIO DE %d: %.2f\n", matricula[i], salario[i]);
           }
           for(i=0; i<icontrol; ++i){
             printf("FALTAS DE %d: %d\n", matricula[i], qtd_faltas[i]);
           }
           printf("------------------------------------------------\n");
           }
           break;
       }
       case 5:{
           if(icontrol == 0){
             printf("NAO HA VENDEDORES CADASTRADOS\n");
             break;
           }
           else {
             for (i = 0; i < icontrol; i++){
                if(vendas_final[i] > 10000){
                  printf("---------------VENDEDORES SENIOR----------------\n");
                  printf("MATRICULA: %d\n", matricula[i]);
                  printf("SALARIO DE %d: %.2f\n", matricula[i], salario[i]);
                  printf("FALTAS: %d\n", qtd_faltas[i]);
                  printf("------------------------------------------------\n");
                }
                 else if(vendas_final[i] <= 10000){
                   printf("NAO HA NENHUM VENDEDOR SENIOR\n");
                   break;
                 }
             }
             break;
           }
       }
       case 6:{
           if(icontrol == 0){
             printf("NAO HA VENDEDORES CADASTRADOS\n");
             break;
           }
           else {
             for (i = 0; i < icontrol; i++){
                if((vendas_final[i] >5000 && vendas_final[i] <= 10000) && frequencia[i]>80){
                  printf("---------VENDEDORES PLENO ACIMA DE 80%%---------\n");
                  printf("MATRICULA: %d\n", matricula[i]);
                  printf("SALARIO DE %d: %.2f\n", matricula[i], salario[i]);
                  printf("FALTAS: %d\n", qtd_faltas[i]);
                  printf("------------------------------------------------\n");
                 }
                 else if(vendas_final[i] < 5000 || vendas_final[i] > 10000 || frequencia[i]<80){
                   printf("NAO HA NENHUM VENDEDOR PLENO COM FREQUENCIA MAIOR QUE 60%%\n");
                   break;
                 }
             }
             break;
           }
          
       }
       case 7:{
             if(icontrol == 0){
               printf("NAO HA VENDEDORES CADASTRADOS\n");
             break;
             }
             else {
               for (i = 0; i < icontrol; i++){
                 if(frequencia[i]<60){
                   printf("-----VENDEDORES COM FREQUENCIA ABAIXO DE 60%%----\n");
                   printf("MATRICULA: %d\n", matricula[i]);
                   printf("SALARIO DE %d: %.2f\n", matricula[i], salario[i]);
                   printf("FALTAS: %d\n", qtd_faltas[i]);
                   printf("FREQUENCIA: %.2f%%\n", frequencia[i]);
                   printf("------------------------------------------------\n");
                 }
                 else if(frequencia[i]>60){
                   printf("NAO HA NENHUM VENDEDOR COM FREQUENCIA MENOR QUE 60%%\n");
                   break;
                 }
               }
             }
             break;
       }
   }
}while(opcao !=0);
}
