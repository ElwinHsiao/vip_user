// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vipuser.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_vipuser_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_vipuser_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_vipuser_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_vipuser_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_vipuser_2eproto;
namespace vipuser {
class UserInfo;
class UserInfoDefaultTypeInternal;
extern UserInfoDefaultTypeInternal _UserInfo_default_instance_;
class VipUserRequest;
class VipUserRequestDefaultTypeInternal;
extern VipUserRequestDefaultTypeInternal _VipUserRequest_default_instance_;
class VipUserResponse;
class VipUserResponseDefaultTypeInternal;
extern VipUserResponseDefaultTypeInternal _VipUserResponse_default_instance_;
}  // namespace vipuser
PROTOBUF_NAMESPACE_OPEN
template<> ::vipuser::UserInfo* Arena::CreateMaybeMessage<::vipuser::UserInfo>(Arena*);
template<> ::vipuser::VipUserRequest* Arena::CreateMaybeMessage<::vipuser::VipUserRequest>(Arena*);
template<> ::vipuser::VipUserResponse* Arena::CreateMaybeMessage<::vipuser::VipUserResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace vipuser {

// ===================================================================

class UserInfo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:vipuser.UserInfo) */ {
 public:
  UserInfo();
  virtual ~UserInfo();

  UserInfo(const UserInfo& from);
  UserInfo(UserInfo&& from) noexcept
    : UserInfo() {
    *this = ::std::move(from);
  }

