#ifndef SDK_H
#define SDK_H

#include "StructsSDK.h"
#include "FNames.h"
#include "GUObjects.h"

using namespace std;

string resolveProp(list<kaddr> &recurrce, kaddr prop) {
    if (prop) {
        string cname = UObject::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty")
            || isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty")
            || isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);
            recurrce.push_back(propertyClass);
            return UObject::getName(propertyClass) + "*";
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);
            recurrce.push_back(metaClass);
            return "class " + UObject::getName(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);
            recurrce.push_back(interfaceClass);
            return "interface class" + UObject::getName(interfaceClass);
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);
            recurrce.push_back(Struct);
            return UObject::getName(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            return resolveProp(recurrce, UArrayProperty::getInner(prop)) + "[]";
        } else if (isEqual(cname, "SetProperty")) {
            return "<" + resolveProp(recurrce, USetProperty::getElementProp(prop)) + ">";
        } else if (isEqual(cname, "MapProperty")) {
            return "<" + resolveProp(recurrce, UMapProperty::getKeyProp(prop)) + "," +
                   resolveProp(recurrce, UMapProperty::getValueProp(prop)) + ">";
        } else if (isEqual(cname, "BoolProperty")) {
            return "bool";
        } else if (isEqual(cname, "ByteProperty")) {
            return "byte";
        } else if (isEqual(cname, "IntProperty")) {
            return "int";
        } else if (isEqual(cname, "Int8Property")) {
            return "int8";
        } else if (isEqual(cname, "Int16Property")) {
            return "int16";
        } else if (isEqual(cname, "Int64Property")) {
            return "int64";
        } else if (isEqual(cname, "UInt16Property")) {
            return "uint16";
        } else if (isEqual(cname, "UInt32Property")) {
            return "uint32";
        } else if (isEqual(cname, "UInt64Property")) {
            return "uint64";
        } else if (isEqual(cname, "DoubleProperty")) {
            return "double";
        } else if (isEqual(cname, "FloatProperty")) {
            return "float";
        } else if (isEqual(cname, "EnumProperty")) {
            return "enum";
        } else if (isEqual(cname, "StrProperty")) {
            return "FString";
        } else if (isEqual(cname, "TextProperty")) {
            return "FText";
        } else if (isEqual(cname, "NameProperty")) {
            return "FName";
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty")) {
            return "delegate";
        } else {
            return UObject::getName(prop) + "(" + cname + ")";
        }
    }
    return "NULL";
}

string resolveProp423(list<kaddr> &recurrce, kaddr prop) {
    if (prop) {
        string cname = FField::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty")
            || isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty")
            || isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);
            recurrce.push_back(propertyClass);
            return UObject::getName(propertyClass) + "*";
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);
            recurrce.push_back(metaClass);
            return "class " + UObject::getName(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);
            recurrce.push_back(interfaceClass);
            return "interface class" + UObject::getName(interfaceClass);
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);
            recurrce.push_back(Struct);
            return UObject::getName(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            return resolveProp423(recurrce, UArrayProperty::getInner(prop)) + "[]";
        } else if (isEqual(cname, "SetProperty")) {
            return "<" + resolveProp423(recurrce, USetProperty::getElementProp(prop)) + ">";
        } else if (isEqual(cname, "MapProperty")) {
            return "<" + resolveProp423(recurrce, UMapProperty::getKeyProp(prop)) + "," +
                   resolveProp423(recurrce, UMapProperty::getValueProp(prop)) + ">";
        } else if (isEqual(cname, "BoolProperty")) {
            return "bool";
        } else if (isEqual(cname, "ByteProperty")) {
            return "byte";
        } else if (isEqual(cname, "IntProperty")) {
            return "int";
        } else if (isEqual(cname, "Int8Property")) {
            return "int8";
        } else if (isEqual(cname, "Int16Property")) {
            return "int16";
        } else if (isEqual(cname, "Int64Property")) {
            return "int64";
        } else if (isEqual(cname, "UInt16Property")) {
            return "uint16";
        } else if (isEqual(cname, "UInt32Property")) {
            return "uint32";
        } else if (isEqual(cname, "UInt64Property")) {
            return "uint64";
        } else if (isEqual(cname, "DoubleProperty")) {
            return "double";
        } else if (isEqual(cname, "FloatProperty")) {
            return "float";
        } else if (isEqual(cname, "EnumProperty")) {
            return "enum";
        } else if (isEqual(cname, "StrProperty")) {
            return "FString";
        } else if (isEqual(cname, "TextProperty")) {
            return "FText";
        } else if (isEqual(cname, "NameProperty")) {
            return "FName";
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty")) {
            return "delegate";
        } else {
            return FField::getName(prop) + "(" + cname + ")";
        }
    }
    return "NULL";
}

//---------------------------------------------------------------------------------------------------------------------------//

uint32 classCount = 0;

string GetGNameFromID(kaddr gname, int32 nameId);
string GetActorNameFromGName(kaddr gname, kaddr actor);

// Export the RefSkeleton bone table from every loaded USkeletalMesh asset.
// FReferenceSkeleton starts with RawRefBoneInfo (a TArray<FMeshBoneInfo>).
void DumpRefSkeletons(const string &out) {
    ofstream bones(out + "/RefSkeleton.txt", ofstream::out | ofstream::trunc);
    if (!bones.is_open()) {
        cout << "Can't open RefSkeleton.txt" << endl;
        return;
    }

    bones << "# USkeletalMesh RefSkeleton bone indices\n";
    bones << "# Mesh | RefSkeleton offset | index | bone name | parent index\n";
    int meshCount = 0;
    int boneCount = 0;
    const kaddr pointerSize = Offsets::PointerSize;

    int32 objectCount = GetObjectCount();
    if (objectCount < 1 || objectCount > 999999) {
        bones << "# ERROR: invalid GUObjectArray count (" << objectCount
              << "). Check --guobj, --newue, and the game-specific offsets.\n";
        cout << "RefSkeleton dump skipped: invalid GUObjectArray count (" << objectCount << ")" << endl;
        return;
    }
    for (int32 i = 0; i < objectCount; ++i) {
        kaddr mesh = GetUObjectFromID(i);
        if (!UObject::isValid(mesh) || !isEqual(UObject::getClassName(mesh), "SkeletalMesh")) continue;

        kaddr meshClass = UObject::getClass(mesh);
        int32 refSkeletonOffset = -1;
        for (kaddr currentClass = meshClass; UObject::isValid(currentClass) && refSkeletonOffset < 0;
             currentClass = UStruct::getSuperClass(currentClass)) {
            kaddr property = isUE423 ? UStruct::getChildProperties(currentClass)
                                     : UStruct::getChildren(currentClass);
            while (property) {
                string propertyName = isUE423 ? FField::getName(property) : UObject::getName(property);
                if (isEqual(propertyName, "RefSkeleton")) {
                    refSkeletonOffset = UProperty::getOffset(property);
                    break;
                }
                property = isUE423 ? FField::getNext(property) : UField::getNext(property);
            }
        }

        string meshName = UObject::getName(mesh);
        if (refSkeletonOffset < 0 || pointerSize == 0) {
            bones << meshName << " | RefSkeleton offset unavailable\n";
            continue;
        }

        kaddr refSkeleton = mesh + static_cast<kaddr>(refSkeletonOffset);
        kaddr rawBoneInfo = getPtr(refSkeleton); // FReferenceSkeleton::RawRefBoneInfo
        int32 count = Read<int32>(refSkeleton + pointerSize);
        if (!rawBoneInfo || count < 0 || count > 512) {
            bones << meshName << " | RefSkeleton offset 0x" << hex << refSkeletonOffset << dec
                  << " | invalid RawRefBoneInfo (count=" << count << ")\n";
            continue;
        }

        ++meshCount;
        for (int32 boneIndex = 0; boneIndex < count; ++boneIndex) {
            // FMeshBoneInfo: FName (comparison index + number), then ParentIndex.
            kaddr info = rawBoneInfo + (static_cast<kaddr>(boneIndex) * 0x10);
            uint32 nameId = Read<uint32>(info);
            int32 parentIndex = Read<int32>(info + 0x8);
            bones << meshName << " | RefSkeleton+0x" << hex << refSkeletonOffset << dec
                  << " | " << boneIndex << " | " << GetFNameFromID(nameId)
                  << " | " << parentIndex << "\n";
            ++boneCount;
        }
    }

    bones.close();
    cout << meshCount << " SkeletalMesh assets, " << boneCount
         << " bones written to RefSkeleton.txt" << endl;
}

