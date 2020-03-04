#include "main.h"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);


}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {






}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor L1_mtr(19);
pros::Motor L2_mtr(20);
pros::Motor R1_mtr(12);
pros::Motor R2_mtr(11);
pros::Motor Tray_mtr(5);


int intakes = 0;



	while (true) {

		if(master.get_digital(DIGITAL_UP) == 1)
		{


		}




		int s = master.get_analog(ANALOG_RIGHT_X);
		int t = master.get_analog(ANALOG_LEFT_X);
		int f = master.get_analog(ANALOG_RIGHT_Y);


		R1_mtr = f + t - s;
		R2_mtr = f - t + s;
		L1_mtr = f + t + s;
		L2_mtr = f + t - s;


		pros::delay(20);
	}
}
