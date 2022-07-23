/****************************************************************************************	
**  This is example LINX firmware for use with the Arduino Uno with the serial 
**  interface enabled.
**
**  For more information see:           www.labviewmakerhub.com/linx
**  For support visit the forums at:    www.labviewmakerhub.com/forums/linx
**  
**  Written By Sam Kristoff
**
**  BSD2 License.
****************************************************************************************/

//Include All Peripheral Libraries Used By LINX
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Servo.h>
#include <LiquidCrystal.h>


//Include Device Specific Header From Sketch>>Import Library (In This Case LinxChipkitMax32.h)
//Also Include Desired LINX Listener From Sketch>>Import Library (In This Case LinxSerialListener.h)
#include <LinxArduinoUno.h>
#include <LinxSerialListener.h>


LiquidCrystal lcd(11, 12, 5, 6, 7, 8);
//Create A Pointer To The LINX Device Object We Instantiate In Setup()
LinxArduinoUno* LinxDevice;

//declare lcd function
int lcdClear();
int lcdInit();
int lcdWrite();

//Initialize LINX Device And Listener
void setup()
{
  //Instantiate The LINX Device
  LinxDevice = new LinxArduinoUno();
  
  //The LINXT Listener Is Pre Instantiated, Call Start And Pass A Pointer To The LINX Device And The UART Channel To Listen On
  LinxSerialConnection.Start(LinxDevice, 0);  

  LinxSerialConnection.AttachCustomCommand(7, lcdClear);
  LinxSerialConnection.AttachCustomCommand(6, lcdWrite);
  LinxSerialConnection.AttachCustomCommand(5, lcdInit);
}

void loop()
{
  //Listen For New Packets From LabVIEW
  LinxSerialConnection.CheckForCommands();
  
  //Your Code Here, But It will Slow Down The Connection With LabVIEW
}

int lcdClear(unsigned char numInputBytes, unsigned char* input, unsigned char* numResponseBytes, unsigned char* response)
{
  if (numInputBytes != 0)
    {
      return 1; // erro
    }
   
   *numResponseBytes = 0;
   lcd.clear();
   
  return 0; // 
}

int lcdInit(unsigned char numInputBytes, unsigned char* input, unsigned char* numResponseBytes, unsigned char* response)
{
  if (numInputBytes < 2)
    {
      return 1; // erro
    }
   
   *numResponseBytes = 0;
   lcd.begin(input[0], input[1]);
   
  return 0; // 
}

int lcdWrite(unsigned char numInputBytes, unsigned char* input, unsigned char* numResponseBytes, unsigned char* response)
{
  if (numInputBytes <= 2)
    {
      return 1; // erro
    }

   lcd.setCursor(input[0], input[1]);
 
   for(int i = 2; i < numInputBytes; i++){
      lcd.write(input[i]);
   }
   
   *numResponseBytes = 0;
  return 0; // 
}
