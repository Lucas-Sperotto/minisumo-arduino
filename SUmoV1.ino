// Inclui a biblioteca para o sensor ultrassônico
#include <Ultrasonic.h>

// Definição de pinos para sensores e motores
#define SENSOR_LINHA_ESQUERDA 11
#define SENSOR_LINHA_CENTRO 12
#define SENSOR_LINHA_DIREITA 13
#define BOTAO_LIGAR 2

#define MOTOR_ESQUERDO_FRENTE 5
#define MOTOR_ESQUERDO_TRAS 6
#define MOTOR_DIREITO_FRENTE 9
#define MOTOR_DIREITO_TRAS 10

#define TRIGGER_ULTRASSONICO 8
#define ECHO_ULTRASSONICO 7

// Configuração do sensor ultrassônico
Ultrasonic ultrasonic(TRIGGER_ULTRASSONICO, ECHO_ULTRASSONICO);

void setup() {
  // Configuração dos sensores de linha como entrada
  pinMode(SENSOR_LINHA_ESQUERDA, INPUT);
  pinMode(SENSOR_LINHA_CENTRO, INPUT);
  pinMode(SENSOR_LINHA_DIREITA, INPUT);

  // Configuração do botão de ligar como entrada com pull-up
  pinMode(BOTAO_LIGAR, INPUT_PULLUP);

  // Configuração dos motores como saída
  pinMode(MOTOR_ESQUERDO_FRENTE, OUTPUT);
  pinMode(MOTOR_ESQUERDO_TRAS, OUTPUT);
  pinMode(MOTOR_DIREITO_FRENTE, OUTPUT);
  pinMode(MOTOR_DIREITO_TRAS, OUTPUT);

  // Configuração dos pinos do sensor ultrassônico
  pinMode(TRIGGER_ULTRASSONICO, OUTPUT);
  pinMode(ECHO_ULTRASSONICO, INPUT);

  Serial.begin(9600);
  Serial.println("Iniciando o robô...");

  // Aguarda o botão de ligar ser pressionado para iniciar
  while (digitalRead(BOTAO_LIGAR) == HIGH) {
    Serial.println("Aguardando ligar...");
    stop(); // Mantém o robô parado até ser ligado
    delay(500);
  }
  Serial.println("Robô ligado!");
}

void loop() {
  // Verifica se detectou a linha preta (borda do ringue)
  if (!digitalRead(SENSOR_LINHA_CENTRO) || !digitalRead(SENSOR_LINHA_DIREITA)) {
    Serial.println("Linha detectada! Recuando...");
    stop();
    delay(100);
    re();
    delay(300);
    stop();
    delay(100);
    girar();
    delay(600);
    stop();
  }

  // Lê a distância do sensor ultrassônico
  int distancia = ultrasonic.read(CM);
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Se um oponente for detectado a menos de 30 cm, ataca
  if (distancia > 0 && distancia < 30) {
    Serial.println("Oponente detectado! Atacando...");
    stop();
    delay(100);
    atacar();
    delay(300);
    stop();
  }
  
  // Caso contrário, segue em frente
  else {
    frente();
  }
  delay(50); // Pequena pausa para evitar leituras erradas
}

// Função para mover o robô para trás
void re() {
  Serial.println("Recuar");
  analogWrite(MOTOR_ESQUERDO_FRENTE, 0);
  analogWrite(MOTOR_ESQUERDO_TRAS, 150);
  analogWrite(MOTOR_DIREITO_FRENTE, 0);
  analogWrite(MOTOR_DIREITO_TRAS, 150);
}

// Função para mover o robô para frente
void frente() {
  Serial.println("Avançando");
  analogWrite(MOTOR_ESQUERDO_FRENTE, 150);
  analogWrite(MOTOR_ESQUERDO_TRAS, 0);
  analogWrite(MOTOR_DIREITO_FRENTE, 150);
  analogWrite(MOTOR_DIREITO_TRAS, 0);
}

// Função para girar o robô
void girar() {
  Serial.println("Girando");
  analogWrite(MOTOR_ESQUERDO_FRENTE, 0);
  analogWrite(MOTOR_ESQUERDO_TRAS, 150);
  analogWrite(MOTOR_DIREITO_FRENTE, 150);
  analogWrite(MOTOR_DIREITO_TRAS, 0);
}

// Função para atacar (acelera para frente)
void atacar() {
  Serial.println("Atacando com força máxima");
  analogWrite(MOTOR_ESQUERDO_FRENTE, 200);
  analogWrite(MOTOR_ESQUERDO_TRAS, 0);
  analogWrite(MOTOR_DIREITO_FRENTE, 200);
  analogWrite(MOTOR_DIREITO_TRAS, 0);
}

// Função para parar o robô
void stop() {
  Serial.println("Parado");
  analogWrite(MOTOR_ESQUERDO_FRENTE, 0);
  analogWrite(MOTOR_ESQUERDO_TRAS, 0);
  analogWrite(MOTOR_DIREITO_FRENTE, 0);
  analogWrite(MOTOR_DIREITO_TRAS, 0);
}
