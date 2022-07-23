# LabView-Projects
Projects developed using LabView 2011 from National Instruments

# PID Positioning Controller 
The work was carried out on a plant mounted with Arduino in which an LCD was connected to show the information of a chosen setpoint and the value of an angle that was measured. Along with it, an H-bridge was connected to adjust the measured angle value to the chosen setpoint within the project in LabVIEW through a PID control.

In the internal part of the project developed in LabVIEW, two functions were first created in the Arduino IDE to be used within two SubVIs which were the functions: Start LCD and Write to LCD.

Then, the project was programmed to show the setpoint and current position on the LCD and the setpoint value to be adjusted internally in the LabVIEW interface. Thus, two graphs were also implemented to show these values in real time in a visual way in the interface.

Finally, the program sends every second in the form of a string into a text file, saving the date, hour, minutes, seconds, setpoint value, process variable value and the manipulated variable.

# PID Water Controller
This project aim to control the level of a reservoir through the use of a pump and an ultrasonic sensor. The pump is controlled so that the level is maintained at or closer to the value set in the program interface. When the pump is at its maximum speed and cannot maintain the desired level, the system issues an alert after a predetermined time. 
If the level exceeds the chosen value, the pump is kept off until its activation is necessary. The current Level is shown on the interface along with the desired level.

# HOW TO RUN THE CODES IN LABVIEW?
1) Download the Vi's and the SubVi's along with its respectives .ino codes
2) Run .ino archive into your arduino module if there is in the chosen project
3) Make sure to have the serial port correctly selected
4) Run! :)
