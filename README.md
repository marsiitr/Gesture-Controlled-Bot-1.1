# Gesture-Controlled-Bot-1.1
Srishti 2019  
## Abstract  
A Gesture Controlled Robot doesn't need to be controlled by clunky buttons. You just need to wear a transmitting device on your hand which includes an acceleration meter. This transmits the appropriate command to the robot so that it can do whatever we want it to.  

![Image 3](https://github.com/Nikhil569/Gesture-Controlled-Bot-1.1/blob/patch-1/Images%20and%20Videos/Images/Implementation%20-%203.jpeg)   

## Motivation   
In spite of the fact that there are numerous con-trolled robots using commands from user or self-controlled that uses GPS and sensors, the requirement for gesture controlled robots are on ascent for military purposes, which is called as Unmanned ground vehicles (UGVs). These robots are utilized to increase the warrior's capacity in an open territory. In the last few years, tremendous research is going on in various parts of the world to develop robots for military purposes.     

## Mechanical Aspects   
1. Our design doesn't consists of any complex or advanced parts. That's why we were able to make it without using solidworks.  
Chasis consists a board(19*16cm,such that circuit components can be placed) on which at back,on left and right side two motors were fixed using L-bracket. In front, at the centre a castor wheel was used at the centre for 360 degree movement.
2. The Motor Driver was placed at the center for easy connections. Node Mcu was placed on the left and battery was placed on the right for stability.   
3. For controlling the bot MPU along with the Node mcu was placed on a hand glove.  

## Electronics Aspects   
1. Electronics design was basically divided into two parts: Sender and reciever end.  
At sender, which was mounted on gloves, with purpose of observing gesture. We used MPU-9250, gyroscope for having tilt of hand. It was read by microcontroller Node MCU esp 8266. The SDA and SCL pin of MPU was solded to D2 and D1 respectively, while VCC and ground of MPU were also solded to MCU using male female holders, jumper wires were not used to avoid delay in data which resulted in stoppage of data flow.   
2. MPU reading was mapped accordingly and sent to receiver MCU using http server  communication in form of . At the reciever end, reciever MCU use to transfer pwm data to motor driver. This motor driver use to control both the motors accordingly. Input pins were connected to D0 and D1 of MCU and direction pins were connected to D2, D3, D4, D5 respectively.   
3. Battery was used to power motordriver bacross 12V and ground terminal, and through 5V and ground terminal we powered MCU. Motors were powereed and controlled through motor driver.

## Cost Structure
For one bot :      
        
| Sr. No. | Item | Cost |  
|---------|---------|---------|    
| 1. | NODE MCU(x2) | Rs 1300 |   
| 2. | MOTOR DRIVER(x1) | Rs 150 |      
| 3. | JHONSON MOTOR(X2) | Rs 150 |      
| 4. | CASTOR WHEEL(X1) | Rs 100 |      
| 5. | BATTERY(X1) | Rs 100 |     
| 6. | POWER BANK  |        |       

## Applications
1. Can be used for military purposes.    
2. Can be used as a transportation vehicle.   

## Limitation   
Could not drive and rotate at the same time. External SS point has to be included otherwise dealy in data transfer will increase.   
 
## Future Improvements
Machine Learning could also be used for further development of the bot. Smartphones could also used for controlling the bot instead of hand glove.

## Team Members
1. Aadarsh Mishra  
2. Harsh Khanna  
3. Harshit Goenka  
4. Gopal Jain  
5. Govind Jain  
6. Madhukar  
7. Nikhil Agarwal  

## Mentors  
1. Shreyash Geda
2. Vedvyas Danturi  
   
## References    
1. https://github.com/bolderflight/MPU9250/blob/master/README.md
2. https://www.how2electronics.com/dc-motor-control-using-mpu6050-gyro-accelerometer/
3. https://randomnerdtutorials.com/esp8266-web-server/


