/*
 * Bit_Op.h
 *
 * Created: 11/11/2022 9:50:03 PM
 *  Author: Ahmed.Elsayed
 */ 


#ifndef BIT_OP_H_
#define BIT_OP_H_


#define Get_Bit(Reg, Bit)   ((Reg >> (Bit)) & 0x01)
#define Set_Bit(Reg, Bit)    Reg |= (1 << Bit)
#define Clear_Bit(Reg, Bit)  Reg &= ~(1 << Bit)
#define Toggle_Bit(Reg, Bit) Reg ^= (1 << Bit)


#endif /* BIT_OP_H_ */