"# Arduino Embedded Systems Projects

A comprehensive collection of 75+ Arduino projects demonstrating various embedded systems concepts, sensors, displays, and components. This repository serves as a complete learning resource for embedded systems development, covering everything from basic LED control to complex multi-sensor systems.

## Overview

This collection is designed for:
- **Beginners** learning Arduino and embedded systems fundamentals
- **Students** working on IoT and embedded systems coursework
- **Makers** looking for project inspiration and reference implementations
- **Educators** seeking teaching resources and demonstrations

All projects include Wokwi simulation support, allowing you to test circuits virtually before building physical prototypes.

## Table of Contents

- [Overview](#overview)
- [Table of Contents](#table-of-contents)
- [Projects by Category](#projects-by-category)
  - [LED \& Basic Output](#led--basic-output)
  - [Input Devices](#input-devices)
  - [Display Systems](#display-systems)
  - [Distance \& Ultrasonic Sensors](#distance--ultrasonic-sensors)
  - [Environmental Sensors](#environmental-sensors)
  - [Optical \& Light Sensors](#optical--light-sensors)
  - [Motion \& Presence Detection](#motion--presence-detection)
  - [Infrared Systems](#infrared-systems)
  - [Segment Displays](#segment-displays)
  - [Time \& Clock](#time--clock)
  - [Motor Control](#motor-control)
  - [Audio \& Sound](#audio--sound)
  - [Advanced Components](#advanced-components)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Simulation](#simulation)
- [Learning Path](#learning-path)
  - [Level 1: Absolute Beginner (Weeks 1-2)](#level-1-absolute-beginner-weeks-1-2)
  - [Level 2: Beginner (Weeks 3-4)](#level-2-beginner-weeks-3-4)
  - [Level 3: Intermediate (Weeks 5-8)](#level-3-intermediate-weeks-5-8)
  - [Level 4: Advanced (Weeks 9-12)](#level-4-advanced-weeks-9-12)
- [Troubleshooting](#troubleshooting)
  - [Common Issues and Solutions](#common-issues-and-solutions)
    - [Upload Errors](#upload-errors)
    - [Display Issues](#display-issues)
    - [Sensor Problems](#sensor-problems)
    - [Power Issues](#power-issues)
    - [Library Errors](#library-errors)
  - [Debugging Tips](#debugging-tips)
  - [Getting Help](#getting-help)
- [License](#license)
- [Contributing](#contributing)

## Projects by Category

### LED & Basic Output

**Difficulty**: Beginner | **Components**: LEDs, Buzzer, Relay

- **01.LED Connect** - Basic LED control and blinking patterns. Learn digital output, pinMode(), digitalWrite(), and delay()
- **02.Buzzer Connect** - Generate tones and melodies using active/passive buzzers. Explore tone() and noTone() functions
- **66.Relay Demonstration** - Control high-voltage devices safely using relay modules. Understand optocoupler isolation

### Input Devices

**Difficulty**: Beginner to Intermediate | **Components**: Buttons, Joystick, Rotary Encoder, Potentiometers

- **04.Push Button** - Digital input with pull-up/pull-down resistors. Implement debouncing techniques
- **48.Joystick** - Read X/Y analog axes and button. Map values for game controls or servo positioning
- **54.KY-040 Rotation** - Rotary encoder with CLK/DT pins. Detect rotation direction using interrupts
- **55.KY-040 Counter** - Build increment/decrement counter. Learn interrupt-driven input handling
- **56.Volume Control** - Adjust volume/brightness using potentiometer. Practice analogRead() and PWM output
- **65.Potentiometer Plotter** - Visualize analog readings in Serial Plotter. Understand ADC resolution (0-1023)
- **69.Slide Pot** - Linear potentiometer for position sensing. Apply to level indicators or sliders

### Display Systems

**Difficulty**: Beginner to Advanced | **Components**: LCD 16x2/20x4, OLED, Nokia 5110

- **03.Serial Monitor** - Debug output via Serial.print(). Essential for troubleshooting and data logging
- **05.LCD Display** - Parallel interface LCD (HD44780). Display text on 16x2 character LCD
- **06.LCD1602 Custom Characters** - Create custom icons and symbols using CGRAM. Design battery, arrows, hearts
- **07.LiquidCrystal_I2C_HelloWorld** - Reduce pins using I2C adapter (PCF8574). Save GPIO pins
- **12.LCD 16x2 I2C Example** - Advanced I2C LCD techniques. Cursor control and backlight management
- **13.Arduino LCD 20x4 I2C Example** - Large format display. Multi-line menu systems and data visualization
- **11.LCD_20x4 Text** - Text scrolling, cursor positioning, and special characters
- **34.OLED i2c ssd1306 display** - High-contrast 128x64 monochrome OLED. Graphics and text rendering
- **35.Draw Bitmap** - Display images on OLED. Convert images to byte arrays for embedded graphics
- **75.Nokia 5110** - 84x48 LCD from Nokia 5110 phone. SPI communication and pixel-level graphics
- **36.Snake game** - Classic snake game on OLED display with joystick control

### Distance & Ultrasonic Sensors

**Difficulty**: Beginner to Intermediate | **Components**: HC-SR04 Ultrasonic Sensor

- **17.Ultrasonic Sensor** - Measure distance using sound waves. Trigger/Echo timing and speed of sound calculations
- **18.Ultrasonic Distance Sensor** - Accurate distance measurement in centimeters. Range: 2-400cm
- **19.Ultrasonic Sensor with Buzzer** - Parking sensor with audio feedback. Beep frequency increases as obstacles approach
- **20.A Virtual Tape Measure** - Digital measuring tool with calibration. Hold button to lock measurement
- **21.Ultrasonic sensor with LCD** - Real-time distance display. Update LCD with current readings
- **22.Ultrasonic sensor and lcd** - Enhanced version with smoothing algorithms. Average multiple readings
- **23.SR04_array_of_struct** - Manage multiple sensors using arrays. 360° obstacle detection system

### Environmental Sensors

**Difficulty**: Beginner to Intermediate | **Components**: DHT11/DHT22, NTC Thermistor

- **28.Ntc Temperature Sensor** - Analog temperature reading with NTC thermistor. Steinhart-Hart equation conversion
- **29.Temperature sensor** - Basic temperature monitoring. Understand resistance-temperature relationship
- **30.DHT22 Test** - High-precision humidity (±2% RH) and temperature (±0.5°C) sensor
- **31.DHT Tester** - Diagnostic tool for DHT sensors. Verify sensor functionality and timing
- **32.DHT22 LCD** - Climate monitoring station. Display temp, humidity, and heat index
- **33.Temp and hum detection system** - Complete environmental monitoring with alerts. Set temperature/humidity thresholds
- **37.OLED and DHT22** - Compact weather station on OLED. Graphical temperature/humidity display

### Optical & Light Sensors

- **24.LDR light sensor** - Light-dependent resistor (LDR) basic usage
- **25.Sensor LDR dengan LED** - LDR controlling LED
- **26.Photoresistor Digital** - Digital photoresistor readings
- **27.Photoresistor Analog** - Analog photoresistor readings

### Motion & Presence Detection

- **38.PIR Sensor** - Passive infrared motion detection
- **64.Pir Adafruit** - Adafruit PIR sensor integration

### Infrared Systems

- **39.IR Receiver I** - IR remote receiver basic
- **40.IR Receiver II** - Advanced IR receiver functionality

### Segment Displays

- **41.Seven segment I** - 7-segment display basic control
- **42.Seven Segment Display II** - Multi-digit 7-segment display
- **43.3-Digit 7 Segment using Arduino** - 3-digit 7-segment display
- **44.SEVEN SEGMENT LED II** - Advanced 7-segment control
- **45.SevSeg Counter** - SevSeg library counter application
- **73.TM1637** - TM1637 4-digit display module
- **74.Example with TM1637** - TM1637 module examples

### Time & Clock

**Difficulty**: Intermediate to Advanced | **Components**: DS1307/DS3231 RTC, TM1637, MAX7219

- **09.Nano Clock** - Digital clock using Arduino Nano. Timekeeping with millis() function
- **47.Alarm Clock** - Full-featured alarm with snooze. Set alarms using buttons, buzzer notification
- **53.DS1307 Basic** - I2C RTC module with battery backup. Maintain time during power loss
- **60.Max7219 Clock DHT** - LED matrix clock with temperature/humidity. Animated display transitions

### Motor Control

**Difficulty**: Intermediate to Advanced | **Components**: Servo (SG90), Stepper Motors (28BYJ-48), A4988 Driver

- **49.Biaxial Stepper Motor** - Control two stepper motors simultaneously. XY positioning system
- **50.Bxaxial Stepper Driver A4988** - High-torque NEMA17 motors with microstepping. Configure step/direction pins
- **67.Servo** - PWM control for precise angular positioning (0-180°). Learn Servo.write() and attach()
- **68.Knob** - Map potentiometer input to servo angle. Real-time position feedback
- **70.Stepper Motor** - Full-step and half-step sequences. Understand phase excitation patterns
- **71.Stepper Motor II** - Variable speed control and acceleration. Direction reversal and position tracking
- **72.Proportional Control Accel Stepper** - Smooth acceleration/deceleration curves. Professional motion control

### Audio & Sound

- **51.Mini Piano** - Simple piano keyboard with buzzer/speaker

### Advanced Components

**Difficulty**: Intermediate to Advanced | **Components**: Keypad, Gas Sensor, SD Card, QR Generator

- **10.Electronic Safe** - Password-protected safe with keypad entry. Store codes in EEPROM
- **14.Key Pad** - 4x4 matrix keypad scanning. Row-column multiplexing technique
- **15.Keypad and LCD I2C with Arduino UNO** - Password entry system with visual feedback. Masked character display
- **16.Calculator** - Working calculator with arithmetic operations. Parse and evaluate expressions
- **52.Arduino Pind Example** - Monitor and control all digital pins. Pin state visualization
- **57.Gas sensor detecting smoke** - MQ-2/MQ-135 gas detection. Analog threshold for smoke/gas alarms
- **58.LED Bar Graph with Pot** - VU meter-style LED array. Visual representation of analog values
- **59.Logic Analyzer Demonstration** - Capture and display digital signals. Debug communication protocols
- **61.Joystick Etch a Sketch** - Drawing app with pixel-by-pixel control. Save sketches to memory
- **62.Arduino QR Code Generator** - Generate QR codes on display. Encode URLs or text data
- **63.Microsd Card Prototype** - Data logging to SD card. File creation, writing, and reading via SPI
- **46.String With Period** - String parsing and manipulation. Split, concatenate, and format text data

## Prerequisites

- Arduino IDE or PlatformIO
- Compatible Arduino board (UNO, Nano, Mega, etc.)
- Required libraries for each project (specified in project files)

## Project Structure

Each project folder contains:
- `src/` - Main source code
- `include/` - Header files
- `lib/` - Local libraries
- `test/` - Test files
- `diagram.json` - Wokwi circuit diagram
- `platformio.ini` - PlatformIO configuration
- `wokwi.toml` - Wokwi simulator configuration

## Getting Started

1. Navigate to the desired project folder
2. Review the circuit diagram (diagram.json) for hardware connections
3. Open the project in Arduino IDE or PlatformIO
4. Install required libraries (see project README or comments)
5. Upload the code to your Arduino board
6. Open Serial Monitor if needed (default: 9600 baud)

## Simulation

Many projects include Wokwi circuit diagrams for online simulation:
- Visit [wokwi.com](https://wokwi.com)
- Import the `diagram.json` and `wokwi.toml` files
- Run the simulation in your browser without any hardware
- Test and debug code before building physical circuits
- Share simulations with others via URL

**Benefits of Simulation:**
- Zero hardware cost for learning
- No risk of damaging components
- Instant component availability
- Easy circuit modifications
- Built-in logic analyzer and serial monitor

## Learning Path

### Level 1: Absolute Beginner (Weeks 1-2)
Start with these projects to learn Arduino basics:
1. **01.LED Connect** - Digital output
2. **02.Buzzer Connect** - Sound generation
3. **03.Serial Monitor** - Debugging and communication
4. **04.Push Button** - Digital input
5. **05.LCD Display** - Text display basics

### Level 2: Beginner (Weeks 3-4)
Expand your knowledge with sensors and analog input:
1. **27.Photoresistor Analog** - Analog reading
2. **65.Potentiometer Plotter** - ADC visualization
3. **17.Ultrasonic Sensor** - Distance measurement
4. **30.DHT22 Test** - Temperature/humidity sensing
5. **07.LiquidCrystal_I2C_HelloWorld** - I2C communication

### Level 3: Intermediate (Weeks 5-8)
Combine multiple components:
1. **21.Ultrasonic sensor with LCD** - Multi-component integration
2. **32.DHT22 LCD** - Sensor data display
3. **14.Key Pad** - Matrix scanning
4. **67.Servo** - Motor control
5. **53.DS1307 Basic** - RTC integration
6. **34.OLED i2c ssd1306 display** - Graphics programming

### Level 4: Advanced (Weeks 9-12)
Build complex projects:
1. **10.Electronic Safe** - Security system
2. **16.Calculator** - Complex logic
3. **47.Alarm Clock** - Complete appliance
4. **70.Stepper Motor** - Motion control
5. **63.Microsd Card Prototype** - Data storage
6. **36.Snake game** - Game development

## Troubleshooting

### Common Issues and Solutions

#### Upload Errors
- **Problem**: `avrdude: stk500_recv(): programmer is not responding`
  - **Solution**: Check USB cable, select correct COM port and board type
  - Disconnect TX/RX pins during upload if using serial communication

- **Problem**: `Port is not available` or `Access denied`
  - **Solution**: Close Serial Monitor before uploading
  - Check if another program is using the port

#### Display Issues
- **Problem**: LCD shows only white blocks
  - **Solution**: Adjust contrast potentiometer on LCD module
  - Check power supply (5V for most LCDs)
  - Verify all 6 data connections (RS, EN, D4-D7)

- **Problem**: OLED display not working
  - **Solution**: Check I2C address (0x3C or 0x3D) using I2C scanner
  - Verify SDA/SCL connections
  - Ensure proper power (3.3V or 5V depending on module)

#### Sensor Problems
- **Problem**: DHT sensor returns NaN or -999
  - **Solution**: Add 10kΩ pull-up resistor to data line
  - Wait 2 seconds between readings
  - Check wiring (VCC, GND, Data)

- **Problem**: Ultrasonic sensor gives erratic readings
  - **Solution**: Mount sensor away from surfaces
  - Add delays between measurements (60ms minimum)
  - Filter noise with averaging

#### Power Issues
- **Problem**: Components not working or resetting randomly
  - **Solution**: Use external power supply for motors/servos
  - Add decoupling capacitors (100nF) near ICs
  - USB provides max 500mA - don't exceed this

#### Library Errors
- **Problem**: `Library not found` or compilation errors
  - **Solution**: Install required libraries via Library Manager
  - Check library compatibility with Arduino version
  - Update to latest library versions

### Debugging Tips
- Use Serial.println() liberally to track program flow
- Test components individually before integration
- Check all connections with multimeter
- Verify voltage levels (5V vs 3.3V logic)
- Read datasheets for component specifications
- Start with simple examples before complex projects

### Getting Help
- Check project comments in source code
- Review Wokwi simulation for correct wiring
- Search Arduino forums and Stack Overflow
- Verify component compatibility
- Test with minimal example code first

## License

Educational projects for learning embedded systems and Arduino programming.

## Contributing

Feel free to add new projects, improve existing ones, or fix bugs." 
