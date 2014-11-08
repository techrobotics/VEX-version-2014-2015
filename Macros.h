
//ROBOT AUTONOMOUS MOVEMENT MACROS
#define driveDistance(inch){ \
	while (lDriveSens < encoderTicksInch(inch, 12/18) - encoderTicksInch(OVERSHOOT_DISTANCE, 12/18)) \
	{ \
		if (lDriveSens < rDriveSens){ \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED - 15; \
		} \
		else if (rDriveSens < lDriveSens){ \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED - 5; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED - 10; \
		} \
		else {\
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED - 10; \
		} \
	} \
}

#define rightDrive(inch){ \
	while (rDriveSens < encoderTicksInch(inch, 12/18) - OVERSHOOT_DISTANCE - 20) \
	{ \
		motor[rDrive] = 45; \
	} \
}




//ROBOT USER-CONTROL MOVEMENT MACROS
#define drive(left, right) { \
	motor[lDrive] = left; \
	motor[rDrive] = right; \
}

#define cubeReadyPos() { \
  while (secArmDegree > -90 && mainArmDegree < 105) { \
  	moveMainLift(MAIN_LIFT_UP_SPEED); \
  	moveSecLift(SEC_LIFT_DOWN_SPEED); \
  	if (secArmDegree = -90) { \
  		moveSecLift(SEC_LIFT_IDLE_SPEED); \
  	} \
  	if (mainArmDegree < 105) { \
  		moveMainLift(MAIN_LIFT_IDLE_SPEED); \
  	} \
  } \
} \

#define moveMainLift(speed) { \
	motor[lMainArm] = speed; \
	motor[rMainArm] = speed; \
	if (mainArmDegree >= 140) { \
		motor[lMainArm] = MAIN_LIFT_IDLE_SPEED; \
		motor[rMainArm] = MAIN_LIFT_IDLE_SPEED; \
	} \
}

#define moveSecLift(speed) { \
	motor[lSecArm] = speed; \
	motor[rSecArm] = speed; \
}

#define clampClaw(speed) { \
	motor[claw] = speed; \
}

#define pivotClaw(speed) { \
	motor[clawPivot] = speed; \
}

//AUTONOMOUS MACRO CODE

#define moveSecTo(degree) { \
	if(secArmDegree > degree) { \
		while(secArmDegree > degree) { \
			moveSecArm(SEC_LIFT_DOWN_SPEED); \
	} \
	else if(secArmDegree < degree) { \
		while(secArmDegree < degree) { \
			moveSecArm(SEC_LIFT_UP_SPEED); \
		} \
	} \
}

#define moveMainTo(degree) { \
	if(mainArmDegree > degree) { \
		while(mainArmDegree > degree) { \
			moveMainArm(MAIN_LIFT_DOWN_SPEED); \
	} \
	else if(mainArmDegree < degree) { \
		while(mainArmDegree < degree) { \
			moveMainArm(MAIN_LIFT_UP_SPEED); \
		} \
	} \
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

#define mainArmDegree (encoderDegrees(mainArmSens, 60/12) + 30)
#define secArmDegree 90 + mainArmDegree - (-rawSecArmDegree)
