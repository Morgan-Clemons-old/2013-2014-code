#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     left_drive,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     right_drive,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     right_launcher, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     left_launcher, tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.



void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
  return;
}
task main()
{
  initializeRobot();

//  waitForStart();   // wait for start of tele-op phase
  int threshold = 6;
  while (true)
  {
  	getJoystickSettings(joystick);
		if(abs(joystick.joy1_y2) > threshold)   	// If the right analog stick's Y-axis readings are either above or below the threshold:
		{
			motor[right_drive] = (joystick.joy1_y2);   // Motor D is assigned a power level equal to the right analog stick's Y-axis reading.
		}
		else                                    	// Else if the readings are within the threshold:
		{
			motor[right_drive] = 0;                        // Motor D is stopped with a power level of 0.
		}
		if(abs(joystick.joy1_y1) > threshold)     // If the left analog stick's Y-axis readings are either above or below the threshold:
		{
			motor[left_drive] = (joystick.joy1_y1); // Motor E is assigned a power level equal to the left analog stick's Y-axis reading.
		}
		else                                    	// Else if the readings are within the threshold:
		{
			motor[left_drive] = 0;                        // Motor E is stopped with a power level of 0.
		}
	  if(joy1Btn(4))
	  {
	  motor[left_launcher] = 85;
	  motor[right_launcher]= -85;
    }
    else
    {
    motor[left_launcher] = 0;
    motor[right_launcher] = 0;
    }
    if(joy1Btn(2))
	  {
	  motor[left_launcher] = -85;
	  motor[right_launcher]= 85;
    }
    else
    {
    motor[left_launcher] = 0;
    motor[right_launcher] = 0;
    }


    }

  }
