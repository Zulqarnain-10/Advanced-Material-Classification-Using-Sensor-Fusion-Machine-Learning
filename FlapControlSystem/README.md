# Flap Control System

This directory contains the code for the flap control system used in the "Advanced Material Classification Using Sensor Fusion & Machine Learning" project.

## File

- **FlapControlSystem.ino**: Arduino sketch for controlling the servo motors that operate the sorting flaps.

## Overview

The flap control system is responsible for directing materials into the appropriate bins based on the classification results from the Convolutional Neural Network (CNN) model. The system uses servo motors to control the flaps that guide the sorted materials.

## Usage

### Uploading the Code to Arduino

1. Open the Arduino IDE on your computer.
2. Connect your Arduino board to your computer via USB.
3. Navigate to the `FlapControlSystem` directory and open the `FlapControlSystem.ino` file in the Arduino IDE.
4. Select the correct board and port from the **Tools** menu.
5. Click the **Upload** button to upload the code to the Arduino.

### Controlling the Flaps

The flap control system receives signals from the main control system to activate the servo motors based on the classification results. The servos are controlled using the following logic (this is a simplified example, adjust according to your actual logic):

```cpp
#include <Servo.h>

Servo servo1;  // Create servo object to control a servo
Servo servo2;  // Create another servo object

void setup() {
  servo1.attach(9);  // Attaches the servo on pin 9 to the servo object
  servo2.attach(10); // Attaches the servo on pin 10 to the servo object
}

void loop() {
  // Example logic for controlling the flaps
  if (classification_result == METAL) {
    servo1.write(0);   // Move servo1 to 0 degrees
    delay(1000);       // Wait for a second
    servo1.write(90);  // Move servo1 back to 90 degrees
  } else if (classification_result == PLASTIC) {
    servo2.write(0);   // Move servo2 to 0 degrees
    delay(1000);       // Wait for a second
    servo2.write(90);  // Move servo2 back to 90 degrees
  }
  // Add more logic for other materials
}
```

## Contributing

Contributions to improve the flap control system are welcome! Please follow the main project's guidelines for contributing.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/Zulqarnain-10/Advanced-Material-Classification-Using-Sensor-Fusion-Machine-Learning/blob/main/LICENSE.txt) file for details.
