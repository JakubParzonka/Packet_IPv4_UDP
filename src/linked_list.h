/*
 * linked_list.h
 *
 *  Created on: Oct 29, 2016
 *      Author: root
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "struktury.h"

void add_to_list(struct list *list, struct eth_ipv4_udp *packet);
void print_list(struct list *list);

#endif /* LINKED_LIST_H_ */
