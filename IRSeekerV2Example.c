#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     intakeMotor,   tmotorTetrix, openLoop, encoder)

task main()
{
	while(true){
	int beaconDir = SensorValue[IRSeeker];
	  if(beaconDir == 0)
		{
			// no reading, turn in place
			motor[rightMotor] = -45;
			motor[leftMotor] = 45;
		}
		else if(beaconDir == 5)
		{
			// Straight ahead
		  break;
		}
		else if(beaconDir < 5)
		{
			// to the left, turn left
			motor[rightMotor] = 35;
			motor[leftMotor] = -35;
		}
		else if(beaconDir > 5)
		{
			// to the right, turn right
			motor[rightMotor] = -35;
			motor[leftMotor] = 35;
		}

		wait1Msec(200);
	}
}
