Lift System

information number of Floors;
GUI keypad
Controller (Working logic)


(2)->  (RequestQueue 4 ) <-- current FLoor

USER

2. DoorWorking
1. RequestScheduling <- GUI Keypad
   queue(4,2, motordirection)
3. Floor_sensor
{curfloor,
	prevFloor,
	}
CaptureRequest(){
	requestedFloor,
	curFloor,
	Direction,

}
LevelManagement(secondaryUsecase)
