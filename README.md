GEMDROID
====================
Description
----------
Welcome to GemDroid, An Infrastructure to Evaluate Mobile Platforms. GemDroid uses traces to feed its simluator. This patch generates traces of an application from the android emulator. The trace contains CPU/Memory access, frame buffer activity and raw instructions.

System Requirement
-------------------
AOSP 4.4.4 from https://source.android.com/source/downloading.html


In this tar ball
-----------------------------
1. gemdroid_qemu 	#GemDroid QEMU part
2. ReadMe.md 	 	#This readme
3. 

To Patch
-------- 
Assume that $AOSP is your aosp folder, follow the following commands you will have an emulator for GemDroid.

```bash
	# backup your original qemu folder
	cd $AOSP
	git clone https://github.com/huz123/GemDroid_QEMU .
	cd $AOSP/sdk/emulator
	git checkout -b gemdroid cbf40c
	cd $AOSP/external
	cp -r $AOSP/GemDroid_QEMU/gemdroid_qemu qemu
	cd qemu
	./android-configure.sh
	# remove "-Wl" in objs/config.make
	make 
	# use emulators in objs/
```



To use
------
0. Need an android virtual device # follow Android Website;
1. start the emulator with your android virtual device as usual;
2. press "volume up" button will trace the Frame Buffer Activity # Note that this is not supported for DIV monitors;
3. press "volume down" button will trace the CPU/Memory accesses;
4. press "call" button will trace raw instructions.

FAQ
-------
Q: I use a DIV monitor. It seems that there is no response when I press "volume up" button.
A: It is a bug in the emulator. A quick fix is to replace $AOSP/sdk/emulator/opengl/host/libs/libOpenglRender/FrameBuffer.cpp using the file we provided. 

Contacts
------
If you find any bugs, please send to haibo at cse.psu.edu or nachi at cse.psu.edu.