task autonomous() {
/*
mode 1 forward grab backwards score (1 point)
mode 2 Scores two cubes in (2 points)
mode 3 Scores cube into low goal (3 points)
mode 4 Puts skyrise into the hole (4 points)
mode 5 mlg 360 euphoric quicknoscopes 420BLAZEIT doritos locos mountain dew the cube into the opponent's goal (9001 points)
*/
	int mode = 1;

	if(mode == 1) {
		//move secondary to
		moveSecTo(0);

		pivotClaw(CLAW_PIVOT_SPEED);
		//wait1MSec(WE DO NOT KNOW);
		pivotClaw(0);

		//driveDistance(WE DO NOT KNOW);

		//driveDistance(-WE DO NOT KNOW);
	}
	else if(mode == 2){
		//NO STRATEGY YET
	}
}
