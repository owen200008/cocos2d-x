// automatically generated, do not modify

#include "flatbuffers/flatbuffers.h"

namespace flatbuffers {

struct cocosrichtextOptions;

struct cocosrichtextOptions : private flatbuffers::Table {
  const WidgetOptions *nodeOptions() const { return GetPointer<const WidgetOptions *>(4); }
  uint8_t ClkBySelf() const { return GetField<uint8_t>(6, 0); }
  float NewWidth() const { return GetField<float>(8, 0); }
  float NewHeight() const { return GetField<float>(10, 0); }
  const flatbuffers::String *drawcolor() const { return GetPointer<const flatbuffers::String *>(12); }
  const flatbuffers::String *m_strFontFile() const { return GetPointer<const flatbuffers::String *>(14); }
  int32_t FontSize() const { return GetField<int32_t>(16, 0); }
  const flatbuffers::String *LabelText() const { return GetPointer<const flatbuffers::String *>(18); }
  uint8_t XCenter() const { return GetField<uint8_t>(20, 0); }
  uint8_t YCenter() const { return GetField<uint8_t>(22, 0); }
  int32_t LineSprite() const { return GetField<int32_t>(24, 0); }
};

struct cocosrichtextOptionsBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_nodeOptions(flatbuffers::Offset<WidgetOptions> nodeOptions) { fbb_.AddOffset(4, nodeOptions); }
  void add_ClkBySelf(uint8_t ClkBySelf) { fbb_.AddElement<uint8_t>(6, ClkBySelf, 0); }
  void add_NewWidth(float NewWidth) { fbb_.AddElement<float>(8, NewWidth, 0); }
  void add_NewHeight(float NewHeight) { fbb_.AddElement<float>(10, NewHeight, 0); }
  void add_drawcolor(flatbuffers::Offset<flatbuffers::String> drawcolor) { fbb_.AddOffset(12, drawcolor); }
  void add_m_strFontFile(flatbuffers::Offset<flatbuffers::String> m_strFontFile) { fbb_.AddOffset(14, m_strFontFile); }
  void add_FontSize(int32_t FontSize) { fbb_.AddElement<int32_t>(16, FontSize, 0); }
  void add_LabelText(flatbuffers::Offset<flatbuffers::String> LabelText) { fbb_.AddOffset(18, LabelText); }
  void add_XCenter(uint8_t XCenter) { fbb_.AddElement<uint8_t>(20, XCenter, 0); }
  void add_YCenter(uint8_t YCenter) { fbb_.AddElement<uint8_t>(22, YCenter, 0); }
  void add_LineSprite(int32_t LineSprite) { fbb_.AddElement<int32_t>(24, LineSprite, 0); }
  cocosrichtextOptionsBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  flatbuffers::Offset<cocosrichtextOptions> Finish() { return flatbuffers::Offset<cocosrichtextOptions>(fbb_.EndTable(start_, 11)); }
};

inline flatbuffers::Offset<cocosrichtextOptions> CreatecocosrichtextOptions(flatbuffers::FlatBufferBuilder &_fbb, flatbuffers::Offset<WidgetOptions> nodeOptions, uint8_t ClkBySelf, float NewWidth, float NewHeight, flatbuffers::Offset<flatbuffers::String> drawcolor, flatbuffers::Offset<flatbuffers::String> m_strFontFile, int32_t FontSize, flatbuffers::Offset<flatbuffers::String> LabelText, uint8_t XCenter, uint8_t YCenter, int32_t LineSprite) {
  cocosrichtextOptionsBuilder builder_(_fbb);
  builder_.add_LineSprite(LineSprite);
  builder_.add_LabelText(LabelText);
  builder_.add_FontSize(FontSize);
  builder_.add_m_strFontFile(m_strFontFile);
  builder_.add_drawcolor(drawcolor);
  builder_.add_NewHeight(NewHeight);
  builder_.add_NewWidth(NewWidth);
  builder_.add_nodeOptions(nodeOptions);
  builder_.add_YCenter(YCenter);
  builder_.add_XCenter(XCenter);
  builder_.add_ClkBySelf(ClkBySelf);
  return builder_.Finish();
}

inline const cocosrichtextOptions *GetcocosrichtextOptions(const void *buf) { return flatbuffers::GetRoot<cocosrichtextOptions>(buf); }

}; // namespace flatbuffers
