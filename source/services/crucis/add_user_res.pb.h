// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: add_user_res.proto

#ifndef PROTOBUF_add_5fuser_5fres_2eproto__INCLUDED
#define PROTOBUF_add_5fuser_5fres_2eproto__INCLUDED

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
#include "error_code.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_add_5fuser_5fres_2eproto {
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
void InitDefaultsAddUserResImpl();
void InitDefaultsAddUserRes();
inline void InitDefaults() {
  InitDefaultsAddUserRes();
}
}  // namespace protobuf_add_5fuser_5fres_2eproto
namespace crucis {
class AddUserRes;
class AddUserResDefaultTypeInternal;
extern AddUserResDefaultTypeInternal _AddUserRes_default_instance_;
}  // namespace crucis
namespace crucis {

// ===================================================================

class AddUserRes : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:crucis.AddUserRes) */ {
 public:
  AddUserRes();
  virtual ~AddUserRes();

  AddUserRes(const AddUserRes& from);

  inline AddUserRes& operator=(const AddUserRes& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AddUserRes(AddUserRes&& from) noexcept
    : AddUserRes() {
    *this = ::std::move(from);
  }

  inline AddUserRes& operator=(AddUserRes&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AddUserRes& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AddUserRes* internal_default_instance() {
    return reinterpret_cast<const AddUserRes*>(
               &_AddUserRes_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(AddUserRes* other);
  friend void swap(AddUserRes& a, AddUserRes& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AddUserRes* New() const PROTOBUF_FINAL { return New(NULL); }

  AddUserRes* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const AddUserRes& from);
  void MergeFrom(const AddUserRes& from);
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
  void InternalSwap(AddUserRes* other);
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

  // string card_id = 1;
  void clear_card_id();
  static const int kCardIdFieldNumber = 1;
  const ::std::string& card_id() const;
  void set_card_id(const ::std::string& value);
  #if LANG_CXX11
  void set_card_id(::std::string&& value);
  #endif
  void set_card_id(const char* value);
  void set_card_id(const char* value, size_t size);
  ::std::string* mutable_card_id();
  ::std::string* release_card_id();
  void set_allocated_card_id(::std::string* card_id);

  // .crucis.ErrorCode code = 2;
  void clear_code();
  static const int kCodeFieldNumber = 2;
  ::crucis::ErrorCode code() const;
  void set_code(::crucis::ErrorCode value);

  // @@protoc_insertion_point(class_scope:crucis.AddUserRes)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr card_id_;
  int code_;
  mutable int _cached_size_;
  friend struct ::protobuf_add_5fuser_5fres_2eproto::TableStruct;
  friend void ::protobuf_add_5fuser_5fres_2eproto::InitDefaultsAddUserResImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AddUserRes

// string card_id = 1;
inline void AddUserRes::clear_card_id() {
  card_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AddUserRes::card_id() const {
  // @@protoc_insertion_point(field_get:crucis.AddUserRes.card_id)
  return card_id_.GetNoArena();
}
inline void AddUserRes::set_card_id(const ::std::string& value) {
  
  card_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:crucis.AddUserRes.card_id)
}
#if LANG_CXX11
inline void AddUserRes::set_card_id(::std::string&& value) {
  
  card_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:crucis.AddUserRes.card_id)
}
#endif
inline void AddUserRes::set_card_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  card_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:crucis.AddUserRes.card_id)
}
inline void AddUserRes::set_card_id(const char* value, size_t size) {
  
  card_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:crucis.AddUserRes.card_id)
}
inline ::std::string* AddUserRes::mutable_card_id() {
  
  // @@protoc_insertion_point(field_mutable:crucis.AddUserRes.card_id)
  return card_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AddUserRes::release_card_id() {
  // @@protoc_insertion_point(field_release:crucis.AddUserRes.card_id)
  
  return card_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AddUserRes::set_allocated_card_id(::std::string* card_id) {
  if (card_id != NULL) {
    
  } else {
    
  }
  card_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), card_id);
  // @@protoc_insertion_point(field_set_allocated:crucis.AddUserRes.card_id)
}

// .crucis.ErrorCode code = 2;
inline void AddUserRes::clear_code() {
  code_ = 0;
}
inline ::crucis::ErrorCode AddUserRes::code() const {
  // @@protoc_insertion_point(field_get:crucis.AddUserRes.code)
  return static_cast< ::crucis::ErrorCode >(code_);
}
inline void AddUserRes::set_code(::crucis::ErrorCode value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:crucis.AddUserRes.code)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace crucis

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_add_5fuser_5fres_2eproto__INCLUDED
