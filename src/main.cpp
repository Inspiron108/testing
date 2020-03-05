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
pros::Motor L1(19);
pros::Motor L2(20);
pros::Motor R1(12,true);
pros::Motor R2(11,true);
pros::Motor Tray(5);
pros::Motor I1(2);
pros::Motor I2(3,true);
pros::Motor Arm(6,true);

int intakes = 0;



	while (true) {

//tray
		if(master.get_digital(DIGITAL_UP) == 1){
				Tray.move_voltage(12000);
				I1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
				I2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
			}
			else
			{
				if(master.get_digital(DIGITAL_DOWN) == 1){
					Tray.move_voltage(-12000);
					I1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
					I2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
				}
				else
				{
				Tray.move_velocity(0);
				}
		}

//arm
	if(master.get_digital(DIGITAL_L1) == 1)
	{
		Arm.move_voltage(12000);
		Tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	}
	else
	{
		if(master.get_digital(DIGITAL_L2) == 1){
			Arm.move_voltage(-12000);
			Tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		}
		else
		{
		Arm.move_velocity(0);
		}
	}

//Intakes
	if(master.get_digital(DIGITAL_R1) == 1)
	{
		I1.move_voltage(12000);
		I2.move_voltage(12000);
	}
	else
	{
		if(master.get_digital(DIGITAL_DOWN) == 1){
			I1.move_voltage(-12000);
			I2.move_voltage(12000);
		}
		else
		{
		I1.move_velocity(0);
		I2.move_velocity(0);
		}
	}




		int s = master.get_analog(ANALOG_RIGHT_X);
		int t = master.get_analog(ANALOG_LEFT_X);
		int f = master.get_analog(ANALOG_RIGHT_Y);


		R1 = -f + t - s;
		R2 = -f - t + s;
		L1 = f + t + s;
		L2 = f + t - s;

		pros::delay(20);

//Intake Breaking
		if(I1.get_target_velocity() == 0)
		{
			I1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
			I2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		}



	}
}
