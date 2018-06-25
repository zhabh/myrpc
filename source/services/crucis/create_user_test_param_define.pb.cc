// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: create_user_test_param_define.proto

#include "create_user_test_param_define.pb.h"

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
class AddUserRequestDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<AddUserRequest>
      _instance;
} _AddUserRequest_default_instance_;
class AddUserResponseDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<AddUserResponse>
      _instance;
} _AddUserResponse_default_instance_;
}  // namespace crucis
namespace protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto {
void InitDefaultsAddUserRequestImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::crucis::_AddUserRequest_default_instance_;
    new (ptr) ::crucis::AddUserRequest();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::crucis::AddUserRequest::InitAsDefaultInstance();
}

void InitDefaultsAddUserRequest() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsAddUserRequestImpl);
}

void InitDefaultsAddUserResponseImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_add_5fuser_5fres_2eproto::InitDefaultsAddUserRes();
  {
    void* ptr = &::crucis::_AddUserResponse_default_instance_;
    new (ptr) ::crucis::AddUserResponse();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::crucis::AddUserResponse::InitAsDefaultInstance();
}

void InitDefaultsAddUserResponse() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsAddUserResponseImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRequest, uid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRequest, nick_name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRequest, seq_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserRequest, online_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::crucis::AddUserResponse, ret_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::crucis::AddUserRequest)},
  { 9, -1, sizeof(::crucis::AddUserResponse)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::crucis::_AddUserRequest_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::crucis::_AddUserResponse_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "create_user_test_param_define.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n#create_user_test_param_define.proto\022\006c"
      "rucis\032\022add_user_res.proto\"P\n\016AddUserRequ"
      "est\022\013\n\003uid\030\001 \001(\004\022\021\n\tnick_name\030\002 \001(\t\022\016\n\006s"
      "eq_id\030\003 \001(\r\022\016\n\006online\030\004 \001(\010\"2\n\017AddUserRe"
      "sponse\022\037\n\003ret\030\001 \001(\0132\022.crucis.AddUserResb"
      "\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 207);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "create_user_test_param_define.proto", &protobuf_RegisterTypes);
  ::protobuf_add_5fuser_5fres_2eproto::AddDescriptors();
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
}  // namespace protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto
namespace crucis {

// ===================================================================

void AddUserRequest::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AddUserRequest::kUidFieldNumber;
const int AddUserRequest::kNickNameFieldNumber;
const int AddUserRequest::kSeqIdFieldNumber;
const int AddUserRequest::kOnlineFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AddUserRequest::AddUserRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::InitDefaultsAddUserRequest();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:crucis.AddUserRequest)
}
AddUserRequest::AddUserRequest(const AddUserRequest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  nick_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.nick_name().size() > 0) {
    nick_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nick_name_);
  }
  ::memcpy(&uid_, &from.uid_,
    static_cast<size_t>(reinterpret_cast<char*>(&online_) -
    reinterpret_cast<char*>(&uid_)) + sizeof(online_));
  // @@protoc_insertion_point(copy_constructor:crucis.AddUserRequest)
}

void AddUserRequest::SharedCtor() {
  nick_name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&uid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&online_) -
      reinterpret_cast<char*>(&uid_)) + sizeof(online_));
  _cached_size_ = 0;
}

AddUserRequest::~AddUserRequest() {
  // @@protoc_insertion_point(destructor:crucis.AddUserRequest)
  SharedDtor();
}

void AddUserRequest::SharedDtor() {
  nick_name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void AddUserRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AddUserRequest::descriptor() {
  ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const AddUserRequest& AddUserRequest::default_instance() {
  ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::InitDefaultsAddUserRequest();
  return *internal_default_instance();
}

AddUserRequest* AddUserRequest::New(::google::protobuf::Arena* arena) const {
  AddUserRequest* n = new AddUserRequest;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void AddUserRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:crucis.AddUserRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  nick_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&uid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&online_) -
      reinterpret_cast<char*>(&uid_)) + sizeof(online_));
  _internal_metadata_.Clear();
}

bool AddUserRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:crucis.AddUserRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint64 uid = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &uid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string nick_name = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nick_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->nick_name().data(), static_cast<int>(this->nick_name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "crucis.AddUserRequest.nick_name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 seq_id = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &seq_id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool online = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &online_)));
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
  // @@protoc_insertion_point(parse_success:crucis.AddUserRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:crucis.AddUserRequest)
  return false;
#undef DO_
}

void AddUserRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:crucis.AddUserRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 uid = 1;
  if (this->uid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->uid(), output);
  }

  // string nick_name = 2;
  if (this->nick_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->nick_name().data(), static_cast<int>(this->nick_name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "crucis.AddUserRequest.nick_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->nick_name(), output);
  }

  // uint32 seq_id = 3;
  if (this->seq_id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->seq_id(), output);
  }

  // bool online = 4;
  if (this->online() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->online(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:crucis.AddUserRequest)
}

::google::protobuf::uint8* AddUserRequest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:crucis.AddUserRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 uid = 1;
  if (this->uid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->uid(), target);
  }

  // string nick_name = 2;
  if (this->nick_name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->nick_name().data(), static_cast<int>(this->nick_name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "crucis.AddUserRequest.nick_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->nick_name(), target);
  }

  // uint32 seq_id = 3;
  if (this->seq_id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->seq_id(), target);
  }

  // bool online = 4;
  if (this->online() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->online(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:crucis.AddUserRequest)
  return target;
}

