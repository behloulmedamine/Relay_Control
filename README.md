# Arduino Relay Control

This project allows you to control two relays using an Arduino via serial communication. You can send commands from a Python script to turn the relays on or off.

## Components Required

- Arduino Nano (or any other compatible board)
- Two relays (with appropriate driver circuit)
- USB cable to connect the Arduino to your PC
- Python installed on your computer with `pyserial` library

## Circuit Diagram

(Include a circuit diagram or image here if available)

## Code Overview

### Arduino Code

The Arduino code listens for serial commands (`0`, `1`, or `2`) to control the relays:

- **Command `0`**: Turns both relays off.
- **Command `1`**: Turns on Relay 1 and turns off Relay 2.
- **Command `2`**: Turns on Relay 2 and turns off Relay 1.

### Python Script

The Python script sends commands to the Arduino based on user input and reads responses.

## How to Use

### Step 1: Upload Arduino Code

1. Open the Arduino IDE.
2. Copy and paste the Arduino code into a new sketch.
3. Select the correct board and port in the IDE.
4. Upload the code to the Arduino.

### Step 2: Run the Python Script

1. Ensure you have Python installed. You can download it from [python.org](https://www.python.org/).
2. Install the `pyserial` library:

   ```bash
   pip install pyserial
   ```

3. Modify the `port` variable in the Python script to match the port your Arduino is connected to (e.g., `'/dev/ttyUSB0'` on Linux or `'/dev/cu.usbmodemXXXX'` on macOS).
4. Run the Python script:

   ```bash
   python your_script_name.py
   ```

5. Follow the prompts in the terminal to send commands to the Arduino.

### Example Commands

- Enter `0` to turn off both relays.
- Enter `1` to turn on Relay 1 and turn off Relay 2.
- Enter `2` to turn on Relay 2 and turn off Relay 1.
- Enter `q` to quit the script.

## Troubleshooting

- Ensure the correct serial port is specified in the Python script.
- Check your connections and ensure the relays are powered appropriately.
- If you encounter a "device busy" error, ensure no other program (like the Arduino IDE Serial Monitor) is using the serial port.

## License

This project is open-source. Feel free to modify and use it as you wish!
