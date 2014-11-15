

//ROBOT USER-CONTROL MOVEMENT MACROS

#define accelerate(port, final) { \
	motor[port] += safeSet((final-motor[port])/ACCEL_CONSTANT); \
}


#define drive(left, right) { \
	motor[lDrive] = left; \
	motor[rDrive] = right; \
}

#define cubeReadyPos() { \
  if (secArmDegree > -90 || mainArmDegree < 115) { \
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
