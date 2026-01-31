# 🌡️ Arduino LCD Temperature Monitor

Arduino-based temperature monitor using a **TMP36 sensor** and a **16x2 LCD display**.  
It shows the current temperature in Celsius, tracks **minimum and maximum values**,  
and visualizes the temperature level with a **vertical bar graph** using custom LCD characters.

---

## ✨ Features

- 🌡️ Real-time temperature reading in °C
- 📉 Minimum and maximum temperature tracking
- 📊 Vertical bar graph visualization
- 🔠 Custom LCD characters (degree symbol and bars)
- ⏱️ Updates every 1 second
- 🛠️ Beginner-friendly Arduino code

---

## 🧰 Components Required

- Arduino UNO  
- TMP36 temperature sensor  
- 16x2 LCD display (HD44780 compatible)  
- Breadboard  
- Jumper wires  
- Potentiometer (for LCD contrast)

---

## 🔌 Wiring

### TMP36 → Arduino

| TMP36 Pin | Arduino |
|-----------|---------|
| VCC       | 5V      |
| OUT       | A0      |
| GND       | GND     |

### LCD 16x2 (4-bit mode)

| LCD Pin | Arduino |
|---------|---------|
| RS      | 12      |
| E       | 11      |
| D4      | 5       |
| D5      | 4       |
| D6      | 3       |
| D7      | 2       |
| VSS     | GND     |
| VDD     | 5V      |
| VO      | Potentiometer |

---

## 🖥️ LCD Output Example

**Line 1: Temperature & Min/Max**

---

## ⚙️ How It Works

1. The TMP36 sensor is read using `analogRead(A0)`  
2. Analog value is converted to voltage  
3. Voltage is converted to temperature in Celsius  
4. Temperature is limited between **0°C and 40°C**  
5. Minimum and maximum values are updated automatically  
6. A vertical bar (0–8 levels) shows the temperature visually  
7. The LCD refreshes every **1 second**

---

## 🧮 TMP36 Formula

```cpp
temperature = (voltage - 0.5) * 100.0;
