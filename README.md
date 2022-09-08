# Password-Protected-Locker
Password Protected Locker with machine-to-machine communication is incorporated in the microcontroller design where a secure password will act as a door unlocking system.
A microcontroller-based application is made in which a password is required to provide through a keypad
for the successful transfer of messages from the Transmitter to the Receiver. The Receiver

microcontroller matches the received password from Transmitter with its original password, a servo-
motor is placed in the interface of the receiver microcontroller to latch or unlatch the locker door through

the dip switch/push button. So when the password is matched servo-motor opens the locker door and
else locked.
We have created a function named GetKeyPressed(), this function returns an index value of keypad to
main function, if the key is pressed. In main function we check if index is returned or not, if it is returned
then we check returned index data to our password character and increment a pointer for next index of
password if it matches.
We run our loop 4 times as our password’s maximum length is 4. After entering 4 digits the password
will be checked at receiver end if password matches we display O to seven-segment otherwise it display
C. Displaying O means door in unlocked and C means door is locked and receiver entered wrong
password. In coding we use USART1 for both receiver and transmitter and 4x4 keypad for entering
password.
