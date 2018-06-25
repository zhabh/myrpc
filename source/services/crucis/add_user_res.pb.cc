// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: add_user_res.proto

#include "add_user_res.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace crucis {
class AddUserResDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<AddUserRes>
      _instance;
} _AddUserRes_default_instance_;
}  // namespace crucis
namespace protobuf_add_5fuser_5fres_2eproto {
void InitDefaultsAddUserResImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::crucis::_AddUserRes_default_instance_;
    new (ptr) ::crucis::AddUserRes();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::crucis::AddUserRes::InitAsDefaultInstance();
}

void InitDefaultsAddUserRes() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsAddUserResImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRes, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRes, card_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRes, code_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::crucis::AddUserRes)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::crucis::_AddUserRes_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "add_user_res.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\022add_user_res.proto\022\006crucis\032\020error_code"
      ".proto\">\n\nAddUserRes\022\017\n\007card_id\030\001 \001(\t\022\037\n"
      "\004code\030\002 \001(\0162\021.crucis.ErrorCodeb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 118);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "add_user_res.proto", &protobuf_RegisterTypes);
  ::protobuf_error_5fcode_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_add_5fuser_5fres_2eproto
namespace crucis {

// ===================================================================

void AddUserRes::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AddUserRes::kCardIdFieldNumber;
const int AddUserRes::kCodeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AddUserRes::AddUserRes()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_add_5fuser_5fres_2eproto::InitDefaultsAddUserRes();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:crucis.AddUserRes)
}
AddUserRes::AddUserRes(const AddUserRes& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  card_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.card_id().size() > 0) {
    card_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.card_id_);
  }
  code_ = from.code_;
  // @@protoc_insertion_point(copy_constructor:crucis.AddUserRes)
}

void AddUserRes::SharedCtor() {
  card_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  code_ = 0;
  _cached_size_ = 0;
}

AddUserRes::~AddUserRes() {
  // @@protoc_insertion_point(destructor:crucis.AddUserRes)
  SharedDtor();
}

void AddUserRes::SharedDtor() {
  card_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void AddUserRes::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AddUserRes::descriptor() {
  ::protobuf_add_5fuser_5fres_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_add_5fuser_5fres_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const AddUserRes& AddUserRes::default_instance() {
  ::protobuf_add_5fuser_5fres_2eproto::InitDefaultsAddUserRes();
  return *internal_default_instance();
}

AddUserRes* AddUserRes::New(::google::protobuf::Arena* arena) const {
  AddUserRes* n = new AddUserRes;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void AddUserRes::Clear() {
// @@protoc_insertion_point(message_clear_start:crucis.AddUserRes)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  card_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  code_ = 0;
  _internal_metadata_.Clear();
}

bool AddUserRes::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:crucis.AddUserRes)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string card_id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_card_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->card_id().data(), static_cast<int>(this->card_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "crucis.AddUserRes.card_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .crucis.ErrorCode code = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_code(static_cast< ::crucis::ErrorCode >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:crucis.AddUserRes)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:crucis.AddUserRes)
  return false;
#undef DO_
}

void AddUserRes::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:crucis.AddUserRes)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string card_id = 1;
  if (this->card_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->card_id().data(), static_cast<int>(this->card_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "crucis.AddUserRes.card_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->card_id(), output);
  }

  // .crucis.ErrorCode code = 2;
  if (this->code() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->code(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:crucis.AddUserRes)
}

::google::protobuf::uint8* AddUserRes::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:crucis.AddUserRes)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string card_id = 1;
  if (this->card_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->card_id().data(), static_cast<int>(this->card_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "crucis.AddUserRes.card_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->card_id(), target);
  }

  // .crucis.ErrorCode code = 2;
  if (this->code() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->code(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:crucis.AddUserRes)
  return target;
}

size_t AddUserRes::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:crucis.AddUserRes)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string card_id = 1;
  if (this->card_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->card_id());
  }

  // .crucis.ErrorCode code = 2;
  if (this->code() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->code());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void AddUserRes::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:crucis.AddUserRes)
  GOOGLE_DCHECK_NE(&from, this);
  const AddUserRes* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const AddUserRes>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:crucis.AddUserRes)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:crucis.AddUserRes)
    MergeFrom(*source);
  }
}

void AddUserRes::MergeFrom(const AddUserRes& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:crucis.AddUserRes)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.card_id().size() > 0) {

    card_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.card_id_);
  }
  if (from.code() != 0) {
    set_code(from.code());
  }
}

void AddUserRes::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:crucis.AddUserRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AddUserRes::CopyFrom(const AddUserRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:crucis.AddUserRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddUserRes::IsInitialized() const {
  return true;
}

void AddUserRes::Swap(AddUserRes* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AddUserRes::InternalSwap(AddUserRes* other) {
  using std::swap;
  card_id_.Swap(&other->card_id_);
  swap(code_, other->code_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata AddUserRes::GetMetadata() const {
  protobuf_add_5fuser_5fres_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_add_5fuser_5fres_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace crucis

// @@protoc_insertion_point(global_scope)