  inline UserInfo& operator=(const UserInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline UserInfo& operator=(UserInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const UserInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const UserInfo* internal_default_instance() {
    return reinterpret_cast<const UserInfo*>(
               &_UserInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(UserInfo& a, UserInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(UserInfo* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline UserInfo* New() const final {
    return CreateMaybeMessage<UserInfo>(nullptr);
  }

  UserInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<UserInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const UserInfo& from);
  void MergeFrom(const UserInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(UserInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "vipuser.UserInfo";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_vipuser_2eproto);
    return ::descriptor_table_vipuser_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserIdFieldNumber = 1,
    kPasswordHashFieldNumber = 2,
  };
  // string userId = 1;
  void clear_userid();
  const std::string& userid() const;
  void set_userid(const std::string& value);
  void set_userid(std::string&& value);
  void set_userid(const char* value);
  void set_userid(const char* value, size_t size);
  std::string* mutable_userid();
  std::string* release_userid();
  void set_allocated_userid(std::string* userid);
  private:
  const std::string& _internal_userid() const;
  void _internal_set_userid(const std::string& value);
  std::string* _internal_mutable_userid();
  public:

  // string passwordHash = 2;
  void clear_passwordhash();
  const std::string& passwordhash() const;
  void set_passwordhash(const std::string& value);
  void set_passwordhash(std::string&& value);
  void set_passwordhash(const char* value);
  void set_passwordhash(const char* value, size_t size);
  std::string* mutable_passwordhash();
  std::string* release_passwordhash();
  void set_allocated_passwordhash(std::string* passwordhash);
  private:
  const std::string& _internal_passwordhash() const;
  void _internal_set_passwordhash(const std::string& value);
  std::string* _internal_mutable_passwordhash();
  public:

  // @@protoc_insertion_point(class_scope:vipuser.UserInfo)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr userid_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr passwordhash_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vipuser_2eproto;
};
// -------------------------------------------------------------------

class VipUserRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:vipuser.VipUserRequest) */ {
 public:
  VipUserRequest();
  virtual ~VipUserRequest();

  VipUserRequest(const VipUserRequest& from);
  VipUserRequest(VipUserRequest&& from) noexcept
    : VipUserRequest() {
    *this = ::std::move(from);
  }

  inline VipUserRequest& operator=(const VipUserRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline VipUserRequest& operator=(VipUserRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const VipUserRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VipUserRequest* internal_default_instance() {
    return reinterpret_cast<const VipUserRequest*>(
               &_VipUserRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(VipUserRequest& a, VipUserRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(VipUserRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline VipUserRequest* New() const final {
    return CreateMaybeMessage<VipUserRequest>(nullptr);
  }

  VipUserRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<VipUserRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const VipUserRequest& from);
  void MergeFrom(const VipUserRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(VipUserRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "vipuser.VipUserRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_vipuser_2eproto);
    return ::descriptor_table_vipuser_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // @@protoc_insertion_point(class_scope:vipuser.VipUserRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vipuser_2eproto;
};
// -------------------------------------------------------------------

class VipUserResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:vipuser.VipUserResponse) */ {
 public:
  VipUserResponse();
  virtual ~VipUserResponse();

  VipUserResponse(const VipUserResponse& from);
  VipUserResponse(VipUserResponse&& from) noexcept
    : VipUserResponse() {
    *this = ::std::move(from);
  }

  inline VipUserResponse& operator=(const VipUserResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline VipUserResponse& operator=(VipUserResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const VipUserResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const VipUserResponse* internal_default_instance() {
    return reinterpret_cast<const VipUserResponse*>(
               &_VipUserResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(VipUserResponse& a, VipUserResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(VipUserResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline VipUserResponse* New() const final {
    return CreateMaybeMessage<VipUserResponse>(nullptr);
  }

  VipUserResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<VipUserResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const VipUserResponse& from);
  void MergeFrom(const VipUserResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(VipUserResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "vipuser.VipUserResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_vipuser_2eproto);
    return ::descriptor_table_vipuser_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 1,
  };
  // string message = 1;
  void clear_message();
  const std::string& message() const;
  void set_message(const std::string& value);
  void set_message(std::string&& value);
  void set_message(const char* value);
  void set_message(const char* value, size_t size);
  std::string* mutable_message();
  std::string* release_message();
  void set_allocated_message(std::string* message);
  private:
  const std::string& _internal_message() const;
  void _internal_set_message(const std::string& value);
  std::string* _internal_mutable_message();
  public:

  // @@protoc_insertion_point(class_scope:vipuser.VipUserResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vipuser_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// UserInfo

// string userId = 1;
inline void UserInfo::clear_userid() {
  userid_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserInfo::userid() const {
  // @@protoc_insertion_point(field_get:vipuser.UserInfo.userId)
  return _internal_userid();
}
inline void UserInfo::set_userid(const std::string& value) {
  _internal_set_userid(value);
  // @@protoc_insertion_point(field_set:vipuser.UserInfo.userId)
}
inline std::string* UserInfo::mutable_userid() {
  // @@protoc_insertion_point(field_mutable:vipuser.UserInfo.userId)
  return _internal_mutable_userid();
}
inline const std::string& UserInfo::_internal_userid() const {
  return userid_.GetNoArena();
}
inline void UserInfo::_internal_set_userid(const std::string& value) {
  
  userid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void UserInfo::set_userid(std::string&& value) {
  
  userid_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vipuser.UserInfo.userId)
}
inline void UserInfo::set_userid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  userid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vipuser.UserInfo.userId)
}
inline void UserInfo::set_userid(const char* value, size_t size) {
  
  userid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vipuser.UserInfo.userId)
}
inline std::string* UserInfo::_internal_mutable_userid() {
  
  return userid_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserInfo::release_userid() {
  // @@protoc_insertion_point(field_release:vipuser.UserInfo.userId)
  
  return userid_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfo::set_allocated_userid(std::string* userid) {
  if (userid != nullptr) {
    
  } else {
    
  }
  userid_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), userid);
  // @@protoc_insertion_point(field_set_allocated:vipuser.UserInfo.userId)
}

// string passwordHash = 2;
inline void UserInfo::clear_passwordhash() {
  passwordhash_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& UserInfo::passwordhash() const {
  // @@protoc_insertion_point(field_get:vipuser.UserInfo.passwordHash)
  return _internal_passwordhash();
}
inline void UserInfo::set_passwordhash(const std::string& value) {
  _internal_set_passwordhash(value);
  // @@protoc_insertion_point(field_set:vipuser.UserInfo.passwordHash)
}
inline std::string* UserInfo::mutable_passwordhash() {
  // @@protoc_insertion_point(field_mutable:vipuser.UserInfo.passwordHash)
  return _internal_mutable_passwordhash();
}
inline const std::string& UserInfo::_internal_passwordhash() const {
  return passwordhash_.GetNoArena();
}
inline void UserInfo::_internal_set_passwordhash(const std::string& value) {
  
  passwordhash_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void UserInfo::set_passwordhash(std::string&& value) {
  
  passwordhash_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vipuser.UserInfo.passwordHash)
}
inline void UserInfo::set_passwordhash(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  passwordhash_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vipuser.UserInfo.passwordHash)
}
inline void UserInfo::set_passwordhash(const char* value, size_t size) {
  
  passwordhash_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vipuser.UserInfo.passwordHash)
}
inline std::string* UserInfo::_internal_mutable_passwordhash() {
  
  return passwordhash_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* UserInfo::release_passwordhash() {
  // @@protoc_insertion_point(field_release:vipuser.UserInfo.passwordHash)
  
  return passwordhash_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void UserInfo::set_allocated_passwordhash(std::string* passwordhash) {
  if (passwordhash != nullptr) {
    
  } else {
    
  }
  passwordhash_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), passwordhash);
  // @@protoc_insertion_point(field_set_allocated:vipuser.UserInfo.passwordHash)
}

// -------------------------------------------------------------------

// VipUserRequest

// string name = 1;
inline void VipUserRequest::clear_name() {
  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& VipUserRequest::name() const {
  // @@protoc_insertion_point(field_get:vipuser.VipUserRequest.name)
  return _internal_name();
}
inline void VipUserRequest::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:vipuser.VipUserRequest.name)
}
inline std::string* VipUserRequest::mutable_name() {
  // @@protoc_insertion_point(field_mutable:vipuser.VipUserRequest.name)
  return _internal_mutable_name();
}
inline const std::string& VipUserRequest::_internal_name() const {
  return name_.GetNoArena();
}
inline void VipUserRequest::_internal_set_name(const std::string& value) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void VipUserRequest::set_name(std::string&& value) {
  
  name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vipuser.VipUserRequest.name)
}
inline void VipUserRequest::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vipuser.VipUserRequest.name)
}
inline void VipUserRequest::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vipuser.VipUserRequest.name)
}
inline std::string* VipUserRequest::_internal_mutable_name() {
  
  return name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* VipUserRequest::release_name() {
  // @@protoc_insertion_point(field_release:vipuser.VipUserRequest.name)
  
  return name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void VipUserRequest::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:vipuser.VipUserRequest.name)
}

// -------------------------------------------------------------------

// VipUserResponse

// string message = 1;
inline void VipUserResponse::clear_message() {
  message_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& VipUserResponse::message() const {
  // @@protoc_insertion_point(field_get:vipuser.VipUserResponse.message)
  return _internal_message();
}
inline void VipUserResponse::set_message(const std::string& value) {
  _internal_set_message(value);
  // @@protoc_insertion_point(field_set:vipuser.VipUserResponse.message)
}
inline std::string* VipUserResponse::mutable_message() {
  // @@protoc_insertion_point(field_mutable:vipuser.VipUserResponse.message)
  return _internal_mutable_message();
}
inline const std::string& VipUserResponse::_internal_message() const {
  return message_.GetNoArena();
}
inline void VipUserResponse::_internal_set_message(const std::string& value) {
  
  message_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void VipUserResponse::set_message(std::string&& value) {
  
  message_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vipuser.VipUserResponse.message)
}
inline void VipUserResponse::set_message(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  message_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vipuser.VipUserResponse.message)
}
inline void VipUserResponse::set_message(const char* value, size_t size) {
  
  message_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vipuser.VipUserResponse.message)
}
inline std::string* VipUserResponse::_internal_mutable_message() {
  
  return message_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* VipUserResponse::release_message() {
  // @@protoc_insertion_point(field_release:vipuser.VipUserResponse.message)
  
  return message_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void VipUserResponse::set_allocated_message(std::string* message) {
  if (message != nullptr) {
    
  } else {
    
  }
  message_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:vipuser.VipUserResponse.message)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace vipuser

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_vipuser_2eproto
