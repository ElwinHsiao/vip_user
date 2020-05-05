{
  "targets": [
    {
      "target_name": "libvipuser_jni",
      "type": "shared_library",
      "dependencies": [
        "<(DJINNI_DIR)/support-lib/support_lib.gyp:djinni_jni",
      ],
      "ldflags": [ "-llog", "-Wl,--build-id,--gc-sections,--exclude-libs,ALL" ],
      "sources": [
        "../android/app/src/main/cpp/vipuser_client_jni.cpp",
        "../client/vipuser_client.cc",
        "<!@(python <(DJINNI_DIR)/example/glob.py generated/jni '*.cpp')",
        "<!@(python <(DJINNI_DIR)/example/glob.py generated/cpp '*.cpp')",
        "<!@(python <(DJINNI_DIR)/example/glob.py ../protos '*.cc')",
      ],
      "include_dirs": [
        "generated/jni",
        "generated/cpp",
        "../client",
        "../android/app/src/main/cpp",
      ],
    },
    {
      "target_name": "libvipuser_objc",
      "type": "static_library",
      "dependencies": [
        "<(DJINNI_DIR)/support-lib/support_lib.gyp:djinni_objc",
      ],
      "sources": [
        "../client/vipuser_client.cc",
        "<!@(python <(DJINNI_DIR)/example/glob.py generated/objc '*.cpp' '*.mm' '*.m')",
        "<!@(python <(DJINNI_DIR)/example/glob.py generated/cpp  '*.cpp')",
        "<!@(python <(DJINNI_DIR)/example/glob.py ../protos '*.cc')",
      ],
      "include_dirs": [
        "generated/objc",
        "generated/cpp",
        "../client",
      ],
    },
  ],
}
