📌Project objective:
To develop an automated and secure parking system using arduino that efficiently manages vehicle movement, displays real-time slot availability, and ensures safety through hazard detection.

🛠️Components Used:
◽Arduino Uno
◽IR Sensors (x2) – for vehicle entry/exit detection
◽Servo Motor – for automatic gate control
◽16x2 I2C LCD – to display parking status and safety alerts
◽LDR Sensor – for detecting low light conditions
◽Flame Sensor – for fire detection
◽Gas Sensor – for gas leakage detection
◽LED – visual alert for darkness
◽Buzzer – audio alert for hazards

⚙️How it works:
Automated Entry/Exit: IR sensors detect approaching or exiting vehicles and the servo motor opens or closes the gate accordingly.

Slot Management: The system maintains a count of available parking slots (up to 4) and updates the LCD display in real time.

Safety Features: The LDR sensor activates an LED in low-light conditions while the flame sensor and gas sensor detect hazardous situations like fire or gas leaks. If a hazard is detected, the buzzer sounds and a warning message is displayed on the LCD.

🌐Real-World Applications:
◽Smart parking in malls, offices, hospitals, and airports.
◽Automated entry/exit in gated communities and complexes.
◽Ideal for smart city infrastructure with future IoT integration.
◽Enhanced safety in underground or enclosed parking areas.
