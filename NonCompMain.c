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
	bool movingToReady = false;

	bool mainGood = true;
	bool secGood = true;

	//Used to compensate autonomous encoders
	int curRightDrive = 0;
	int curLeftDrive = 0;



	//AUTONOMOUS

	int mode = 2;



	if(mode == 1) {


		moveSecLift(SEC_LIFT_IDLE_SPEED);
		//clampClaw(-CLAW_CLAMP_SPEED);

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

		turnRightDeg(198);
		wait1Msec(250);
		clampClaw(-CLAW_CLAMP_SPEED + 10);
		driveDistanceForward(10);
		wait1Msec(500);
		clampClaw(CLAW_CLAMP_SPEED + 25);
		wait1Msec(250);
		clampClaw(0);
		moveMainTo(160);
		// claw grip whatever
		// claw pivot up

		driveDistanceBackward(15);
		wait1Msec(250);
		turnLeftDeg(28);
		wait1Msec(250);
		driveDistanceForward(2);
		moveMainTo(140);
		clampClaw(-CLAW_CLAMP_SPEED);
		wait1Msec(500);


	}
	else if(mode == 2){
		moveToCubeReady();
		wait1Msec(1500);
		moveToClawPosXY(18, 10);


		wait1Msec(5000);
	}



	//USER CONTROL

	while (true)
	{
		drive(vexRT[Ch3], vexRT[Ch2]);


		//USED TO MAKE SURE BUTTON IS RELEASED BEFORE PRESSING AGAIN
		if (vexRT[Btn7L] == 0) {
			canPress = true;
		}

		//TOGGLE BETWEEN CUBE AND NO CUBE
		if (vexRT[Btn7L] > 0) {
			if (!hasCube && canPress) {
				hasCube = true;
				canPress = false;
			}

			else if (hasCube && canPress) {
				hasCube = false;
				canPress = false;
			}
		}


		//MOVES TO READY TO GRAB CUBE POSITION
		if (vexRT[Btn5D] > 0) {
			movingToReady = true;
			cubeReadyPos();
		}
		else if (vexRT[Btn5U] > 0) {
			movingToReady = true;
			skyriseReadyPos();
		}
		else {
			movingToReady = false;
		}




		//MAIN LIFT
		if (vexRT[Btn7U] > 0 && mainArmDegree < 140) {
			moveMainLift(MAIN_LIFT_UP_SPEED);
		}
		else if (vexRT[Btn7D] > 0) {
			moveMainLift(MAIN_LIFT_DOWN_SPEED);
		}
		else {
			if (!movingToReady) {
				if (hasCube) {
					moveMainLift(MAIN_LIFT_CUBE_IDLE);
				}
				else {
					moveMainLift(MAIN_LIFT_IDLE_SPEED);
				}
			}
		}


		//SECONDARY LIFT
		if (secArmDegree <= 85) {
			if (vexRT[Btn8U] > 0 ) {
				moveSecLift(SEC_LIFT_UP_SPEED);
			}
			else if (vexRT[Btn8D] > 0) {
				moveSecLift(SEC_LIFT_DOWN_SPEED);
			}
			else {
				if (!movingToReady) {
					if (hasCube) {
						moveSecLift(SEC_LIFT_CUBE_IDLE);
					}
					else {
						moveSecLift(SEC_LIFT_IDLE_SPEED);
					}
				}
			}
		}

		else if (secArmDegree > 95) {
			if (vexRT[Btn8U] > 0) {
				moveSecLift(-SEC_LIFT_DOWN_SPEED);
			}
			else if (vexRT[Btn8D] > 0) {
				moveSecLift(-SEC_LIFT_UP_SPEED);
			}
			else {
				if (!movingToReady) {
					if (hasCube) {
						moveSecLift(-SEC_LIFT_CUBE_IDLE);
					}
					else {
						moveSecLift(-SEC_LIFT_IDLE_SPEED);
					}
				}
			}
		}

		else {
			if (vexRT[Btn8U] > 0 ) {
				moveSecLift(SEC_LIFT_UP_SPEED);
			}
			else if (vexRT[Btn8D] > 0) {
				moveSecLift(SEC_LIFT_DOWN_SPEED);
			}
			else {
				if (!movingToReady) {
					if (hasCube) {
						moveSecLift(0);
					}
					else {
						moveSecLift(0);
					}
				}
			}
		}



		//CLAW
		if (vexRT[Btn6U] > 0) {
			clampClaw(CLAW_CLAMP_SPEED);
		}
		else if (vexRT[Btn6D] > 0) {
			clampClaw(-CLAW_CLAMP_SPEED);
		}
		else {
			clampClaw(0);
		}



		//CLAW PIVOT
		if (vexRT[Btn8R] > 0) {
			pivotClaw(CLAW_PIVOT_SPEED);
		}
		else if (vexRT[Btn8L] > 0) {
			pivotClaw(-CLAW_PIVOT_SPEED);
		}
		else {
			if (hasCube) {
				pivotClaw(CLAW_PIVOT_IDLE_SPEED);
			}
			else {
				pivotClaw(0);
			}
		}
	}
}
