// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: servic_result.proto

#ifndef PROTOBUF_servic_5fresult_2eproto__INCLUDED
#define PROTOBUF_servic_5fresult_2eproto__INCLUDED

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

namespace protobuf_servic_5fresult_2eproto {
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
}  // namespace protobuf_servic_5fresult_2eproto
namespace crucis {
}  // namespace crucis
namespace crucis {

enum ServicResult {
  servic_result_unknown = 0,
  ServicResult_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ServicResult_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ServicResult_IsValid(int value);
const ServicResult ServicResult_MIN = servic_result_unknown;
const ServicResult ServicResult_MAX = servic_result_unknown;
const int ServicResult_ARRAYSIZE = ServicResult_MAX + 1;

const ::google::protobuf::EnumDescriptor* ServicResult_descriptor();
inline const ::std::string& ServicResult_Name(ServicResult value) {
  return ::google::protobuf::internal::NameOfEnum(
    ServicResult_descriptor(), value);
}
inline bool ServicResult_Parse(
    const ::std::string& name, ServicResult* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ServicResult>(
    ServicResult_descriptor(), name, value);
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

template <> struct is_proto_enum< ::crucis::ServicResult> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::crucis::ServicResult>() {
  return ::crucis::ServicResult_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_servic_5fresult_2eproto__INCLUDED
