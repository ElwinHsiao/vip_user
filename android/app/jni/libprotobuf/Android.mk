LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := protobuf

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libprotobuf.a
include $(PREBUILT_STATIC_LIBRARY)

# SOURCE_BASE := ../../../../third_party/grpc/third_party/protobuf/src
# SOURCE_DIR := $(SOURCE_BASE)/
# SOURCE_FILES := $(shell cat $(LOCAL_PATH)/full_files.txt)
# LOCAL_SRC_FILES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
# LOCAL_C_INCLUDES := $(SOURCE_BASE)/include 
# LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

# LOCAL_CFLAGS +=  -DHAVE_PTHREAD -DGOOGLE_PROTOBUF_DONT_USE_UNALIGNED
# include $(BUILD_STATIC_LIBRARY)

