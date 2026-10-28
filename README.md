## UE4Dumper(Unreal Engine 4 Dumper)
Unreal Engine 4 Dumper for Android Devices, Dump Lib libUE4.so from Memory of Game Process and Generate Structure SDK of Supported Game in Android. You can Find Latest Dumped SDK from [HERE](https://github.com/kp7742/UE4Dumper/tree/master/SDKs/)

## Changelog
- v0.21:
    - 1) Merged code from private repo
    - 2) Added Support for Farlight84 Mobile
    - 3) Improved UTF16 to UTF8 string conversion
    - 4) And in the end, this is probably last and final update of UE4Dumper
- v0.20:
    - 1) Few more improvements to SDK Dumping
    - 2) Added Option to use pointer decryption
    - 3) Added Support for PUBG New State Mobile
    - 4) Added GWorld and GName Workaround for PUBGM Series
    - 5) Offsets are not upto date with latest game versions so please update them yourself
- v0.19:
    - 1) Fixed Object Dumping issue with PUBG CN
    - 2) Improved String Dumping Output
    - 3) Fixed Verbose Output Not Showing while String Dumping
    - 4) General Improvements to SDK Dumping
- v0.18:
    - 1) Fixed Dumping issue with 64bit PUBG CN
    - 2) Fixed Another Issue with String Dumping
- v0.17:
    - 1) Fixed Crash with Deref Options
    - 2) Fixed Issue with Wide String Dumping
- v0.16: Fixed Dumping issue with 64bit PUBG Lite
- v0.15:
    - 1) Fixed Struct Property Dumping
    - 2) Experimental Wide String Support Added for UE 4.23+ Mode
- v0.14: Fixed Support for Battlegrounds Mobile India
- v0.13:
    - 1) Fixed String Reading for Objects for UE 4.23+ Mode
    - 2) Fixed SDK Dumping Issue Due to Invalid UStruct
    - 3) Added Offset Support for Fortnite Mobile
- v0.12:
    - 1) Fixed Offsets for UE 4.23+ Mode
    - 2) Fixed SDK Dumping for UE 4.23+ Mode
    - 3) Fixed String Dumping for UE 4.23+ Mode
    - 4) Added Offset Support for Apex Legends Mobile
    - 5) Added Option to Detour or De-Reference GNames, GUObject Addresses
    - 6) Added Option to See Verbose Output of String, Object and SDK Dumping
- v0.11: Fixed Dumping issue with 64bit PUBG Lite
- v0.10:
    - 1) Added Option to Print Actors of Main Level(Use new Option: --actors)
    - 2) Support for PUBG CN(GFP) Fixed(Tested on GFP v1.9.10)
    - 3) Fixed Some Offsets Issues due to Modified UE4 Versions
    - 4) Offsets System Updated to Work with Other games, other then PUBG
- v0.9: Fixed Dumping issue with 64bit PUBG
- v0.8: Fixed 64bit Support for Latest PUBG Version
- v0.7: Fixed Object Dumping issue for PUBG CN(Tested on GFP v1.8.10)
- v0.6:
    - 1) Added Support for UE 4.23+ Games for Strings and Objects(Use new Option: --newue)
    - 2) Added 64bit Offsets to Fix 64bit Support
    - 3) Updated SDK Generation Method for Faster Dumping
    - 4) Short Options has been remove due to conflict with new options
- v0.5: Added Support to Resolve Functions
- v0.4:
    - 1) Expanded 64bit Support,
    - 2) Fixed 64bit Library Rebuilding Not Working
    - 3) Added New Elf Dump Fix for 64bit Library
    - 4) Added Option to Dump SDK with GWorld
    - 5) Updated Usage Text
- v0.3:
    - 1) Fix Object Iteration Issue during Dumping SDK 
    - 2) Added Support to Resolve Arrays, Sets and Maps Structure
- v0.2: Experimental 64bit Support Added
- v0.1: First Release

## Features
- No need of Ptrace
- Bypass Anti Debugging
- Dumping of Lib from Memory of Game
- Fix and Regenerate So(Elf) File from Dump
- Dumping of Game Structure SDK file(Need to Find Pointers Manually)
- Support Fast Dumping(Might Miss some data)
- Support SDK Dumping for UE4 Based Android Games
- Tested on 32bit and 64bit PUBG Mobile Series

