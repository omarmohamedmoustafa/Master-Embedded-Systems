/*
 * types.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Omar_
 */
/*HEADER PROTECTION*/
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef unsigned long 		boolean;

typedef signed char 		sint8_t;
typedef unsigned char 		uint8_t;

typedef signed short		sint16_t;
typedef unsigned short		uint16_t;

typedef signed int			sint32_t;
typedef unsigned long 		uint32_t;

typedef signed long long	sint64_t;
typedef unsigned long long	uint64_t;


typedef volatile signed char 		v_sint8_t;
typedef volatile unsigned char 		v_uint8_t;

typedef volatile signed short		v_sint16_t;
typedef volatile unsigned short		v_uint16_t;

typedef volatile signed int			v_sint32_t;
typedef volatile unsigned int 		v_uint32_t;

typedef volatile signed long long	v_sint64_t;
typedef volatile unsigned long long	v_uint64_t;

#endif