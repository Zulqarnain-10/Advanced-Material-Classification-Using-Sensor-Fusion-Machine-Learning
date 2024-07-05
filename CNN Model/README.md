# CNN Model

This directory contains the Convolutional Neural Network (CNN) model files for the project "Advanced Material Classification Using Sensor Fusion & Machine Learning".

## Files

- **my_cnn_model_updated(latest).h5**: The latest trained CNN model file in HDF5 format.

## Overview

The CNN model is designed to classify materials such as metals, plastics, and glass based on sensor data. The model has been trained using a custom dataset and integrated into the material classification system.

## Usage

### Loading the Model

To use the CNN model in your application, load the model using the following Python code:

from tensorflow.keras.models import load_model

# Load the model
model = load_model('path/to/my_cnn_model_updated(latest).h5')

### Making Predictions

Once the model is loaded, you can use it to make predictions on new data. Here’s an example of how to do that:

import numpy as np

# Assuming data is a preprocessed input for the model
predictions = model.predict(data)

# Interpreting the predictions
predicted_classes = np.argmax(predictions, axis=1)
print(predicted_classes)

## Training the Model

The model was trained using a Jupyter Notebook, which can be found in the `CNNModelTraining` directory of the main project repository. Refer to the `CNNModelTraining` directory for details on how to retrain the model with new data.

## Contributing

Contributions to improve the CNN model are welcome! Please follow the main project's guidelines for contributing.

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.
