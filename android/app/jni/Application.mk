APP_ABI := armeabi-v7a arm64-v8a x86_64 #x86
APP_OPTIM := release
APP_PLATFORM := android-24
# GCC 4.9 Toolchain - requires NDK r10
NDK_TOOLCHAIN_VERSION = clang
#NDK_TOOLCHAIN_VERSION = 4.9
APP_CFLAGS += -Wno-unused-parameter #-Wall
APP_CPPFLAGS += -std=c++11 -fexceptions #-frtti -Werror,-Wunused-parameter
# GNU libc++ is the only Android STL which supports C++11 features
APP_STL := c++_static
#APP_BUILD_SCRIPT := jni/Android.mk
#APP_MODULES := libvipuser_jni
