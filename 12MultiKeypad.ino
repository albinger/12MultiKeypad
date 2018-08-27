/*
|| @file 12MultiKeypad.ino
|| @version 1.0
|| @author Andrew Albinger

	Based on:
	file MultiKey.ino
	@version 1.0
	@author Mark Stanley

|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is a
|| | simple macropad.
|| #
*/

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

/*
* I wired this up slightly incorrectly.
* My phisical layout is:
* 1  2  3  4
* 5  6  7  8
* 9  a  b  c
*/

char keys[ROWS][COLS] = {
	{'4','8','c'},
	{'3','7','b'},
	{'2','6','a'},
	{'1','5','9'}
};
byte rowPins[ROWS] = {6, 5, 4, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {1, 0,2}; //connect to the column pinouts of the keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

bool Shifted = false;


void setup() {
Serial.begin(9600);

}


void loop() {
// Fills kpd.key[ ] array with up-to 10 active keys.
// Returns true if there are ANY active keys.
if (kpd.getKeys())
{
	for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
	{
		if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
		{
			switch (kpd.key[i].kchar) {
		
			case '1':
			if(kpd.key[i].kstate == PRESSED)  Keyboard.print("iastate.edu");
			break;

			case '2':
			if(kpd.key[i].kstate == PRESSED)  {
        if(Shifted){
          Keyboard.press(MODIFIERKEY_GUI);
          Keyboard.press(KEY_PRINTSCREEN);
          Keyboard.release(KEY_PRINTSCREEN);
          Keyboard.release(MODIFIERKEY_GUI);
        }else{
				Keyboard.press(MODIFIERKEY_GUI);
				Keyboard.press(KEY_D);
				Keyboard.release(KEY_D);
				Keyboard.release(MODIFIERKEY_GUI);
        }
			}
			break;

			case '3':
			if(kpd.key[i].kstate == PRESSED)
			{
				Keyboard.press(KEY_MEDIA_VOLUME_INC);
				Keyboard.release(KEY_MEDIA_VOLUME_INC);
			}
			break;

			case '4':
			if(kpd.key[i].kstate == PRESSED)  Mouse.scroll(1);
			break;

			case '5':
			if(kpd.key[i].kstate == PRESSED)  Keyboard.print("albinger@iastate.edu");
			break;

			case '6':
			if(kpd.key[i].kstate == PRESSED)  Keyboard.print("andrew.albinger@gmail.com");
			break;

			case '7':
			if(kpd.key[i].kstate == PRESSED)  {
				if(Shifted)
				{
					Keyboard.press(KEY_MEDIA_MUTE);
					Keyboard.release(KEY_MEDIA_MUTE);
				} else {
					Keyboard.press(KEY_MEDIA_VOLUME_DEC);
					Keyboard.release(KEY_MEDIA_VOLUME_DEC);
				}
			} else if (kpd.key[i].kstate == HOLD) {
				Keyboard.press(KEY_MEDIA_MUTE);
				Keyboard.release(KEY_MEDIA_MUTE);
			}
			break;

			case '8':
			if(kpd.key[i].kstate == PRESSED)  Mouse.scroll(-1);
			break;

			case '9':
			if(kpd.key[i].kstate == PRESSED)  {
				if(Shifted){
					Keyboard.print("login.iastate.edu\n\n");
				}else{
					Keyboard.print("\n-Andrew\n\n");
				}
			}
			break;

			case 'a':
			if(kpd.key[i].kstate == PRESSED)  {
				Keyboard.press(MODIFIERKEY_CTRL);
				Keyboard.press(KEY_C);
				Keyboard.release(KEY_C);
				Keyboard.release(MODIFIERKEY_CTRL);
			}
     if(kpd.key[i].kstate == HOLD)  {
        Keyboard.press(MODIFIERKEY_CTRL);
        Keyboard.press(KEY_X);
        Keyboard.release(KEY_X);
        Keyboard.release(MODIFIERKEY_CTRL);
      }
			break;

			case 'b':
			if(kpd.key[i].kstate == PRESSED)  {
				Keyboard.press(MODIFIERKEY_CTRL);
				Keyboard.press(KEY_V);
				Keyboard.release(KEY_V);
				Keyboard.release(MODIFIERKEY_CTRL);
			}
			break;


			case 'c':
			if(kpd.key[i].kstate == PRESSED)   Shifted = true;
			if(kpd.key[i].kstate == RELEASED)  Shifted = false;
			break;

			default:
			break;
			}
		}
	}
}
}