vector<kaddr> structAddressMap;
struct SDKPackageOutput {
    string classes;
    string structs;
    string parameters;
    string functions;
};
map<string, SDKPackageOutput> sdkPackageOutputs;

string sdkIdentifier(const string &value) {
    string result;
    result.reserve(value.size());
    for (unsigned char ch : value) {
        result.push_back(isalnum(ch) || ch == '_' ? static_cast<char>(ch) : '_');
    }
    if (result.empty() || isdigit(static_cast<unsigned char>(result[0]))) {
        result.insert(result.begin(), '_');
    }
    return result;
}

string sdkPackageIdentifier(const string &packageName) {
    size_t slash = packageName.find_last_of('/');
    string leaf = slash == string::npos ? packageName : packageName.substr(slash + 1);
    string slug = sdkIdentifier(leaf);
    if (slug.size() > 48) slug.resize(48);
    uint32 hash = 2166136261u;
    for (unsigned char ch : packageName) {
        hash = (hash ^ ch) * 16777619u;
    }
    ostringstream suffix;
    suffix << hex << setw(8) << setfill('0') << hash;
    return slug + "_" + suffix.str();
}

uint64 sdkHexValue(const string &line, const string &label) {
    size_t position = line.find(label);
    if (position == string::npos) return 0;
    position += label.size();
    if (line.compare(position, 2, "0x") == 0) position += 2;
    return strtoull(line.c_str() + position, nullptr, 16);
}

void addStructuredSDKClass(kaddr clazz, const string &classDump) {
    string packageName = "UnknownPackage";
    kaddr outer = UObject::getOuter(clazz);
    while (UObject::isValid(outer)) {
        packageName = UObject::getName(outer);
        outer = UObject::getOuter(outer);
    }

    string className = UObject::getName(clazz);
    if (className.empty()) return;
    string packageId = sdkPackageIdentifier(packageName);
    string classId = sdkIdentifier(className);
    SDKPackageOutput &package = sdkPackageOutputs[packageId];
    string reflectedType = UObject::getClassName(clazz);
    string &contents = isEqual(reflectedType, "ScriptStruct") || isEqual(reflectedType, "Enum")
                       ? package.structs : package.classes;
    contents += "// Class: " + packageName + "." + className + "\n";
    contents += "class " + classId + " {\npublic:\n";

    struct LayoutField { uint64 offset; uint64 size; string name; string description; };
    vector<LayoutField> fields;
    istringstream input(classDump);
    string line;
    while (getline(input, line)) {
        if (line.find("[Offset: 0x") == string::npos || line.find("Size: 0x") == string::npos)
            continue;
        uint64 offset = sdkHexValue(line, "[Offset: ");
        uint64 size = sdkHexValue(line, "Size: ");
        if (size == 0 || size > 0x1000000) continue;
        size_t semicolon = line.find(';');
        if (semicolon == string::npos) continue;
        string declaration = line.substr(0, semicolon);
        size_t end = declaration.find_last_not_of(" \t\r\n");
        if (end == string::npos) continue;
        size_t begin = declaration.find_last_of(" \t", end);
        string memberName = declaration.substr(begin == string::npos ? 0 : begin + 1,
                                               end - (begin == string::npos ? 0 : begin + 1) + 1);
        fields.push_back({offset, size, sdkIdentifier(memberName), line});
    }

    sort(fields.begin(), fields.end(), [](const LayoutField &left, const LayoutField &right) {
        return left.offset < right.offset;
    });
    uint64 cursor = 0;
    unsigned int paddingIndex = 0;
    for (const LayoutField &field : fields) {
        if (field.offset < cursor) {
            contents += "    // Overlapping field retained in SDK.txt: " + field.description + "\n";
            continue;
        }
        if (field.offset > cursor) {
            contents += "    uint8_t _pad_" + to_string(paddingIndex++) + "[0x";
            ostringstream number; number << hex << (field.offset - cursor);
            contents += number.str() + "];\n";
        }
        contents += "    uint8_t " + field.name + "[0x";
        ostringstream number; number << hex << field.size;
        contents += number.str() + "]; // " + field.description + "\n";
        cursor = field.offset + field.size;
    }
    for (istringstream functions(classDump); getline(functions, line);) {
        if (line.find("// 0x") != string::npos) contents += "    // " + line + "\n";
    }
    contents += "};\n\n";

    package.functions += "// " + packageName + "." + className + "\n";
    for (istringstream functions(classDump); getline(functions, line);) {
        if (line.find("// 0x") != string::npos) package.functions += "// " + line + "\n";
    }

    kaddr function = UStruct::getChildren(clazz);
    while (function) {
        string functionType = UObject::getClassName(function);
        if (isStartWith(functionType, "Function") || isEqual(functionType, "DelegateFunction")) {
            string functionName = UObject::getName(function);
            string paramsName = classId + "_" + sdkIdentifier(functionName) + "_" +
                                to_string(UObject::getIndex(function)) + "_Params";
            vector<LayoutField> params;
            kaddr param = isUE423 ? UStruct::getChildProperties(function) : UStruct::getChildren(function);
            while (param) {
                uint64 flags = UProperty::getPropertyFlags(param);
                if ((flags & 0x80) != 0) {
                    string paramName = isUE423 ? FField::getName(param) : UObject::getName(param);
                    int32 paramOffset = UProperty::getOffset(param);
                    int32 paramSize = UProperty::getElementSize(param);
                    if (paramOffset < 0 || paramSize <= 0 || paramSize > 0x1000000) {
                        param = isUE423 ? FField::getNext(param) : UField::getNext(param);
                        continue;
                    }
                    list<kaddr> dependencies;
                    ostringstream description;
                    description << (isUE423 ? resolveProp423(dependencies, param)
                                             : resolveProp(dependencies, param))
                                << " " << paramName << " [Offset: 0x" << hex
                                << paramOffset << ", Size: 0x"
                                << paramSize << "]";
                    params.push_back({static_cast<uint64>(paramOffset),
                                      static_cast<uint64>(paramSize),
                                      sdkIdentifier(paramName), description.str()});
                }
                param = isUE423 ? FField::getNext(param) : UField::getNext(param);
            }
            sort(params.begin(), params.end(), [](const LayoutField &left, const LayoutField &right) {
                return left.offset < right.offset;
            });
            package.parameters += "// Function " + packageName + "." + className + "." + functionName + "\n";
            package.parameters += "struct " + paramsName + " {\n";
            uint64 cursor = 0;
            unsigned int pad = 0;
            for (const LayoutField &field : params) {
                if (field.offset < cursor) {
                    package.parameters += "    // Overlapping parameter: " + field.description + "\n";
                    continue;
                }
                if (field.offset > cursor) {
                    ostringstream count; count << hex << (field.offset - cursor);
                    package.parameters += "    uint8_t _pad_" + to_string(pad++) + "[0x" + count.str() + "];\n";
                }
                ostringstream count; count << hex << field.size;
                package.parameters += "    uint8_t " + field.name + "[0x" + count.str() +"]; // "
                                      + field.description + "\n";
                cursor = field.offset + field.size;
            }
            package.parameters += "};\n\n";
        }
        function = UField::getNext(function);
    }
}

