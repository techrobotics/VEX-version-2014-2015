#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  rightDriveSens, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  leftDriveSens,  sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  mainArmSens,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           leftDrive,     tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port2,           leftMainArm,   tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port3,           leftSecArm,    tmotorVex393, openLoop, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port4,           clawPivot,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           claw,          tmotorVex269, openLoop)
#pragma config(Motor,  port8,           rightSecArm,   tmotorVex393, openLoop)
#pragma config(Motor,  port9,           rightMainArm,  tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rightDrive,    tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//convert specified degrees and gear ratio into encoder ticks
#define encoderTicks(degrees, gearRatio) 627.2 * degrees/360 * gearRatio

//derived from isolating degrees from above
//convert specified encoder ticks and gear ratio into degree measurement
#define encoderDegrees(ticks, gearRatio) 360 * ticks / (627.2 * gearRatio)

#define rawSecArmDegree encoderDegrees(nMotorEncoder[leftSecArm], 60/12)

#define mainArmDegree encoderDegrees(nMotorEncoder[leftMainArm], 60/12)
#define secArmDegree 90 + mainArmDegree - rawSecArmDegree

task main()
{


	//nMotorEncoder[rightDrive] = 0;
	nMotorEncoder[leftMainArm] = 0;
	/*
	while(nMotorEncoder[rightDrive]<627.2){
		motor[rightDrive] = 75;
	}
	motor[rightDrive] = 0;
	*/

	// test 1: driveDistance(4);

	/* test 2: while(mainArmDegree < 100){
		motor[leftMainArm] = 50;
		motor[rightMainArm] = 50;
	}
	motor[leftMainArm] = 0;
	motor[rightMainArm] = 0;*/

	/*while(mainArmDegree < 45){
		motor[leftMainArm] = 50;
		motor[rightMainArm] = 50;
	}
	motor[leftMainArm] = 0;
	motor[rightMainArm] = 0;*/

	//main arm check: 150 degrees, check using iphone
	//distance driving check
	//160 degree implementation

}
