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
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << setbase(10) << classCount << " Items Dumped in SDK in " << elapsed_secs << "S" << endl;
    }
}

void TestDump(kaddr uobj);

void DumpSDKW(const string& out) {
    classCount = 0;
    structAddressMap.clear();
    sdkPackageOutputs.clear();
    ofstream sdk(out + "/SDK.txt", ofstream::out);
    if (sdk.is_open()) {
        cout << "Dumping SDK List" << endl;
        clock_t begin = clock();
        kaddr gworld = getPtr(UWorld::getGWorld());
        cout << "UWorld: " << setbase(16) << gworld << setbase(10) << " | Name: "
             << UObject::getName(gworld) << endl;
        if (UObject::isValid(gworld)) {
            //Iterate World
            writeStruct(sdk, UObject::getClass(gworld));
            //Iterate Entities
            kaddr level = getPtr(gworld + Offsets::UWorldToPersistentLevel);
            kaddr actorList = getPtr(level + Offsets::ULevelToAActors);
            int actorsCount = Read<int>(level + Offsets::ULevelToAActorsCount);
            for (int i = 0; i < actorsCount; i++) {
                kaddr actor = getPtr(actorList + (i * Offsets::PointerSize));
                if (UObject::isValid(actor)) {
                    writeStruct(sdk, UObject::getClass(actor));
                }
            }
        }
        sdk.close();
        writeStructuredSDK(out);
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
