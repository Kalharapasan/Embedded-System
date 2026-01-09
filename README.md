"# Arduino Embedded Systems Projects

A comprehensive collection of Arduino projects demonstrating various embedded systems concepts, sensors, displays, and components.

## Table of Contents

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
- [License](#license)
- [Contributing](#contributing)

## Projects by Category

### LED & Basic Output

- **01.LED Connect** - Basic LED control and blinking
- **02.Buzzer Connect** - Buzzer sound control
- **66.Relay Demonstration** - Relay switching circuit

### Input Devices

- **04.Push Button** - Push button input handling
- **48.Joystick** - Analog joystick control
- **54.KY-040 Rotation** - Rotary encoder basic usage
- **55.KY-040 Counter** - Rotary encoder counter application
- **56.Volume Control** - Potentiometer volume control
- **65.Potentiometer Plotter** - Analog input plotting
- **69.Slide Pot** - Slide potentiometer control

### Display Systems

- **03.Serial Monitor** - Serial communication basics
- **05.LCD Display** - 16x2 LCD display control
- **06.LCD1602 Custom Characters** - Custom character creation on LCD
- **07.LiquidCrystal_I2C_HelloWorld** - I2C LCD interface
- **12.LCD 16x2 I2C Example** - I2C 16x2 display setup
- **13.Arduino LCD 20x4 I2C Example** - I2C 20x4 display setup
- **11.LCD_20x4 Text** - 20x4 LCD text operations
- **34.OLED i2c ssd1306 display** - OLED display (I2C)
- **35.Draw Bitmap** - Bitmap drawing on OLED
- **75.Nokia 5110** - Nokia 5110 display interface

### Distance & Ultrasonic Sensors

- **17.Ultrasonic Sensor** - HC-SR04 basic usage
- **18.Ultrasonic Distance Sensor** - Distance measurement
- **19.Ultrasonic Sensor with Buzzer** - Distance alert system
- **20.A Virtual Tape Measure** - Ultrasonic-based measurement tool
- **21.Ultrasonic sensor with LCD** - Distance display on LCD
- **22.Ultrasonic sensor and lcd** - Enhanced ultrasonic LCD integration
- **23.SR04_array_of_struct** - Multiple ultrasonic sensors

### Environmental Sensors

- **28.Ntc Temperature Sensor** - NTC thermistor temperature measurement
- **29.Temperature sensor** - Basic temperature sensing
- **30.DHT22 Test** - DHT22 humidity and temperature sensor
- **31.DHT Tester** - DHT sensor testing utility
- **32.DHT22 LCD** - DHT22 data display on LCD
- **33.Temp and hum detection system** - Complete temperature/humidity system
- **37.OLED and DHT22** - DHT22 readings on OLED display

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

- **09.Nano Clock** - Arduino Nano clock project
- **47.Alarm Clock** - Functional alarm clock
- **53.DS1307 Basic** - DS1307 real-time clock module
- **60.Max7219 Clock DHT** - MAX7219 display with DHT sensors

### Motor Control

- **49.Biaxial Stepper Motor** - Two-axis stepper motor control
- **50.Bxaxial Stepper Driver A4988** - A4988 stepper driver module
- **67.Servo** - Servo motor control
- **68.Knob** - Servo control with potentiometer
- **70.Stepper Motor** - Basic stepper motor control
- **71.Stepper Motor II** - Advanced stepper motor operations
- **72.Proportional Control Accel Stepper** - AccelStepper library usage

### Audio & Sound

- **51.Mini Piano** - Simple piano keyboard with buzzer/speaker

### Advanced Components

- **10.Electronic Safe** - Electronic safe with security features
- **14.Key Pad** - 4x4 keypad matrix input
- **15.Keypad and LCD I2C with Arduino UNO** - Keypad with I2C LCD integration
- **16.Calculator** - Calculator using keypad and display
- **52.Arduino Pind Example** - Pin state demonstration
- **57.Gas sensor detecting smoke** - MQ series gas sensor
- **58.LED Bar Graph with Pot** - Analog bar graph display
- **59.Logic Analyzer Demonstration** - Digital signal analysis
- **61.Joystick Etch a Sketch** - Drawing application with joystick
- **62.Arduino QR Code Generator** - QR code generation on display
- **63.Microsd Card Prototype** - SD card file operations
- **46.String With Period** - String manipulation example

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
- Run the simulation in your browser

## License

Educational projects for learning embedded systems and Arduino programming.

## Contributing

Feel free to add new projects, improve existing ones, or fix bugs." 