void writeStructuredSDK(const string &out) {
    if (sdkPackageOutputs.empty()) return;
    string directory = out + "/SDK";
    mkdir(directory.c_str(), 0777);
    ofstream index(out + "/SDK.hpp", ofstream::out | ofstream::trunc);
    if (!index.is_open()) {
        cout << "Can't write SDK.hpp" << endl;
        return;
    }
    ofstream basic(directory + "/Basic.hpp", ofstream::out | ofstream::trunc);
    basic << "#pragma once\n#include <cstdint>\n\nnamespace SDK {}\n";
    index << "#pragma once\n#include \"SDK/Basic.hpp\"\n\n";
    const char *categories[] = {"structs", "classes", "parameters"};
    for (const auto &entry : sdkPackageOutputs) {
        const string *contents[] = {&entry.second.structs, &entry.second.classes,
                                    &entry.second.parameters};
        for (size_t category = 0; category < 3; ++category) {
            string filename = entry.first + "_" + categories[category] + ".hpp";
            ofstream header(directory + "/" + filename, ofstream::out | ofstream::trunc);
            if (!header.is_open()) continue;
            header << "#pragma once\n#include \"Basic.hpp\"\n#pragma pack(push, 1)\n\n"
                   << "namespace SDK { namespace " << entry.first << " {\n\n"
                   << *contents[category] << "} }\n#pragma pack(pop)\n";
            index << "#include \"SDK/" << filename << "\"\n";
        }
        ofstream functions(directory + "/" + entry.first + "_functions.cpp",
                           ofstream::out | ofstream::trunc);
        if (functions.is_open()) {
            functions << "#include \"../SDK.hpp\"\n\n" << entry.second.functions;
        }
    }
    index << "\n";
}

bool isScanned(kaddr address) {
    for (kaddr scanned : structAddressMap) {
        if (scanned == address) { return true; }
    }
    return false;
}

list<kaddr> writeStructChild(ostream &sdk, kaddr childprop) {
    list<kaddr> recurrce;
    kaddr child = childprop;
    while (child) {
        kaddr prop = child;
        string oname = UObject::getName(prop);
        string cname = UObject::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty") ||
            isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty") ||
            isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);

            sdk << "\t" << UObject::getName(propertyClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(propertyClass);
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);

            sdk << "\tclass " << UObject::getName(metaClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);

            sdk << "\tinterface class " << UObject::getName(interfaceClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);

            sdk << "\t" << UObject::getName(Struct) << " " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            sdk << "\t" << resolveProp(recurrce, UArrayProperty::getInner(prop)) << "[] " << oname
                << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "SetProperty")) {
            sdk << "\t<" << resolveProp(recurrce, USetProperty::getElementProp(prop)) << "> "
                << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "MapProperty")) {
            sdk << "\t<" << resolveProp(recurrce, UMapProperty::getKeyProp(prop)) << ","
                << resolveProp(recurrce, UMapProperty::getValueProp(prop)) << "> " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "BoolProperty")) {
            sdk << "\tbool " << oname << ";"
                << setbase(10) << "//(ByteOffset: " << (int) UBoolProperty::getByteOffset(prop)
                << ", ByteMask: " << (int) UBoolProperty::getByteMask(prop)
                << ", FieldMask: " << (int) UBoolProperty::getFieldMask(prop) << ")"
                << "[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "ByteProperty")) {
            sdk << "\tbyte " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "IntProperty")) {
            sdk << "\tint " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int8Property")) {
            sdk << "\tint8 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int16Property")) {
            sdk << "\tint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int64Property")) {
            sdk << "\tint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt16Property")) {
            sdk << "\tuint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt32Property")) {
            sdk << "\tuint32 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt64Property")) {
            sdk << "\tuint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DoubleProperty")) {
            sdk << "\tdouble " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "FloatProperty")) {
            sdk << "\tfloat " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "EnumProperty")) {
            sdk << "\tenum " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StrProperty")) {
            sdk << "\tFString " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "TextProperty")) {
            sdk << "\tFText " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "NameProperty")) {
            sdk << "\tFName " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty") ||
                   isEqual(cname, "MulticastInlineDelegateProperty") ||
                   isEqual(cname, "MulticastSparseDelegateProperty")) {
            sdk << "\tdelegate " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "XigPtrProperty")) {
            sdk << "\tXigPtrProperty " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isStartWith(cname, "Function") || isEqual(cname, "DelegateFunction")) {
            string returnVal = "void";
            string params;

            kaddr funcParam = UStruct::getChildren(prop);
            while (funcParam) {
                uint64 PropertyFlags = UProperty::getPropertyFlags(funcParam);

                if ((PropertyFlags & 0x0000000000000400) == 0x0000000000000400) {
                    returnVal = resolveProp(recurrce, funcParam);
                } else {
                    if ((PropertyFlags & 0x0000000000000100) == 0x0000000000000100) {
                        params += "out ";
                    }
                    /*if((PropertyFlags & 0x0000000008000000) == 0x0000000008000000){
                        params += "ref ";
                    }*/
                    if ((PropertyFlags & 0x0000000000000002) == 0x0000000000000002) {
                        params += "const ";
                    }
                    params += resolveProp(recurrce, funcParam);
                    params += " ";
                    params += UObject::getName(funcParam);
                    params += ", ";
                }

                funcParam = UField::getNext(funcParam);
            }

            if (!params.empty()) {
                params.pop_back();
                params.pop_back();
            }

            sdk << "\t";

            int32 FunctionFlags = UFunction::getFunctionFlags(prop);

            if ((FunctionFlags & 0x00002000) == 0x00002000) {
                sdk << "static" << " ";
            }
            /*if((FunctionFlags & 0x00000001) == 0x00000001){
                sdk << "final" << " ";
            }
            if((FunctionFlags & 0x00020000) == 0x00020000){
                sdk << "public" << " ";
            }
            if((FunctionFlags & 0x00040000) == 0x00040000){
                sdk << "private" << " ";
            }
            if((FunctionFlags & 0x00080000) == 0x00080000){
                sdk << "protected" << " ";
            }*/

            sdk << returnVal << " " << oname << "(" << params << ");"
                << "// 0x" << setbase(16) << (UFunction::getFunc(prop) - libbase) << endl;
        } else {
            sdk << "\t" << cname << " " << oname << ";"
                << "//[Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        }

        child = UField::getNext(child);
    }
    return recurrce;
}

