#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     intakeMotor,   tmotorTetrix, openLoop, encoder)

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Conveyorbot Gyro - Autonomous Score Routine

This program is designed for the the Virtual World 'FTC Block Party!'
It is designed to score the preload block in the blue box with a Conveyorbot
at start point B1.

Start at B1 with Conveyorbot
1) Move forward for 4000 encoder counts (using encoders)
2) Turn to the right until gyro reads 45 degrees (using gyroscope)
3) Line track onto the ramp for 3000 encoder counts (using light sensor and encoders)
4) Raise arm for 600 encoder counts (using the arm's encoder)
5) Turn to the right until gyro reads 140 degrees (using gyroscope)
6) Move forward until close enough to side wall (using sonar)
7) Lower arm for -200 encoder counts (using the arm's encoder)
8) Turn on intake (reversed) and score the preload object

Robot Model(s): TETRIX Conveyorbot (Gyro) (Virtual Worlds)

[I/O Port]          [Name]              [Type]                [Description]
Motor Port D        rightMotor          TETRIX Motor          Right side motor
Motor Port E				leftMotor						TETRIX Motor					Left side motor
Motor Port F 				armMotor						TETRIX Motor					Arm motor
Motor Port G 				intakeMotor					TETRIX Motor 					Intake motor

Sensor Port 2				gyro								HiTechnic Gyro				HiTechnic Gyro
Sensor Port 3				light   						Light Sensor					NXT Light Sensor (Active)
Sensor Port 4				sonar 							Sonar Sensor					NXT Sonar Sensor

----------------------------------------------------------------------------------------------------*/


void forward4000ENC()
{

			while(nMotorEncoder(rightMotor) < 4000)//While right motor encoder is LESS THAN (<) 4000 Countsies.
		  {
		  //Move robot FORWARD.
		  motor[rightMotor]=35;
			motor[leftMotor]=35;
		  }
}
void clearENCcount()	//CLEARED encoders
{

			nMotorEncoder(rightMotor) = 0;
			nMotorEncoder(leftMotor)  = 0;
}
void STOPROBOTNOW()//STOP robot!
{

			motor[rightMotor]=0;
			motor[leftMotor]=0;
}
void Gyroturn()
{
//WHILE sensor is less then 350.............
			while(SensorValue[gyro] < 350)
		{
			//..TURN robot!
				motor[rightMotor] =	-75;
				motor[leftMotor]  =  75;
		}
}
void drive1()
{

      while(nMotorEncoder(rightMotor) < 2000)////While right motor encoder is LESS THAN (<) 2000 countsies.
		  {
		  //Move robot FORWARD AGAIN.
		  motor[rightMotor]=35;
			motor[leftMotor]=35;
		  }
      motor[rightMotor]=0;
      motor[leftMotor]=0;
		  }
void leftturn()
{
	while(nMotorEncoder(leftMotor) < 600)////While right motor encoder is LESS THAN (<) 2000 countsies.
		  {
		  //Move robot FORWARD AGAIN.
		  motor[rightMotor]=35;
			motor[leftMotor]=-35;
		  }
      motor[rightMotor]=0;
      motor[leftMotor]=0;
}
task reportgyro()//report IR seeker readings
{while(true)
	{
		int A=SensorRaw[S2];// sensor port 2
	nxtDisplayString(1,"");//clear display
	wait1Msec(10);// wait ten msec ticks
		nxtDisplayString(1, "Gyro(%i)", A);// prints a message on the nxt screen
	}
}


			task main()
			{
				StartTask(reportgyro);

		  }
