# anti-aleeping-alarm
An Arduino-based driver drowsiness detection and alert system that monitors eye state using infrared reflection and triggers an alarm when prolonged eye closure is detected. This project was developed as part of an Applied Physics laboratory to demonstrate practical applications of optics, sensing, and embedded control in safety systems.

# 📌 Overview

Driver fatigue is a major cause of road accidents. This project implements a simple real-time monitoring system that detects eye closure duration using an IR eye-blink sensor. If the eyes remain closed for more than 3 seconds, the system:

Activates an audible buzzer alarm

Stops the motor (vehicle model) via relay

When eyes reopen, the system automatically returns to normal operation.

#⚙️ System Working Principle

The system operates on the principle of infrared (IR) reflection:

IR emitted → reflected by open eye → detected by sensor

Eyes closed → reflection reduced/absent

Arduino measures duration of reflection loss

If duration ≥ threshold → drowsiness detected

The Arduino Nano processes the sensor signal using millis-based timing to distinguish normal blinking from prolonged eye closure.

# 🧩 Hardware Components

Arduino Nano

HW-201 IR Eye Blink Sensor

5V Relay Module (active-low)

DC Motor + Wheel

Buzzer

2 × 9V Batteries

Connecting wires / breadboard

# 🔌 Circuit Connections

IR Sensor → Arduino

VCC → 5V

GND → GND

OUT → D2

Relay Module → Arduino

VCC → 5V

GND → GND

IN → D8

Buzzer

→ D9

− → GND

Motor via Relay

Motor + → Relay COM

Relay NO → Motor battery +

Motor − → Motor battery −

Common Ground: All grounds connected together.

# 🧠 Logic Flow
Condition	Motor	Buzzer
Eyes open	ON	OFF
Eyes closed < 3 s	ON	OFF
Eyes closed ≥ 3 s	OFF	ON
Eyes reopen	ON	OFF

# 🎯 Features

Real-time eye closure monitoring

Time-threshold drowsiness detection

Automatic alarm and motor cutoff

Simple, low-cost hardware

Educational embedded safety model

# 🚀 Applications

Driver drowsiness alert systems

Transportation safety models

Fatigue monitoring research

Embedded systems education

Human-machine interaction demos

# 🔧 Possible Improvements

Adjustable sensitivity / delay

LED visual alerts

Wearable sensor mount

Vehicle integration

Wireless monitoring

Camera-based detection

# 📄 License

This project is open-source and free to use for educational and research purposes.
