# Linux build-related commands.
# ===================================================================

cmdLinux:
	cmake -S . -B out/build/Linux/Debug -DCMAKE_BUILD_TYPE=Debug
cmrLinux:
	cmake -S . -B out/build/Linux/Release -DCMAKE_BUILD_TYPE=Release
bdLinux:
	make -C out/build/Linux/Debug
brLinux:
	make -C out/build/Release/Linux
rdLinux:
	out/build/Linux/Debug/Network_Simulatord
rdtLinux:
	out/build/Linux/Debug/Network_Simulator
runLinux:
	out/build/Linux/Release/Network_Simulatord
rrtLinux:
	out/build/Linux/Release/Network_Simulator

# MacOS build-related commands.
# ===================================================================

cmdMacU:
	cmake -S . -B out/build/MacOS/Debug -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug
cmrMacU:
	cmake -S . -B out/build/MacOS/Release -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release
cmdMac:
	cmake -S . -B out/build/MacOS/Debug -DCMAKE_BUILD_TYPE=Debug
cmrMac:
	cmake -S . -B out/build/MacOS/Release -DCMAKE_BUILD_TYPE=Release
bdMac:
	make -C out/build/MacOS/Debug
brMac:
	make -C out/build/MacOS/Release
rdMac:
	out/build/MacOS/Debug/Network_Simulator.app/Contents/MacOS/Network_Simulator
rdtMac:
	out/build/MacOS/Debug/Network_Simulator_test
runMac:
	out/build/MacOS/Release/Network_Simulator
rrtMac:
	out/build/MacOS/Release/Network_Simulator_test