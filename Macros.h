

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

#define acceleration(startSpeed, endSpeed, increments) { \
	while (startSpeed < endSpeed) \
	{ \
		startSpeed = startSpeed + 1; \
		motor[lMainArm] = startSpeed; \
		motor[rMainArm] = startSpeed; \
		wait1MSec(increments); \
} \
} \

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
	motor[clawPivot] = speed; \
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
