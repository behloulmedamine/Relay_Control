import serial
import time

# Serial port configuration
port = '/dev/ttyUSB0'  # Replace with the correct port
baud_rate = 9600
arduino = serial.Serial(port, baud_rate, timeout=2)  # Add a 2-second timeout
time.sleep(2)  # Delay to allow the serial connection to stabilize

print("Enter 0, 1, or 2 to send a command to the Arduino (q to quit)")

try:
    while True:
        user_input = input("Your choice: ")
        if user_input in ['0', '1', '2']:
            arduino.write(user_input.encode())  # Send the command
            print(f"Sent: {user_input}")

            # Try to read the response from Arduino
            response = arduino.readline().decode('utf-8').strip()  # Attempt to read data
            if response:  # Only print if we receive a response
                print(f"Received from Arduino: {response}")
            else:
                print("No response from Arduino.")

        elif user_input == 'q':
            print("Closing connection.")
            break
        else:
            print("Invalid input. Enter 0, 1, 2, or 'q' to quit.")

finally:
    arduino.close()
