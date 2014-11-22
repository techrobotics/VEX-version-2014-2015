#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rDrive,        tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port2,           lMainArm,      tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port3,           lSecArm,       tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port4,           lClawPivot,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           claw,          tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           rClawPivot,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           rSecArm,       tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rMainArm,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          lDrive,        tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
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
	bool mainGood = true;
	bool secGood = true;

	//Used to compensate autonomous encoders
	int curRightDrive = 0;
	int curLeftDrive = 0;



	//AUTONOMOUS

	int mode = 1;

	if(mode == 1) {

<<<<<<< HEAD
		moveSecLift(SEC_LIFT_IDLE_SPEED);

		driveDistanceBackward(4);
		wait1Msec(250);
		turnRightDeg(90);
		wait1Msec(250);
		pivotClaw((-CLAW_PIVOT_SPEED - 2));
		driveDistanceForward(9);
		// clampClaw(-CLAW_CLAMP_SPEED);
		pivotClaw(0);
		wait1Msec(250);
		moveToCubeReady();
		wait1Msec(250);
		moveToSkyriseReady();
		wait1Msec(250);

		turnRightDeg(196);
		wait1Msec(250);
		driveDistanceForward(10);
		wait1Msec(500);
		clampClaw(CLAW_CLAMP_SPEED);
		wait1Msec(250);
		clampClaw(0);
		moveMainTo(160);
		// claw grip whatever
		// claw pivot up

	  driveDistanceBackward(10);
	  turnLeftDeg(40);
=======
		turnRightDeg(180);
		wait1Msec(2000);
		turnLeftDeg(180);
>>>>>>> 608432faa5eed8842a3fd168508376a19f11bc88

	}
	else if(mode == 2){
		//NO STRATEGY YET
	}



}
