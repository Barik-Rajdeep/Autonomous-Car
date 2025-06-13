# Autonomous-Car
Final Year Project 
  🔥 Overview
This project integrates Raspberry Pi, Arduino Uno, Ultrasonic Sensors, and Relay Modules to create an intelligent autonomous car system that can detect obstacles, make real-time driving decisions, and control motor movement seamlessly.

 🎯 Features
✅ Ultrasonic Obstacle Detection – Avoids collisions using real-time distance analysis  
✅  Smart Decision Making – Raspberry Pi analyzes sensor data & controls movement  
✅  Rear Wheel Control – Arduino manages relay-driven motor driver system  
✅  Web Dashboard – Live serial monitor displaying sensor readings & wheel status  
✅ Smooth Servo Steering – Mimics realistic vehicle movement  

⚙️ System Components
  Hardware
- 🛠 Raspberry Pi – Central processing unit for analysis & command execution  
- 🛠 Arduino Uno (x2) – One for ultrasonic data, one for relay control
- 🛠 Ultrasonic Sensor (GY-NEO6MV2) – Measures real-time distance from obstacles  
- 🛠 JQC3F 5V Dual DC Relay Module – Controls rear wheels for movement  
- 🛠 Motor Driver– Handles forward, backward, and stop functions  
- 🛠 Servo Motor – Implements realistic steering behavior  

   Software
- 🔧 Python Flask Web App – Displays ultrasonic data & rear wheel movement
- 🔧 Arduino Sketches – Manages sensor input, relays, and motor controls  
- 🔧 Serial Communication– Enables seamless command transmission between Raspberry Pi & Arduino  

 🚀 How It Works
1. Obstacle Detection – The ultrasonic sensor continuously scans for obstacles.  
2. Data Processing – Raspberry Pi analyzes distance readings & decides movement actions.  
3. Command Execution – Raspberry Pi sends forward, backward, or stop commands to the second Arduino.  
4. Relay & Motor Driver – The second Arduino triggers relays to control wheel movement.  
5.Live Web Dashboard – Displays distance readings & real-time wheel movement status.  

 🔗 Setup Instructions
1️⃣ Wiring Connections**
- Ultrasonic Sensor → Arduino 1 (TX/RX for serial)  
- Arduino 1 → Raspberry Pi (Serial communication via GPIO)  
- Raspberry Pi → Arduino 2(USB Serial for command relay)  
- Relay Module → Motor Driver (Controls rear wheels)  

2️⃣ Software Setup**
- Raspberry Pi: Install Flask & Serial packages  
  ```bash
  sudo apt update
  sudo apt install python3-serial
  pip3 install flask
  ```
-Upload Arduino Codes: Flash both **ultrasonic & relay control scripts** to Arduino Uno.  
- Run the Web App: Start the Flask server on Raspberry Pi  
  ```bash
  python3 monitor.py
  ```

🎥 Demo Video (Optional)
_🚧 Coming soon!_

💡 Future Enhancements
🔜 **AI-based Path Planning** – Add ML-based obstacle navigation  
🔜 **GPS Integration** – Implement real-time location tracking  
🔜 **Speed Optimization** – Dynamic speed control based on environment  

 🛠 Contributing
Feel free to **fork, modify, and improve** the project! 🚀  
Issues & pull requests are always welcome.  

 📜 License
_This project is open-source under the MIT License._  




