# 🚗 Automotive CAN-Based Dashboard System using PIC18F4580

## 📌 Overview
The **Automotive CAN-Based Dashboard System** is an embedded systems project implemented using the **PIC18F4580 microcontroller** and the **Controller Area Network (CAN) protocol**. The system simulates communication between multiple Electronic Control Units (ECUs) typically used in modern vehicles.

In automotive systems, different ECUs are responsible for handling various vehicle parameters such as speed, engine RPM, gear position, and indicator status. These ECUs communicate with each other using the **CAN bus**, enabling reliable and real-time data exchange.

This project demonstrates a **multi-node CAN communication system** where different ECUs generate and transmit vehicle parameters, and another ECU receives and displays the information on a dashboard.

---

# ⚙ System Architecture

The system consists of **three ECUs connected through CAN bus communication**.

### ECU1 – Vehicle Speed & Gear Module
- Reads **vehicle speed using ADC input**
- Processes speed value and transmits it via CAN
- Gear selection is controlled using a **digital keypad**
- Sends **speed and gear data** to the CAN bus

### ECU2 – Engine RPM & Indicator Module
- Reads **RPM value using ADC input**
- Indicator control using **digital keypad**
- Supports:
  - Left Indicator
  - Right Indicator
  - Hazard Indicator
- Indicator status is also represented using **LED outputs**
- Sends **RPM and indicator data** through the CAN bus

### ECU3 – Dashboard Display Module
- Receives CAN messages from **ECU1 and ECU2**
- Extracts parameters from CAN frames
- Displays vehicle parameters on the **CLCD dashboard**

Displayed parameters include:
- Vehicle Speed
- Gear Position
- Engine RPM
- Indicator Status

---

# 🧠 CAN Protocol

The **Controller Area Network (CAN)** protocol is widely used in automotive systems for communication between ECUs.

Key advantages include:

- Real-time communication
- High reliability
- Built-in error detection
- Multi-node communication
- Reduced wiring complexity

In this project, CAN frames are used to transmit vehicle parameters between ECUs.

---

# 📊 Data Communication

| Parameter | ECU Source | Description |
|-----------|------------|-------------|
| Speed | ECU1 | Vehicle speed from ADC |
| Gear | ECU1 | Gear selected via keypad |
| RPM | ECU2 | Engine RPM from ADC |
| Indicator | ECU2 | Indicator / hazard status |

ECU3 receives the data and updates the dashboard display.

---

# 🖥 Hardware Components

- **Microcontroller:** PIC18F4580  
- **CAN Transceiver:** MCP2551  
- **Display:** CLCD (Character LCD)  
- **Analog Input:** Potentiometer / Sensor via ADC  
- **Input Device:** Digital Keypad  
- **Indicator Output:** LEDs  
- **Communication Bus:** CAN Bus  

---

# 🛠 Software Implementation

The project is developed in **Embedded C** using **MPLAB IDE** and **XC8 Compiler**.

Key modules include:

- CAN initialization
- CAN message transmission
- CAN message reception
- ADC configuration and data reading
- Keypad interface
- Indicator and hazard control
- LCD dashboard display
- Vehicle parameter processing

---

# 📡 CAN Message Flow

1️⃣ ECU1 reads **speed from ADC** and **gear from keypad**  
2️⃣ ECU1 transmits speed and gear using CAN frames  

3️⃣ ECU2 reads **RPM from ADC** and **indicator status from keypad**  
4️⃣ ECU2 transmits RPM and indicator status using CAN frames  

5️⃣ ECU3 receives CAN frames  
6️⃣ ECU3 processes the data and updates the **dashboard display**

---

# 📋 Features

- Multi-node CAN communication
- ADC-based speed and RPM simulation
- Keypad-based gear selection
- Indicator and hazard control
- LED indicator visualization
- Dashboard display using CLCD
- Real-time ECU communication

---

# 🎯 Applications

This project demonstrates concepts used in:

- Automotive dashboard systems
- Vehicle ECU networks
- CAN-based communication systems
- Embedded automotive electronics
- Real-time monitoring systems

---

# 🧠 Learning Outcomes

This project helps in understanding:

- CAN bus communication
- Embedded C programming
- Microcontroller peripheral interfacing
- ADC data acquisition
- Keypad interfacing
- Automotive ECU architecture
- Real-time embedded system design

---

# 🚀 Possible Enhancements

Future improvements may include:

- Fuel level monitoring
- Temperature sensing
- OBD diagnostics integration
- Graphical dashboard display
- CAN error monitoring
- Wireless telemetry

---

# 👨‍💻 Author
**Pranav Prasad**
