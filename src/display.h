/*
 * naglowki.h
 *
 *  Created on: 21 mar 2016
 *      Author: root
 */

#ifndef FUNKCJE_H_
#define FUNKCJE_H_
void display_structure(el_listy *list);
void display_structure_from_struct(struct eth_ipv4_udp *pakiet);
void displayCharArray(char title[], int size, unsigned char value[]);
void displayChar(char title[], int size, unsigned char value);
void displayCharTTL(char title[], int size, unsigned char value);
void displayShortInt(char title[], int size, unsigned short int value);
void displayShortIntTTL(char title[], int size, unsigned short int value);
void displayInt(char title[], int size, unsigned int value);
void displayIntAddress(char title[], int size, unsigned int value);
void displayIntPort(char title[], int size, unsigned int value);
void displayEthertype(char title[], int size, unsigned short int value);
void displayUDPLength(char title[], int size, unsigned short int value);
void displayV4Protocol(char title[], int size, unsigned char value);
void displayAddress(char title[], int size, unsigned char value[]);

#endif /* FUNKCJE_H_ */
