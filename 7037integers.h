int move(int speed, int time)
{
  motor[motorD] = speed;
  motor[motorE] = speed;
  wait1Msec(time);
  motor[motorD] = 0;// stops motor
  motor[motorE] = 0;// stops motor
  return 0;
}
task main()

{
	move(50,500);
}
