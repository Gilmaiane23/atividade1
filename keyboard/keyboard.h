#include <pico/stdlib.h>


void inicializa_teclado(uint8_t linhas[], uint8_t colunas[], uint8_t n_lin,uint8_t n_col){
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

char teclado(uint8_t linhas[], uint8_t colunas[], uint8_t n_lin,uint8_t n_col,char teclas[n_lin][n_col] ){

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