# traffic-Light
AVR-based traffic light controller with LCD and dual 7-segment countdown. Displays 'STOP', 'READY', and 'GO' messages with timed LED control for red, yellow, and green signals.

# AVR Traffic Light System with LCD & 7-Segment Display

## 📌 Overview
This project implements a traffic light controller using an **ATmega microcontroller**, an **LCD display**, and **two 7-segment displays**.  
The system:
- Controls **Red, Yellow, and Green LEDs** for traffic signaling.
- Displays a countdown timer on **two 7-segment displays** (tens and ones).
- Shows a **text message** on an LCD corresponding to the current light:
  - **"STOP"** when Red
  - **"READY"** when Yellow
  - **"GO"** when Green

---

## 🛠 Hardware Connections

### **Port Mapping**
| Component             | Port / Pin         | Description                  |
|-----------------------|--------------------|------------------------------|
| LCD RS                | `PORTA0`           | LCD Register Select          |
| LCD RW                | `PORTA1`           | LCD Read/Write               |
| LCD E                 | `PORTA2`           | LCD Enable                   |
| LCD Data Lines D0–D7  | `PORTC0–PORTC7`    | LCD Parallel Data Bus        |
| Green LED             | `PORTA5`           | Traffic Light Green Signal   |
| Yellow LED            | `PORTA6`           | Traffic Light Yellow Signal  |
| Red LED               | `PORTA7`           | Traffic Light Red Signal     |
| 7-Segment (Ones)      | `PORTB`            | Common Cathode Segment Lines |
| 7-Segment (Tens)      | `PORTD`            | Common Cathode Segment Lines |

---

## 📂 File Structure
/TrafficLight-LCD-AVR
│── main.c # Main traffic light program
│── LCD.c # LCD driver implementation
│── LCD.h # LCD driver header
│── README.md # This documentation


---

## ⚙ Software Details
- **Language**: C (AVR-GCC)
- **Microcontroller**: ATmega series (tested on ATmega16/32)
- **Clock Frequency**: 8 MHz
- **Libraries**:
  - `<avr/io.h>`
  - `<util/delay.h>`

---

## 🚦 How It Works
1. **Initialization**
   - Sets all LCD, LED, and 7-segment pins as outputs.
   - Initializes the LCD display.

2. **Traffic Light Cycle**
   - **Green Light (30s)** → LCD shows `"GO"` → LEDs and countdown update.
   - **Yellow Light (10s)** → LCD shows `"READY"` → LEDs and countdown update.
   - **Red Light (30s)** → LCD shows `"STOP"` → LEDs and countdown update.
   - Loops indefinitely.

---

## 🔌 Circuit Diagram
<img width="1375" height="1013" alt="image" src="https://github.com/user-attachments/assets/fd7da80e-6488-4ef5-9dbc-0812e654e6e3" />