## Note
- Only for Educational or Learning Purpose.
- Project is Deprecated, No more updates in Future.
- Use 32bit and 64bit Version on Respected Arch of Game.
- Recommend to use in Training Mode for PUBG Mobile.
- Some Games with Modified UE4 Might not Dump Correctly.
- For Modified Engines, You May Need Put Your Custom Offsets For That Game.
- If it stuck during Generating SDK, Then Simply Stop it, Check Dump file and If needed then Try again.
 
## How to use
- You can Use latest precompiled Binaries from [HERE](https://github.com/kp7742/UE4Dumper/tree/master/libs/) or You Can build your Own.
- Needs Either Root Access or Virtual Space
- Put Executable in folder like /data/local/tmp (/sdcard not allow to execute binary so don't put it there)
- Get Either Root Shell through Adb or Terminal Apps(type and run: 'su') or Normal Shell into Virtual Space via Terminal Apps in that folder
- Give it executable permission with either 'chmod +x ue4dumper' or 'chmod 755 ue4dumper'
- Run './ue4dumper -h' For Usage Help
	```
    UE4Dumper v0.21 <==> Made By KMODs(kp7742)
    Usage: ./ue4dumper <option(s)>
    Dump Lib libUE4.so from Memory of Game Process and Generate structure SDK for UE4 Engine
    Tested on PUBG Mobile Series and Other UE4 Based Games
    Options:
    --SDK Dump With GObjectArray Args--------------------------------------------------------
    --sdku                              Dump SDK with GUObject
    --gname <address>                   GNames Pointer Address
    --guobj <address>                   GUObject Pointer Address
    --SDK Dump With GWorld Args--------------------------------------------------------------
    --sdkw                              Dump SDK with GWorld
    --gname <address>                   GNames Pointer Address
    --gworld <address>                  GWorld Pointer Address
    --Dump Strings Args----------------------------------------------------------------------
    --strings                           Dump Strings
    --gname <address>                   GNames Pointer Address
    --Dump Objects Args----------------------------------------------------------------------
    --objs                              Dumping Object List
    --gname <address>                   GNames Pointer Address
    --guobj <address>                   GUObject Pointer Address
    --Lib Dump Args--------------------------------------------------------------------------
    --lib                               Dump libUE4.so from Memory
    --raw(Optional)                     Output Raw Lib and Not Rebuild It
    --fast(Optional)                    Enable Fast Dumping(May Miss Some Bytes in Dump)
    --Show ActorList With GWorld Args--------------------------------------------------------
    --actors                            Show Actors with GWorld
    --gname <address>                   GNames Pointer Address
    --gworld <address>                  GWorld Pointer Address
    --Other Args-----------------------------------------------------------------------------
    --newue(Optional)                   Run in UE 4.23+ Mode
    --ptrdec(Optional)                  Use Pointer Decryption Mode
    --verbose(Optional)                 Show Verbose Output of Dumping
    --derefgname(Optional) <true/false> De-Reference GNames Address(Default: true)
    --derefguobj(Optional) <true/false> De-Reference GUObject Address(Default: false)
    --gname-adjust <offset>            Extra offset from the first GNames pointer
    --package <packageName>             Package Name of App(Default: com.tencent.ig)
    --output <outputPath>               File Output path
    --help                              Display this information
	```

- `--sdku` and `--sdkw` write the readable `SDK.txt` report and a package-organized export under `SDK/`: `SDK.hpp`, `Basic.hpp`, and per-package `_structs.hpp`, `_classes.hpp`, `_parameters.hpp`, and `_functions.cpp` files.
- Generated type and parameter headers preserve reflected offsets and sizes as byte-array layouts. Function signatures and addresses are recorded in `_functions.cpp` comments and `SDK.txt`; this exporter does not generate `ProcessEvent` wrapper bodies.

### Extract readable strings from any `.so` file

The dumper's `--strings` option reads Unreal Engine name strings using `GNames`; it does not extract arbitrary strings from another shared library. To list readable ASCII strings from any `.so`, use `llvm-strings.exe` from the Android NDK on Windows. Set `LIB` to the library path and replace `<ndk-version>` with your installed NDK version:

```cmd
set "LIB=C:\path\to\libOther.so"
"%LOCALAPPDATA%\Android\Sdk\ndk\<ndk-version>\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-strings.exe" -a "%LIB%" > OtherStrings.txt
```

To extract strings from the library on a connected Android device, first copy it to the computer, then run `llvm-strings.exe` on the pulled file:

```cmd
adb pull /path/on/device/libOther.so .
"%LOCALAPPDATA%\Android\Sdk\ndk\<ndk-version>\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-strings.exe" -a libOther.so > OtherStrings.txt
```

Replace `/path/on/device/libOther.so` with the actual device path. This extracts readable strings from the `.so` file; it does not dump a library from a running process's memory.

### Example: Dump SDK from a connected Android device

Create the output directory on the device, then run the dumper as root:

```cmd
adb shell su -c "mkdir -p /data/local/tmp/sdk"
adb shell su -c "/data/local/tmp/ue4dumper64 --sdku --gname 0xe833d20 --gname-adjust 0x110 --guobj 0xEB04D00 --package com.pubg.imobile --output /data/local/tmp/sdk"
```

Pull the generated files to the current PC directory with:

```cmd
adb pull /data/local/tmp/sdk sdk
```

### Run the RefSkeleton dump from Windows CMD

Connect the Android device with USB debugging, open the game, and run this in the repository folder. The script pushes the ARM64 dumper, writes its temporary output under `/data/local/tmp/ue4dumper-output`, then pulls `RefSkeleton.txt` into the repository folder:

```cmd
powershell -ExecutionPolicy Bypass -File .\tools\Run-RefSkeletonDump.ps1 -GName 0xe833d20 -GUObject 0xeb04d00 -GNameAdjust 0x110 -Package com.pubg.imobile -NewUE
```

Replace the addresses and package with values for your game. Omit `-NewUE` for versions before UE 4.23. The script expects `libs\arm64-v8a\ue4dumper64` and root access through `su`.

### Find bot/player flag offsets from the SDK dump

After generating `SDK.txt`, run this Windows PowerShell script from the repository folder:

```cmd
powershell -ExecutionPolicy Bypass -File .\tools\Find-BotPlayerOffset.ps1
```

It lists boolean fields such as `PlayerState::bIsABot` and `UAECharacter::bIsAI` with their class-relative offsets and byte masks. In the current `SDK.txt`, `PlayerState::bIsABot` is at `0x4DC` with mask `0x04`; test it by reading the byte at `PlayerState + 0x4DC` and checking `(value & 0x04) != 0`. `UAECharacter::bIsAI` at `0xA40` is a secondary candidate. Resolve the actor's `PlayerState` pointer before reading the flag. These values are SDK/build-specific and should be checked against a fresh dump for the target game version.

The finder also prints the SDK relationship offsets: `Actor::Owner` (`0xF0`) and `Pawn::PlayerState` (`0x4D0`). The current SDK dump has no `ModelTarget` class/field, so it cannot provide a direct ModelTarget-to-bot link. Validate any owner/player-state pointer with GName before using its bot flag.
	
## How to Build
- Clone this repo
- Install Android NDK, if not already.
- Open Shell/CMD in Project Folder
- Drag ndk-build from NDK in Shell or CMD and then Execute
- Output will be in libs Folder.

## Credits
- [SoFixer](https://github.com/F8LEFT/SoFixer): 32bit So(Elf) Rebuilding
- [elf-dump-fix](https://github.com/maiyao1988/elf-dump-fix): 64bit So(Elf) Rebuilding
- [UnrealDumper-4.25](https://github.com/guttir14/UnrealDumper-4.25): UE 4.25+ Support

## Technlogy Communication
> Email: patel.kuldip91@gmail.com





powershell -ExecutionPolicy Bypass -File tools\Find-GNames.ps1 -Package com.pubg.imobile




powershell -ExecutionPolicy Bypass -File .\tools\Run-RefSkeletonDump.ps1 -GName 0xe833d20 -GUObject 0xeb04d00 -GWorld 0xEDC6210 -GNameAdjust 0x110 -Package com.pubg.imobile -NewUE
