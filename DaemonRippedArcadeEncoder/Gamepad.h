//  Gamepad.h - 2025 Author: regiregi22
//  
//  Based on the advanced HID library for Arduino: 
//  https://github.com/NicoHood/HID
//  Copyright (c) 2014-2015 NicoHood
//  Copyright (c) 2020 Mikael Norrgård


#pragma once

#include "HID.h"

extern const char* gp_serial;

typedef struct {
  uint16_t buttons : 12;
  int8_t X;
  int8_t Y;
} GamepadReport;


class Gamepad_ : public PluggableUSBModule
{  
  private:
    uint8_t reportId;

  protected:
    int getInterface(uint8_t* interfaceCount);
    int getDescriptor(USBSetup& setup);
    uint8_t getShortName(char *name);
    bool setup(USBSetup& setup);
    
    uint8_t epType[1];
    uint8_t protocol;
    uint8_t idle;
    
  public:
    GamepadReport _GamepadReport;
    Gamepad_(void);
    void reset(void);
    void send();
};
