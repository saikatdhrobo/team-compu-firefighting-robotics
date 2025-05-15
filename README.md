# Fire Fighting Robot — Robotics Course Group Project

This Arduino code is developed for the **Fire Fighting Robot** as part of our Robotics course group project. The robot is designed to detect fire, avoid obstacles, and extinguish fire using a water pump.

## Features

- Detects obstacles using left, right, and forward sensors.
- Controls left and right motors for movement (forward, backward, left, right).
- Uses an ultrasonic sensor to measure distance for obstacle avoidance.
- Activates a water pump to extinguish detected fire.
- Accepts movement commands through serial communication.
- Automatically stops and sprays water when fire is detected.

## Hardware Pin Configuration

| Component           | Arduino Pin       |
|---------------------|-------------------|
| Left Sensor         | 9                 |
| Right Sensor        | 11                |
| Forward Sensor      | 10                |
| Left Motor Control  | 2 (LM1), 3 (LM2)  |
| Right Motor Control | 4 (RM1), 5 (RM2)  |
| Water Pump          | 7                 |
| Ultrasonic Trigger  | 12                |
| Ultrasonic Echo     | 13                |
| Motor Speed PWM     | 6                 |

## How It Works

- Reads input from fire and obstacle sensors.
- Controls motors to move based on serial commands:
  - `F` - Move forward
  - `B` - Move backward
  - `L` - Turn left
  - `R` - Turn right
  - `S` - Stop and scan using ultrasonic sensor
- Stops and activates water pump to extinguish fire when detected.
- Uses ultrasonic sensor to measure distance and avoid collisions.

## Libraries Used

- `Servo.h` for servo control
- `SoftwareSerial.h` for serial communication

## Usage Instructions

1. Upload this code to your Arduino board.
2. Connect all sensors, motors, and pump according to the hardware pin configuration.
3. Use Serial Monitor or an external controller to send movement commands.
4. The robot will navigate, avoid obstacles, and extinguish fire automatically.

---

*Developed as part of the Robotics course group project.*
