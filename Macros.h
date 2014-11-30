
//ROBOT AUTONOMOUS MOVEMENT MACROS
//DRIVING STRAIGHT
#define driveDistanceForward(inch){ \
	curLeftDrive = lDriveSens; \
	curRightDrive = rDriveSens; \
	int goal = encoderTicksInch((inch), 12/18); \
	while (lDriveSens - curLeftDrive < goal ) \
	{ \
		if (lDriveSens - curLeftDrive < rDriveSens - curRightDrive){ \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED - 5; \
		} \
		else if (rDriveSens - curRightDrive < lDriveSens - curLeftDrive){ \
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED - 5; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED ; \
		} \
		else {\
			motor[lDrive] = AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = AUTONOMOUS_DRIVING_SPEED; \
		} \
	} \
	motor[lDrive] = 0; \
	motor[rDrive] = 0; \
}


#define driveDistanceBackward(inch){ \
	curLeftDrive = lDriveSens; \
	curRightDrive = rDriveSens; \
	int goal = encoderTicksInch((-inch), 12/18); \
	while (lDriveSens - curLeftDrive > goal) \
	{ \
		if (lDriveSens - curLeftDrive > rDriveSens - curRightDrive){ \
			motor[lDrive] = -AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = -AUTONOMOUS_DRIVING_SPEED + 5; \
		} \
		else if (rDriveSens - curRightDrive > lDriveSens - curLeftDrive){ \
			motor[lDrive] = -AUTONOMOUS_DRIVING_SPEED + 5; \
			motor[rDrive] = -AUTONOMOUS_DRIVING_SPEED ; \
		} \
		else {\
			motor[lDrive] = -AUTONOMOUS_DRIVING_SPEED; \
			motor[rDrive] = -AUTONOMOUS_DRIVING_SPEED; \
		} \
	} \
	motor[lDrive] = 0; \
	motor[rDrive] = 0; \
}


//TURNING
#define turnRightDeg(degree){ \
	curLeftDrive = lDriveSens; \
	curRightDrive = rDriveSens; \
	int arcR = ((degree - 5) * PI * DIAMETER) / 360; \
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
	int arcL = ((degree- 5) * PI * DIAMETER) / 360; \
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


//MOVE ARMS
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

//MOVE TO READY POSITIONS
#define moveToCubeReady() { \
	while (secArmDegree > -90 || mainArmDegree < 110) { \
		cubeReadyPos(); \
	} \
	moveMainLift(MAIN_LIFT_IDLE_SPEED); \
	moveSecLift(SEC_LIFT_IDLE_SPEED); \
}

#define moveToSkyriseReady() { \
	while (secArmDegree > -45 || mainArmDegree < 145) { \
		skyriseReadyPos(); \
	} \
	moveMainLift(MAIN_LIFT_IDLE_SPEED); \
	moveSecLift(SEC_LIFT_IDLE_SPEED); \
}


#define moveToClawPosXY(x, y) { \
	mainGood = false; \
	secGood = false; \
	while (!mainGood || !secGood) { \
		clawPosXY((float)x, (float)y); \
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


#define clawPosXY(x, y) { \
	float newSecArm = rawSecArmDegree + 360; \
	float od = (sqrt(pow(y, 2) + pow(x, 2))); \
	float secGoal = 2 * (asin( od / ( 2 * 16.5 ) ) * (180/PI) ); \
	float mainGoal = 90 + ((atan(y/x)) * (180/PI)) + (acos(od / (2 * 16.5) ) * (180/PI) ); \
	\
	if (od < 25 && x > 0 && y > -16) { \
		if ((mainArmDegree < mainGoal - 3) && !mainGood) { \
			moveMainLift(MAIN_LIFT_UP_SPEED); \
		} \
		else if ((mainGoal + 3 < mainArmDegree) && !mainGood) { \
			moveMainLift(MAIN_LIFT_DOWN_SPEED); \
		} \
		else { \
			mainGood = true; \
			if (hasCube) { \
				moveMainLift(MAIN_LIFT_CUBE_IDLE); \
			} \
			else { \
				moveMainLift(MAIN_LIFT_IDLE_SPEED);  \
			} \
		} \
		\
		if ((newSecArm < secGoal - 3) && !secGood) { \
			moveSecLift(SEC_LIFT_UP_SPEED); \
		} \
		else if ((secGoal + 3 < newSecArm) && !secGood) { \
			moveSecLift(SEC_LIFT_DOWN_SPEED); \
		} \
		\
		else { \
			secGood = true; \
			if (hasCube) { \
				moveSecLift(SEC_LIFT_CUBE_IDLE); \
			} \
			else { \
				moveSecLift(SEC_LIFT_IDLE_SPEED); \
			} \
		} \
	} \
	else { \
		if (hasCube) { \
			moveMainLift(MAIN_LIFT_CUBE_IDLE); \
			moveSecLift(SEC_LIFT_CUBE_IDLE); \
		} \
		else { \
			moveMainLift(MAIN_LIFT_IDLE_SPEED); \
			moveSecLift(SEC_LIFT_IDLE_SPEED); \
		} \
	} \
}



#define cubeReadyPos() { \
	if (secArmDegree > -90) { \
		moveSecLift(SEC_LIFT_DOWN_SPEED); \
	} \
	else if (secArmDegree < -95) { \
		moveSecLift(SEC_LIFT_UP_SPEED); \
	} \
	else { \
		moveSecLift(SEC_LIFT_IDLE_SPEED); \
	} \
	if (mainArmDegree < 110) { \
		moveMainLift(MAIN_LIFT_UP_SPEED); \
	} \
	else if (mainArmDegree > 115) { \
		moveMainLift(MAIN_LIFT_DOWN_SPEED); \
	} \
	else { \
		moveMainLift(MAIN_LIFT_IDLE_SPEED); \
	} \
}

#define skyriseReadyPos() { \
	if (secArmDegree > -75) { \
		moveSecLift(SEC_LIFT_DOWN_SPEED); \
	} \
	else if (secArmDegree < -80) { \
		moveSecLift(SEC_LIFT_UP_SPEED); \
	} \
	else { \
		moveSecLift(SEC_LIFT_IDLE_SPEED); \
	} \
	if (mainArmDegree < 142) { \
		moveMainLift(MAIN_LIFT_UP_SPEED); \
	} \
	else if (mainArmDegree > 147) { \
		moveMainLift(MAIN_LIFT_DOWN_SPEED); \
	} \
	else { \
		moveMainLift(MAIN_LIFT_IDLE_SPEED); \
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

#define mainArmDegree (encoderDegrees(mainArmSens, 84/12) + 30)
#define secArmDegree 90 + mainArmDegree - (-rawSecArmDegree)
