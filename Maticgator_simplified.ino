#include <TroykaDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//unecessary
//#define powlcd 12

----------------// INPUT --------------
// SENSOR
#define DHTpin A0
#define DHTtype DHT11

// TOMBOL
int male=A1;
int female=A3;
int enter=A2;
int mulai=2;

-------------// OUTPUT --------------
#define heater  4  // pin pemanas
#define fan  5  // pin DC FAN
#define mist  6 // pin mist


//LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal_I2C lcd(0x27,20,4);
DHT dht(DHTpin,DHTtype);


int m,f,e,s,m1,f1,e1;
int lock=0;
float a,t;

int volt = 1;
String jenis[] = {"Penyu",
                  "Kura-kura",
                  "Labi-labi",
                  "Ular",
                  "Iguana",
                  "Bearded Dragon",
                  "Water Dragon",
                  "Kura-kura Asia",
                  "Komodo",
                  "Aligator",
                  "Leopard Gecko",
                  "Red Eared Slider",
                  "Lainnya"};
//int tukik,kura,labi,ular,iguana,Bearded,Water,asia,komodo,aligator,gecko,slider,lainnya; 
//String jenis, jenisKelamin;

int h,b;
int id=1;
String jenisTukik, device, timerPompa;

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();

  pinMode(heat,OUTPUT); digitalWrite(heat,HIGH);
  pinMode(cold,OUTPUT); digitalWrite(cold,HIGH);
  pinMode(coldin,OUTPUT); digitalWrite(coldin,HIGH);
//  pinMode(powlcd,OUTPUT); digitalWrite(powlcd,HIGH);
  pinMode(male,INPUT_PULLUP);
  pinMode(female,INPUT_PULLUP);
  pinMode(enter,INPUT_PULLUP);
  pinMode(mulai,INPUT_PULLUP);
  
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  Serial.println("WELCOME");  
  delay(500);
  lcd.print("   MATICGATOR");//incubator's turtle
//  mySerial.println("MATICGATOR");
//  mySerial.println("================");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Silahkan Pilih");  
  lcd.setCursor(1,1);// (x colom ,y baris)
  lcd.print("   Jenisnya   ");
//  mySerial.println("Silahkan Pilih Jantan / Betina");      
  delay(3000);   
  lcd.clear();
}

void loop()
{
    if(lock==0)
    {
      m = digitalRead(male);
      f = digitalRead(female);
      e = digitalRead(enter);
      s = digitalRead(mulai);
      if(m==0)
        { 
        volt+=1;
        if(volt>=13) volt=13; 
        delay(1000);}
      if(f==0)
        { 
        volt-=1; 
        if(volt<=0) volt=1; 
        delay(1000);}
    }
//===========
//----------------Penyu----------------------//
    if(volt==1)
    { 
      tukik=1;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(tukik==1)
      {   
        Serial.print("Penyu");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("     Penyu      ");        
//        jenis = "Penyu";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          tukik=2;
          delay(1000);
        }
      }
    }
    
      if(tukik==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          tukik = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Penyu Jantan  ");    
//            jenisKelamin = "Penyu Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          tukik = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Penyu Betina  ");
//            jenisKelamin = "Penyu Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          tukik = 1;
        }
      }
      
//----------------Kura-kura----------------------//    
    if(volt==2)
    { 
      tukik=0;  kura=1;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(kura==1)
      {   
        Serial.print("Kura-kura");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("   Kura-kura    ");        
//        jenis = "Kura-kura";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          kura=2;
          delay(1000);
        }
      }
    }
    
      if(kura==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          kura = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Kura-kura Jantan");    
//            jenisKelamin = "Kura-kura Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          kura = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Kura-kura Betina");
//            jenisKelamin = "Kura-kura Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          kura = 1;
        }
      }
      
//----------------Labi-labi----------------------//    
    if(volt==3)
    { 
      tukik=0;  kura=0;   labi=1;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(labi==1)
      {   
        Serial.print("Labi-labi");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("   Labi-labi    ");        
//        jenis = "Labi-labi";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          labi=2;
          delay(1000);
        }
      }
    }
    
      if(labi==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          labi = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Labi-labi Jantan");    
//            jenisKelamin = "Labi-labi Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          labi = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Labi-labi Betina");
//            jenisKelamin = "Labi-labi Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          labi = 1;
        }
      }

