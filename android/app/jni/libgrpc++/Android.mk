LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := grpc++

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include


### tips : .a build
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libgrpc++.a
include $(PREBUILT_STATIC_LIBRARY)
