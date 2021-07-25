/*
 * Maticgator
 * November 2017
 * Project by Ibrahim Hasan with modification by Aidil Pandu
 * Teknik Elektro_Universitas Brawijaya
 * #want to be master of instrumenstation n control#
 */

#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#define powlcd 12

#define DHTpin A0
#define DHTtype DHT22
#define heat  2
#define cold  3
#define coldin 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTpin,DHTtype);

/*
 * The circuit:
 * RX is digital pin 7 (connect to TX of other device)
 * TX is digital pin 8 (connect to RX of other device)
 * Contoh Pengiriman Data:
 * Serial.print("Hasil|");
 * Serial.print(data1); Serial.print("|");
 * Serial.print(data2); Serial.print("|");
 * Serial.print(data3); 
 * Hasil | 123 | 456
 * Data1 |Data2|Data3
 */ 
SoftwareSerial mySerial  (7, 8); // RX, TX Arduino

int male=A1;
int female=A3;
int enter=A2;
int sw=A6;
int masukan=A7;
int m,f,e,m1,f1,m2,f2,m3,f3,e1,in;
int lock=0;
float a,t,volt;
int h,b;
int id=1;
int tukik,kura,reptil,lainnya;
String jenis, device, timerPompa, jenisKelamin;

void setup() 
{
  lcd.begin(); lcd.backlight();
  dht.begin();
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(heat,OUTPUT); digitalWrite(heat,HIGH);
  pinMode(cold,OUTPUT); digitalWrite(cold,HIGH);
  pinMode(coldin,OUTPUT); digitalWrite(coldin,HIGH);
  pinMode(powlcd,OUTPUT); digitalWrite(powlcd,HIGH);
  pinMode(male,INPUT_PULLUP);
  pinMode(female,INPUT_PULLUP);
  pinMode(enter,INPUT_PULLUP);
  pinMode(sw,INPUT);
  
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
  lcd.print("   Jenisnya");
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
      //in = digitalRead(masukan);
      rv();
    }
/******************Menu jenis telur**************/

/******************TUKIK**************/
    if(volt>4.80)       
    {
      tukik=1;
      kura=0;
      reptil=0;
      lainnya=0;
     
      if(tukik==1)
      {
        Serial.print("tukik");
        lcd.setCursor(0,0);
        lcd.print("Anda memilih  ");
        lcd.setCursor(0,1);
        lcd.print("Penyu       ");      
        jenis = "Tukik";
      
        if(m==0)
        {
          m1=1;
          f1=0;
          if(m1==1)
          {
            lcd.setCursor(0,0);
            lcd.print("Anda memilih  ");
            lcd.setCursor(0,1);
            lcd.print("Penyu Jantan? "); 
            delay(5000);  
            lcd.clear();     
            jenisKelamin = "Penyu Jantan";
          }
        }

        if(f==0)
        {
          f1=1;
          m1=0;
          if(f1==1)
          {
            lcd.setCursor(0,0);
            lcd.print("Anda memilih  ");
            lcd.setCursor(0,1);
            lcd.print("Penyu Betina? ");
            delay(5000);
            lcd.clear();
            jenisKelamin = "Penyu Betina"; 
          } 
        }
      }
    }  
/******************KURA-KURA***********************/
    if(volt>3.85 && volt <4.22)
    { 
      tukik=0;
      kura=1;
      reptil=0;
      lainnya=0;
      
      if(kura==1)
      {   
        Serial.print("kura-kura");
        lcd.setCursor(0,0);
        lcd.print("Anda memilih  ");
        lcd.setCursor(0,1);
        lcd.print("Kura-kura ");        
        jenis = "Kura-kura";
        
        if(m==0)
        {
          m2=1;
          f2=0;
          if(m2==1)
          {
            lcd.setCursor(0,0);
            lcd.print("Anda memilih  ");
            lcd.setCursor(0,1);
            lcd.print("Kura-kura Jantan?"); 
            delay(5000); 
            lcd.clear();      
            jenisKelamin = "Kura-kura Jantan";
          }
        }

        if(f==0)
        {
          f2=1;
          m2=0;
          if(f2==1)
          {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Anda memilih  ");
            lcd.setCursor(0,1);
            lcd.print("Kura-kura Betina?");
            delay(5000);
            lcd.clear();
            jenisKelamin = "Kura-kura Betina"; 
          } 
        }
      }
    }
