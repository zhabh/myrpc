// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: auth_error_code.proto

#ifndef PROTOBUF_auth_5ferror_5fcode_2eproto__INCLUDED
#define PROTOBUF_auth_5ferror_5fcode_2eproto__INCLUDED

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace protobuf_auth_5ferror_5fcode_2eproto {
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
inline void InitDefaults() {
}
}  // namespace protobuf_auth_5ferror_5fcode_2eproto
namespace crucis {
}  // namespace crucis
namespace crucis {

enum AuthErrorCode {
  auth_error_code_unknow = 0,
  auth_error_code_pass = 1,
  auth_error_code_error_password = 2,
  auth_error_code_gamer_not_found = 3,
  AuthErrorCode_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  AuthErrorCode_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool AuthErrorCode_IsValid(int value);
const AuthErrorCode AuthErrorCode_MIN = auth_error_code_unknow;
const AuthErrorCode AuthErrorCode_MAX = auth_error_code_gamer_not_found;
const int AuthErrorCode_ARRAYSIZE = AuthErrorCode_MAX + 1;

const ::google::protobuf::EnumDescriptor* AuthErrorCode_descriptor();
inline const ::std::string& AuthErrorCode_Name(AuthErrorCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    AuthErrorCode_descriptor(), value);
}
inline bool AuthErrorCode_Parse(
    const ::std::string& name, AuthErrorCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<AuthErrorCode>(
    AuthErrorCode_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace crucis

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::crucis::AuthErrorCode> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::crucis::AuthErrorCode>() {
  return ::crucis::AuthErrorCode_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_auth_5ferror_5fcode_2eproto__INCLUDED
