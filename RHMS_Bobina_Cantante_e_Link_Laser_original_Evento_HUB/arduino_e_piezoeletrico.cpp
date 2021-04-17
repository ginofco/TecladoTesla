int conta = 0, valor = 0, batida = 120; // Variaveis
byte piezo = A0;         // Piezo conectado a porta analogica A0
byte Led1 = 2, Led2 = 3; // Define as saidas dos pinos dos led's

void setup(){
  Serial.begin(9600); // Inicia o serial monitor
  pinMode (Led1, OUTPUT);
  pinMode (Led2, OUTPUT);
}
void loop(){
  valor = analogRead (piezo); // Le sensor e guarda a leitura em valor
    if ( valor >= batida){    // Verifica se batida foi maior que 120
      conta++;                // Conta as batidas
      delay (50);             // Atraso para a proxima leitura
      if (conta == 2){        // Se receber 2 batidas faça isso abaixo
      digitalWrite (Led1, HIGH);
      Serial.println ("Led 1 vermelho aceso");  // Imprimi texto na seial monitor
      delay (200);            // Atraso para a proxima leitura
   }      
    if (conta == 4){          // Se a conta chegar a 4 batidas faça osso abaixo
    digitalWrite (Led2, HIGH);
    Serial.println ("Led 2 azul aceso"); // Imprimi o texto na serial monitor
    delay (200);              // Atraso para zera a contagem
    }
    if (conta == 5){          // Se a conta chegar a 5 batidas faça isso abaixo
    digitalWrite (Led1, LOW); // Apaga o Led1 vermelho
    digitalWrite (Led2, LOW); // Apaga o Led2 azul
    Serial.println ("Apaga os Led's"); // Imprimi texto no serial monitor
    delay (200);              // Atraso de 200 ms
    conta = 0;                // Zeraa contagem das batidas
   }
 }
}