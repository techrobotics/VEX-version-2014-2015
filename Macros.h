
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
	motor[lDrive] = 0; \
	motor[rDrive] = 0; \
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
	motor[lDrive] = 0; \
	motor[rDrive] = 0; \
}

#define turnLeftDeg(degree){ \
	curLeftDrive = lDriveSens; \
	curRightDrive = rDriveSens; \
	int arcL = (degree * PI * DIAMETER) / 360; \
	while ( (lDriveSens - curLeftDrive >= encoderTicksInch(-arcL, 12/18)) || (rDriveSens - curRightDrive <= encoderTicksInch(arcL, 12/18)) ) { \
		if (lDriveSens - curLeftDrive >= encoderTicksInch(-arcL, 12/18)) { \
			motor[lDrive] = -AUTONOMOUS_DRIVING_SPEED; \
		} \
		else { \
			motor[lDrive] = 0; \
		} \
		if (rDriveSens - curRightDrive <= encoderTicksInch(arcL, 12/18)) { \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED; \
		} \
		else { \
			motor[rDrive] = 0; \
		} \
	} \
	motor[lDrive] = 0; \
	motor[rDrive] = 0; \
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
	if (hasCube) { \
		moveMainLift(MAIN_LIFT_CUBE_IDLE); \
	} \
	else { \
		moveMainLift(MAIN_LIFT_IDLE_SPEED); \
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
	if (hasCube) { \
		moveSecLift(SEC_LIFT_CUBE_IDLE); \
	} \
	else { \
		moveSecLift(SEC_LIFT_IDLE_SPEED); \
	} \
}


#define moveToCubeReady() { \
	while (secArmDegree > -90 || mainArmDegree < 110) { \
		cubeReadyPos(); \
	} \
	moveMainLift(MAIN_LIFT_IDLE_SPEED); \
	moveSecLift(SEC_LIFT_IDLE_SPEED); \
}




//ROBOT USER-CONTROL MOVEMENT MACROS
#define accelerate(port, final) { \
	motor[port] += safeSet((final-motor[port])/ACCEL_CONSTANT); \
}

#define drive(left, right) { \
	motor[lDrive] = left; \
	motor[rDrive] = right; \
}


#define moveClawPosXY(x, Y) { \
	int newSecArm = 180 + secArmDegree; \
	int od = sqrt(pow(y, 2) + pow(x, 2)); \
	int secGoal = acos( (-pow(od, 2)   + 2 * pow(17.5, 2) ) / (2 * pow(17.5, 2) ) ) ; \
	int mainGoal = 90 + atan(y/x) +  acos(od / (2 * 17.5) ); \
	\
	if (mainArmDegree < mainGoal) { \
		moveMainLift(MAIN_LIFT_UP_SPEED); \
	} \
	else if (mainGoal < mainArmDegree) { \
		moveMainLift(MAIN_LIFT_DOWN_SPEED); \
	} \
	else { \
		if (hasCube) { \
			moveMainLift(MAIN_LIFT_CUBE_IDLE); \
		} \
		else { \
			moveMainLift(MAIN_LIFT_IDLE_SPEED);  \
		} \
	} \
	\
	if (newSecArm < secGoal) { \
		moveSecLift(SEC_LIFT_UP_SPEED); \
	} \
	else if (secGoal < newSecArm) { \
		moveSecLift(SEC_LIFT_DOWN_SPEED); \
	} \
	else { \
		if (hasCube) { \
			moveSecLift(SEC_LIFT_CUBE_IDLE); \
		} \
		else { \
			moveSecLift(SEC_LIFT_IDLE_SPEED); \
		} \
	} \
}


#define cubeReadyPos() { \
	if (secArmDegree > -90 || mainArmDegree < 110) { \
		if (secArmDegree <= -90) { \
			moveSecLift(SEC_LIFT_IDLE_SPEED); \
		} \
		else { \
			moveSecLift(SEC_LIFT_DOWN_SPEED); \
		} \
		if (mainArmDegree >= 110) { \
			moveMainLift(MAIN_LIFT_IDLE_SPEED); \
		} \
		else { \
			moveMainLift(MAIN_LIFT_UP_SPEED); \
		} \
	} \
}

#define moveMainLift(speed) { \
	if (speed == MAIN_LIFT_UP_SPEED) { \
		accelerate(lMainArm, speed); \
		accelerate(rMainArm, speed); \
	} \
	else { \
		motor[lMainArm] = speed; \
		motor[rMainArm] = speed; \
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
	motor[lClawPivot] = speed; \
	motor[rClawPivot] = speed; \
}


// Useful things
//#define abs(x) ((x > 0) ? (x) : -(x))
#define min(x,y) ((x > y) ? (y) : (x))
#define max(x,y) ((x > y) ? (x) : (y))
#define safeSet(power) (max(-MAX_POWER, min(MAX_POWER, power)))


//ENCODER CODE

#define encoderTicksInch(inches, gearRatio) 627.2 * inches/CIRCUMFERENCE * gearRatio

//convert specified degrees and gear ratio into encoder ticks
#define encoderTicksDeg(degrees, gearRatio) 627.2 * degrees/360 * gearRatio

//derived from isolating degrees from encoderTicks Macro
//convert specified encoder ticks and gear ratio into degree measurement
#define encoderDegrees(encTicks, gearRatio) 360 * encTicks / (627.2 * gearRatio)


//to get degree of arms
#define rawSecArmDegree (encoderDegrees(secArmSens, 60/12) - 67)

#define mainArmDegree (encoderDegrees(mainArmSens, 84/12) + 28)
#define secArmDegree 90 + mainArmDegree - (-rawSecArmDegree)