list<kaddr> writeStructChild423(ostream &sdk, kaddr childprop) {
    list<kaddr> recurrce;
    kaddr child = childprop;
    while (child) {
        kaddr prop = child;
        string oname = FField::getName(prop);
        string cname = FField::getClassName(prop);

        if (isEqual(cname, "ObjectProperty") || isEqual(cname, "WeakObjectProperty") ||
            isEqual(cname, "LazyObjectProperty") || isEqual(cname, "AssetObjectProperty") ||
            isEqual(cname, "SoftObjectProperty")) {
            kaddr propertyClass = UObjectProperty::getPropertyClass(prop);

            sdk << "\t" << UObject::getName(propertyClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(propertyClass);
        } else if (isEqual(cname, "ClassProperty") || isEqual(cname, "AssetClassProperty") ||
                   isEqual(cname, "SoftClassProperty")) {
            kaddr metaClass = UClassProperty::getMetaClass(prop);

            sdk << "\tclass " << UObject::getName(metaClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(metaClass);
        } else if (isEqual(cname, "InterfaceProperty")) {
            kaddr interfaceClass = UInterfaceProperty::getInterfaceClass(prop);

            sdk << "\tinterface class " << UObject::getName(interfaceClass) << "* " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StructProperty")) {
            kaddr Struct = UStructProperty::getStruct(prop);

            sdk << "\t" << UObject::getName(Struct) << " " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;

            recurrce.push_back(Struct);
        } else if (isEqual(cname, "ArrayProperty")) {
            sdk << "\t" << resolveProp423(recurrce, UArrayProperty::getInner(prop)) << "[] "
                << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "SetProperty")) {
            sdk << "\t<" << resolveProp423(recurrce, USetProperty::getElementProp(prop)) << "> "
                << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "MapProperty")) {
            sdk << "\t<" << resolveProp423(recurrce, UMapProperty::getKeyProp(prop)) << ","
                << resolveProp423(recurrce, UMapProperty::getValueProp(prop)) << "> " << oname
                << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "BoolProperty")) {
            sdk << "\tbool " << oname << ";"
                << setbase(10) << "//(ByteOffset: " << (int) UBoolProperty::getByteOffset(prop)
                << ", ByteMask: " << (int) UBoolProperty::getByteMask(prop)
                << ", FieldMask: " << (int) UBoolProperty::getFieldMask(prop) << ")"
                << "[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "ByteProperty")) {
            sdk << "\tbyte " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "IntProperty")) {
            sdk << "\tint " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int8Property")) {
            sdk << "\tint8 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int16Property")) {
            sdk << "\tint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "Int64Property")) {
            sdk << "\tint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt16Property")) {
            sdk << "\tuint16 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt32Property")) {
            sdk << "\tuint32 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "UInt64Property")) {
            sdk << "\tuint64 " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DoubleProperty")) {
            sdk << "\tdouble " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "FloatProperty")) {
            sdk << "\tfloat " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "EnumProperty")) {
            sdk << "\tenum " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "StrProperty")) {
            sdk << "\tFString " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "TextProperty")) {
            sdk << "\tFText " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "NameProperty")) {
            sdk << "\tFName " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "DelegateProperty") ||
                   isEqual(cname, "MulticastDelegateProperty") ||
                   isEqual(cname, "MulticastInlineDelegateProperty") ||
                   isEqual(cname, "MulticastSparseDelegateProperty")) {
            sdk << "\tdelegate " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else if (isEqual(cname, "XigPtrProperty")) {
            sdk << "\tXigPtrProperty " << oname << ";"
                << "//[Offset: 0x" << setbase(16) << UProperty::getOffset(prop) << ", "
                << "Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        } else {
            sdk << "\t" << cname << " " << oname << ";"
                << "//[Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        }

        child = FField::getNext(child);
    }
    return recurrce;
}

list<kaddr> writeStructChild423_Func(ostream &sdk, kaddr childprop) {
    list<kaddr> recurrce;
    kaddr child = childprop;
    while (child) {
        kaddr prop = child;
        string oname = UObject::getName(prop);
        string cname = UObject::getClassName(prop);

        if (isStartWith(cname, "Function") || isEqual(cname, "DelegateFunction")) {
            string returnVal = "void";
            string params;

            kaddr funcParam = UStruct::getChildProperties(prop);
            while (funcParam) {
                uint64 PropertyFlags = UProperty::getPropertyFlags(funcParam);

                if ((PropertyFlags & 0x0000000000000400) == 0x0000000000000400) {
                    returnVal = resolveProp423(recurrce, funcParam);
                } else {
                    if ((PropertyFlags & 0x0000000000000100) == 0x0000000000000100) {
                        params += "out ";
                    }
                    /*if((PropertyFlags & 0x0000000008000000) == 0x0000000008000000){
                        params += "ref ";
                    }*/
                    if ((PropertyFlags & 0x0000000000000002) == 0x0000000000000002) {
                        params += "const ";
                    }
                    params += resolveProp423(recurrce, funcParam);
                    params += " ";
                    params += FField::getName(funcParam);
                    params += ", ";
                }

                funcParam = FField::getNext(funcParam);
            }

            if (!params.empty()) {
                params.pop_back();
                params.pop_back();
            }

            sdk << "\t";

            int32 FunctionFlags = UFunction::getFunctionFlags(prop);

            if ((FunctionFlags & 0x00002000) == 0x00002000) {
                sdk << "static" << " ";
            }
            /*if((FunctionFlags & 0x00000001) == 0x00000001){
                sdk << "final" << " ";
            }
            if((FunctionFlags & 0x00020000) == 0x00020000){
                sdk << "public" << " ";
            }
            if((FunctionFlags & 0x00040000) == 0x00040000){
                sdk << "private" << " ";
            }
            if((FunctionFlags & 0x00080000) == 0x00080000){
                sdk << "protected" << " ";
            }*/

            sdk << returnVal << " " << oname << "(" << params << ");"
                << "// 0x" << setbase(16) << (UFunction::getFunc(prop) - libbase) << endl;
        } else {
            sdk << "\t" << cname << " " << oname << ";"
                << "//[Size: 0x" << setbase(16) << UProperty::getElementSize(prop) << "]" << endl;
        }

        child = UField::getNext(child);
    }
    return recurrce;
}

std::string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

void writeStruct(ofstream &sdk, kaddr clazz) {
    list<kaddr> recurrce;

    kaddr currStruct = clazz;
    while (UObject::isValid(currStruct)) {
        string name = UObject::getName(currStruct);
        if (isStartWith(name, "None") || isContain(name, "/Game/") || isContain(name, "_png") || name.empty()) {
            break;
        }

        uint32 NameID = UObject::getNameID(currStruct);
        if (!isScanned(currStruct)) {
            //Verbose Output
            if (isVerbose) {
                cout << "Obj: 0x" << std::hex << currStruct << std::dec << endl;
                cout << "Name: " << name << endl;
                cout << "NameID: 0x" << std::hex << NameID << std::dec << endl;
                cout << "Class: " << UStruct::getStructClassPath(currStruct) << endl;
                cout << endl;
            }

            //Dumping
            structAddressMap.push_back(currStruct);
            ostringstream classDump;
            classDump << "Class: " << UStruct::getStructClassPath(currStruct) << endl;
            if (isUE423) {
                recurrce.merge(writeStructChild423(classDump, UStruct::getChildProperties(currStruct)));
                recurrce.merge(writeStructChild423_Func(classDump, UStruct::getChildren(currStruct)));
            } else {
                recurrce.merge(writeStructChild(classDump, UStruct::getChildren(currStruct)));
            }
            classDump << "\n--------------------------------" << endl;
            sdk << classDump.str();
            addStructuredSDKClass(currStruct, classDump.str());
            classCount++;
        }

        currStruct = UStruct::getSuperClass(currStruct);
    }

    for (auto it = recurrce.begin(); it != recurrce.end(); ++it)
        writeStruct(sdk, *it);
}

void DumpSDK(const string& out) {
    classCount = 0;
    structAddressMap.clear();
    sdkPackageOutputs.clear();
    ofstream sdk(out + "/SDK.txt", ofstream::out);
    if (sdk.is_open()) {
        cout << "Dumping SDK List" << endl;
        clock_t begin = clock();
        int32 oCount = GetObjectCount();
        kaddr guobj = getRealOffset(Offsets::GUObjectArray);
        if (deRefGUObjectArray) {
            guobj = getPtr(guobj);
        }
        cout << "GUObjectArray: " << setbase(16) << guobj << endl;
        cout << "Objects Counts: " << setbase(10) << oCount << endl;
        if(oCount < 10 || oCount > 999999){
            oCount = 300000;
        }
        for (int32 i = 0; i < oCount; i++) {
            kaddr uobj = GetUObjectFromID(i);
            if (UObject::isValid(uobj)) {
                string objectType = UObject::getClassName(uobj);
                if (isEqual(objectType, "Class") || isEqual(objectType, "ScriptStruct") ||
                    isEqual(objectType, "Enum")) {
                    writeStruct(sdk, uobj);
                }
                writeStruct(sdk, UObject::getClass(uobj));
            }
        }
        sdk.close();
        writeStructuredSDK(out);
        DumpRefSkeletons(out);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << setbase(10) << classCount << " Items Dumped in SDK in " << elapsed_secs << "S" << endl;
    }
}

