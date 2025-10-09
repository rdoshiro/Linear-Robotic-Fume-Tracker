Intro:

<img width="432" height="387" alt="image" src="https://github.com/user-attachments/assets/bc74c739-7664-4d37-b798-f7e7805d3fb1" />



The Linear Fume Tracker is a system designed to follow the welding gun to effectively extract fumes, ensuring a clean working environment for the welder.

Overview:
In this prototype, two miniature blocks were used: a smaller block (the follower) and a larger block (the welding gun). As the larger block moves along the track, the follower adjusts its position in real-time, maintaining a constant distance and varying speed. The system operates using an ultrasonic sensor for real-time distance tracking and PID control to adjust the follower’s movement, maintaining a precise distance from the welding gun. This setup mimics the fume extractor hood's functionality in a real-world welding scenario, providing an automated solution for cleaner air during welding operations.

Features:
•	Real-time fume extraction based on welding gun movement.
•	Distance tracking with an ultrasonic sensor.
•	Precise follower movement using PID control.
•	Adjustable DC motor speed and direction based on PID feedback.

How to build: 
Electronics Components: 
•	Ultrasonic Sensors
•	DC Motor 
•	L293D Chip
•	Arduino Uno
•	Breadboard
•	Jumper Cables
Mechanical Components:
•	Small and Big Wooden Blocks
•	Wooden Frame
•	Aluminium Channels
•	Leadscrew
•	Pulley

Step-by-Step Instructions:
1. Connecting the Ultrasonic Sensor:
•	Connect VCC to the positive rail of the breadboard.
•	Connect Echo to Arduino Uno digital pin 3.
•	Connect Trig to Arduino Uno digital pin 4.
•	Connect Ground to the negative rail of the breadboard.
2. Connecting the L293D Motor Driver:
•	Insert the L293D chip onto the breadboard.
•	Connect pin 1 on the chip to Arduino Uno digital pin 5.
•	Connect pin 2 on the chip to Arduino Uno digital pin 4.
•	Connect pin 3 on the chip to Arduino Uno digital pin 7.
•	Connect pin 4 to the negative rail on the breadboard.
•	Connect pin 8 to the positive rail on the breadboard.
3. Connecting the DC Motor:
•	Connect the red (positive) wire of the motor to L293D pin 6.
•	Connect the black (negative) wire of the motor to L293D pin 7.

Sensor Calibration: 
• Once the ultrasonic sensor circuit is set up, perform static calibration to eliminate unexpected readings. Place the follower block at a fixed distance and send ultrasonic waves via the Trig pin to check for accuracy.

How to Use:
•	Move the larger block at varying speeds (slow, medium, fast) toward the follower block equipped with the sensor.
•	Set initial PID parameters Ki and Kd to 0, and increment Kp while observing system oscillations.
•	Fine-tune Ki and Kd after observing system behavior.
•	After tuning all PID parameters, manually move the larger block toward the follower.
•	Use the Arduino Serial Plotter to monitor and record system performance to assess accuracy and responsiveness.
•	To reduce noise, ensure that all negative terminals of the circuit are connected to ground.

Flow Chart: 
<img width="938" height="498" alt="image" src="https://github.com/user-attachments/assets/8025e26d-07b6-4db1-8769-b0b560539f83" />

Wiring Diagram: 
<img width="831" height="217" alt="image" src="https://github.com/user-attachments/assets/b375a6c1-e3b3-4bcb-a1fb-acddc712c6b4" />


Expected Outcome:
After completing the setup, calibrating sensors, and tuning the PID controller, the follower should smoothly track the welding gun’s movement, maintaining a constant distance and adjusting speed based on the sensor feedback.

