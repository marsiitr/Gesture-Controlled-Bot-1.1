# Gesture-Controlled-Bot-1.1
Srishti 2019  
## ABSTRACT  
A Gesture Controlled Robot doesn't need to be controlled by clunky buttons. You just need to wear a transmitting device on your hand which includes an acceleration meter. This transmits the appropriate command to the robot so that it can do whatever we want it to.

## MECHANICAL ASPECTS   
Our design doesn't consists of any complex or advanced parts. That's why we were able to make it without using solidworks.  
Chasis consists a board(19*16cm,such that circuit components can be placed) on which at back,on left and right side two motors were fixed using L-bracket. In front, at the centre a castor wheel was used at the centre for 360 degree movement.
The Motor Driver was placed at the center for easy connections. Node Mcu was placed on the left and battery was placed on the right for stability.   
For controlling the bot MPU along with the Node mcu was placed on a hand glove.  

## ELECTRONICS ASPECTS   
Electronics design was basically divided into two parts: Sender and reciever end.  
At sender, which was mounted on gloves, with purpose of observing gesture. We used MPU-9250, gyroscope for having tilt of hand. It was read by microcontroller Node MCU esp 8266. The SDA and SCL pin of MPU was solded to D2 and D1 respectively, while VCC and ground of MPU were also solded to MCU using male female holders, jumper wires were not used to avoid delay in data which resulted in stoppage of data flow.   
MPU reading was mapped accordingly and sent to receiver MCU using http server  communication in form of . At the reciever end, reciever MCU use to transfer pwm data to motor driver. This motor driver use to control both the motors accordingly. Input pins were connected to D0 and D1 of MCU and direction pins were connected to D2, D3, D4, D5 respectively.   
Battery was used to power motordriver bacross 12V and ground terminal, and through 5V and ground terminal we powered MCU. Motors were powereed and controlled through motor driver.

## COST STRUCTURE
For one bot
1. NODE MCU(x2) - Rs 1300   
2. MOTOR DRIVER(x1) - Rs 150   
3. JHONSON MOTOR(X2) - Rs 150   
4. CASTOR WHEEL(X1) - Rs 100   
5. BATTERY(X1) - Rs 100
6. POWER BANK   

## APPLICATONS
1. Can be used for military purposes.    
2. Can be used as a transportation vehicle.   

## LIMITATION   
Could not drive and rotate at the same time. External SS point has to be included otherwise dealy in data transfer will increase.   
 
## FUTURE IMPROVEMENTS
Machine Learning could also be used for further development of the bot. Smartphones could also used for controlling the bot instead of hand glove.

## TEAM MEMBERS
1. AADARSH MISHRA  
2. HARSH KHANNA  
3. HARSHIT GOENKA  
4. GOPAL JAIN  
5. GOVIND JAIN  
6. MADHUKAR  
7. NIKHIL AGARWAL  

## MENTORS  
1. SHREYASH GEDA
2. VEDVYAS DANTURI  
   



