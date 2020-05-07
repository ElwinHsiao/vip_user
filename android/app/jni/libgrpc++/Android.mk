LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := grpc++
LOCAL_STATIC_LIBRARIES := ssl crypto protobuf

# LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
# LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libgrpc++.a
# include $(PREBUILT_STATIC_LIBRARY)

SOURCE_BASE := ../../../../third_party/grpc
SOURCE_DIR := $(SOURCE_BASE)/
SOURCE_FILES := $(shell cat $(LOCAL_PATH)/files.txt)
SOURCE_FILES += $(shell cat $(LOCAL_PATH)/absl_files.txt)
LOCAL_SRC_FILES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/$(SOURCE_BASE) \
	$(LOCAL_PATH)/$(SOURCE_BASE)/include \
	$(LOCAL_PATH)/$(SOURCE_BASE)/third_party/abseil-cpp \
	$(LOCAL_PATH)/$(SOURCE_BASE)/src/core/ext/upb-generated \
	$(LOCAL_PATH)/$(SOURCE_BASE)/third_party/upb \
	$(LOCAL_PATH)/$(SOURCE_BASE)/third_party/address_sorting/include \
	$(LOCAL_PATH)/$(SOURCE_BASE)/libgrpc++/include

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)
include $(BUILD_STATIC_LIBRARY)