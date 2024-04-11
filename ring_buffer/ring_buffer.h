/*
 * ring_buffer.h
 *
 *  Created on: Apr 10, 2024
 *      Author: RAFAŁ
 */

#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stdint.h>

#define RING_BUFFER_SIZE	32

typedef enum
{
	BUFF_OK,
	BUFF_ERROR,
}buff_state_t;

typedef struct
{
	uint8_t head;
	uint8_t tail;
	uint8_t ring_buffer[RING_BUFFER_SIZE];
}ring_buff_t;


buff_state_t ring_buffer_write(ring_buff_t *buff, uint8_t value);
buff_state_t ring_buffer_read(ring_buff_t *buff, uint8_t *data);
void ring_buffer_flush(ring_buff_t *buff);

#endif /* RING_BUFFER_H_ */
