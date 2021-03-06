// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpc_response_data.proto

#ifndef PROTOBUF_rpc_5fresponse_5fdata_2eproto__INCLUDED
#define PROTOBUF_rpc_5fresponse_5fdata_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "message_type.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_rpc_5fresponse_5fdata_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsRpcResponseDataImpl();
void InitDefaultsRpcResponseData();
inline void InitDefaults() {
  InitDefaultsRpcResponseData();
}
}  // namespace protobuf_rpc_5fresponse_5fdata_2eproto
namespace crucis {
class RpcResponseData;
class RpcResponseDataDefaultTypeInternal;
extern RpcResponseDataDefaultTypeInternal _RpcResponseData_default_instance_;
}  // namespace crucis
namespace crucis {

// ===================================================================

class RpcResponseData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:crucis.RpcResponseData) */ {
 public:
  RpcResponseData();
  virtual ~RpcResponseData();

  RpcResponseData(const RpcResponseData& from);

  inline RpcResponseData& operator=(const RpcResponseData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RpcResponseData(RpcResponseData&& from) noexcept
    : RpcResponseData() {
    *this = ::std::move(from);
  }

  inline RpcResponseData& operator=(RpcResponseData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RpcResponseData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RpcResponseData* internal_default_instance() {
    return reinterpret_cast<const RpcResponseData*>(
               &_RpcResponseData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(RpcResponseData* other);
  friend void swap(RpcResponseData& a, RpcResponseData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RpcResponseData* New() const PROTOBUF_FINAL { return New(NULL); }

  RpcResponseData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const RpcResponseData& from);
  void MergeFrom(const RpcResponseData& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(RpcResponseData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes content = 4;
  void clear_content();
  static const int kContentFieldNumber = 4;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  #if LANG_CXX11
  void set_content(::std::string&& value);
  #endif
  void set_content(const char* value);
  void set_content(const void* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // .crucis.MessageType type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::crucis::MessageType type() const;
  void set_type(::crucis::MessageType value);

  // uint32 seq_id = 2;
  void clear_seq_id();
  static const int kSeqIdFieldNumber = 2;
  ::google::protobuf::uint32 seq_id() const;
  void set_seq_id(::google::protobuf::uint32 value);

  // uint64 service_object = 3;
  void clear_service_object();
  static const int kServiceObjectFieldNumber = 3;
  ::google::protobuf::uint64 service_object() const;
  void set_service_object(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:crucis.RpcResponseData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  int type_;
  ::google::protobuf::uint32 seq_id_;
  ::google::protobuf::uint64 service_object_;
  mutable int _cached_size_;
  friend struct ::protobuf_rpc_5fresponse_5fdata_2eproto::TableStruct;
  friend void ::protobuf_rpc_5fresponse_5fdata_2eproto::InitDefaultsRpcResponseDataImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RpcResponseData

// .crucis.MessageType type = 1;
inline void RpcResponseData::clear_type() {
  type_ = 0;
}
inline ::crucis::MessageType RpcResponseData::type() const {
  // @@protoc_insertion_point(field_get:crucis.RpcResponseData.type)
  return static_cast< ::crucis::MessageType >(type_);
}
inline void RpcResponseData::set_type(::crucis::MessageType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:crucis.RpcResponseData.type)
}

// uint32 seq_id = 2;
inline void RpcResponseData::clear_seq_id() {
  seq_id_ = 0u;
}
inline ::google::protobuf::uint32 RpcResponseData::seq_id() const {
  // @@protoc_insertion_point(field_get:crucis.RpcResponseData.seq_id)
  return seq_id_;
}
inline void RpcResponseData::set_seq_id(::google::protobuf::uint32 value) {
  
  seq_id_ = value;
  // @@protoc_insertion_point(field_set:crucis.RpcResponseData.seq_id)
}

// uint64 service_object = 3;
inline void RpcResponseData::clear_service_object() {
  service_object_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 RpcResponseData::service_object() const {
  // @@protoc_insertion_point(field_get:crucis.RpcResponseData.service_object)
  return service_object_;
}
inline void RpcResponseData::set_service_object(::google::protobuf::uint64 value) {
  
  service_object_ = value;
  // @@protoc_insertion_point(field_set:crucis.RpcResponseData.service_object)
}

// bytes content = 4;
inline void RpcResponseData::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RpcResponseData::content() const {
  // @@protoc_insertion_point(field_get:crucis.RpcResponseData.content)
  return content_.GetNoArena();
}
inline void RpcResponseData::set_content(const ::std::string& value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:crucis.RpcResponseData.content)
}
#if LANG_CXX11
inline void RpcResponseData::set_content(::std::string&& value) {
  
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:crucis.RpcResponseData.content)
}
#endif
inline void RpcResponseData::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:crucis.RpcResponseData.content)
}
inline void RpcResponseData::set_content(const void* value, size_t size) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:crucis.RpcResponseData.content)
}
inline ::std::string* RpcResponseData::mutable_content() {
  
  // @@protoc_insertion_point(field_mutable:crucis.RpcResponseData.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RpcResponseData::release_content() {
  // @@protoc_insertion_point(field_release:crucis.RpcResponseData.content)
  
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RpcResponseData::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    
  } else {
    
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:crucis.RpcResponseData.content)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace crucis

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rpc_5fresponse_5fdata_2eproto__INCLUDED
