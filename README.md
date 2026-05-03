# 🌿 Sistema de Monitoramento de Estufa (IoT)

Projeto de Internet das Coisas (IoT) desenvolvido para o curso de Análise e Desenvolvimento de Sistemas da FIAP.

## 👨‍💻 Integrantes
* João Pedro Camilo (RM 562005)
* Lucas Matsubara Reis (RM 565020)
* Pamella Christiny Chaves Brito (RM 565206)

## 🎥 Demonstração do Projeto
* **Link do vídeo:** [https://youtu.be/vJaBlemnND8](https://youtu.be/vJaBlemnND8)

---

## 1. Descrição do Projeto
A solução consiste em um ecossistema IoT projetado para o monitoramento contínuo de uma estufa agrícola. O sistema coleta dados em tempo real do ambiente interno (temperatura, umidade e luminosidade) através de sensores simulados em um ESP32. Além do monitoramento interno, o sistema consome uma API externa para capturar a temperatura climática da cidade, permitindo uma comparação visual através de um dashboard interativo. Todos os dados coletados pelos sensores são armazenados em um banco de dados relacional em nuvem para histórico e futuras análises.

## 2. Arquitetura da Solução
A infraestrutura foi dividida em quatro camadas principais:
*   **Edge (Hardware):** Um microcontrolador ESP32 programado em C++ realizando a leitura de um sensor DHT22 (Temperatura/Umidade) e um LDR (Luminosidade).
*   **Mensageria:** Comunicação via protocolo MQTT utilizando o broker HiveMQ Cloud. A conexão é criptografada via TLS/SSL (Porta 8883) garantindo a segurança no envio dos dados de telemetria.
*   **Integração e Visualização:** O Node-RED atua como o cérebro da operação. Ele assina os tópicos MQTT, formata os dados, consome a API do OpenWeatherMap (HTTP GET) para obter o clima externo e plota todas as informações em um Node-RED Dashboard.
*   **Persistência:** Banco de dados relacional (MySQL) hospedado em nuvem (Clever Cloud), recebendo requisições diretas do Node-RED para gravação do histórico.

## 3. Tecnologias Utilizadas
*   **C / C++** (Framework Arduino para ESP32)
*   **Wokwi Simulator** (Simulação do circuito e hardware)
*   **VS Code & PlatformIO** (Ambiente de desenvolvimento e compilação)
*   **MQTT & HiveMQ Cloud** (Protocolo de comunicação e Broker)
*   **Node-RED** (Orquestração de dados e Dashboard de UI)
*   **MySQL & Clever Cloud** (Banco de dados na nuvem)
*   **OpenWeatherMap API** (Dados meteorológicos externos)

## 4. Instruções de Execução

### Pré-requisitos
*   Node-RED instalado ou rodando em nuvem.
*   Visual Studio Code com as extensões `PlatformIO IDE` e `Wokwi Simulator`.
*   Acesso a um banco de dados MySQL.

### Passo a Passo
1.  **Banco de Dados:**
    *   Rode o script fornecido no arquivo `database.sql` na sua instância MySQL para criar a tabela `medicoes_estufa`.
2.  **Node-RED:**
    *   No Node-RED, vá no menu superior direito > Importar > Selecione o arquivo `flows.json` deste repositório.
    *   Ajuste as credenciais dos nós MQTT (usuário e senha do seu broker HiveMQ) e do nó MySQL (usuário, senha e host do seu banco Clever Cloud).
    *   Clique em "Deploy". O dashboard estará acessível no caminho `/ui`.
3.  **Simulação do Hardware (ESP32):**
    *   Abra a pasta do projeto C++ no VS Code.
    *   Aguarde o PlatformIO carregar as dependências e clique no botão **Build** (ícone de check no rodapé) para gerar o executável `.elf`.
    *   Abra o comando do VS Code (`F1`), digite `Wokwi: Start Simulator` e dê Enter.
    *   O simulador iniciará, conectará ao WiFi virtual, enviará os dados via MQTT e os ponteiros do Node-RED reagirão em tempo real.
