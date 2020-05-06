LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := grpc++

#LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
# LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libgrpc++.a
# include $(PREBUILT_STATIC_LIBRARY)

SOURCE_BASE := $(LOCAL_PATH)/../../../../third_party/grpc
SOURCE_DIR := $(SOURCE_BASE)/
SOURCE_FILES := $(shell cat $(LOCAL_PATH)/files.txt)
LOCAL_SRC_FILES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
#LOCAL_SRC_FILES := $(SOURCE_BASE)/src/cpp/client/channel_cc.cc	
LOCAL_C_INCLUDES := $(SOURCE_BASE)/include
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

include $(BUILD_STATIC_LIBRARY)