//----------------Ular----------------------//
    if(volt==4)
    { 
      tukik=0;  kura=0;   labi=0;   ular=1;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(ular==1)
      {   
        Serial.print("Ular");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("      Ular      ");        
//        jenis = "Ular";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          ular=2;
          delay(1000);
        }
      }
    }
    
      if(ular==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          ular = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Ular Jantan  ");    
//            jenisKelamin = "Ular Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          ular = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Ular Betina  ");
//            jenisKelamin = "Ular Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          ular = 1;
        }
      }

//----------------iguana----------------------//
    if(volt==5)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=1;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(iguana==1)
      {   
        Serial.print("iguana");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("     Iguana     ");        
//        jenis = "iguana";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          iguana=2;
          delay(1000);
        }
      }
    }
    
      if(iguana==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          iguana = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Iguana Jantan  ");    
//            jenisKelamin = "iguana Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          iguana = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Iguana Betina  ");
//            jenisKelamin = "iguana Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          iguana = 1;
        }
      }

//----------------Bearded----------------------//
    if(volt==6)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=1;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(Bearded==1)
      {   
        Serial.print("Bearded");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print(" Bearded Dragon ");        
//        jenis = "Bearded";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          Bearded=2;
          delay(1000);
        }
      }
    }
    
      if(Bearded==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          Bearded = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Bearded Jantan  ");    
//            jenisKelamin = "Bearded Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          Bearded = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Bearded Betina  ");
//            jenisKelamin = "Bearded Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          Bearded = 1;
        }
      }
      
//----------------Water----------------------//
    if(volt==7)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=1;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(Water==1)
      {   
        Serial.print("Water");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("  Water Dragon  ");        
//        jenis = "Water";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          Water=2;
          delay(1000);
        }
      }
    }
    
      if(Water==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          Water = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Water Jantan  ");    
//            jenisKelamin = "Water Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          Water = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Water Betina  ");
//            jenisKelamin = "Water Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          Water = 1;
        }
      }

//----------------Kura-kura Asia----------------------//
    if(volt==8)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=1;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(asia==1)
      {   
        Serial.print("asia");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print(" Kura-kura Asia ");        
//        jenis = "asia";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          asia=2;
          delay(1000);
        }
      }
    }
    
      if(asia==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          asia = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Kura Asia Jantan");    
//            jenisKelamin = "asia Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          asia = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Kura Asia Betina");
//            jenisKelamin = "asia Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          asia = 1;
        }
      }

//----------------Komodo----------------------//
    if(volt==9)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=1;   aligator=0;   gecko=0;   slider=0;
      lainnya=0;
      if(komodo==1)
      {   
        Serial.print("komodo");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("     Komodo     ");        
//        jenis = "komodo";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          komodo=2;
          delay(1000);
        }
      }
    }
    
      if(komodo==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          komodo = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Komodo Jantan  ");    
//            jenisKelamin = "komodo Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          komodo = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Komodo Betina  ");
//            jenisKelamin = "komodo Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          komodo = 1;
        }
      }

//----------------Aligator----------------------//
    if(volt==10)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=1;   gecko=0;   slider=0;
      lainnya=0;
      if(aligator==1)
      {   
        Serial.print("aligator");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("    Aligator    ");        
//        jenis = "aligator";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          aligator=2;
          delay(1000);
        }
      }
    }
    
      if(aligator==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          aligator = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Aligator Jantan");    
//            jenisKelamin = "aligator Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          aligator = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Aligator Betina");
//            jenisKelamin = "aligator Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          aligator = 1;
        }
      }

//----------------Leopard Gecko----------------------//
    if(volt==11)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=1;   slider=0;
      lainnya=0;
      if(gecko==1)
      {   
        Serial.print("gecko");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("  Leopard Gecko ");        
//        jenis = "gecko";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          gecko=2;
          delay(1000);
        }
      }
    }
    
      if(gecko==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          gecko = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Leopard Jantan");    
//            jenisKelamin = "gecko Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          gecko = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Leopard Betina  ");
//            jenisKelamin = "gecko Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          gecko = 1;
        }
      }