string GetTextFromGNameEntry(kaddr nameEntry) {
    if (!nameEntry) return "";
    char buffer[41] = {};
    char text[42] = {};
    if (!vm_readv(reinterpret_cast<void *>(nameEntry + 4 + Offsets::PointerSize),
                  reinterpret_cast<void *>(buffer), sizeof(buffer))) {
        return "";
    }
    int32 i = 0;
    for (; i < 41; ++i) {
        if (buffer[i] == '\0') break;
        text[i] = buffer[i];
        if (buffer[i] == 67 && i > 10) break;
    }
    text[(i + 1 < static_cast<int32>(sizeof(text))) ? i + 1 : static_cast<int32>(sizeof(text)) - 1] = '\0';
    return string(text);
}

string GetGNameFromID(kaddr gname, int32 nameId) {
    if (!gname) return "";
    if (nameId <= 0) return "";
    int32 page = nameId / 0x4000;
    int32 index = nameId % 0x4000;
    if (page < 0 || page >= 64) return "";

    kaddr chunk = getPtr(gname + (static_cast<kaddr>(page) * Offsets::PointerSize));
    if (!chunk) return "";
    kaddr nameEntry = getPtr(chunk + (static_cast<kaddr>(index) * Offsets::PointerSize));
    if (!nameEntry) return "";

    return GetTextFromGNameEntry(nameEntry);
}

string GetActorNameFromGName(kaddr gname, kaddr actor) {
    if (!actor) return "";
    int32 nameId = Read<int32>(actor + 8 + (2 * Offsets::PointerSize));
    return GetGNameFromID(gname, nameId);
}

string ReadFStringUTF16(kaddr address) {
#if defined(__LP64__)
    const kaddr minimumUserAddress = 0x100000000ULL;
    const kaddr maximumUserAddress = 0x800000000000ULL;
#else
    const kaddr minimumUserAddress = 0x10000000;
    const kaddr maximumUserAddress = 0xF0000000;
#endif
    if (address < minimumUserAddress || address >= maximumUserAddress) return "";
    kaddr data = getPtr(address);
    int32 length = Read<int32>(address + Offsets::PointerSize);
    if (data < minimumUserAddress || data >= maximumUserAddress || length < 1 || length > 128) return "";
    if (Read<UTF16>(data + (static_cast<kaddr>(length - 1) * sizeof(UTF16))) == 0) --length;
    if (length <= 0) return "";

    vector<UTF16> units(static_cast<size_t>(length));
    if (!vm_readv(reinterpret_cast<void *>(data), units.data(), units.size() * sizeof(UTF16))) return "";

    string result;
    for (int32 i = 0; i < length; ++i) {
        uint32 codepoint = units[i];
        if (codepoint >= 0xD800 && codepoint <= 0xDBFF && i + 1 < length &&
            units[i + 1] >= 0xDC00 && units[i + 1] <= 0xDFFF) {
            codepoint = 0x10000 + ((codepoint - 0xD800) << 10) + (units[++i] - 0xDC00);
        }
        if (codepoint <= 0x7F) {
            result.push_back(static_cast<char>(codepoint));
        } else if (codepoint <= 0x7FF) {
            result.push_back(static_cast<char>(0xC0 | (codepoint >> 6)));
            result.push_back(static_cast<char>(0x80 | (codepoint & 0x3F)));
        } else if (codepoint <= 0xFFFF) {
            result.push_back(static_cast<char>(0xE0 | (codepoint >> 12)));
            result.push_back(static_cast<char>(0x80 | ((codepoint >> 6) & 0x3F)));
            result.push_back(static_cast<char>(0x80 | (codepoint & 0x3F)));
        } else {
            result.push_back(static_cast<char>(0xF0 | (codepoint >> 18)));
            result.push_back(static_cast<char>(0x80 | ((codepoint >> 12) & 0x3F)));
            result.push_back(static_cast<char>(0x80 | ((codepoint >> 6) & 0x3F)));
            result.push_back(static_cast<char>(0x80 | (codepoint & 0x3F)));
        }
    }
    return result;
}

struct BoneInfoArray {
    kaddr data = 0;
    int32 count = 0;
    int32 objectOffset = -1;
};

// RefSkeleton is a native USkeletalMesh member on some builds rather than a
// reflected property. Locate its TArray<FMeshBoneInfo> by validating names and
// parent indices in the candidate array entries.
BoneInfoArray FindRawBoneInfoArray(kaddr skeletalMeshAsset, kaddr gname) {
    BoneInfoArray best;
    int bestScore = 0;
#if defined(__LP64__)
    const kaddr minAddress = 0x100000000ULL;
    const kaddr maxAddress = 0x800000000000ULL;
#else
    const kaddr minAddress = 0x10000000;
    const kaddr maxAddress = 0xF0000000;
#endif

    for (int32 offset = Offsets::BoneInfoScanStart; offset < Offsets::BoneInfoScanEnd;
         offset += Offsets::BoneInfoScanStep) {
        kaddr array = skeletalMeshAsset + offset;
        kaddr data = getPtr(array);
        int32 count = Read<int32>(array + 8);
        int32 capacity = Read<int32>(array + 12);
        if (data < minAddress || data >= maxAddress || count < 16 || count > 512 ||
            capacity < count || capacity > 512) continue;

        int validNames = 0;
        int validParents = 0;
        int inspected = count < 16 ? count : 16;
        for (int32 i = 0; i < inspected; ++i) {
            kaddr info = data + (static_cast<kaddr>(i) * Offsets::BoneInfoEntrySize);
            int32 nameId = Read<int32>(info);
            int32 parentIndex = Read<int32>(info + Offsets::BoneInfoParentIndexOffset);
            if (parentIndex == -1 || (parentIndex >= 0 && parentIndex < count)) ++validParents;
            if (nameId > 0 && !GetGNameFromID(gname, nameId).empty()) ++validNames;
        }

        int score = validNames * 4 + validParents;
        if (validNames >= 4 && validParents >= inspected - 2 && score > bestScore) {
            best.data = data;
            best.count = count;
            best.objectOffset = offset;
            bestScore = score;
        }
    }
    return best;
}

