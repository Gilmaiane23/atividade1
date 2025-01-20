
#include "pico/stdlib.h"

// Configuração teclado matricial
uint8_t linhas[4]={16,17,18,28};  //amarelo=28;
uint8_t colunas[4]={19,20,4,9};  //azul=19;
uint8_t n_lin=4,n_col=4;

char teclas[4][4] = {{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};


void menu(){
    printf("Bem vindo! Comandos disponíveis:\n");
    printf("  Tecla 1 - Liga o LED vermelho\n");
    printf("  Tecla 2 - Desliga o LED vermelho\n");
    printf("  Tecla 3 - Liga o LED verde\n");
    printf("  Tecla 4 - Desiga o LED verde\n");
    printf("  Tecla 5 - Liga o LED azul\n");
    printf("  Tecla 6 - Desiga o LED azul\n");
    printf("  Tecla # - Aciona o buzzer \n");

}   
// Inicializa o teclado matricial
void inicializa_teclado(){
  for(uint8_t i=0; i<n_lin; i++){
    gpio_init(linhas[i]);
    gpio_set_dir(linhas[i],GPIO_OUT);
    gpio_put(linhas[i],1);
  }

  for(uint8_t i=0; i<n_col; i++){
    gpio_init(colunas[i]);
    gpio_set_dir(colunas[i],GPIO_IN);
    gpio_pull_up(colunas[i]);
  }
}


// Verifica tecla pressionada
char teclado(){

  char caractere=' ';

  for(uint8_t i=0; i<n_lin;i++){
    gpio_put(linhas[i],0);

    for(uint8_t j=0;j<n_col;j++){
      if(!gpio_get(colunas[j])){
        caractere=teclas[i][j];
        
        while(!gpio_get(colunas[j])){
          sleep_ms(10);
        }

        break;
      }
    }
    gpio_put(linhas[i],1);
  }
  return caractere;
}