//----------------Red Eared Slider----------------------//
    if(volt==12)
    { 
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=1;
      lainnya=0;
      if(slider==1)
      {   
        Serial.print("slider");
        lcd.setCursor(0,0);
        lcd.print("  Anda Memilih  ");
        lcd.setCursor(0,1);
        lcd.print("Red Eared Slider");        
//        jenis = "slider";

        if(digitalRead(enter)==0)
        {
          lcd.clear();
          lcd.print("   Loading... ");
          slider=2;
          delay(1000);
        }
      }
    }
    
      if(slider==2)
      {
        lock = 4;
        lcd.setCursor(0,0);
        lcd.print("Pilih Gender   ");
        lcd.setCursor(0,1);
        lcd.print(""); 
        volt=-1;
        if(digitalRead(male)==0)
        {
          slider = 2;
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Red Eared Jantan");    
//            jenisKelamin = "slider Jantan";
            volt=-1;
          }
        }
        if(digitalRead(female)==0)
        {
          slider = 2;
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,1);
            lcd.print("Read Eared Betina  ");
//            jenisKelamin = "slider Betina"; 
            volt=-1;
          } 
        }
        if(digitalRead(enter)==0) 
        {
          lcd.clear();
          volt = 0;
          slider = 1;
        }
      }

//----------------Lainnya----------------------//          
    if (volt >12)
    {
      tukik=0;  kura=0;   labi=0;   ular=0;   iguana=0;   Bearded=0;    Water=0;    asia=0;   komodo=0;   aligator=0;   gecko=0;   slider=0;
      lainnya=1;
      if(lainnya==1)
      {
        Serial.print("Belum tersedia");
        lcd.setCursor(0,0);
        lcd.print("  Maaf Pilihan  ");
        lcd.setCursor(0,1);
        lcd.print("  Belum ada     ");        
        //jenis = "Belum ada";
      }
    }

    if (volt==0)
    {
      lcd.setCursor(0,0);
      lcd.print("  Kembali...  ");
      lcd.setCursor(0,1);
      lcd.print("              ");  
      delay(1000);
      lock=0;
      volt=1; 
    }
    

//===========
if((digitalRead(mulai)==0 && m1==1)||(digitalRead(mulai)==0 && f1==1))
{
  lock=1;
  
  if(m1==1)
  {  
    for(int y=0;y<60;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Menetaskan Jenis");
    cetakjantan();  
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_j();
    digitalWrite(coldin,LOW);
    }
    
    for(int y=0;y<360;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Menetaskan Jenis");
    cetakjantan();
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_j();
    digitalWrite(coldin,HIGH);
    }
  }
  //===============================
  if(f1==1)
  {
   for(int y=0;y<60;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Menetaskan Jenis");
    cetakbetina();
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b();
    digitalWrite(coldin,LOW);
    }
   
   for(int y=0;y<360;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Menetaskan Jenis");
    cetakbetina();
    delay(10);
    }
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b();
    digitalWrite(coldin,HIGH);
    }
  }
}
}

void temp()
{
  dht.read();
  // Read temperature as Celsius (the default)
  t = dht.getTemperatureC();
  b = dht.getHumidity();

  a=t;
  h=b;
  //lcd.clear();
  lcd.setCursor(0,0);   
  lcd.print("Suhu:");
  lcd.setCursor(6,0);
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Kelembaban:");
  lcd.setCursor(12,1);
  lcd.print(h);
  lcd.print("%");     

  delay(10);
}
void cnt_j()
{
  /*digitalWrite(heat,LOW);
  delay(2000);
  digitalWrite(heat,HIGH);
  delay(2000); 
  digitalWrite(cold,LOW);
  delay(2000);
  digitalWrite(cold,HIGH);
  delay(2000); 
  digitalWrite(coldin,LOW);
  delay(2000);
  digitalWrite(coldin,HIGH);
  delay(2000); */
  if (a < 27)
  {
    id=1;
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
  }
  
  if (a > 27 && a < 29);
  {
   if(id==1)
    {
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
    }    
      else 
     {
      delay(1000);
      digitalWrite(cold,LOW);
      delay(1000);
      digitalWrite(heat,HIGH);
     }   
   }

  if (a > 29)
  {
    id=0;
    delay(1000);
    digitalWrite(heat,HIGH);
    delay(1000);
    digitalWrite(cold,LOW);
  }
}

