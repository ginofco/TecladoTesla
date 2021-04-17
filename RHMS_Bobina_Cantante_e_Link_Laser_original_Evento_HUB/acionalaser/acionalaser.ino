
int pin2 = 9;
int valor = 0;
void setup(){


  pinMode (pin2, OUTPUT);



}

void loop(){

valor = analogRead(0); // Le sensor e guarda a leitura em valor

    if ( valor < 490 ){    // Verifica se batida foi maior que 120

      digitalWrite(pin2, HIGH);                // Conta as batidas

      delay (10000);             // Atraso para a proxima leitura

      digitalWrite (pin2, LOW);
}
}

