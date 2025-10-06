# 🚗 Car Parking Sensor System

## 🧩 Overview

The **Car Parking Sensor System** is an **embedded systems project** based on the **ATmega32 microcontroller**, designed to assist drivers while parking by detecting nearby obstacles.
The system uses an **ultrasonic sensor** to measure distance, displays it on an **LCD screen**, and provides **visual (LEDs)** and **auditory (buzzer)** feedback depending on the obstacle’s proximity.

---

## 🎯 Objective

To design and implement a **smart car parking assistant** that alerts the driver when approaching an obstacle, preventing collisions and improving parking safety.

---

## ⚙️ Features

* **Ultrasonic Distance Measurement:**
  Measures the distance between the car and obstacles using an HC-SR04 ultrasonic sensor.
* **LCD Display:**
  Shows the measured distance in centimeters and displays “STOP” when too close.
* **LED Indicators:**
  Three LEDs (Red, Green, Blue) show proximity levels.
* **Buzzer Alert:**
  Sounds when an obstacle is very close (≤ 5 cm).
* **Dynamic LED Behavior:**
  Visual alerts adapt in real time based on distance ranges.

| Distance Range | LED Status        | Buzzer | LCD Display |
| -------------- | ----------------- | ------ | ----------- |
| ≤ 5 cm         | All LEDs flashing | ON     | “STOP”      |
| 6–10 cm        | All LEDs ON       | OFF    | Distance    |
| 11–15 cm       | Red & Green ON    | OFF    | Distance    |
| 16–20 cm       | Red ON only       | OFF    | Distance    |
| > 20 cm        | All LEDs OFF      | OFF    | Distance    |

---

## 🔩 Hardware Components

* 🧠 **ATmega32 Microcontroller**
* 📡 **HC-SR04 Ultrasonic Sensor**
* 💡 **3 LEDs (Red, Green, Blue)**
* 🔊 **Buzzer**
* 🖥️ **16x2 LCD Display (4-bit mode)**
* 🔌 **Power Supply (5V)**

---

## 🧠 System Operation

1. The ultrasonic sensor sends a pulse and measures the reflection time from nearby objects.
2. The microcontroller calculates the distance using the time difference.
3. The measured distance is shown on the LCD.
4. LEDs and buzzer respond based on proximity thresholds.
5. The system updates continuously, offering **real-time distance feedback**.

---

## 🔧 Pin Configuration

| Component          | ATmega32 Pin | Description        |
| ------------------ | ------------ | ------------------ |
| LCD RS             | PA1          | Register Select    |
| LCD E              | PA2          | Enable             |
| LCD D4–D7          | PA3–PA6      | Data pins          |
| Ultrasonic Trigger | PD7          | Trigger output     |
| Ultrasonic Echo    | PD6          | Echo input         |
| Red LED            | PC0          | Distance indicator |
| Green LED          | PC1          | Distance indicator |
| Blue LED           | PC2          | Distance indicator |
| Buzzer             | PC5          | Audio alert        |

---

## 🧩 Software Layers (Drivers)

The system follows a **layered architecture** with modular drivers:

### 🕹️ GPIO Driver

* Handles pin direction and digital I/O.
* Used across all modules (LEDs, LCD, Buzzer, Ultrasonic).

### 🧭 ICU Driver

* Configured with **F_CPU/8** frequency and rising-edge detection.
* Used by the Ultrasonic driver for pulse timing.

### 🔊 Buzzer Driver

* `Buzzer_init()` – Initializes the buzzer pin.
* `Buzzer_on()` / `Buzzer_off()` – Controls sound output.

### 🖥️ LCD Driver

* 4-bit mode operation.
* Displays measured distance or “STOP” warning.

### 📡 Ultrasonic Driver

Functions:

```c
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);
```

* Measures pulse duration using the ICU driver and converts it to distance.

---

## 🧰 Tools & Requirements

* **Microcontroller:** ATmega32
* **Clock Frequency:** 16 MHz
* **Software:** Code Composer Studio / Atmel Studio
* **Language:** Embedded C
* **Architecture:** Layered (MCAL → HAL → APP)
* **Video Demo:** [YouTube Link](https://youtu.be/bhtyP1ZBiJg)

---

## 🧪 How It Works

1. Place the system on the car’s rear bumper.
2. Power on the ATmega32 board.
3. As the car moves closer to an object:

   * LCD shows decreasing distance.
   * LEDs light progressively (Blue → Green → Red).
   * Buzzer activates when distance ≤ 5 cm.

---

## 🧑‍💻 Contributors

Developed by **Edges For Training Team**

هل ترغب أضيف قسم "🔬 Future Improvements" في آخر الـREADME (زي تطوير النظام لاستخدام Arduino أو شاشة OLED أو Bluetooth App)؟
