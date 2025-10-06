/******************************************************************************
 *
 * Module: Ultrasonic Sensor
 *
 * File Name: Ultrasonic.h
 *
 * Description: Header file for the HC-SR04 Ultrasonic Sensor driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/GPIO/std_type.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Ultrasonic sensor pins configuration */
#define Ultrasonic_Echo_PORT_ID          PORTD_ID
#define Ultrasonic_Echo_PIN_ID           PIN6_ID

#define Ultrasonic_Trigger_PORT_ID       PORTD_ID
#define Ultrasonic_Trigger_PIN_ID        PIN7_ID

/* Trigger pulse duration in microseconds */
#define TRIGGER_DELAY                    10

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initialize the ultrasonic sensor:
 * - Initialize ICU driver with F_CPU/8 prescaler and rising edge detection
 * - Setup callback function for edge processing
 * - Configure trigger pin as output
 */
void Ultrasonic_init(void);

/*
 * Description:
 * Send trigger pulse to ultrasonic sensor:
 * - Generate 10us high pulse on trigger pin
 */
void Ultrasonic_Trigger(void);

/*
 * Description:
 * Read distance measured by ultrasonic sensor
 * - Send trigger pulse to start measurement
 * - Wait for echo pulse measurement to complete
 * - Calculate distance based on echo high time
 * Returns: Distance in centimeters
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description:
 * Callback function for ICU edge detection
 * - Processes rising and falling edges of echo pulse
 * - Calculates the high time duration of echo pulse
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
