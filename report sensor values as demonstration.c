#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     Ultrasonic,     sensorSONAR)
#pragma config(Sensor, S4,     LineTracker,    sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task reportIRSeeker()//report IR seeker readings
{while(true)
	{
		int A=SensorRaw[S2];// sensor port 2
		int B=10*A;// declares b as an integer and uses operators to scale output values
	nxtDisplayString(1,"");//clear display
	wait1Msec(10);// wait ten msec ticks
		nxtDisplayString(1, "IRSeeker=(%i)", B);// prints a message on the nxt screen
	}
}
task reportLineTracker()// reports the line tracker value
{while(true)
	{
		nxtDisplayString(2,"");//clear display
		wait1Msec(10);// wait ten msec ticks
		nxtDisplayString(2, "LineTracker=(%i)", SensorRaw[S4] /*SensorValue[S4]*/);// prints a message on the
	}
}
task reportSonar()// reports values read from sonar sensor
{while(true)
	{
		nxtDisplayString(3,"");// clear display
		wait1Msec(10);// wait ten msec ticks
		nxtDisplayString(3, "Ultrasonic=(%i)",SensorRaw[S3] /*Sensor Value in raw readings[port number]*/);
	}
}
task reportAvgVoltage()// gives the avg voltage of the tetrix battery
{while(true)
	{
		int BVolt=externalBatteryAvg;// declares "B" as an integer equal to the external Battery Avg
		int AVolt=.001*BVolt;// scales the value for int BVolt
		nxtDisplayString(4,"");// clear display
		wait1Msec(10);// wait ten msec ticks
		nxtDisplayString(4, "Avg-Volt=(%f", AVolt );// prints a message on the nxt screen
	}
}

//task main()
//{
//		int i; //the variable "i" is declared as an integer

//   for(i = 0; i< 20000; i++)// do task for 20,000 increments of i
//   {
//     StartTask(reportIRSeeker);// starts report IR task
//     StartTask(reportLineTracker);// Starts report line tracker task
//     StartTask(reportSonar);// starts (report sonar task
//   }
//}

task main()
{while(true)// report infinitly
    {
     StartTask(reportIRSeeker);// starts report IR task
     StartTask(reportLineTracker);// Starts report line tracker task
     StartTask(reportSonar);// starts report sonar task
     StartTask(reportAvgVoltage);
   }
}
