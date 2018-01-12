// automatically generated, do not modify

#include "flatbuffers/flatbuffers.h"

namespace flatbuffers {

struct dylistviewOptions;

struct dylistviewOptions : private flatbuffers::Table {
  const ListViewOptions *nodeOptions() const { return GetPointer<const ListViewOptions *>(4); }
};

struct dylistviewOptionsBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_nodeOptions(flatbuffers::Offset<ListViewOptions> nodeOptions) { fbb_.AddOffset(4, nodeOptions); }
  dylistviewOptionsBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  flatbuffers::Offset<dylistviewOptions> Finish() { return flatbuffers::Offset<dylistviewOptions>(fbb_.EndTable(start_, 1)); }
};

inline flatbuffers::Offset<dylistviewOptions> CreatedylistviewOptions(flatbuffers::FlatBufferBuilder &_fbb, flatbuffers::Offset<ListViewOptions> nodeOptions) {
  dylistviewOptionsBuilder builder_(_fbb);
  builder_.add_nodeOptions(nodeOptions);
  return builder_.Finish();
}

inline const dylistviewOptions *GetdylistviewOptions(const void *buf) { return flatbuffers::GetRoot<dylistviewOptions>(buf); }

}; // namespace flatbuffers
