#include "ports.h"

//Read Byte from the port
unsigned char inb(unsigned short port)
{
    //load d with port
    //get data of port in al
    //save ax as result
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

//Write Byte to the port
void outb(unsigned short port, unsigned char data)
{
    //Load al with data
    //Load dx with port 
    //Write al to port (Out signal)
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

//Read Word From Port
unsigned short inw(unsigned short port)
{
    unsigned short result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

uint8 read_register(uint8 reg)
{
    outb(0x70, reg);
    return inb(0x71);
}

void write_register(uint8 reg, uint8 value)
{
    outb(0x70, reg);
    outb(0x71, value);
}