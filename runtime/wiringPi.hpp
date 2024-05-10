/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */


#ifndef	WIRING_PI
#define	WIRING_PI

 // C doesn't have true/false by default and I can never remember which
 //	way round they are, so ...

#ifndef	TRUE
#  define	TRUE	(1==1)
#  define	FALSE	(!TRUE)
#endif

// Handy defines

// wiringPi modes

#define	WPI_MODE_PINS		 0
#define	WPI_MODE_GPIO		 1
#define	WPI_MODE_GPIO_SYS	 2
#define	WPI_MODE_PHYS		 3
#define	WPI_MODE_PIFACE		 4
#define	WPI_MODE_UNINITIALISED	-1

// Pin modes

#define	INPUT			 0
#define	OUTPUT			 1
#define	PWM_OUTPUT		 2
#define	GPIO_CLOCK		 3
#define	SOFT_PWM_OUTPUT		 4
#define	SOFT_TONE_OUTPUT	 5
#define	PWM_TONE_OUTPUT		 6

#define	LOW			 0
#define	HIGH			 1

// Pull up/down/none

#define	PUD_OFF			 0
#define	PUD_DOWN		 1
#define	PUD_UP			 2

// PWM

#define	PWM_MODE_MS		0
#define	PWM_MODE_BAL		1

// Interrupt levels

#define	INT_EDGE_SETUP		0
#define	INT_EDGE_FALLING	1
#define	INT_EDGE_RISING		2
#define	INT_EDGE_BOTH		3

// Pi model types and version numbers
//	Intended for the GPIO program Use at your own risk.

#define	PI_MODEL_A		0
#define	PI_MODEL_B		1
#define	PI_MODEL_AP		2
#define	PI_MODEL_BP		3
#define	PI_MODEL_2		4
#define	PI_ALPHA		5
#define	PI_MODEL_CM		6
#define	PI_MODEL_07		7
#define	PI_MODEL_3		8
#define	PI_MODEL_ZERO		9

#define	PI_VERSION_1		0
#define	PI_VERSION_1_1		1
#define	PI_VERSION_1_2		2
#define	PI_VERSION_2		3

#define	PI_MAKER_SONY		0
#define	PI_MAKER_EGOMAN		1
#define	PI_MAKER_MBEST		2
#define	PI_MAKER_UNKNOWN	3

extern const char* piModelNames[16];
extern const char* piRevisionNames[16];
extern const char* piMakerNames[16];
extern const int   piMemorySize[8];


//	Intended for the GPIO program Use at your own risk.

// Threads

#define	PI_THREAD(X)	void *X (void *dummy)

// Failure modes

#define	WPI_FATAL	(1==1)
#define	WPI_ALMOST	(1==2)


// wiringPiNodeStruct:
//	This describes additional device nodes in the extended wiringPi
//	2.0 scheme of things.
//	It's a simple linked list for now, but will hopefully migrate to 
//	a binary tree for efficiency reasons - but then again, the chances
//	of more than 1 or 2 devices being added are fairly slim, so who
//	knows....

struct wiringPiNodeStruct
{
  int     pinBase;
  int     pinMax;

  int          fd;	// Node specific
  unsigned int data0;	//  ditto
  unsigned int data1;	//  ditto
  unsigned int data2;	//  ditto
  unsigned int data3;	//  ditto

  void   (*pinMode)         (struct wiringPiNodeStruct* node, int pin, int mode);
  void   (*pullUpDnControl) (struct wiringPiNodeStruct* node, int pin, int mode);
  int    (*digitalRead)     (struct wiringPiNodeStruct* node, int pin);
  void   (*digitalWrite)    (struct wiringPiNodeStruct* node, int pin, int value);
  void   (*pwmWrite)        (struct wiringPiNodeStruct* node, int pin, int value);
  int    (*analogRead)      (struct wiringPiNodeStruct* node, int pin);
  void   (*analogWrite)     (struct wiringPiNodeStruct* node, int pin, int value);

  struct wiringPiNodeStruct* next;
};

extern struct wiringPiNodeStruct* wiringPiNodes;


// Function prototypes
//	c++ wrappers thanks to a comment by Nick Lott
//	(and others on the Raspberry Pi forums)

#ifdef __cplusplus
extern "C" {
#endif

  // Data

  // Internal

  extern int wiringPiFailure(int fatal, const char* message, ...);

  // Core wiringPi functions

  extern struct wiringPiNodeStruct* wiringPiFindNode(int pin);
  extern struct wiringPiNodeStruct* wiringPiNewNode(int pinBase, int numPins);

  extern int  wiringPiSetup(void);
  extern int  wiringPiSetupSys(void);
  extern int  wiringPiSetupGpio(void);
  extern int  wiringPiSetupPhys(void);

  extern void pinModeAlt(int pin, int mode);
  extern void pinMode(int pin, int mode);
  extern void pullUpDnControl(int pin, int pud);
  extern int  digitalRead(int pin);
  extern void digitalWrite(int pin, int value);
  extern void pwmWrite(int pin, int value);
  extern int  analogRead(int pin);
  extern void analogWrite(int pin, int value);

  // PiFace specifics 
  //	(Deprecated)

  extern int  wiringPiSetupPiFace(void);
  extern int  wiringPiSetupPiFaceForGpioProg(void);	// Don't use this - for gpio program only

  // On-Board Raspberry Pi hardware specific stuff

  extern signed int  piBoardRev(void);
  extern signed void piBoardId(int* model, int* rev, int* mem, int* maker, int* overVolted);
  extern signed int  wpiPinToGpio(int wpiPin);
  extern signed int  physPinToGpio(int physPin);
  extern signed void setPadDrive(int group, int value);
  extern signed int  getAlt(int pin);
  extern signed void pwmToneWrite(int pin, int freq);
  extern signed void digitalWriteByte(int value);
  extern unsigned int  digitalReadByte(void);
  extern signed void pwmSetMode(int mode);
  extern signed void pwmSetRange(unsigned int range);
  extern signed void pwmSetClock(int divisor);
  extern signed void gpioClockSet(int pin, int freq);

  // Interrupts
  //	(Also Pi hardware specific)

  extern int  waitForInterrupt(int pin, int mS);
  extern int  wiringPiISR(int pin, int mode, void (*function)(void));

  // Threads

  extern int  piThreadCreate(void* (*fn)(void*));
  extern void piLock(int key);
  extern void piUnlock(int key);

  // Schedulling priority

  extern int piHiPri(const int pri);

  // Extras from arduino land

  extern void         delay(unsigned int howLong);
  extern void         delayMicroseconds(unsigned int howLong);
  extern unsigned int millis(void);
  extern unsigned int micros(void);

#ifdef __cplusplus
}
#endif

#endif
