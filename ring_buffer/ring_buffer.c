/*
 * ring_buffer.c
 *
 *  Created on: Apr 10, 2024
 *      Author: RAFAŁ
 */

#include "ring_buffer.h"

buff_state_t ring_buffer_write(ring_buff_t *buff, uint8_t value);
buff_state_t ring_buffer_read(ring_buff_t *buff, uint8_t *data);
void ring_buffer_flush(ring_buff_t *buff);


void ring_buffer_flush(ring_buff_t *buff)
{
	buff->head = 0;
	buff->tail = 0;
}

buff_state_t ring_buffer_write(ring_buff_t *buff, uint8_t value)
{
	uint8_t new_head = (buff->head + 1) % RING_BUFFER_SIZE;

	if(new_head == buff->tail)
	{
		return BUFF_ERROR;
	}

	buff->ring_buffer[buff->head] = value;
	buff->head = new_head;

	return BUFF_OK;
}

buff_state_t ring_buffer_read(ring_buff_t *buff, uint8_t *data)
{
	if(buff->head == buff->tail)
	{
		return BUFF_ERROR;
	}

	*data = buff->ring_buffer[buff->tail];
	buff->tail = (buff->tail + 1) % RING_BUFFER_SIZE;

	return BUFF_OK;
}

