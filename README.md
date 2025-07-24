# AquaMaqua - Aquarium Monitoring System for ESP8266

A hobby project from when I was 14, showcasing early passion for programming and problem-solving.

## Overview

AquaMaqua is an aquarium monitoring system built for the ESP8266 microcontroller. It features real-time sensor monitoring, Wi-Fi connectivity, data logging, and a custom-built GUI framework, all written from scratch in C++.

## Features

### Custom GUI Framework
- Built entirely from scratch using TFT display primitives
- Interactive UI with textboxes, keyboard interface, and shapes
- Screen-based navigation system (inspired by Unity's UI concepts)
- Interrupt-driven input handling for responsive user experience

### Real-Time Monitoring
- Sensor data collection and display
- Custom-coded graphing system using only drawBP and drawLine functions
- Configurable graph density and display options
- Periodic data logging to remote server

### Connectivity
- Wi-Fi connection management through GUI
- User-selectable networks with password entry
- Remote data logging capabilities

### Data Storage
- Custom EEPROM wrapper with localStorage-like API
- Key-value pair storage system for configuration persistence
- Easy data access and management

## Technical Highlights

- **Hardware**: ESP8266 microcontroller with TFT display and input switches
- **Language**: C++ with extensive use of Object-Oriented Programming
- **Libraries**: Custom implementations including linked lists and data structures
- **Architecture**: Modular screen-based GUI system with interrupt handling

### Prerequisites
- PlatformIO IDE (VS Code extension)
- ESP8266 development board
- TFT display (compatible with Adafruit TFT library)
- Sensors (temperature, pH, etc.)

### Project Structure
```
aquamaqua/
├── lib/          # Required libraries
├── src/          # Main source code
└── README.md     # This file
```

## Development Notes

This project represents an early exploration into embedded systems development, featuring:
- Ground-up GUI framework development
- Custom data structures and algorithms
- Hardware-software integration
- Real-time system design

Feel free to explore the source code to discover additional features and implementation details.
