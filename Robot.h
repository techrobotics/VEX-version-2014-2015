//ROBOT MOVEMENT SPEEDS
#define MAIN_LIFT_UP_SPEED 80
#define MAIN_LIFT_DOWN_SPEED -25
#define MAIN_LIFT_IDLE_SPEED 15

#define SEC_LIFT_UP_SPEED 80
#define SEC_LIFT_DOWN_SPEED -25
#define SEC_LIFT_IDLE_SPEED 15

#define CLAW_CLAMP_SPEED 80
#define CLAW_PIVOT_SPEED 50
#define CLAW_PIVOT_IDLE_SPEED 30

//OTHER CONSTANTS
#define circumference 4 * PI

//ENCODER MACROS
#define mainArmSens nMotorEncoder[lMainArm]
#define secArmSens nMotorEncoder[lSecArm]
#define lDriveSens nMotorEncoder[lDrive]
#define rDriveSens nMotorEncoder[rDrive]