// Export runtime component-space bone transform addresses for verified player actors.
int32 DumpBoneTransformAddresses(kaddr actor, const string &actorName, const string &playerName,
                                 kaddr gname, ofstream &bones) {
#if defined(__LP64__)
    const kaddr minimumUserAddress = 0x100000000ULL;
    const kaddr maximumUserAddress = 0x800000000000;
#else
    const kaddr minimumUserAddress = 0x10000000;
    const kaddr maximumUserAddress = 0xF0000000;
#endif

    if (actor < minimumUserAddress) return 0;
    kaddr mesh = getPtr(actor + Offsets::BoneActorToMesh);
    if (mesh < minimumUserAddress || mesh >= maximumUserAddress) return 0;

    kaddr masterPose = getPtr(mesh + Offsets::BoneMeshToMasterPose);
    bool validMasterPose = masterPose >= minimumUserAddress && masterPose < maximumUserAddress;
    kaddr poseMesh = validMasterPose ? masterPose : mesh;
    kaddr transformArray = poseMesh + Offsets::BoneMeshToCachedComponentSpaceTransforms;
    kaddr transforms = getPtr(transformArray);
    int32 transformCount = Read<int32>(transformArray + Offsets::PointerSize);
    int32 transformMax = Read<int32>(transformArray + Offsets::PointerSize + sizeof(int32));
    // Some target components report Num=0 while retaining an allocated,
    // initialized component-space transform buffer. Use its bounded capacity.
    if (transformCount == 0 && transformMax > 0 && transformMax <= 512) {
        transformCount = transformMax;
    }
    if (transforms < minimumUserAddress || transforms >= maximumUserAddress ||
        transformCount < 1 || transformCount > 512) return 0;

    kaddr skeletalMeshAsset = getPtr(poseMesh + Offsets::BoneMeshToSkeletalMesh);
    kaddr skeleton = skeletalMeshAsset >= minimumUserAddress && skeletalMeshAsset < maximumUserAddress
                         ? getPtr(skeletalMeshAsset + Offsets::BoneSkeletalMeshToSkeleton)
                         : 0;
    kaddr boneTreeArray = skeleton >= minimumUserAddress && skeleton < maximumUserAddress
                              ? skeleton + Offsets::BoneSkeletonToBoneTree
                              : 0;
    kaddr boneTree = boneTreeArray ? getPtr(boneTreeArray) : 0;
    int32 boneNameCount = boneTreeArray ? Read<int32>(boneTreeArray + Offsets::PointerSize) : 0;
    if (!boneTree || boneNameCount < 1 || boneNameCount > 512) {
        boneTree = 0;
        boneNameCount = 0;
    }

    BoneInfoArray rawBoneInfo;
    if (skeletalMeshAsset >= minimumUserAddress && skeletalMeshAsset < maximumUserAddress) {
        rawBoneInfo = FindRawBoneInfoArray(skeletalMeshAsset, gname);
    }

    for (int32 boneIndex = 0; boneIndex < transformCount; ++boneIndex) {
        kaddr transformAddress = transforms +
                                 (static_cast<kaddr>(boneIndex) * Offsets::BoneFTransformSize);
        string boneName;
        if (boneTree && boneIndex < boneNameCount) {
            kaddr boneNode = boneTree +
                             (static_cast<kaddr>(boneIndex) * Offsets::BoneTreeEntrySize);
            boneName = GetGNameFromID(gname, Read<int32>(boneNode));
        }
        if (boneName.empty() && rawBoneInfo.data && boneIndex < rawBoneInfo.count) {
            kaddr info = rawBoneInfo.data +
                         (static_cast<kaddr>(boneIndex) * Offsets::BoneInfoEntrySize);
            boneName = GetGNameFromID(gname, Read<int32>(info));
        }
        if (boneName.empty()) boneName = "Unknown_" + to_string(boneIndex);
        bones << actorName << " | " << playerName << " | " << boneIndex << " | " << boneName
              << " | 0x" << hex << transformAddress << dec << "\n";
    }
    return transformCount;
}

// ComponentToWorld is not a reflected UProperty in many UE4 builds, so it is
// absent from SDK.txt. Collect plausible live FTransform layouts from several
// player mesh objects and report offsets that recur across those objects.
bool GetComponentToWorldLayoutCandidate(const string &sdkPath, kaddr &candidateOffset,
                                        kaddr &relativeScaleOffset, kaddr &relativeScaleSize) {
    ifstream sdk(sdkPath.c_str());
    if (!sdk.is_open()) return false;
    bool inSceneComponent = false;
    string line;
    while (getline(sdk, line)) {
        if (line.find("Class: ") == 0) {
            inSceneComponent = line.find("Class: SceneComponent.") == 0;
            continue;
        }
        if (!inSceneComponent || line.find("RelativeScale3D;") == string::npos) continue;
        size_t offsetMarker = line.find("Offset: 0x");
        size_t sizeMarker = line.find(", Size: 0x");
        if (offsetMarker == string::npos || sizeMarker == string::npos) return false;
        const char *offsetText = line.c_str() + offsetMarker + 10;
        const char *sizeText = line.c_str() + sizeMarker + 10;
        relativeScaleOffset = static_cast<kaddr>(strtoull(offsetText, nullptr, 16));
        relativeScaleSize = static_cast<kaddr>(strtoull(sizeText, nullptr, 16));
        candidateOffset = (relativeScaleOffset + relativeScaleSize + 0xF) & ~static_cast<kaddr>(0xF);
        return relativeScaleSize != 0;
    }
    // The current PUBG SDK dump can omit classes when UObject name validation
    // fails during --sdkw. Keep its reflected SceneComponent anchor as fallback.
    if (pkg == "com.pubg.imobile") {
        relativeScaleOffset = 0x1FC; // sdk/SDK.txt: SceneComponent::RelativeScale3D
        relativeScaleSize = 0x0C;
        candidateOffset = (relativeScaleOffset + relativeScaleSize + 0xF) & ~static_cast<kaddr>(0xF);
        return true;
    }
    return false;
}

void CollectComponentToWorldCandidates(kaddr mesh, const string &actorName,
                                      const char *componentKind, map<kaddr, int> &candidateHits,
                                      ofstream &details) {
#if defined(__LP64__)
    const kaddr minimumUserAddress = 0x100000000ULL;
    const kaddr maximumUserAddress = 0x800000000000;
#else
    const kaddr minimumUserAddress = 0x10000000;
    const kaddr maximumUserAddress = 0xF0000000;
#endif
    if (mesh < minimumUserAddress || mesh >= maximumUserAddress) return;

    struct alignas(16) MeshProbe {
        uint8 bytes[0x1030];
    };
    MeshProbe sample = Read<MeshProbe>(mesh);

    // UE FTransform memory is quaternion, translation, then scale.
    for (kaddr offset = 0x100; offset <= 0x1000; offset += 4) {
        if (mesh + offset + 0x30 >= maximumUserAddress) break;
        const float *values = reinterpret_cast<const float *>(sample.bytes + offset);
        float quatLength = values[0] * values[0] + values[1] * values[1] +
                           values[2] * values[2] + values[3] * values[3];
        bool plausible = isfinite(quatLength) && quatLength > 0.80f && quatLength < 1.20f;
        for (int i = 4; i <= 10 && plausible; ++i) plausible = isfinite(values[i]);
        for (int i = 4; i <= 6 && plausible; ++i) {
            if (fabsf(values[i]) > 10000000.0f) plausible = false;
        }
        for (int i = 8; i <= 10 && plausible; ++i) {
            if (fabsf(values[i]) < 0.01f || fabsf(values[i]) > 100.0f) plausible = false;
        }
        if (plausible) {
            ++candidateHits[offset];
            details << actorName << " | " << componentKind << " | 0x" << hex << mesh
                    << " | 0x" << offset << dec
                    << " | translation " << values[4] << ", " << values[5] << ", " << values[6]
                    << " | scale " << values[8] << ", " << values[9] << ", " << values[10]
                    << " | quatNorm2 " << quatLength << "\n";
        }
    }
}

// PUBG actor-array pointer decryption layout supplied for this build.
struct EncryptedActors {
    uint64 Enc_1, Enc_2, Enc_3, Enc_4;
};

struct ActorArrayChunk {
    uint8 val_1, val_2, val_3, val_4;
    uint8 val_5, val_6, val_7, val_8;
};

kaddr DecryptActorsArray(kaddr level, int actorsOffset, int encryptedActorsOffset) {
    if (level < 0x10000000) return 0;

    if (Read<uint64>(level + actorsOffset) > 0) return level + actorsOffset;
    if (Read<uint64>(level + encryptedActorsOffset) > 0) return level + encryptedActorsOffset;

    EncryptedActors actors = Read<EncryptedActors>(level + encryptedActorsOffset + 0x10);
    if (actors.Enc_1 > 0) {
        ActorArrayChunk enc = Read<ActorArrayChunk>(actors.Enc_1 + 0x80);
        uint64 low24 = (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_1)) |
                        (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_2)) << 8) |
                        (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_3)) << 0x10)) &
                       0xFFFFFFULL;
        uint64 low40 = (low24 |
                        (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_4)) << 0x18) |
                        (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_5)) << 0x20)) &
                       0xFFFF00FFFFFFFFFFULL;
        return low40 |
               (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_6)) << 0x28) |
               (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_7)) << 0x30) |
               (static_cast<uint64>(Read<uint8>(actors.Enc_1 + enc.val_8)) << 0x38);
    }
    if (actors.Enc_2 > 0) {
        uint64 lostActors = Read<uint64>(actors.Enc_2);
        if (lostActors > 0) {
            return ((uint16)(lostActors - 0x400) & 0xFF00) |
                   ((uint8)(lostActors - 0x04)) |
                   ((lostActors + 0xFC0000) & 0xFF0000) |
                   ((lostActors - 0x4000000) & 0xFF000000) |
                   ((lostActors + 0xFC00000000) & 0xFF00000000) |
                   ((lostActors + 0xFC0000000000) & 0xFF0000000000) |
                   ((lostActors + 0xFC000000000000) & 0xFF000000000000) |
                   ((lostActors - 0x400000000000000) & 0xFF00000000000000);
        }
    }
    if (actors.Enc_3 > 0) {
        uint64 lostActors = Read<uint64>(actors.Enc_3);
        if (lostActors > 0) return (lostActors >> 0x38) | (lostActors << (64 - 0x38));
    }
    if (actors.Enc_4 > 0) {
        uint64 lostActors = Read<uint64>(actors.Enc_4);
        if (lostActors > 0) return lostActors ^ 0xCDCD00;
    }
    return 0;
}

