#ifndef MiniLFR_h
#define MiniLFR_h

#define PIN_BUZZ  4
#define EYE_LEFT  12
#define EYE_RIGHT 11

#define PIN_RGB	  13
#define PIN_BTN1  7
#define PIN_BTN2  8

#define PIN_M1A	6
#define PIN_M1B 5
#define PIN_M2A 10
#define PIN_M2B 9

#define IR_POWER	0xFFA25D
#define IR_MENU		0xFF629D
#define IR_MUTE		0xFFE21D
#define IR_MODE		0xFF22DD
#define IR_PLUS		0xFF02FD
#define IR_RETURN	0xFFC23D
#define IR_BACK		0xFFE01F
#define IR_PLAY		0xFFA857
#define IR_FORWARD	0xFF906F
#define IR_0		0xFF6897
#define IR_MINUS	0xFF9867
#define IR_OK		0xFFB04F
#define IR_1		0xFF30CF
#define IR_2		0xFF18E7
#define IR_3		0xFF7A85
#define IR_4		0xFF10EF
#define IR_5		0xFF38C7
#define IR_6		0xFF5AA5
#define IR_7		0xFF42BD
#define IR_8		0xFF4AB5
#define IR_9		0xFF52AD

class MiniLFR
{
private:
	float error, errorLast, erroInte;
	int outlineCnt;
	float getTrace();
	float calcPid(float input);
	bool loopCallback(uint32_t key);
   
public:
	float Kp = 90; // 80
	float Ki = 0.15; // 0.15
	float Kd = 1200; //1200
	
	MiniLFR();
	void init();
	void loadSetup();
	void syncSetup();
	void loop();
	int registerCallback(uint32_t key, void * fun());
	// motor related
	void speedSet(int spdl, int spdr);
	void speedSet(int spdl, int spdr, int duration);
	void stopMotor();
	void motorDiffSet(float diff);
	float motorDiffGet();
	// peripheral
	int buttonGet(int btn);
	void spotlightSet(int left, int right);
	float distance();
	float batteryVoltage();
	uint32_t infraReceive();
	void infraSend(int hex);
	void extIo(int d12, int d10, int t);
	// music 
	void buzz(int freq, int duration);
	void buzz(int freq, int duration, int delayms);
	void playNote(int note, int clap);
	void playMusic(const char * notes);
	// RGB
	void setRgbBrightness(int value);
	void hoverRgbShow(int pix, int r, int g, int b);
	void headRgbShow(int pix, int r, int g, int b);
	void ringRgbShow(int pix, int r, int g, int b);
	// Sensor
	int getSensor(int index);
	void setSensorThreshold(int index, int value);
	int getSensorThreshold(int index);
	void setSensorMax(int index, int value);
	int getSensorMax(int index);
	void setSensorMin(int index, int value);
	int getSensorMin(int index);
	// LED matrix
	void matrixShow(const char * data);
	void matrixShowString(const char * str);
	// Linefollow related
	void updatePid(float p, float i, float d);
	void startLineFollow();
	int pidLoop();
protected:
	int AD[5] = { A3,A2,A1,A0,A6 };
};
#endif
