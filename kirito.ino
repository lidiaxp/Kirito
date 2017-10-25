#define opticT A0 //resistor de 10k e um d 300
#define opticF A1 //resistor de 10k e um d 300
#define IN1 3  //tras esquerda
#define IN2 5  //frente esquerda
#define IN3 6   //tras direira
#define IN4 7   //frente direita
#define infra 10

int estinfra = 0;
int leitura0, leitura1, stdLeitura0, stdLeitura1;

//----------------------------------------------------------
void frente(int velocidade) {
  analogWrite(IN3, 0);
  analogWrite(IN4, velocidade);
  analogWrite(IN1, 0);
  analogWrite(IN2, velocidade);
  
}
//----------------------------------------------------------
void tras(int velocidade) { 
  analogWrite(IN3, velocidade);
  analogWrite(IN4, 0);
  analogWrite(IN1, velocidade);
  analogWrite(IN2, 0);
}
//----------------------------------------------------------
void esquerda(int velocidade) {
  analogWrite(IN1, 0);
  analogWrite(IN2, velocidade);
  analogWrite(IN3, velocidade);
  analogWrite(IN4, 0);
}
//----------------------------------------------------------
void parar() {       //ou tudo low
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}

//----------------------------------------------------------
void direita(int velocidade) {
  analogWrite(IN1, velocidade);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, velocidade);
}
//-----------------------------------------------------------
void linhaF(){
  direita(200);
  delay(200);
  tras(200);
  delay(250);
}
//-----------------------------------------------------------
void linhaT(){
  tras(200);
  delay(200);
}
//-----------------------------------------------------------
void lerSensores(){
  estinfra = digitalRead(infra);
  leitura1 = analogRead(opticF);//A0
  leitura0 = analogRead(opticT);//A1
}
//-----------------------------------------------------------
void setup() {
  Serial.begin(9600);
  Serial.println("Espere 4 segundos");
  delay(4000);
  Serial.println("Começamos");
  
  pinMode(opticF, INPUT);
  pinMode(opticT, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(infra, INPUT);
  
  lerSensores();
  
  stdLeitura0 = leitura0;
  stdLeitura1 = leitura1;
  Serial.print("padrao 0: ");
  Serial.println(stdLeitura0);
  Serial.print("padrao 1: ");
  Serial.println(stdLeitura1);
}
//-----------------------------------------------------------
void loop() {
  lerSensores();
  
  /*Serial.print("tras: ");
  Serial.println(leitura0);
  delay(1100);
  Serial.print("frente: ");
   Serial.println(leitura1);
  delay(1100);*/

  if(leitura0 < stdLeitura0 - 13){
    linhaF();
  }else if(leitura1 < stdLeitura1 - 13){
    linhaF();
  }else if(estinfra == 0){
    tras(220);
    delay(1000);
  }else{
    esquerda(150);
    delay(10);  
  }
  //sensor infravermelho
  /*if(leitura0 < stdLeitura0 - 13){
      parar();
      delay(2000);
      //linhaT(); //T
    }
    if(leitura1 < stdLeitura1 - 20){
      parar();
      delay(2000);
      //linhaF(); //F
    }
  
  while (estinfra == 0){
    tras(200);
    delay(10);
  }

    if(leitura0 < stdLeitura0 - 13){
      
      parar();
      delay(2000);//linhaT(); //T
    }
    if(leitura1 < stdLeitura1 - 20){
      parar();
      delay(2000);//linhaF(); //F
    }
    
  esquerda(150);
  delay(10);
  */
  //teste optico
  /*lerSensores();
  Serial.println("frente: ");
  Serial.println(leitura1);
  delay(1000);
  Serial.println("tras: ");
  Serial.println(leitura0);
  delay(1000);*/

  //teste de motores
  /*Serial.println("frente");
  frente(125);
  delay(2000);*/
  /*Serial.println("parar");
  parar();
  delay(2000);*/
  /*Serial.println("tras");
  tras(200);
  delay(2000);*/
  /*Serial.println("esquerda");
  esquerda(200);
  delay(2000);*/
  /*Serial.println("direita");
  direita(200);
  delay(2000);*/

  //teste de sensor infravermelho
  /*lerSensores();
  Serial.print("Sensor: ");
  Serial.println(estinfra);*/
}