kaddr getEntityAddr(kaddr base, kaddr &level) {
    level = getPtr(getPtr(getPtr(getPtr(base + Offsets::GWorld) + 0x810) + 0x78) + 0x30);
    cout << "Resolved Level: 0x" << hex << level << dec << endl;
    return DecryptActorsArray(level, 0xA0, 0x448);
}

void TestDump(kaddr uobj);

void DumpSDKW(const string& out) {
    classCount = 0;
    structAddressMap.clear();
    sdkPackageOutputs.clear();
    ofstream sdk(out + "/SDK.txt", ofstream::out);
    ofstream boneAddresses(out + "/BoneTransformAddresses.txt", ofstream::out | ofstream::trunc);
    ofstream componentCandidates(out + "/ComponentToWorldCandidates.txt", ofstream::out | ofstream::trunc);
    map<kaddr, int> componentCandidateHits;
    int componentObjectsScanned = 0;
    kaddr layoutCandidateOffset = 0;
    kaddr relativeScaleOffset = 0;
    kaddr relativeScaleSize = 0;
    bool layoutCandidateFound = false;
    if (componentCandidates.is_open()) {
        componentCandidates << "# Plausible runtime FTransform values from player mesh memory\n"
                            << "# Candidate values are heuristic; compare translations with known live world positions.\n"
                            << "# Actor | component kind | component address | candidate offset | translation | scale | quatNorm2\n";
    }
    if (boneAddresses.is_open()) {
        boneAddresses << "# Actor class | player name | bone index | bone name | runtime FTransform address\n";
    }
    if (sdk.is_open()) {
        cout << "Dumping SDK List" << endl;
        clock_t begin = clock();
        kaddr gworld = getPtr(UWorld::getGWorld());
        cout << "UWorld: " << setbase(16) << gworld << setbase(10) << " | Name: "
             << UObject::getName(gworld) << endl;
        // A UObject name/class check can fail for a valid world when the
        // game's UObject offsets differ. Continue from the world pointer and
        // validate the level/actor array before walking it.
        if (gworld) {
            kaddr worldClass = UObject::getClass(gworld);
            if (UObject::isValid(worldClass)) writeStruct(sdk, worldClass);

            kaddr level = 0;
            kaddr actorArray = getEntityAddr(libbase, level);
            kaddr actorList = actorArray ? getPtr(actorArray) : 0;
            int32 actorsCount = actorArray ? Read<int32>(actorArray + Offsets::PointerSize) : 0;
            // Match the game's chain: gnameGlobal = *(base + GNames),
            // then gname = *(gnameGlobal + GNamesAdjustment).
            kaddr gnameGlobal = getPtr(getRealOffset(Offsets::GNames));
            kaddr gname = gnameGlobal
                              ? getPtr(gnameGlobal + Offsets::GNamesAdjustment)
                              : 0;
            cout << "PersistentLevel: " << setbase(16) << level
                 << " | ActorArray: " << actorArray << " | ActorData: " << actorList
                 << setbase(10) << " | ActorCount: " << actorsCount
                 << " | GNameGlobal: 0x" << setbase(16) << gnameGlobal
                 << " | GNameRoot: 0x" << gname << setbase(10) << endl;

            if (level && actorList && actorsCount > 0 && actorsCount <= 100000) {
                int32 actorPointersFound = 0;
                int32 namedActors = 0;
                int32 playerActorsFound = 0;
                int32 botPlayersFound = 0;
                int32 realPlayersFound = 0;
                int32 unknownPlayerType = 0;
                int32 actorsWithBones = 0;
                int32 boneTransformsWritten = 0;
                for (int32 i = 0; i < actorsCount; ++i) {
                    kaddr actor = getPtr(actorList + (static_cast<kaddr>(i) * Offsets::PointerSize));
                    if (actor >= 0x10000000) {
                        ++actorPointersFound;
                        string actorName = GetActorNameFromGName(gname, actor);
                        if (!actorName.empty()) ++namedActors;
                        bool isPlayer = actorName.find("BP_PlayerPawn") != string::npos ||
                                        actorName.find("BP_PlayerCharacter") != string::npos ||
                                        actorName.find("BP_CharacterModelTaget") != string::npos;
                        if (!isPlayer) continue;
                        ++playerActorsFound;
                        kaddr playerState = getPtr(actor + Offsets::BoneActorToPlayerState);
                        string playerStateClass;
                        if (playerState >= 0x10000000) {
                            kaddr playerStateClassObject = UObject::getClass(playerState);
                            playerStateClass = playerStateClassObject
                                                   ? GetActorNameFromGName(gname, playerStateClassObject)
                                                   : "";
                        }
                        bool validPlayerState = playerState >= 0x10000000 &&
                                                playerStateClass.find("PlayerState") != string::npos;
                        bool actorClassSaysAI = actorName.find("PlayerPawn") != string::npos &&
                                                actorName.find("AI") != string::npos;
                        kaddr ownerActor = actorName.find("BP_CharacterModelTaget") != string::npos
                                               ? getPtr(actor + Offsets::ActorToOwner)
                                               : 0;
                        kaddr ownerClassObject = ownerActor >= 0x10000000
                                                     ? UObject::getClass(ownerActor)
                                                     : 0;
                        string ownerClassName = ownerClassObject
                                                    ? GetActorNameFromGName(gname, ownerClassObject)
                                                    : "";
                        bool ownerClassSaysAI = ownerClassName.find("PlayerPawn") != string::npos &&
                                                ownerClassName.find("AI") != string::npos;
                        bool isBot = false;
                        bool isRealPlayer = false;
                        if (actorClassSaysAI || ownerClassSaysAI) {
                            ++botPlayersFound;
                            isBot = true;
                        } else if (validPlayerState) {
                            uint8 botFlags = Read<uint8>(playerState + Offsets::PlayerStateToIsBot);
                            if ((botFlags & Offsets::PlayerStateIsBotMask) != 0) {
                                ++botPlayersFound;
                                isBot = true;
                            } else {
                                ++realPlayersFound;
                                isRealPlayer = true;
                            }
                        } else {
                            ++unknownPlayerType;
                        }
                        cout << "GName player actor: " << actorName
                             << " | PlayerState class: "
                             << (playerStateClass.empty() ? "unresolved" : playerStateClass)
                             << " | Owner class: "
                             << (ownerClassName.empty() ? "unresolved" : ownerClassName)
                             << " | Classification: "
                             << (isBot ? "bot" : (isRealPlayer ? "real" : "unknown"))
                             << endl;
                        string playerName = playerState
                                                ? ReadFStringUTF16(playerState + Offsets::BonePlayerStateToPlayerName)
                                                : "";
                        if (playerName.empty()) {
                            string actorLabel = ReadFStringUTF16(actor + Offsets::BoneActorToDisplayPlayerName);
                            if (!actorLabel.empty() && actorLabel != "ModelTarget") playerName = actorLabel;
                        }
                        if (playerName.empty()) {
                            int32 objectNumber = Read<int32>(actor + 8 + (2 * Offsets::PointerSize) + 4);
                            // The actor's +0x960 FString is often the generic "ModelTarget"
                            // label. Prefer a unique actor identity when PlayerState has no name.
                            playerName = "PlayerActor_" + to_string(objectNumber > 0 ? objectNumber - 1 : 0);
                        }

                        kaddr actorClass = UObject::getClass(actor);
                        if (UObject::isValid(actorClass)) writeStruct(sdk, actorClass);
                        kaddr mesh = getPtr(actor + Offsets::BoneActorToMesh);
                        if (componentObjectsScanned < 128 && mesh) {
                            CollectComponentToWorldCandidates(mesh, actorName, "Mesh",
                                                              componentCandidateHits, componentCandidates);
                            ++componentObjectsScanned;
                            // Actor::RootComponent is 0x208 in the active SDK dump.
                            // Comparing root and mesh world positions helps disambiguate
                            // transform-shaped fields that pass the layout heuristic.
                            kaddr rootComponent = getPtr(actor + 0x208);
                            if (rootComponent >= 0x10000000) {
                                CollectComponentToWorldCandidates(rootComponent, actorName, "Root",
                                                                  componentCandidateHits, componentCandidates);
                                ++componentObjectsScanned;
                            }
                        }
                        if (boneAddresses.is_open()) {
                            int32 written = DumpBoneTransformAddresses(actor, actorName, playerName,
                                                                       gname, boneAddresses);
                            if (written > 0) {
                                ++actorsWithBones;
                                boneTransformsWritten += written;
                            }
                        }
                    }
                }
                cout << "Actor pointers accepted: " << actorPointersFound
                     << " | Named actors: " << namedActors
                     << " | Player-name matches: " << playerActorsFound
                     << " | Bots (PlayerState::bIsABot): " << botPlayersFound
                     << " | Real players: " << realPlayersFound
                     << " | Unknown player type: " << unknownPlayerType
                     << " | Actors with bone transforms: " << actorsWithBones
                     << " | Bone transforms written: " << boneTransformsWritten << endl;
            } else {
                cout << "Actor traversal skipped: invalid level/actor array or count." << endl;
            }
        } else {
            cout << "Actor traversal skipped: GWorld pointer resolved to null." << endl;
        }
        sdk.close();
        if (boneAddresses.is_open()) boneAddresses.close();
        layoutCandidateFound = GetComponentToWorldLayoutCandidate(
            out + "/SDK.txt", layoutCandidateOffset, relativeScaleOffset, relativeScaleSize);
        if (componentCandidates.is_open()) {
            componentCandidates << "\n# Repeated offsets summary\n"
                                << "# Candidate offset | matching components | scanned components\n";
            for (const auto &candidate : componentCandidateHits) {
                if (candidate.second >= 2) {
                    componentCandidates << "0x" << hex << candidate.first << dec << " | "
                                        << candidate.second << " | " << componentObjectsScanned << "\n";
                }
            }
            if (layoutCandidateFound) {
                componentCandidates << "# RelativeScale3D ends at 0x" << hex
                                    << (relativeScaleOffset + relativeScaleSize)
                                    << "; 16-byte aligned slot: 0x" << layoutCandidateOffset << dec << "\n";
                auto match = componentCandidateHits.find(layoutCandidateOffset);
                if (match != componentCandidateHits.end() && match->second >= 4) {
                    componentCandidates << "RUNTIME-VERIFIED ComponentToWorld offset: 0x"
                                        << hex << layoutCandidateOffset << dec << " ("
                                        << match->second << " matching live components)\n";
                } else {
                    componentCandidates << "No runtime FTransform match at the layout-derived offset.\n";
                }
            } else {
                componentCandidates << "Could not derive the ComponentToWorld slot from SceneComponent::RelativeScale3D.\n";
            }
            componentCandidates.close();
        }
        writeStructuredSDK(out);
        DumpRefSkeletons(out);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << classCount << " Items Dumped in SDK in " << elapsed_secs << "S" << endl;
    }
}

