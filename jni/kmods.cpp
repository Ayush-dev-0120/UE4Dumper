#include "kmods.h"
#include "Offsets.h"
#include "SDK.h"

using namespace std;

const char *short_options = "hlrfnsabcdevi:j:p:o:g:u:w:";
const struct option long_options[] = {
        {"help",       no_argument,       nullptr, 'h'},
        {"lib",        no_argument,       nullptr, 'l'},
        {"raw",        no_argument,       nullptr, 'r'},
        {"fast",       no_argument,       nullptr, 'f'},
        {"objs",       no_argument,       nullptr, 'n'},
        {"strings",    no_argument,       nullptr, 's'},
        {"strings-lib", required_argument, nullptr, 'L'},
        {"strings-lib-min", required_argument, nullptr, 'm'},
        {"sdku",       no_argument,       nullptr, 'a'},
        {"sdkw",       no_argument,       nullptr, 'b'},
        {"newue",      no_argument,       nullptr, 'c'},
        {"actors",     no_argument,       nullptr, 'd'},
        {"ptrdec",     no_argument,       nullptr, 'e'},
        {"verbose",    no_argument,       nullptr, 'v'},
        {"derefgname", required_argument, nullptr, 'i'},
        {"derefguobj", required_argument, nullptr, 'j'},
        {"package",    required_argument, nullptr, 'p'},
        {"output",     required_argument, nullptr, 'o'},
        {"gname",      required_argument, nullptr, 'g'},
        {"guobj",      required_argument, nullptr, 'u'},
        {"gworld",     required_argument, nullptr, 'w'},
        {"gname-adjust", required_argument, nullptr, 'x'},
        {nullptr, 0,                      nullptr, 0}
};

void Usage() {
    printf("UE4Dumper v0.21 <==> Made By KMODs(kp7742)\n");
    printf("Usage: ./ue4dumper <option(s)>\n");
    printf("Dump Lib libUE4.so from Memory of Game Process and Generate structure SDK for UE4 Engine\n");
    printf("Tested on PUBG Mobile Series and Other UE4 Based Games\n");
    printf(" Options:\n");
    printf("--SDK Dump With GObjectArray Args--------------------------------------------------------\n");
    printf("  --sdku                              Dump SDK with GUObject\n");
    printf("                                      Also writes SDK.hpp and package headers under SDK/\n");
    printf("  --gname <address>                   GNames Pointer Address\n");
    printf("  --guobj <address>                   GUObject Pointer Address\n");
    printf("--SDK Dump With GWorld Args--------------------------------------------------------------\n");
    printf("  --sdkw                              Dump SDK with GWorld\n");
    printf("  --gname <address>                   GNames Pointer Address\n");
    printf("  --gworld <address>                  GWorld Pointer Address\n");
    printf("  --gname-adjust <offset>              Extra offset from the first GNames pointer\n");
    printf("--Dump Strings Args----------------------------------------------------------------------\n");
    printf("  --strings                           Dump Strings\n");
    printf("  --gname <address>                   GNames Pointer Address\n");
    printf("  --strings-lib <library.so>          Dump runtime memory and strings from a loaded library\n");
    printf("  --strings-lib-min <length>          Minimum extracted string length (default: 4)\n");
    printf("--Dump Objects Args----------------------------------------------------------------------\n");
    printf("  --objs                              Dumping Object List\n");
    printf("  --gname <address>                   GNames Pointer Address\n");
    printf("  --guobj <address>                   GUObject Pointer Address\n");
    printf("--Lib Dump Args--------------------------------------------------------------------------\n");
    printf("  --lib                               Dump libUE4.so from Memory\n");
    printf("  --raw(Optional)                     Output Raw Lib and Not Rebuild It\n");
    printf("  --fast(Optional)                    Enable Fast Dumping(May Miss Some Bytes in Dump)\n");
    printf("--Show ActorList With GWorld Args--------------------------------------------------------\n");
    printf("  --actors                            Show Actors with GWorld\n");
    printf("  --gname <address>                   GNames Pointer Address\n");
    printf("  --gworld <address>                  GWorld Pointer Address\n");
    printf("--Other Args-----------------------------------------------------------------------------\n");
    printf("  --newue(Optional)                   Run in UE 4.23+ Mode\n");
    printf("  --ptrdec(Optional)                  Use Pointer Decryption Mode\n");
    printf("  --verbose(Optional)                 Show Verbose Output of Dumping\n");
    printf("  --derefgname(Optional) <true/false> De-Reference GNames Address(Default: true)\n");
    printf("  --derefguobj(Optional) <true/false> De-Reference GUObject Address(Default: false)\n");
    printf("  --package <packageName>             Package Name of App(Default: com.tencent.ig)\n");
    printf("  --output <outputPath>               File Output path\n");
    printf("  --help                              Display this information\n");
}

