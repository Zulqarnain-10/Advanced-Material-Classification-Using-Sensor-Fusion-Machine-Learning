# Instructions to Run the Image Classification Script on Raspberry Pi

Overview
This guide provides step-by-step instructions on how to run the provided Python script for image classification using a trained model on a Raspberry Pi. The script captures an image, classifies it, and activates the corresponding GPIO pin based on the predicted class.

Requirements
Ensure that you have the following software and hardware setup
1. Raspberry Pi with Raspbian OS installed.
2. Raspberry Pi Camera Module connected and enabled.
3. Python 3 and necessary libraries installed (TensorFlow, Keras, RPi.GPIO, numpy).
4. The trained model file (model.h5) available on the Raspberry Pi.

Installation of Required Libraries
1. Update and upgrade your Raspberry Pi packages
   ```
   sudo apt-get update
   sudo apt-get upgrade
   ```

2. Install Python libraries
   ```
   sudo apt-get install python3-pip
   pip3 install tensorflow keras numpy RPi.GPIO
   ```

3. Install `libcamera` for camera operations
   ```
   sudo apt-get install libcamera-apps
   ```

Running the Script
1. Open a terminal on your Raspberry Pi.
2. Navigate to the directory where your script and model file are located
   ```
   cd pathtoyourscript
   ```

3. Ensure your model file is in the correct path specified in the script
   ```
   model = load_model('pathtoyourmodel.h5')
   ```

4. Run the script
   ```
   python3 your_script_name.py
   ```

Notes
- Ensure that the GPIO pins defined in the script match the ones connected to your hardware setup.
- Monitor the terminal for output messages indicating the captured image path, predicted class, and GPIO pin activation.
- The script captures an image every 5 seconds, classifies it, and activates the corresponding GPIO pin.

Ending the Program
- To stop the script, press `Ctrl+C` in the terminal.
- The GPIO cleanup is handled at the end of the script to reset the GPIO pins.

If you encounter any issues or have further questions, please refer to the project documentation or contact the project team.