APP_ABI := all
APP_OPTIM := release
APP_PLATFORM := android-24
# GCC 4.9 Toolchain - requires NDK r10
NDK_TOOLCHAIN_VERSION = clang
#NDK_TOOLCHAIN_VERSION = 4.9
APP_CFLAGS += -Wall
APP_CPPFLAGS += -std=c++11 -frtti -fexceptions
# GNU libc++ is the only Android STL which supports C++11 features
APP_STL := c++_static
APP_BUILD_SCRIPT := jni/Android.mk
APP_MODULES := libtextsort_jni