/******************REPTIL******************************/   
    if(volt>2.80 && volt <3.20)
    {
      tukik=0;
      kura=0;
      reptil=1;
      lainnya=0;
      if(reptil==1)
      {
        Serial.print("Reptil");
        lcd.setCursor(0,0);
        lcd.print("Anda memilih  ");
        lcd.setCursor(0,1);
        lcd.print("Reptil      ");        
        jenis = "Reptil";

        if(m==0)
        {
          m3=1;
          f3=0;
          if(m3==1)
          {
            lcd.setCursor(0,0);
            lcd.print("Anda memilih  ");
            lcd.setCursor(0,1);
            lcd.print("Reptil Jantan? "); 
            delay(5000); 
            lcd.clear();      
            jenisKelamin = "Reptil Jantan";
          }
        }

        if(f==0)
        {
          f3=1;
          m3=0;
          if(f3==1)
          {
            lcd.setCursor(0,0);
            lcd.print("Anda memilih  ");
            lcd.setCursor(0,1);
            lcd.print("Reptil Betina? ");
            delay(5000);
            lcd.clear();
            jenisKelamin = "Reptil Betina"; 
          } 
        }
      }
    }
/******************LAINNYA**********r**************/
    if(volt>0.80 && volt <2.20)
    {
      tukik=0;
      kura=0;
      reptil=0;
      lainnya=1;
      if(lainnya==1)
      {
        Serial.print("Belum tersedia");
        rv();
        lcd.setCursor(0,0);
        lcd.print("  Maaf Pilihan  ");
        lcd.setCursor(0,1);
        lcd.print("  Belum ada ");        
        //jenis = "Belum ada";
      }
    }
    
    if(volt<0.7)
    {
      tukik=0;
      kura=0;
      reptil=0;
      lainnya=1;
      if(lainnya==1)
      {
        Serial.print("Belum tersedia");
        rv();
        lcd.setCursor(0,0);
        lcd.print("  Maaf Pilihan  ");
        lcd.setCursor(0,1);
        lcd.print("  Belum ada ");        
        //jenis = "Belum ada";
      }
    }
    
