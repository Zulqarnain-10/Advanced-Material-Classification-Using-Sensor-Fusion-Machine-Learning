# Material Sort Signal

This directory contains the code used on the Raspberry Pi for generating classification signals in the "Advanced Material Classification Using Sensor Fusion & Machine Learning" project.

## File

- **materialsortsignal.py**: Python script for generating classification signals based on sensor data.

## Overview

The `materialsortsignal.py` script is responsible for processing sensor data and generating signals to classify materials. This script runs on the Raspberry Pi, which interfaces with various sensors and processes their data using a trained machine learning model.

## Usage

### Running the Script

1. Ensure the Raspberry Pi is connected to all necessary sensors.
2. Transfer the `materialsortsignal.py` script to the Raspberry Pi.
3. Open a terminal on the Raspberry Pi.
4. Navigate to the directory containing the script:
   ```bash
   cd path/to/MaterialSortSignal
   ```
5. Run the script:
   ```bash
   python materialsortsignal.py
   ```

### Functionality

The script performs the following tasks:
- Reads data from the connected sensors (e.g., IR sensor, metal proximity sensor, color sensor, load cells).
- Processes the sensor data to extract relevant features.
- Uses a trained machine learning model to classify the material.
- Generates control signals based on the classification result to operate sorting mechanisms.

### Example Code Snippet

Here is a simplified example of what the script does:

```python
import time
import RPi.GPIO as GPIO
from tensorflow.keras.models import load_model

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)  # Example pin for output signal

# Load the trained model
model = load_model('path/to/your_model.h5')

def read_sensors():
    # Function to read sensor data
    # Replace this with actual sensor reading code
    sensor_data = [0.1, 0.2, 0.3]  # Dummy data
    return sensor_data

def classify_material(data):
    # Function to classify material based on sensor data
    prediction = model.predict([data])
    return prediction

while True:
    data = read_sensors()
    result = classify_material(data)
    if result == 'metal':
        GPIO.output(18, GPIO.HIGH)
    else:
        GPIO.output(18, GPIO.LOW)
    time.sleep(1)
```

## Contributing

Contributions to improve the signal generation script are welcome! Please follow the main project's guidelines for contributing.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/Zulqarnain-10/Advanced-Material-Classification-Using-Sensor-Fusion-Machine-Learning/blob/main/LICENSE.txt) file for details.
