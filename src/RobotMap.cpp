
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "PIDController.h"
#include "WPILib.h"

std::shared_ptr<SpeedController> RobotMap::speedControllerFL;
std::shared_ptr<SpeedController> RobotMap::speedControllerFR;
std::shared_ptr<SpeedController> RobotMap::speedControllerBL;
std::shared_ptr<SpeedController> RobotMap::speedControllerBR;
std::shared_ptr<RobotDrive> RobotMap::driveRobotDrive4;

std::shared_ptr<AnalogGyro> RobotMap::driveGyro;

std::shared_ptr<Relay> RobotMap::ledRelay1;
std::shared_ptr<Relay> RobotMap::ledRelay2;
std::shared_ptr<Relay> RobotMap::ledRelay3;
std::shared_ptr<Relay> RobotMap::ledRelay4;

void RobotMap::init() {
    LiveWindow *lw = LiveWindow::GetInstance();

    speedControllerFL.reset(new Talon(DRIVE_SPEED_CONTROLLER_1_CHANNEL));
    lw->AddActuator("Drive", "Speed Controller 1", (Talon&) speedControllerFL);
    
    speedControllerFR.reset(new Talon(DRIVE_SPEED_CONTROLLER_2_CHANNEL));
    lw->AddActuator("Drive", "Speed Controller 2", (Talon&) speedControllerFR);
    
    speedControllerBL.reset(new Talon(DRIVE_SPEED_CONTROLLER_3_CHANNEL));
    lw->AddActuator("Drive", "Speed Controller 3", (Talon&) speedControllerBL);
    
    speedControllerBR.reset(new Talon(DRIVE_SPEED_CONTROLLER_4_CHANNEL));
    lw->AddActuator("Drive", "Speed Controller 4", (Talon&) speedControllerBR);
    
    //driveRobotDrive4.reset(new RobotDrive(speedControllerBL, speedControllerBR,
              //speedControllerFL, speedControllerFR));
    
    driveRobotDrive4.reset(new RobotDrive(speedControllerBL, speedControllerFL,
                            speedControllerBR, speedControllerFR));
    driveRobotDrive4->SetSafetyEnabled(false);
	driveRobotDrive4->SetExpiration(0.1);
	driveRobotDrive4->SetSensitivity(0.5);
	driveRobotDrive4->SetMaxOutput(1.0);

    //driveGyro.reset(new AnalogGyro(SPI::kOnboardCS0));
	driveGyro.reset(new AnalogGyro(0));
    driveGyro->Calibrate();
    //lw->AddActuator("Drive", "Drive Gyro", driveGyro);

    ledRelay1.reset(new Relay(0, Relay::kReverseOnly));
	ledRelay1->Set(Relay::kOff);
	ledRelay2.reset(new Relay(1, Relay::kReverseOnly));
	ledRelay2->Set(Relay::kOff);
	ledRelay3.reset(new Relay(2, Relay::kReverseOnly));
	ledRelay3->Set(Relay::kOff);
	ledRelay4.reset(new Relay(3, Relay::kReverseOnly));
	ledRelay4->Set(Relay::kOff);
}