/*********************LOCK MAIN CONTROL****************/
if(e==0)
{
  lock=1;
  while (mySerial.available())   //Check if there is an available byte to read
  {
   delay(10); //Delay added to make thing stable 
   char c = mySerial.read(); //Conduct a serial read
   device += c; //build the string.
  }  
  if (device.length() > 0) 
  {
//   Serial.print("Command received from BT ==> ");
//   Serial.println(device); 
   timerPompa = device;
   device ="";  //Reset the variable
   mySerial.flush();
  } 
  
  if(m1==1)
  {  
    for(int y=0;y<60;y++)
    {
      lcd.clear();
      for(int i=0;i<500;i++)
      {
        lcd.setCursor(0,0);
        lcd.print("  Tukik Jantan  ");
        lcd.setCursor(0,1);
        lcd.print("                ");    
        delay(10);
      }
      lcd.clear();
      for(int i=0;i<500;i++)
      {
        temp();
      }
      cnt_j1();
      digitalWrite(coldin,LOW);
    }
    for(int y=0;y<360;y++)
    {
      lcd.clear();
      for(int i=0;i<500;i++)
      {
        lcd.setCursor(0,0);
        lcd.print("  Penyu Jantan  ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        delay(10);
      }
      lcd.clear();
      for(int i=0;i<500;i++)
      {
        temp();
      }
      cnt_j1();
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
    lcd.print("  Penyu Betina  ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b1();
    digitalWrite(coldin,LOW);
    }
   
   for(int y=0;y<360;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("  Tukik Betina  ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);
    }
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b1();
    digitalWrite(coldin,HIGH);
    }
  }

  if(m2==1)
  {  
    for(int y=0;y<60;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Kura-kura Jantan");
    lcd.setCursor(0,1);
    lcd.print("                ");    
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_j2();
    digitalWrite(coldin,LOW);
    }
    
    for(int y=0;y<360;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Kura-kura Jantan");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_j2();
    digitalWrite(coldin,HIGH);
    }
  }
  //===============================
  if(f2==1)
  {
   for(int y=0;y<60;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Kura-kura Betina");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b2();
    digitalWrite(coldin,LOW);
    }
   
   for(int y=0;y<360;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Kura-kura Betina");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);
    }
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b2();
    digitalWrite(coldin,HIGH);
    }
  }

  if(m3==1)
  {  
    for(int y=0;y<60;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Reptil Jantan");
    lcd.setCursor(0,1);
    lcd.print("                ");    
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_j3();
    digitalWrite(coldin,LOW);
    }
    
    for(int y=0;y<360;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Reptil Jantan");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_j3();
    digitalWrite(coldin,HIGH);
    }
  }
  //===============================
  if(f3==1)
  {
   for(int y=0;y<60;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Reptil Betina");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);}
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b3();
    digitalWrite(coldin,LOW);
    }
   
   for(int y=0;y<360;y++)
    {
    lcd.clear();
    for(int i=0;i<500;i++)
    {lcd.setCursor(0,0);
    lcd.print("Reptil Betina");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(10);
    }
    lcd.clear();
    for(int i=0;i<500;i++)
    {temp();}
    cnt_b3();
    digitalWrite(coldin,HIGH);
    }
  }
}
}

void temp()
{
  t = dht.readTemperature();
  b = map(t,23,34,75,60);

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

  //  Pengiriman ke Aplikasi Maticgator
//  JenisTukik | TimerPompa | Suhu  | Kelembaban
//  Data 1     | Data 2     | Data3 | Data 4             
  mySerial.print(jenisKelamin + '|' + timerPompa + '|' + t + '|' + h + '|');  
  
//  Pengiriman ke Bluetooth Serial Monitor
//  mySerial.print("Suhu      : "); mySerial.print(t); mySerial.println(" Celcius");
//  mySerial.print("Kelembaban: "); mySerial.print(h); mySerial.println(" %\n");
  delay(10);
}

void cnt_j1()
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
  if (a < 25)
  {
    id=1;
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
  }
  
  if (a > 25 && a < 29);
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

void cnt_b1()
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

void cnt_j2()
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
  if (a < 25)
  {
    id=1;
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
  }
  
  if (a > 25 && a < 27);
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

  if (a > 27)
  {
    id=0;
    delay(1000);
    digitalWrite(heat,HIGH);
    delay(1000);
    digitalWrite(cold,LOW);
  }
}

void cnt_b2()
{
  /*digitalWrite(heat,LOW);
  digitalWrite(cold,LOW);
  delay(3000);
  digitalWrite(heat,HIGH);
  digitalWrite(cold,HIGH);*/
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

void cnt_j3()
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
  if (a < 28)
  {
    id=1;
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
  }
  
  if (a > 28 && a < 30);
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

  if (a > 30)
  {
    id=0;
    delay(1000);
    digitalWrite(heat,HIGH);
    delay(1000);
    digitalWrite(cold,LOW);
  }
}

void cnt_b3()
{
  /*digitalWrite(heat,LOW);
  digitalWrite(cold,LOW);
  delay(3000);
  digitalWrite(heat,HIGH);
  digitalWrite(cold,HIGH);*/
  if (a < 30)
  {
    id=1;
    delay(1000);
    digitalWrite(cold,HIGH);
    delay(1000);
    digitalWrite(heat,LOW);
  }
  
  if (a > 30 && a < 32);
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


void rv()
{
  volt = analogRead(sw)*5.00/1024; // BACA POTENSIO
  Serial.println(volt);
  delay(10);
}