kaddr getHexAddr(const char *addr) {
#ifndef __SO64__
    return (kaddr) strtoul(addr, nullptr, 16);
#else
    return (kaddr) strtoull(addr, nullptr, 16);
#endif
}

int main(int argc, char *argv[]) {
    int c;
    string outputpath(".");
    bool isValidArg = true,
            isLibDump = false,
            isFastDump = false,
            isRawDump = false,
            isObjsDump = false,
            isStrDump = false,
            isSdkDump = false,
            isSdkDump2 = false,
            isActorDump = false;
    string stringsLib;
    size_t stringsMinLength = 4;

    while ((c = getopt_long(argc, argv, short_options, long_options, nullptr)) != -1) {
        switch (c) {
            case 'l':
                isLibDump = true;
                break;
            case 'r':
                isRawDump = true;
                break;
            case 'f':
                isFastDump = true;
                break;
            case 'p':
                pkg = optarg;
                break;
            case 'o':
                outputpath = optarg;
                break;
            case 'g':
                Offsets::GNames = getHexAddr(optarg);
                break;
            case 'u':
                Offsets::GUObjectArray = getHexAddr(optarg);
                break;
            case 'w':
                Offsets::GWorld = getHexAddr(optarg);
                break;
            case 'x':
                Offsets::GNamesAdjustment = getHexAddr(optarg);
                break;
            case 'n':
                isObjsDump = true;
                break;
            case 's':
                isStrDump = true;
                break;
            case 'L':
                stringsLib = optarg;
                break;
            case 'm': {
                char *end = nullptr;
                unsigned long parsed = strtoul(optarg, &end, 10);
                if (end == optarg || *end != '\0' || parsed == 0 || parsed > 4096) {
                    isValidArg = false;
                } else {
                    stringsMinLength = static_cast<size_t>(parsed);
                }
                break;
            }
            case 'a':
                isSdkDump = true;
                break;
            case 'b':
                isSdkDump2 = true;
                break;
            case 'c':
                isUE423 = true;
                break;
            case 'd':
                isActorDump = true;
                break;
            case 'e':
                isPtrDec = true;
                break;
            case 'v':
                isVerbose = true;
                break;
            case 'i':
                deRefGNames = isEqual(optarg, "true");
                break;
            case 'j':
                deRefGUObjectArray = isEqual(optarg, "true");
                break;
            default:
                isValidArg = false;
                break;
        }
    }

#if defined(__LP64__)
    Offsets::initOffsets_64();
    if (isUE423) {
        Offsets::patchUE423_64();
    }
    Offsets::patchCustom_64();
#else
    Offsets::initOffsets_32();
    if (isUE423) {
        Offsets::patchUE423_32();
    }
    Offsets::patchCustom_32();
#endif

    isPGLite = isPUBGLite();
    isPUBGCN = isGameOfPeace();
    isPUBGNS = isPUBGNewState();

    if (!isValidArg ||
        (!isLibDump && !isObjsDump && !isStrDump && !isSdkDump && !isSdkDump2 &&
         !isActorDump && stringsLib.empty())) {
        printf("Wrong Arguments, Please Check!!\n");
        Usage();
        return -1;
    }

    //Find PID
    target_pid = find_pid(pkg.c_str());
    if (target_pid == -1) {
        cout << "Can't find the process" << endl;
        return -1;
    }
    cout << "Process name: " << pkg.c_str() << ", Pid: " << target_pid << endl;

    //Lib Base Address
    const char *targetModule = stringsLib.empty() ? lib_name : stringsLib.c_str();
    libbase = get_module_base(targetModule);
    if (libbase == 0) {
        cout << "Can't find Library: " << targetModule << endl;
        return -1;
    }
    cout << "Base Address of " << targetModule << " Found At " << setbase(16) << libbase << setbase(10)
         << endl;

    if (!stringsLib.empty()) {
        vector<ModuleMemoryRegion> regions = get_module_regions(targetModule);
        if (regions.empty()) {
            cout << "No memory mappings found for Library: " << targetModule << endl;
            return -1;
        }
        size_t slash = stringsLib.find_last_of('/');
        string outputName = stringsLib.substr(slash == string::npos ? 0 : slash + 1);
        kaddr imageBase = regions.front().start;
        kaddr imageEnd = regions.front().end;
        for (const auto &region : regions) {
            imageBase = min(imageBase, region.start);
            imageEnd = max(imageEnd, region.end);
        }
        ofstream stringsOut(outputpath + "/Strings_" + outputName + ".txt");
        ofstream xrefsOut(outputpath + "/Xrefs_" + outputName + ".txt");
        ofstream memoryOut(outputpath + "/Runtime_" + outputName + ".bin", ofstream::out | ofstream::binary);
        if (!stringsOut.is_open() || !xrefsOut.is_open() || !memoryOut.is_open()) {
            cout << "Can't create runtime dump output files" << endl;
            return -1;
        }
        const size_t chunkSize = 4096;
        vector<unsigned char> buffer(chunkSize);
        vector<unsigned char> zeros(chunkSize, 0);
        string current;
        string wideCurrent;
        kaddr currentStart = 0;
        kaddr wideStart = 0;
        vector<pair<kaddr, string>> stringLocations;
        uint64 count = 0;
        auto flushString = [&]() {
            if (current.size() >= stringsMinLength) {
                stringsOut << "[+0x" << hex << (currentStart - imageBase) << "] [0x"
                           << currentStart << "] " << current << dec << '\n';
                stringLocations.push_back(make_pair(currentStart, current));
                ++count;
            }
            current.clear();
        };
        auto flushWideString = [&]() {
            if (wideCurrent.size() >= stringsMinLength) {
                stringsOut << "[+0x" << hex << (wideStart - imageBase) << "] [0x"
                           << wideStart << "] [UTF-16] " << wideCurrent << dec << '\n';
                stringLocations.push_back(make_pair(wideStart, wideCurrent));
                ++count;
            }
            wideCurrent.clear();
        };
        cout << "Dumping runtime memory and extracting strings from " << targetModule << endl;
        for (const auto &region : regions) {
            if (!region.readable) continue;
            flushString();
            for (kaddr address = region.start; address < region.end;) {
                size_t amount = static_cast<size_t>(min<kaddr>(chunkSize, region.end - address));
                memoryOut.seekp(static_cast<streamoff>(address - imageBase));
                if (!vm_readv(reinterpret_cast<void *>(address), buffer.data(), amount)) {
                    memoryOut.write(reinterpret_cast<const char *>(zeros.data()), amount);
                    flushString();
                    flushWideString();
                    address += amount;
                    continue;
                }
                memoryOut.write(reinterpret_cast<const char *>(buffer.data()), amount);
                for (size_t i = 0; i < amount; ++i) {
                    unsigned char ch = buffer[i];
                    if (ch >= 0x20 && ch <= 0x7e) {
                        if (current.empty()) currentStart = address + i;
                        current.push_back(static_cast<char>(ch));
                    } else flushString();
                }
                for (size_t i = 0; i + 1 < amount; ++i) {
                    unsigned char ch = buffer[i];
                    if (ch >= 0x20 && ch <= 0x7e && buffer[i + 1] == 0) {
                        if (wideCurrent.empty()) wideStart = address + i;
                        wideCurrent.push_back(static_cast<char>(ch));
                        ++i;
                    } else {
                        flushWideString();
                    }
                }
                address += amount;
            }
            flushString();
            flushWideString();
        }
        stringsOut.close();
        // Find exact 64-bit pointers to extracted strings across readable process mappings.
        unordered_map<kaddr, size_t> stringByAddress;
        for (size_t i = 0; i < stringLocations.size(); ++i)
            stringByAddress[stringLocations[i].first] = i;
        vector<uint64> xrefCounts(stringLocations.size(), 0);
        vector<ModuleMemoryRegion> processRegions = get_process_regions();
        xrefsOut << "# Exact 64-bit pointer references to string start addresses.\n"
                 << "# A reference inside executable memory may be a data literal; this does not identify a function by itself.\n";
        const size_t scanSize = 64 * 1024;
        vector<unsigned char> scanBuffer(scanSize + sizeof(kaddr));
        for (const auto &region : processRegions) {
            if (!region.readable || region.name.find(".so") == string::npos) continue;
            for (kaddr address = region.start; address + sizeof(kaddr) <= region.end;) {
                size_t amount = static_cast<size_t>(min<kaddr>(scanSize, region.end - address));
                if (!vm_readv(reinterpret_cast<void *>(address), scanBuffer.data(), amount)) {
                    address += amount;
                    continue;
                }
                for (size_t i = 0; i + sizeof(kaddr) <= amount; i += sizeof(kaddr)) {
                    kaddr value = 0;
                    memcpy(&value, scanBuffer.data() + i, sizeof(value));
                    auto found = stringByAddress.find(value);
                    if (found == stringByAddress.end()) continue;
                    size_t stringIndex = found->second;
                    kaddr refAddress = address + i;
                    xrefsOut << "[string +0x" << hex << (stringLocations[stringIndex].first - imageBase)
                             << "] [ref 0x" << refAddress << "] [" << (region.executable ? "executable" : "data") << "] ["
                             << region.name << "] " << stringLocations[stringIndex].second << dec << '\n';
                    ++xrefCounts[stringIndex];
                }
                address += amount;
            }
        }
        xrefsOut << "\n# Strings without an exact pointer match are not listed in the reference section.\n";
        for (size_t i = 0; i < stringLocations.size(); ++i) {
            if (xrefCounts[i] == 0)
                xrefsOut << "[string +0x" << hex << (stringLocations[i].first - imageBase)
                         << "] [no exact pointer found] " << stringLocations[i].second << dec << '\n';
        }
        xrefsOut.close();
        memoryOut.close();
        cout << count << " strings written to " << outputpath << "/Strings_"
             << outputName << ".txt" << endl;
        cout << "Runtime memory image written to " << outputpath << "/Runtime_" << outputName
             << ".bin (span: " << (imageEnd - imageBase) << " bytes; base: 0x"
             << hex << imageBase << dec << ")" << endl;
        cout << "Pointer reference report written to " << outputpath << "/Xrefs_"
             << outputName << ".txt" << endl;
        return 0;
    }

    if (isLibDump) {
        //Lib End Address
        kaddr start_addr = libbase;
        kaddr end_addr = get_module_end(lib_name);
        if (end_addr == 0) {
            cout << "Can't find End of Library: " << lib_name << endl;
            return -1;
        }
        cout << "End Address of " << lib_name << " Found At " << setbase(16) << end_addr
             << setbase(10) << endl;

        //Lib Dump
        size_t libsize = (end_addr - libbase);
        cout << "Lib Size: " << libsize << endl;

        if (isRawDump) {
            ofstream rdump(outputpath + "/" + lib_name, ofstream::out | ofstream::binary);
            if (rdump.is_open()) {
                if (isFastDump) {
                    auto *buffer = new uint8_t[libsize];
                    memset(buffer, '\0', libsize);
                    vm_readv((void *) start_addr, buffer, libsize);
                    rdump.write((char *) buffer, libsize);
                } else {
                    char *buffer = new char[1];
                    while (libsize != 0) {
                        vm_readv((void *) (start_addr++), buffer, 1);
                        rdump.write(buffer, 1);
                        --libsize;
                    }
                }
            } else {
                cout << "Can't Output File" << endl;
                return -1;
            }
            rdump.close();
        } else {
            string tempPath = outputpath + "/KTemp.dat";

            ofstream ldump(tempPath, ofstream::out | ofstream::binary);
            if (ldump.is_open()) {
                if (isFastDump) {
                    auto *buffer = new uint8_t[libsize];
                    memset(buffer, '\0', libsize);
                    vm_readv((void *) start_addr, buffer, libsize);
                    ldump.write((char *) buffer, libsize);
                } else {
                    char *buffer = new char[1];
                    while (libsize != 0) {
                        vm_readv((void *) (start_addr++), buffer, 1);
                        ldump.write(buffer, 1);
                        --libsize;
                    }
                }
            } else {
                cout << "Can't Output File" << endl;
                return -1;
            }
            ldump.close();

            //SoFixer Code//
            cout << "Rebuilding Elf(So)" << endl;

#if defined(__LP64__)
            string outPath = outputpath + "/" + lib_name;

            fix_so(tempPath.c_str(), outPath.c_str(), start_addr);
#else
            ElfReader elf_reader;

            elf_reader.setDumpSoFile(true);
            elf_reader.setDumpSoBaseAddr(start_addr);

            auto file = fopen(tempPath.c_str(), "rb");
            if (nullptr == file) {
                printf("source so file cannot found!!!\n");
                return -1;
            }
            auto fd = fileno(file);

            elf_reader.setSource(tempPath.c_str(), fd);

            if (!elf_reader.Load()) {
                printf("source so file is invalid\n");
                return -1;
            }

            ElfRebuilder elf_rebuilder(&elf_reader);
            if (!elf_rebuilder.Rebuild()) {
                printf("error occured in rebuilding elf file\n");
                return -1;
            }
            fclose(file);
            //SoFixer Code//

            ofstream redump(outputpath + "/" + lib_name, ofstream::out | ofstream::binary);
            if (redump.is_open()) {
                redump.write((char*) elf_rebuilder.getRebuildData(), elf_rebuilder.getRebuildSize());
            } else {
                cout << "Can't Output File" << endl;
                return -1;
            }
            redump.close();
#endif

            cout << "Rebuilding Complete" << endl;
            remove(tempPath.c_str());
        }
    }

    if (isStrDump) {
        if (Offsets::GNames < 1) {
            printf("Please Enter Correct GName Addresses!!\n");
            Usage();
            return -1;
        }
        DumpStrings(outputpath);
        cout << endl;
    }
    if (isObjsDump) {
        if (Offsets::GUObjectArray < 1) {
            printf("Please Enter Correct GUObject Addresses!!\n");
            Usage();
            return -1;
        }
        DumpObjects(outputpath);
        cout << endl;
    }
    if (isSdkDump) {
        if (Offsets::GNames < 1 || Offsets::GUObjectArray < 1) {
            printf("Please Enter Correct GName and GUObject Addresses!!\n");
            Usage();
            return -1;
        }
        DumpSDK(outputpath);
        cout << endl;
    }
    if (isSdkDump2) {
        if (Offsets::GNames < 1 || Offsets::GWorld < 1) {
            printf("Please Enter Correct GName and GWorld Addresses!!\n");
            Usage();
            return -1;
        }
        DumpSDKW(outputpath);
        cout << endl;
    }
    if (isActorDump) {
        if (Offsets::GNames < 1 || Offsets::GWorld < 1) {
            printf("Please Enter Correct GName and GWorld Addresses!!\n");
            Usage();
            return -1;
        }
        DumpActors();
        cout << endl;
    }
    return 0;
}