size_t AddUserRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:crucis.AddUserRequest)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string nick_name = 2;
  if (this->nick_name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->nick_name());
  }

  // uint64 uid = 1;
  if (this->uid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->uid());
  }

  // uint32 seq_id = 3;
  if (this->seq_id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->seq_id());
  }

  // bool online = 4;
  if (this->online() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void AddUserRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:crucis.AddUserRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const AddUserRequest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const AddUserRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:crucis.AddUserRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:crucis.AddUserRequest)
    MergeFrom(*source);
  }
}

void AddUserRequest::MergeFrom(const AddUserRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:crucis.AddUserRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.nick_name().size() > 0) {

    nick_name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nick_name_);
  }
  if (from.uid() != 0) {
    set_uid(from.uid());
  }
  if (from.seq_id() != 0) {
    set_seq_id(from.seq_id());
  }
  if (from.online() != 0) {
    set_online(from.online());
  }
}

void AddUserRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:crucis.AddUserRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AddUserRequest::CopyFrom(const AddUserRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:crucis.AddUserRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddUserRequest::IsInitialized() const {
  return true;
}

void AddUserRequest::Swap(AddUserRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AddUserRequest::InternalSwap(AddUserRequest* other) {
  using std::swap;
  nick_name_.Swap(&other->nick_name_);
  swap(uid_, other->uid_);
  swap(seq_id_, other->seq_id_);
  swap(online_, other->online_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata AddUserRequest::GetMetadata() const {
  protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void AddUserResponse::InitAsDefaultInstance() {
  ::crucis::_AddUserResponse_default_instance_._instance.get_mutable()->ret_ = const_cast< ::crucis::AddUserRes*>(
      ::crucis::AddUserRes::internal_default_instance());
}
void AddUserResponse::clear_ret() {
  if (GetArenaNoVirtual() == NULL && ret_ != NULL) {
    delete ret_;
  }
  ret_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AddUserResponse::kRetFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AddUserResponse::AddUserResponse()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::InitDefaultsAddUserResponse();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:crucis.AddUserResponse)
}
AddUserResponse::AddUserResponse(const AddUserResponse& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_ret()) {
    ret_ = new ::crucis::AddUserRes(*from.ret_);
  } else {
    ret_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:crucis.AddUserResponse)
}

void AddUserResponse::SharedCtor() {
  ret_ = NULL;
  _cached_size_ = 0;
}

AddUserResponse::~AddUserResponse() {
  // @@protoc_insertion_point(destructor:crucis.AddUserResponse)
  SharedDtor();
}

void AddUserResponse::SharedDtor() {
  if (this != internal_default_instance()) delete ret_;
}

void AddUserResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AddUserResponse::descriptor() {
  ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const AddUserResponse& AddUserResponse::default_instance() {
  ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::InitDefaultsAddUserResponse();
  return *internal_default_instance();
}

AddUserResponse* AddUserResponse::New(::google::protobuf::Arena* arena) const {
  AddUserResponse* n = new AddUserResponse;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void AddUserResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:crucis.AddUserResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == NULL && ret_ != NULL) {
    delete ret_;
  }
  ret_ = NULL;
  _internal_metadata_.Clear();
}

bool AddUserResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:crucis.AddUserResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .crucis.AddUserRes ret = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_ret()));
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
  // @@protoc_insertion_point(parse_success:crucis.AddUserResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:crucis.AddUserResponse)
  return false;
#undef DO_
}

void AddUserResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:crucis.AddUserResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .crucis.AddUserRes ret = 1;
  if (this->has_ret()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->ret_, output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:crucis.AddUserResponse)
}

::google::protobuf::uint8* AddUserResponse::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:crucis.AddUserResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .crucis.AddUserRes ret = 1;
  if (this->has_ret()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, *this->ret_, deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:crucis.AddUserResponse)
  return target;
}

size_t AddUserResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:crucis.AddUserResponse)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .crucis.AddUserRes ret = 1;
  if (this->has_ret()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *this->ret_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void AddUserResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:crucis.AddUserResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const AddUserResponse* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const AddUserResponse>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:crucis.AddUserResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:crucis.AddUserResponse)
    MergeFrom(*source);
  }
}

void AddUserResponse::MergeFrom(const AddUserResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:crucis.AddUserResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_ret()) {
    mutable_ret()->::crucis::AddUserRes::MergeFrom(from.ret());
  }
}

void AddUserResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:crucis.AddUserResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AddUserResponse::CopyFrom(const AddUserResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:crucis.AddUserResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddUserResponse::IsInitialized() const {
  return true;
}

void AddUserResponse::Swap(AddUserResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AddUserResponse::InternalSwap(AddUserResponse* other) {
  using std::swap;
  swap(ret_, other->ret_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata AddUserResponse::GetMetadata() const {
  protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_create_5fuser_5ftest_5fparam_5fdefine_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace crucis

// @@protoc_insertion_point(global_scope)