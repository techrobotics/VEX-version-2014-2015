
//ROBOT AUTONOMOUS MOVEMENT MACROS
#define driveDistance(inch){ \
	curLeftDrive = lDriveSens; \
	curRightDrive = rDriveSens; \
	while (lDriveSens - curLeftDrive < encoderTicksInch(inch, 12/18) - encoderTicksInch(OVERSHOOT_DISTANCE, 12/18)) \
	{ \
		if (lDriveSens - curLeftDrive < rDriveSens - curRightDrive){ \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED - 15; \
		} \
		else if (rDriveSens - curRightDrive < lDriveSens - curLeftDrive){ \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED - 5; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED - 10; \
		} \
		else {\
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED - 10; \
		} \
	} \
}


//FOR TESTING RIGHT WHEELS
#define rightDrive(inch){ \
	while (rDriveSens < encoderTicksInch(inch, 12/18) - OVERSHOOT_DISTANCE - 20) \
	{ \
		motor[rDrive] = 45; \
	} \
}


#define turnRightDeg(degree){ \
	curLeftDrive = lDriveSens; \
	curRightDrive = rDriveSens; \
	int arcR = (degree * PI * DIAMETER) / 360; \
	while ( (lDriveSens - curLeftDrive <= encoderTicksInch(arcR, 12/18)) || (rDriveSens - curRightDrive >= encoderTicksInch(-arcR, 12/18)) ) { \
		if (lDriveSens - curLeftDrive <= encoderTicksInch(arcR, 12/18)) { \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
		} \
		else { \
			motor[lDrive] = 0; \
		} \
		if (rDriveSens - curRightDrive >= encoderTicksInch(-arcR, 12/18)) { \
			motor[rDrive] = -AUTONOMOUS_DRIVING_SPEED; \
		} \
		else { \
			motor[rDrive] = 0; \
		} \
	} \
}

#define turnLeftDeg(degree){ \
	curLeftDrive = lDriveSens; \
	curRightDrive = rDriveSens; \
	int arcL = (degree * PI * DIAMETER) / 360; \
	while ( (lDriveSens - curLeftDrive >= encoderTicksInch(-arcL, 12/18)) || (rDriveSens - curRightDrive <= encoderTicksInch(arcL, 12/18)) ) { \
		if (lDriveSens - curLeftDrive >= encoderTicksInch(-arcL, 12/18)) { \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
		} \
		else { \
			motor[lDrive] = 0; \
		} \
		if (rDriveSens - curRightDrive <= encoderTicksInch(arcL, 12/18)) { \
			motor[rDrive] = -AUTONOMOUS_DRIVING_SPEED; \
		} \
		else { \
			motor[rDrive] = 0; \
		} \
	} \
}



#define moveMainTo(degree) { \
	if(mainArmDegree > degree) { \
		while(mainArmDegree > degree) { \
			moveMainLift(MAIN_LIFT_DOWN_SPEED); \
		} \
	} \
	else if(mainArmDegree < degree) { \
		while(mainArmDegree < degree) { \
			moveMainLift(MAIN_LIFT_UP_SPEED); \
		} \
	} \
}

#define moveSecTo(degree) { \
	if(secArmDegree > degree) { \
		while(secArmDegree > degree) { \
			moveSecLift(SEC_LIFT_DOWN_SPEED); \
		} \
	} \
	else if(secArmDegree < degree) { \
		while(secArmDegree < degree) { \
			moveSecLift(SEC_LIFT_UP_SPEED); \
		} \
	} \
}





//ROBOT USER-CONTROL MOVEMENT MACROS
#define drive(left, right) { \
	motor[lDrive] = left; \
	motor[rDrive] = right; \
}


#define cubeReadyPos() { \
	if (secArmDegree > -90 || mainArmDegree < 105) { \
		if (secArmDegree <= -90) { \
			moveSecLift(SEC_LIFT_IDLE_SPEED); \
		} \
		else { \
			moveSecLift(SEC_LIFT_DOWN_SPEED); \
		} \
		if (mainArmDegree >= 105) { \
			moveMainLift(MAIN_LIFT_IDLE_SPEED); \
		} \
		else { \
			moveMainLift(MAIN_LIFT_UP_SPEED); \
		} \
	} \
}

#define moveMainLift(speed) { \
	motor[lMainArm] = speed; \
	motor[rMainArm] = speed; \
}

#define moveSecLift(speed) { \
	motor[lSecArm] = speed; \
	motor[rSecArm] = speed; \
}

#define clampClaw(speed) { \
	motor[claw] = speed; \
}

#define pivotClaw(speed) { \
	motor[lClawPivot] = speed; \
	motor[rClawPivot] = speed; \
}



//ENCODER CODE

#define encoderTicksInch(inches, gearRatio) 627.2 * inches/CIRCUMFERENCE * gearRatio

//convert specified degrees and gear ratio into encoder ticks
#define encoderTicksDeg(degrees, gearRatio) 627.2 * degrees/360 * gearRatio

//derived from isolating degrees from encoderTicks Macro
//convert specified encoder ticks and gear ratio into degree measurement
#define encoderDegrees(encTicks, gearRatio) 360 * encTicks / (627.2 * gearRatio)


//to get degree of arms
#define rawSecArmDegree (encoderDegrees(secArmSens, 60/12) - 53)

#define mainArmDegree (encoderDegrees(mainArmSens, 84/12) + 30)
#define secArmDegree 90 + mainArmDegree - (-rawSecArmDegree)
