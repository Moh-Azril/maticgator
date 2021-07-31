#include <TroykaDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define NUMITEMS(arg) ((unsigned int) (sizeof (arg) / sizeof (arg [0])))

// SENSOR
#define DHTpin A0
#define DHTtype DHT11

//LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal_I2C lcd(0x27,20,4);
DHT dht(DHTpin,DHTtype);

// pin input
#define kanan A1
#define kiri A3
#define enter A2
#define mulai 2

// PIN OUTPUT
#define heater  4  // pin pemanas
#define fan  5  // pin DC FAN
#define mist  6 // pin mist

// kondisi input
int buttonRisingEdgeKanan = 0, lastButtonStateKanan = 0;
int buttonRisingEdgeKiri = 0, lastButtonStateKiri = 0;
int buttonRisingEdgeEnter = 0, lastButtonStateEnter = 0;
int buttonRisingEdgeMulai = 0, lastButtonStateMulai = 0;

int lastButtonPressed = NULL;

// Kondisi alat
/* kondisi 1 : pilihJenis
 * kondisi 2 : pilihGender
 * kondisi 3 : kontrol
*/
const int pilihJenis = 1, pilihGender = 2, kontrol = 3;
int kondisi;

// Jenis Telur
String jenis[] = {"AYAM", "PENYU"};
int index_jenis;
int maxIndexJenis;

String gender = "";

// nilai pembacaan sensor
float suhu;
int kelembapan;
int id=1;

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();

  // INPUT
  pinMode(kanan,INPUT_PULLUP);
  pinMode(kiri,INPUT_PULLUP);
  pinMode(enter,INPUT_PULLUP);
  pinMode(mulai,INPUT_PULLUP);
  
  // OUTPUT
  pinMode(heater,OUTPUT); digitalWrite(heater,HIGH);
  pinMode(fan,OUTPUT); digitalWrite(fan,HIGH);
  pinMode(mist,OUTPUT); digitalWrite(mist,HIGH);

  //Set initial states
  lastButtonStateKanan = digitalRead(kanan);
  buttonRisingEdgeKanan = lastButtonStateKanan;

  lastButtonStateKiri = digitalRead(kiri);
  buttonRisingEdgeKiri = lastButtonStateKiri;
  
  lastButtonStateEnter = digitalRead(enter);
  buttonRisingEdgeEnter = lastButtonStateEnter;
  
  lastButtonStateMulai = digitalRead(mulai);
  buttonRisingEdgeMulai = lastButtonStateMulai;
  
  kondisi = 1;
 
  maxIndexJenis = NUMITEMS (jenis) - 1;
  if (maxIndexJenis <= 0) maxIndexJenis = 0;
  index_jenis = -1;
  
}

void loop() {
  switch(kondisi) {
    case pilihJenis:
      memilihJenis();
      break;
     case pilihGender:
      memilihGender();
      break;
     case kontrol:
      inkubasi();
      break;  
    default:
      welcome();
      break;
  }
}

void welcome() {
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print("   MATICGATOR");//incubator's turtle
//  mySerial.println("MATICGATOR");
//  mySerial.println("================");
  delay(2000);
  lcd.clear();
  kondisi = pilihJenis;
}

void memilihJenis() {
    // deteksi tombol yang ditekan
  switch(buttonkey(&lastButtonPressed)) {
      case kanan:
            index_jenis += 1;
            if (index_jenis > maxIndexJenis) {index_jenis = maxIndexJenis;}
            lcd.clear();
            break;
        case kiri:
            index_jenis -= 1;
            if (index_jenis < 0) {index_jenis = 0;}
            lcd.clear();
            break;
        case enter:
            kondisi = pilihGender;
            lcd.clear();
            break;  
        default:
          if (index_jenis < 0){
              lcd.setCursor(1,0);
              lcd.print("Silahkan Pilih");  
              lcd.setCursor(1,1);// (x colom ,y baris)
              lcd.print("   Jenisnya   ");
            } else {
              lcd.setCursor(0,0);
              lcd.print("  Anda Memilih  ");
              lcd.setCursor(0, 1);
              lcd.print(jenis[index_jenis]);
            }
        break;
    }
  
}

void memilihGender() {

  switch(buttonkey(&lastButtonPressed)) {
      case kanan:
            gender = "JANTAN";
            lcd.clear();
            break;
        case kiri:
            gender = "BETINA";
            lcd.clear();
            break;
        case enter:
            kondisi = pilihJenis;
            index_jenis = -1;
            gender = "";
            lcd.clear();
            break;
        case mulai:
            kondisi = kontrol;
            lcd.clear();
            break; 
        default:
            lcd.setCursor(0,0);
            lcd.print("Pilih Gender   ");
            lcd.setCursor(0,1);
            lcd.print(String(jenis[index_jenis]) + " " + String(gender));
        break;
  }
  
}

