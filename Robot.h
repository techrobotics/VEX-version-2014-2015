//ROBOT MOVEMENT SPEEDS
#define MAIN_LIFT_UP_SPEED 80
#define MAIN_LIFT_DOWN_SPEED -25
#define MAIN_LIFT_IDLE_SPEED 15
#define MAIN_LIFT_CUBE_IDLE 22.5

#define SEC_LIFT_UP_SPEED 80
#define SEC_LIFT_DOWN_SPEED -25
#define SEC_LIFT_IDLE_SPEED 10
#define SEC_LIFT_CUBE_IDLE 15

#define CLAW_CLAMP_SPEED 80
#define CLAW_PIVOT_SPEED 50
#define CLAW_PIVOT_IDLE_SPEED -20

#define AUTONOMOUS_DRIVING_SPEED 50

//OTHER CONSTANTS
#define DIAMETER (133/8)
#define CIRCUMFERENCE (4 * PI)
#define OVERSHOOT_DISTANCE (CIRCUMFERENCE/8)


//ENCODER MACROS
#define mainArmSens nMotorEncoder[lMainArm]
#define secArmSens nMotorEncoder[lSecArm]
#define lDriveSens nMotorEncoder[lDrive]
#define rDriveSens nMotorEncoder[rDrive]
