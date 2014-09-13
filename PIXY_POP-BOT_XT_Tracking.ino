//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//

#include <PixyUART.h>
#include <popxt.h>

PixyUART pixy;

unsigned long time = 0;

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");
  
  pixy.init();
}

void loop()
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  blocks = pixy.getBlocks();
  
  if (blocks)
  {
    i++;
    
    if (i%1==0)
    {
      if(pixy.blocks[j].x > 190) {
        sr(20);
        time = millis();
      } else if(pixy.blocks[j].x < 130) {
        sl(20); 
        time = millis();
      } else {
        ao();  
      }
    }
  }  
  
  if(millis()  - time > 200) {
    ao();
    time = 0;  
  }
}
