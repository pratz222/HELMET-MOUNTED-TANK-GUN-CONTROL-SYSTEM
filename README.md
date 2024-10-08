# Helmet-Mounted Tank Gun Control System

## Overview

The Helmet-Mounted Tank Gun Control System is an innovative solution that allows tank operators to control the movement of the main gun using head movements instead of traditional manual controls. This project aims to enhance situational awareness and improve reaction time during combat, enabling operators to focus on critical tasks while engaging targets.

## Features

- **Hands-Free Operation**: Control the tank gun with head movements for increased situational awareness.
- **High Accuracy**: Utilizes IMU sensors to track head movements and accurately aim and fire the main gun.
- **Wireless Communication**: Transmits head movement data between the transmitter and receiver via radio frequency.

## Hardware Highlights

- **Microcontrollers**: Two microcontrollers (one for the transmitter and one for the receiver).
- **IMU Sensor**: MPU6050 for detecting head movements.
- **RF Modules**: Radio frequency modules for wireless communication.
- **Servos**: Servos for controlling the gun's elevation and rotation.

## Hardware Configuration

### Pin Configuration

| Component                   | Pin Number |
|-----------------------------|------------|
| Servo for Gun Elevation     | 5          |
| Servo for Gun Rotation      | 6          |

### Additional Hardware

- **Power Supply**: Ensure a stable power supply for both transmitter and receiver circuits.
- **Mounting Equipment**: Design a suitable helmet mount for the IMU sensor.

## Code Overview

### Transmitter Code

The transmitter code reads the head movement data from the MPU6050 IMU sensor and sends it via RF to the receiver.

- Initializes the I2C communication with the MPU6050.
- Maps the accelerometer data to appropriate angles for controlling the servos.

### Receiver Code

The receiver code receives the head movement data from the transmitter and controls the servos accordingly.

- Initializes the RF module and servos.
- Reads the incoming data and moves the servos based on the received angles.

## Dependencies

- **Libraries**: 
  - RH_ASK for RF communication.
  - I2Cdev for I2C communication with the MPU6050.
  - ServoTimer2 for controlling the servos.

## Setup Instructions

1. **Connect the IMU Sensor**: Connect the MPU6050 to the microcontroller using I2C (SDA and SCL pins).
2. **Set Up RF Communication**: Connect the RF modules to the respective microcontrollers for wireless communication.
3. **Attach Servos**: Connect the servos to the designated pins for gun movement control.
4. **Upload Code**: Upload the transmitter code to the microcontroller connected to the IMU and the receiver code to the microcontroller connected to the servos.

## Monitoring and Testing

- Test the system by wearing the helmet and moving your head to see the tank gun respond accordingly.
- Monitor the serial output for debugging and verifying the angles being transmitted and received.


![Prototype](https://github.com/pratz222/HELMET-MOUNTED-TANK-GUN-CONTROL-SYSTEM/assets/53640877/b3d6af60-47e8-4924-818a-29c48e2cf5f3)

![Design](https://github.com/pratz222/HELMET-MOUNTED-TANK-GUN-CONTROL-SYSTEM/assets/53640877/ca50588a-6aa0-4a0b-989b-969d2e019e8e)

