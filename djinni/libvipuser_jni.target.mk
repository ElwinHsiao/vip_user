# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE := libvipuser_jni
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
LOCAL_SDK_VERSION := 19
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES := \
	$(call intermediates-dir-for,STATIC_LIBRARIES,djinni_jni,,,$(GYP_VAR_PREFIX))/djinni_jni.a

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

$(gyp_intermediate_dir)/vipuser_client.cpp: $(LOCAL_PATH)/client/vipuser_client.cc
	mkdir -p $(@D); cp $< $@
LOCAL_GENERATED_SOURCES := \
	$(gyp_intermediate_dir)/vipuser_client.cpp

GYP_COPIED_SOURCE_ORIGIN_DIRS := \
	$(LOCAL_PATH)/client

LOCAL_SRC_FILES := \
	third_party/djinni/support-lib/jni/djinni_main.cpp \
	djinni/generated/jni/NativeTokenInfo.cpp \
	djinni/generated/jni/NativeAccountInfo.cpp \
	djinni/generated/jni/NativeAccessTicket.cpp \
	djinni/generated/jni/NativeVipUserWrapListener.cpp \
	djinni/generated/jni/NativeReplyResult.cpp \
	djinni/generated/jni/NativeVipUserClientWrap.cpp


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	-gdwarf-2 \
	-Werror \
	-Wall \
	-Wextra \
	-Wno-missing-field-initializers \
	-g \
	-O0 \
	-DDEBUG=1

MY_DEFS_Debug := \
	'-DDEBUG=1'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(LOCAL_PATH)/djinni/generated/jni \
	$(LOCAL_PATH)/djinni/generated/cpp \
	$(LOCAL_PATH)/client \
	$(LOCAL_PATH)/third_party/djinni/support-lib/jni


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-std=c++11 \
	-frtti \
	-fexceptions


# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	-gdwarf-2 \
	-Werror \
	-Wall \
	-Wextra \
	-Wno-missing-field-initializers \
	-Os \
	-fomit-frame-pointer \
	-fdata-sections \
	-ffunction-sections \
	-DNDEBUG=1

MY_DEFS_Release := \
	'-DNDEBUG=1'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(LOCAL_PATH)/djinni/generated/jni \
	$(LOCAL_PATH)/djinni/generated/cpp \
	$(LOCAL_PATH)/client \
	$(LOCAL_PATH)/third_party/djinni/support-lib/jni


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-std=c++11 \
	-frtti \
	-fexceptions


LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.

LOCAL_LDFLAGS_Debug := \
	-llog \
	-Wl,--build-id,--gc-sections,--exclude-libs,ALL


LOCAL_LDFLAGS_Release := \
	-llog \
	-Wl,--build-id,--gc-sections,--exclude-libs,ALL

LOCAL_GYP_LIBS :=

LOCAL_LDFLAGS := $(LOCAL_LDFLAGS_$(GYP_CONFIGURATION)) $(LOCAL_GYP_LIBS)

LOCAL_STATIC_LIBRARIES := \
	djinni_jni

# Enable grouping to fix circular references
LOCAL_GROUP_STATIC_LIBRARIES := true
# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: libvipuser_jni

LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)