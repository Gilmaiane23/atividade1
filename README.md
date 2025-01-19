 # **Projeto com Raspberry Pi Pico W: Controle de Pinos por Teclado Matricial**

## **Descrição do Projeto**
**Objetivo do projeto:** Com fim a aprimorar os conceitos básicos de programação em Sistemas Embarcados, este projeto desenvolvido na placa Raspberry 
Pi Pico W, utiliza um **Teclado Matricial 4x4** para controlar um **LED RGB** e um **buzzer**, todos conectados aos pinos GPIO da respectiva placa. Baseada no **microcontrolador 
RP 2040**, a placa foi programada em **linguagem C** seguindo os padrões da **Pico C/C++ SDK**, além de contar com o ambiente de simulação Wokwi que permite o monitoramento
serial do sistema. Para a aplicação prática foi utilizada a placa **BitDogLab** (esta comporta uma Raspberry Pi Pico W) que conta com um LED RGB (pinos: 11 (verde), 12(azul), 13(vermelho)) e um buzzer (pinos: 10 e 21).


![keypad_control](https://github.com/user-attachments/assets/134fe01f-c358-4565-a7b4-e07b7bd5370d)

A imagem apresenta a **BitDogLab** (à esquerda) e o **Teclado Matricial** (à direita) utilizados na prática.

## **Funcionalidades**
O projeto contém um teclado matricial 4x4 que controla, ao pressionar suas teclas, um LED RGB e um Buzzer na placa Raspberry Pi Pico W. Segue a função de cada tecla:
- "1": Liga o LED vermelho
- "2": Desliga o LED vermelho
- "3": Liga o LED verde
- "4": Desliga o LED verde
- "5": Liga o LED azul
- "6": Desliga o LED azul
- "#": Ativa o buzzer (sinal sonoro)

## Componentes Utilizados

### Hardware
- **Microcontrolador RP 2040**
- **Raspberry Pi Pico W**
- **Teclado Matricial 4x4**
- **LED RGB**
- **Buzzer (Alto-falante)**

### Software
- **Linguagem C**
- **IDE Visual Studio Code**
- **Extensões do Visual Studio Code**:
  - Raspberry Pi Pico
  - CMake Tools
  - Wokwi
  - C/C++
- **Bibliotecas**:
  - `pico/stdlib`
  - `stdio`
  - `hardware/pwm`
  - `hardware/clocks`
    
### **Pré-requisitos para utilização**
Certifique-se de que os seguintes itens estão instalados:

1. **Visual Studio Code**  
   - Ambiente de desenvolvimento integrado (IDE) para edição, compilação e depuração do código.

2. **Git**  
   - Ferramenta para versionamento de código e controle de repositórios.  

3. **Extensões do Visual Studio Code**  
   - **C/C++**: Suporte à linguagem C/C++ para análise de código, depuração e IntelliSense.  
   - **CMake Tools**: Para gerenciar e configurar projetos que utilizam o CMake.  
   - **Wokwi**: Extensão para simulação do projeto em ambiente virtual com a Raspberry Pi Pico W.  
   - **Raspberry Pi Pico**: Extensão para facilitar o desenvolvimento e a comunicação com a placa Raspberry Pi Pico.  

4. **Zadig**  
   - Software necessário para instalar drivers USB.  
   - Permite a conexão via USB da placa Raspberry Pi Pico com o desktop ou notebook.  

5. **Versão 2.0.0+ do Raspberry Pi Pico SDK**  
   - Certifique-se de que a versão 2.0.0 ou superior do SDK para Raspberry Pi Pico está instalada.  
---

## **Como executar o Projeto**

### **1. Configuração Inicial**
1. Certifique-se de que todas as dependências acima estão instaladas no seu computador.
2. Clone o repositório do projeto usando os comandos abaixo no terminal:  
   ```bash
   git init
   git clone [link do repositório]
3. Abra o projeto clonado no VS Code

### **2. Compilação e Carregamento na Placa**
1. Compile o projeto clicando na opção "**Compile Project**" da extensão Raspberry Pi Pico no **Visual Studio Code**.
2. Após a compilação bem-sucedida, conecte a Raspberry Pi Pico W ao computador utilizando um cabo USB.
3. Coloque a placa em modo **BootSel**:
   - Pressione e segure o botão **BOOTSEL** enquanto conecta a placa pelo cabo USB.
   - Caso esteja utilizando a BitDogLab, aperte o botão **RESET** enquanto pressiona e segura o botão **BOOTSEL** (este método não exige a reconexão do cabo USB) 
4. Localize o arquivo gerado com extensão .uf2 (como **tarefa1.uf2**) e arraste-o para o dispositivo que aparecerá no computador.
   
### 3. Operação na Prática
1. Conecte o teclado matricial, o LED RGB e o buzzer aos pinos GPIO indicados no projeto.
2. Inicie a aplicação.
3. Use o teclado para interagir com os periféricos:
   - Pressione "1" para acender o LED vermelho e "2" para apagá-lo.
   - Teste as demais teclas conforme descrito na seção **Funcionalidades**.

## **Exemplo de Uso**
// Inserir vídeo

## **Licença**
// Inserir licença educacional