void cnt_b()
{
  /*digitalWrite(heat,LOW);
  digitalWrite(cold,LOW);
  delay(3000);
  digitalWrite(heat,HIGH);
  digitalWrite(cold,HIGH);*/
  if (a < 29)
  {
    id=1;
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
  }
  
  if (a > 29 && a < 32);
  {
   if(id==1)
    {
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
    }    
      else 
     {
      delay(1000);
      digitalWrite(cold,LOW);
      delay(1000);
      digitalWrite(heat,HIGH);
     }   
   }

  if (a > 32)
  {
    id=0;
    delay(1000);
    digitalWrite(heat,HIGH);
    delay(1000);
    digitalWrite(cold,LOW);
  } 
}

void cetakbetina()
{
      if(tukik==2){
        lcd.setCursor(0,1);
        lcd.print("  Penyu Betina  ");}
      else if(kura==2){
        lcd.setCursor(0,1);
        lcd.print("Kura-kura Betina");}
      else if(labi==2){
        lcd.setCursor(0,1);
        lcd.print("Labi-labi Betina");}
      else if(ular==2){
        lcd.setCursor(0,1);
        lcd.print("  Ular Betina   ");}
      else if(iguana==2){
        lcd.setCursor(0,1);
        lcd.print(" Iguana Betina  ");}
      else if(Bearded==2){
        lcd.setCursor(0,1);
        lcd.print(" Bearded Betina ");}
      else if(Water==2){
        lcd.setCursor(0,1);
        lcd.print("  Water Betina  ");}
      else if(asia==2){
        lcd.setCursor(0,1);
        lcd.print("Kura Asia Betina");}
      else if(komodo==2){
        lcd.setCursor(0,1);
        lcd.print(" Komodo Betina  ");}
      else if(aligator==2){
        lcd.setCursor(0,1);
        lcd.print("Aligator Betina ");}
      else if(gecko==2){
        lcd.setCursor(0,1);
        lcd.print(" Leopard Betina ");}
      else if(slider==2){
        lcd.setCursor(0,1);
        lcd.print("Red Eared Betina ");}
}

void cetakjantan()
{
      if(tukik==2){
        lcd.setCursor(0,1);
        lcd.print("  Penyu Jantan  ");}
      else if(kura==2){
        lcd.setCursor(0,1);
        lcd.print("Kura-kura Jantan");}
      else if(labi==2){
        lcd.setCursor(0,1);
        lcd.print("Labi-labi Jantan");}
      else if(ular==2){
        lcd.setCursor(0,1);
        lcd.print("  Ular Jantan   ");}
      else if(iguana==2){
        lcd.setCursor(0,1);
        lcd.print(" Iguana Jantan  ");}
      else if(Bearded==2){
        lcd.setCursor(0,1);
        lcd.print(" Bearded Jantan ");}
      else if(Water==2){
        lcd.setCursor(0,1);
        lcd.print("  Water Jantan  ");}
      else if(asia==2){
        lcd.setCursor(0,1);
        lcd.print("Kura Asia Jantan");}
      else if(komodo==2){
        lcd.setCursor(0,1);
        lcd.print(" Komodo Jantan  ");}
      else if(aligator==2){
        lcd.setCursor(0,1);
        lcd.print("Aligator Jantan ");}
      else if(gecko==2){
        lcd.setCursor(0,1);
        lcd.print(" Leopard Jantan ");}
      else if(slider==2){
        lcd.setCursor(0,1);
        lcd.print("Red Eared Jantan ");}
}