void inkubasi() {
  
  if (gender == "JANTAN"){    
    if (suhu < 27) {
      id=1;
      digitalWrite(fan,HIGH);
      digitalWrite(heater,LOW);
    } else if (suhu >= 27 && suhu < 29) {
      if (id==1) {
        digitalWrite(fan,HIGH);
        digitalWrite(heater,LOW);
      } else {
        digitalWrite(fan,LOW);
        digitalWrite(heater,HIGH);
      }   
    } else if (suhu >= 29) {
      id=0;
      digitalWrite(fan,LOW);
      digitalWrite(heater,HIGH);     
    }
    
  } else if (gender == "BETINA") {    
    if (suhu < 29) {
      id=1;
      digitalWrite(fan,HIGH);
      digitalWrite(heater,LOW);
    } else if (suhu >= 29 && suhu < 32) {
      if (id==1) {
        digitalWrite(fan,HIGH);
        digitalWrite(heater,LOW);
      } else {
        digitalWrite(fan,LOW);
        digitalWrite(heater,HIGH);
      }   
    } else if (suhu >= 32) {
      id=0;
      digitalWrite(fan,LOW);
      digitalWrite(heater,HIGH);     
    }
    
  }
  
}

bool PinStateChanged(int pin, int *lastButtonState, int *buttonRisingEdge)
{
 //Get pin state
 int buttonState = digitalRead(pin);
 
 //Here starts the code for detecting an edge
 if (buttonState != *lastButtonState) {
 if (buttonState == LOW) {
 *buttonRisingEdge = 0;
 } else {
 *buttonRisingEdge = 1;
 }
 *lastButtonState = buttonState;
 return true;
 }
 
 return false;
}

int buttonkey(int *lastButtonPressed) {
  if (PinStateChanged(kanan, &lastButtonStateKanan, &buttonRisingEdgeKanan)) {
    //Pin 11 state changed.
    //buttonRisingEdgeA says how: 0 == falling, 1 == Rising
    if (buttonRisingEdgeKanan == 0) {
      if (*lastButtonPressed == NULL){
        *lastButtonPressed = kanan;
        return kanan;
        Serial.println("There was a falling edge on pin " + String());
      }
    } else {
      if (*lastButtonPressed == kanan){
        Serial.println("There was a rising edge on pin 6");
        *lastButtonPressed = NULL;
      }
    }
  } else if (PinStateChanged(kiri, &lastButtonStateKiri, &buttonRisingEdgeKiri)) {
    //Pin 12 state changed.
    //buttonRisingEdgeB says how: 0 == falling, 1 == Rising
    if (buttonRisingEdgeKiri == 0) {
      if (*lastButtonPressed == NULL){
        *lastButtonPressed = kiri;
        return kiri;
        Serial.println("There was a falling edge on pin 7");
      }
    } else {
      if (*lastButtonPressed == kiri){
        Serial.println("There was a rising edge on pin 7");
        *lastButtonPressed = NULL;
      }
    }
  } else if (PinStateChanged(enter, &lastButtonStateEnter, &buttonRisingEdgeEnter)) {
    //Pin 12 state changed.
    //buttonRisingEdgeB says how: 0 == falling, 1 == Rising
    if (buttonRisingEdgeEnter == 0) {
      if (*lastButtonPressed == NULL){
        *lastButtonPressed = enter;
        return enter;
        Serial.println("There was a falling edge on pin 7");
      }
    } else {
      if (*lastButtonPressed == enter){        
        Serial.println("There was a rising edge on pin 7");
        *lastButtonPressed = NULL;
      }
    }
  } else if (PinStateChanged(mulai, &lastButtonStateMulai, &buttonRisingEdgeMulai)) {
    //Pin 12 state changed.
    //buttonRisingEdgeB says how: 0 == falling, 1 == Rising
    if (buttonRisingEdgeMulai == 0) {
      if (*lastButtonPressed == NULL){
        *lastButtonPressed = mulai;
        return mulai;
        Serial.println("There was a falling edge on pin 7");
      }
    } else {
      if (*lastButtonPressed == mulai){
        Serial.println("There was a rising edge on pin 7");
        *lastButtonPressed = NULL;
      }
    }
  }
  return -1;
}
