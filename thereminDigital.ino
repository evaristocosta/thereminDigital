//Carrega as bibliotecas de sensor ultrassonico e toneAC
#include <Ultrasonic.h>
#include <toneAC.h>
 
//Define os pinos para trigger e echo 
int pino_trigger1 = A0;
int pino_echo1 = A1;
int pino_trigger2 = A5;
int pino_echo2 = A4;
 
//Inicializa os sensores nos pinos definidos acima
Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);
 
void setup() {}
 
void loop() {
	//Le as informacoes dos sensores em cm
	float cm1, cm2, nota, intensidade;
	long microsec1 = ultrasonic1.timing();
	long microsec2 = ultrasonic2.timing();
	cm1 = ultrasonic1.convert(microsec1, Ultrasonic::CM);
	cmc2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);

    // Mapeia a leitura dos sensores entre 5cm e 30cm
    // Notas vao de La2 ate La4 (2 oitavas)
	nota = map(cm1, 5, 30, 220, 880);
	// Intensidade varia entre minino e maximo possivel
	intensidade = map(cm2, 5, 30, 1, 10);

	toneAC(nota, intensidade);
}