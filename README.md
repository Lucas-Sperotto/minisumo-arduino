# Robô MiniSumo com Arduino

Este repositório contém o código-fonte e instruções para montar um **robô minisumo** utilizando **Arduino**. O robô é projetado para competir em lutas de sumô, detectando adversários com sensores ultrassônicos e evitando a saída da arena com sensores infravermelhos.

## 📜 Descrição do Projeto
O robô segue uma lógica simples:
1. **Detecta a linha da arena** usando sensores infravermelhos e recua caso esteja prestes a sair.
2. **Busca um oponente** utilizando um sensor ultrassônico.
3. **Ataca** o oponente ao detectá-lo dentro do alcance.
4. **Se não houver adversário**, continua se movendo para frente.

## 🛠️ Componentes Utilizados
- Arduino Uno R3
- Driver Ponte H L9110s
- Sensores Infravermelhos TCRT5000
- Sensor Ultrassônico HC-SR04
- Motores DC com caixa de redução 48:1 200RPM + Rodas
- Baterias 18650 Li-Ion 3.7V + Carregador
- Chassi MDF

## 🚀 Como Usar
1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/minisumo-arduino.git
   ```
2. Abra o arquivo `minisumo.ino` na **IDE do Arduino**.
3. Selecione a placa **Arduino Uno** e a porta correta.
4. Compile e envie o código para a placa.
5. Monte o hardware conforme os componentes listados.
6. Pressione o botão para iniciar a luta!

## 📜 Licença
Este projeto está licenciado sob a licença **MIT**. Veja o arquivo `LICENSE` para mais detalhes.

## 📞 Contato
Caso tenha dúvidas ou sugestões, entre em contato!

---
📌 Desenvolvido para fins educacionais e competições de robótica. Divirta-se montando seu robô! 🤖🔥