void TestDump(kaddr uobj) {
    cout << "Obj: " << setbase(16) << uobj << endl;
    cout << "Name: " << UObject::getName(uobj) << endl;
    cout << "Class: " << UObject::getName(UObject::getClass(uobj)) << endl;
    cout << "Outer: " << UObject::getName(UObject::getOuter(uobj)) << endl;
    cout << "ClassPath: " << UStruct::getClassPath(uobj) << endl;

    // HexDump(uobj, 40);printf("\n\n");

    kaddr clazz = UObject::getClass(uobj);

    // HexDump(clazz, 50);printf("\n\n");

    if (isUE423) {
        //Props
        kaddr child = UStruct::getChildProperties(clazz);
        while (child) {
            cout << setbase(16) << "0x" << child << " - " << FField::getName(child) << " - "
                 << FField::getClassName(child) << " - 0x" << UProperty::getOffset(child) << " - 0x"
                 << setbase(16) << UProperty::getArrayDim(child) << " - 0x" << UProperty::getElementSize(child) << ";" << endl;

            //HexDump(child, 40);

            child = FField::getNext(child);
        }

        //Functions
        child = UStruct::getChildren(clazz);
        while (child) {
            cout << setbase(16) << "0x" << child << " - " << UObject::getName(child) << " - "
                 << UObject::getClassName(child) <<
                 " - 0x" << UFunction::getFunc(child) - libbase << ";" << endl;

            //HexDump(child, 40);

            kaddr funcParam = UStruct::getChildProperties(child);
            while (funcParam) {
                cout << "\t" << setbase(16) << "0x" << child << " - " << FField::getName(funcParam) << " - "
                     << FField::getClassName(funcParam) << " - 0x" << UProperty::getOffset(funcParam) << " - 0x"
                     << setbase(16) << UProperty::getArrayDim(funcParam) << " - 0x" << UProperty::getElementSize(funcParam) << ";" << endl;

                funcParam = FField::getNext(funcParam);
            }

            child = UField::getNext(child);
        }
    } else {
        kaddr child = UStruct::getChildren(clazz);
        while (child) {
            cout << setbase(16) << "0x" << child << " - " << UObject::getName(child) << " - "
                 << UObject::getClassName(child) << ";" << endl;

            //HexDump(child, 30);

            child = UField::getNext(child);
        }
    }
}

void DumpActors() {
    ///Dump All Actors
    kaddr gworld = UWorld::getGWorld();
    kaddr world = getPtr(gworld);

    // kaddr vtable = getPtr(world);
    //
    // for(kaddr i = 0; i < 0x100; i++){
    //     kaddr fnAddr = getPtr(vtable + (i * Offsets::PointerSize)) - libbase;
    //     printf("VTable[0x%lx]: 0x%lx\n", i, fnAddr);
    // }

    // TestDump(world);

    cout << "UWorld: " << setbase(16) << gworld << " | World: " << world << " | Name: "
         << UObject::getName(world) << endl;

    // HexDump(world, 40, 0x0);

    kaddr level = getPtr(world + Offsets::UWorldToPersistentLevel);
    cout << "Level: " << setbase(16) << level << " | Name: " << UObject::getName(level) << endl;

    //HexDump(level + 0x90, 60, 0x90);

    kaddr actorList = getPtr(level + Offsets::ULevelToAActors);
    int actorsCount = Read<int>(level + Offsets::ULevelToAActorsCount);
    cout << "ActorList: " << setbase(16) << actorList << ", ActorCount: " << setbase(10)
         << actorsCount << "\n" << endl;

    for (int i = 0; i < actorsCount; i++) {
        kaddr actor = getPtr(actorList + (i * sizeof(kaddr)));
        if (UObject::isValid(actor)) {
            cout << "Id: " << setbase(10) << i << ", Addr: " << setbase(16) << actor << ", Actor: "
                 << UObject::getName(actor) << endl;
        } else {
            cout << "Id: " << setbase(10) << i << ", Addr: " << setbase(16) << actor << endl;
        }
    }
}

#endif
