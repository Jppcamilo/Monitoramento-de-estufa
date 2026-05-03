# Sistema de Monitoramento de Estufa (IoT) 🌿

Projeto de Internet das Coisas (IoT) desenvolvido para o curso de Análise e Desenvolvimento de Sistemas da FIAP, focado no monitoramento ambiental de uma estufa agrícola.

## 👨‍💻 Integrantes
* João Pedro Camilo (RM 562005)
* Lucas Matsubara Reis
* Pamella Christiny Chaves Brito

## 🎥 Demonstração
* **Vídeo do projeto rodando:** [https://youtu.be/vJaBlemnND8](https://youtu.be/vJaBlemnND8)

## 🏗️ Arquitetura do Projeto
A solução foi desenhada para conectar hardware simulado a um banco de dados em nuvem através de mensageria assíncrona:
1. **Hardware:** ESP32 simulado no Wokwi, coletando dados de sensores DHT22 (Temperatura e Umidade) e LDR (Luminosidade).
2. **Mensageria (MQTT):** Broker HiveMQ Cloud operando via porta segura (8883) com TLS.
3. **Backend & Integração:** Node-RED atuando como subscriber MQTT, processando os dados e consumindo a API externa do OpenWeatherMap (Clima Externo).
4. **Armazenamento:** Banco de Dados relacional MySQL hospedado na Clever Cloud.

## 📦 Estrutura de Arquivos
* `main.cpp`: Código em C++ utilizado no microcontrolador ESP32.
* `flows.json`: Fluxo de integração exportado do Node-RED.
* `database.sql`: Script de criação da tabela no MySQL.
