
//ROBOT AUTONOMOUSE MOVEMENT MACROS
#define driveDistance(inch){ \
	while (lDriveSens < inch/circumference * 627.2 * 12/18) \
	{ \
		motor[lDrive] = 25; \
	} \
}


//ROBOT USER-CONTROL MOVEMENT MACROS
#define drive(left, right) { \
	motor[lDrive] = left; \
	motor[rDrive] = right; \
}

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


//ENCODER CODE

//convert specified degrees and gear ratio into encoder ticks
#define encoderTicks(degrees, gearRatio) 627.2 * degrees/360 * gearRatio

//derived from isolating degrees from encoderTicks Macro
//convert specified encoder ticks and gear ratio into degree measurement
#define encoderDegrees(encTicks, gearRatio) 360 * encTicks / (627.2 * gearRatio)


//to get degree of arms
#define rawSecArmDegree (encoderDegrees(secArmSens, 60/12) -45)

#define mainArmDegree (encoderDegrees(mainArmSens, 60/12) + 30)
#define secArmDegree 90 + mainArmDegree - (-rawSecArmDegree)
