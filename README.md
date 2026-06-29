# Advanced Material Classification — Sensor Fusion + CNN

![Python](https://img.shields.io/badge/Python-3.x-3776AB?logo=python&logoColor=white)
![TensorFlow](https://img.shields.io/badge/TensorFlow-CNN-FF6F00?logo=tensorflow&logoColor=white)
![Keras](https://img.shields.io/badge/Keras-deep%20learning-D00000?logo=keras&logoColor=white)
![Raspberry Pi](https://img.shields.io/badge/Raspberry%20Pi-hardware-A22846?logo=raspberrypi&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-control-00979D?logo=arduino&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green)

> An automated recycling sorter that classifies materials — metal, plastic, glass — by fusing multi-sensor readings with a CNN, built end-to-end with real hardware as a final-year capstone.

## Problem

Recycling streams mix metals, plastics, and glass, and manual sorting is slow and error-prone. A practical sorter must identify material type reliably from low-cost sensors and actuate a sorting mechanism in real time.

## Approach

Two complementary models run on a Raspberry Pi + Arduino rig:

- **CNN vision model** (TensorFlow / Keras) — classifies material from camera images, trained on a **custom dataset** captured under varied lighting and angles with a **70/30 train/test split**.
- **Sensor-fusion model** — combines **IR**, **metal-proximity**, **color (TCS3200)**, and **load-cell (HX711)** readings to disambiguate cases the camera alone can't (e.g., clear plastic vs. glass).
- **Actuation** — an Arduino **flap-control system** routes each item to the correct bin based on the prediction.

## Results

- The CNN reaches **~96% classification accuracy** on the custom dataset (validation accuracy ranges ~92–100% across epochs — see [`CNNModelTraining/CNNModelTraining.ipynb`](CNNModelTraining/CNNModelTraining.ipynb)).
- Real-time predictions demonstrated live on hardware for metal, plastic, and glass (see demo videos in `Videos/`).
- Full methodology, schematics, and results documented in the [Final Project Report](Final%20Project%20Report/).

## Tech stack

`Python` · `TensorFlow` · `Keras` · `NumPy` · `Pandas` · `Raspberry Pi` · `Arduino (C/C++)` · sensors: `IR` · `metal proximity` · `TCS3200 color` · `HX711 load cell`

## Demo

Demonstration videos (metal / plastic / glass detection) and hardware photos are in [`Videos/`](Videos/) and [`Images/`](Images/). Hardware and software block diagrams are in [`Flowcharts & Block Diagrams/`](Flowcharts%20&%20Block%20Diagrams/).

## Repository structure

| Path | Contents |
| --- | --- |
| `CNNModelTraining/` | CNN training notebook + script |
| `SensorFusionModelTraining/` | Sensor-fusion model training |
| `CNN Model/` | Saved trained model (`.h5`) |
| `Datasets/` | Per-material sensor datasets (CSV) |
| `FlapControlSystem/` | Arduino sorting-flap controller (`.ino`) |
| `MaterialSortSignal/` | Signal-processing for sorting |
| `Datasheets/` | Sensor & component datasheets |
| `Final Project Report/` | Full capstone report (PDF) |

## How to run

**Train the CNN**

```bash
pip install -r requirements.txt
# Download the dataset (link below), then open and run:
#   CNNModelTraining/CNNModelTraining.ipynb
```

Dataset: [Google Drive](https://drive.google.com/file/d/1zLjwx7HyiJ9iWzKVWlQKtAgT0XEnE_bh/view?usp=sharing)

**Run on hardware** — wire the sensors and actuators per the schematics in `Flowcharts & Block Diagrams/`, flash the Arduino sketch in `FlapControlSystem/`, then run the control scripts on the Raspberry Pi.

## License

MIT — see [LICENSE.txt](LICENSE.txt).
