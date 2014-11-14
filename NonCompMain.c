#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           lDrive,        tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port2,           lMainArm,      tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port3,           lSecArm,       tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port4,           clawPivot,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           claw,          tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port8,           rSecArm,       tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rMainArm,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rDrive,        tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Robot.h"
#include "Macros.h"
#include "Autonomous.c"
#include "UserControl.c"

task main()
{
	//INITIALIZATION
	mainArmSens = 0;
	secArmSens = 0;
	lDriveSens = 0;
	rDriveSens = 0;

	bool hasCube = false;
	bool canPress = true;

	//Used to compensate autonomous encoders
	int curRightDrive = 0;
	int curLeftDrive = 0;



	//AUTONOMOUS

	//rightDrive((CIRCUMFERENCE));

	/*
	mode 1 forward grab backwards score (1 point)
	mode 2 Scores two cubes in (2 points)
	mode 3 Scores cube into low goal (3 points)
	mode 4 Puts skyrise into the hole (4 points)
	mode 5 mlg 360 euphoric quicknoscopes 420BLAZEIT doritos locos mountain dew the cube into the opponent's goal (9001 points)
	*/
	int mode = 1;

	if(mode == 1) {
		//move secondary to
		moveSecTo(0);

		pivotClaw(CLAW_PIVOT_SPEED);
		//wait1MSec(WE DO NOT KNOW);
		pivotClaw(0);

		//driveDistance(WE DO NOT KNOW);

		//driveDistance(-WE DO NOT KNOW);
	}
	else if(mode == 2){
		//NO STRATEGY YET
	}



}
